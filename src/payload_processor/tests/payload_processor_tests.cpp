#include <CppUTest/TestHarness.h>
#include <external/nanopb/pb_encode.h>
#include <external/sgp4/sgp4.h>
#include <src/adcs/state_estimators/location_estimator.h>
#include <src/board/i2c/io_expander/io_expander.h>
#include <src/config/satellite.h>
#include <src/config/unit_tests.h>
#include <src/database/circular_buffer_nanopb.h>
#include <src/database/sd_card.h>
#include <src/messages/CurrentReading.pb.h>
#include <src/messages/IoExpanderToggleUplinkPayload.pb.h>
#include <src/messages/Time.pb.h>
#include <src/messages/Tle.pb.h>
#include <src/payload_processor/payload_processor.h>
#include <src/payload_processor/runnable_payload_processor.h>
#include <src/payload_processor/tests/mock_uplink_builder.h>
#include <src/payload_processor/uplinks/io_expander_toggle_uplink.h>
#include <src/payload_processor/uplinks/lithium_beacon_period_uplink.h>
#include <src/payload_processor/uplinks/science_data_uplink.h>
#include <src/payload_processor/uplinks/test_uplink.h>
#include <src/payload_processor/uplinks/tle_update_uplink.h>
#include <src/sensors/measurable_id.h>
#include <src/sensors/measurable_manager.h>
#include <src/telecomms/lithium.h>
#include <src/telecomms/msp_payloads/test_ones_payload.h>
#include <src/telecomms/runnable_beacon.h>
#include <src/util/etl_utils.h>
#include <src/util/message_codes.h>
#include <src/util/nanopb_utils.h>
#include <src/util/satellite_time_source.h>
#include <src/util/task_utils.h>
#include <stdio.h>
#include <ti/sysbios/BIOS.h>

TEST_GROUP(PayloadProcessor){};

TEST(PayloadProcessor, TestPayloadProcessor) {
    byte payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);

    // Set the bytes necessary for 2 x test command
    builder.AddUplinkCode(kTestUplink)
        .AddData<byte>(TestUplink::kTestValue1)
        .AddData<byte>(TestUplink::kTestValue2)
        .AddUplinkCode(kTestUplink)
        .AddData<byte>(TestUplink::kTestValue1)
        .AddData<byte>(TestUplink::kTestValue2);

    PayloadProcessor payload_processor;
    CHECK(payload_processor.ParseAndExecuteUplinks(builder.Build()));
}

TEST(PayloadProcessor, TestForceResetUplink) {
    if (!kForceResetCommandEnabled) {
        TEST_EXIT
    }

    byte payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);
    builder.AddUplinkCode(kForceResetUplink);

    PayloadProcessor payload_processor;
    CHECK(payload_processor.ParseAndExecuteUplinks(builder.Build()));
    FAIL("Software reset failed.");  // reset has failed if program
                                     // reaches this line
}

TEST(PayloadProcessor, TestTleUpdateUplink) {
    Tle test_tle;
    // TLE test data (from sgp4_tests.cpp)
    test_tle.epoch = 00179.78495062;
    test_tle.mean_motion = 10.824191574;
    test_tle.eccentricity_1e7 = 1859667;
    test_tle.inclination = 34.2682;
    test_tle.raan = 348.7242;
    test_tle.argument_of_perigee = 331.7664;
    test_tle.mean_anomaly = 19.3264;
    test_tle.bstar_drag = 0.000028098;

    uint8_t payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);
    builder.AddUplinkCode(kTleUpdateUplink).AddNanopbMacro(Tle)(test_tle);

    // Create test mailbox
    Mailbox_Params_init(&LocationEstimator::tle_update_uplink_mailbox_params);
    Mailbox_Handle tle_update_uplink_mailbox_handle = Mailbox_create(
        sizeof(Tle), 1, &LocationEstimator::tle_update_uplink_mailbox_params,
        NULL);
    if (tle_update_uplink_mailbox_handle == NULL) {
        etl::exception e("Unable to create TLE update command mailbox",
                         __FILE__, __LINE__);
        throw e;
    }
    TleUpdateUplink::SetTleUpdateUplinkMailboxHandle(
        tle_update_uplink_mailbox_handle);
    LocationEstimator::SetTleUpdateUplinkMailboxHandle(
        tle_update_uplink_mailbox_handle);

    // Send the encoded TLE to a payload processor (which decodes it and posts
    // it to the TLE update mailbox)
    PayloadProcessor test_payload_processor;
    CHECK(test_payload_processor.ParseAndExecuteUplinks(builder.Build()));

    // Have a location estimator retrieve the decoded TLE from the mailbox and
    // update its internal satrec values
    LocationEstimator test_location_estimator;
    test_location_estimator.CheckForUpdatedTle();
    elsetrec generated_satrec = test_location_estimator.GetSatrec();

    CHECK(generated_satrec.no_kozai ==
          test_tle.mean_motion / Sgp4Utils::xpdotp);
    CHECK(generated_satrec.inclo ==
          test_tle.inclination * Sgp4Utils::kDegreesToRadians);
    CHECK(generated_satrec.nodeo ==
          test_tle.raan * Sgp4Utils::kDegreesToRadians);
    CHECK(generated_satrec.argpo ==
          test_tle.argument_of_perigee * Sgp4Utils::kDegreesToRadians);
    CHECK(generated_satrec.mo ==
          test_tle.mean_anomaly * Sgp4Utils::kDegreesToRadians);
    CHECK(generated_satrec.bstar == test_tle.bstar_drag);
}

TEST(PayloadProcessor, TestLithiumTestUplink) {
    if (!kTcomBoardAvailable) {
        TEST_EXIT
    }

    byte payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);
    builder.AddUplinkCode(kLithiumTestUplink);
    PayloadProcessor payload_processor;

    // Should also verify on the ground that 10 packets have been received
    CHECK(payload_processor.ParseAndExecuteUplinks(builder.Build()));
}

TEST(PayloadProcessor, TestLithiumBeaconPeriodUplink) {
    byte payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);

    LithiumBeaconPeriodUplinkPayload injected_beacon_period = {5000};
    builder.AddUplinkCode(kLithiumBeaconPeriodUplink)
        .AddNanopbMacro(LithiumBeaconPeriodUplinkPayload)(
            injected_beacon_period);
    PayloadProcessor payload_processor;

    CHECK(payload_processor.ParseAndExecuteUplinks(builder.Build()));
    CHECK_EQUAL(RunnableBeacon::GetBeaconPeriodMs(), 5000);

    // Reset to nominal

    injected_beacon_period = {kNominalBeaconPeriodMs};

    byte reset_payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder reset_builder(reset_payload,
                                    Lithium::kMaxReceivedUplinkSize);
    reset_builder.AddUplinkCode(kLithiumBeaconPeriodUplink)
        .AddNanopbMacro(LithiumBeaconPeriodUplinkPayload)(
            injected_beacon_period);

    CHECK(payload_processor.ParseAndExecuteUplinks(reset_builder.Build()));
    CHECK_EQUAL(RunnableBeacon::GetBeaconPeriodMs(), kNominalBeaconPeriodMs);
}

TEST(PayloadProcessor, TestScienceDataUplink) {
    try {
        if (!kSdCardAvailable) {
            TEST_EXIT
        }

        Time requested_time = SatelliteTimeSource::GetTime();

        PayloadProcessor payload_processor;
        byte payload[Lithium::kMaxReceivedUplinkSize] = {0};
        MockUplinkBuilder builder(payload, Lithium::kMaxReceivedUplinkSize);
        builder.AddUplinkCode(kScienceDataUplink)
            .AddData<uint8_t>(
                static_cast<uint8_t>(kTestCurrent))  // Requested measurable ID
            .AddData<uint8_t>(0)
            .AddNanopbMacro(Time)(requested_time);

        // Create a CircularBuffer and put a value in it
        char filename[4];
        sprintf(filename, "%3d", kTestCurrent);
        CircularBufferNanopb(CurrentReading)::Create(filename, 10);

        CurrentReading test_current =
            MeasurableManager::GetInstance()
                ->ReadNanopbMeasurable<CurrentReading>(kComInI2, 0);
        CircularBufferNanopb(CurrentReading)::WriteMessage(filename,
                                                           test_current);

        CHECK(payload_processor.ParseAndExecuteUplinks(builder.Build()));

        SdCard::GetInstance()->FileDelete(filename);
    } catch (etl::exception& e) {
        EtlUtils::LogException(e);
        FAIL("Uncaught exception in test");
    }
}

// TODO(dingbenjamin): Figure out how to teardown for just this test
TEST(PayloadProcessor, TestIoExpanderToggleUplink) {
    byte buffer_off[Lithium::kMaxReceivedUplinkSize] = {0};

    MockUplinkBuilder builder_off(buffer_off, Lithium::kMaxReceivedUplinkSize);
    // Set nanopb message
    // Toggle comms regulators expander
    IoExpanderToggleUplinkPayload en_1_off = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn1),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOff), 1000};
    IoExpanderToggleUplinkPayload en_3_off = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn3),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOff), 1000};
    IoExpanderToggleUplinkPayload en_4_off = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn4),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOff), 1000};
    IoExpanderToggleUplinkPayload en_5_off = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn5),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOff), 1000};

    builder_off.AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_1_off)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_3_off)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_4_off)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_5_off);

    PayloadProcessor payload_processor;
    CHECK(payload_processor.ParseAndExecuteUplinks(builder_off.Build()));

    // Check Lithium is now unable to transmit
    TaskUtils::SleepMilli(2000);
    TestOnesPayload ones;
    CHECK_FALSE(Lithium::GetInstance()->Transmit(&ones));

    // Turn back on
    IoExpanderToggleUplinkPayload en_1_on = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn1),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOn), 1000};
    IoExpanderToggleUplinkPayload en_3_on = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn3),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOn), 1000};
    IoExpanderToggleUplinkPayload en_4_on = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn4),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOn), 1000};
    IoExpanderToggleUplinkPayload en_5_on = {
        static_cast<uint32_t>(IoExpander::kCommsIoExpander),
        static_cast<uint32_t>(IoExpander::kIoExpanderPinTelecomsEn5),
        static_cast<uint32_t>(IoExpanderToggleUplink::kToggleOn), 1000};

    byte buffer_on[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder_on(buffer_on, Lithium::kMaxReceivedUplinkSize);

    builder_on.AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_1_on)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_3_on)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_4_on)
        .AddUplinkCode(kIoExpanderToggleUplink)
        .AddNanopbMacro(IoExpanderToggleUplinkPayload)(en_5_on);

    CHECK(payload_processor.ParseAndExecuteUplinks(builder_on.Build()));
    TaskUtils::SleepMilli(2000);
    CHECK(Lithium::GetInstance()->Transmit(&ones));
}

TEST(PayloadProcessor, TestSequence) {
    PayloadProcessor payload_processor;
    RunnablePayloadProcessor::check_sequence = true;
    RunnablePayloadProcessor::check_hmac = false;
    RunnablePayloadProcessor::use_fec = false;
    RunnablePayloadProcessor::sequence = 0;

    // Build a command that is reused in the test
    // Don't need to set HMAC or FEC as these are turned off for now
    byte rpp_payload[Lithium::kMaxReceivedUplinkSize] = {0};
    MockUplinkBuilder builder(
        rpp_payload + RunnablePayloadProcessor::kMspUplinkIndex,
        Lithium::kMaxReceivedUplinkSize -
            RunnablePayloadProcessor::kMspUplinkIndex);

    builder.AddUplinkCode(kTestUplink)
        .AddData<byte>(TestUplink::kTestValue1)
        .AddData<byte>(TestUplink::kTestValue2)
        .AddUplinkCode(kTestUplink)
        .AddData<byte>(TestUplink::kTestValue1)
        .AddData<byte>(TestUplink::kTestValue2)
        .Build();

    // Check start
    for (uint16_t i = 0; i <= 50; i++) {
        rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex] =
            static_cast<uint8_t>(i >> 8);
        rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex + 1] =
            static_cast<uint8_t>(i % 256);
        CHECK(RunnablePayloadProcessor::CheckSequence(rpp_payload));
        CHECK(payload_processor.ParseAndExecuteUplinks(
            builder.GetMockUplinkBuffer()));

        // Check invalid
        CHECK_FALSE(RunnablePayloadProcessor::CheckSequence(rpp_payload));
    }

    // Check end (skip the middle)
    RunnablePayloadProcessor::sequence = 65530;

    for (uint16_t i = RunnablePayloadProcessor::sequence; i < UINT16_MAX; i++) {
        rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex] =
            static_cast<uint8_t>(i >> 8);
        rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex + 1] =
            static_cast<uint8_t>(i % 256);
        CHECK(RunnablePayloadProcessor::CheckSequence(rpp_payload));
        CHECK(payload_processor.ParseAndExecuteUplinks(
            builder.GetMockUplinkBuffer()));

        // Check invalid
        CHECK_FALSE(RunnablePayloadProcessor::CheckSequence(rpp_payload));
    }

    // Check last value and wraparound

    rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex] =
        static_cast<uint8_t>(UINT16_MAX >> 8);
    rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex + 1] =
        static_cast<uint8_t>(UINT16_MAX % 256);
    CHECK(RunnablePayloadProcessor::CheckSequence(rpp_payload));
    CHECK(payload_processor.ParseAndExecuteUplinks(
        builder.GetMockUplinkBuffer()));

    rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex] = 0;
    rpp_payload[RunnablePayloadProcessor::kMspSequenceNumberIndex + 1] = 0;
    CHECK(RunnablePayloadProcessor::CheckSequence(rpp_payload));
    CHECK(payload_processor.ParseAndExecuteUplinks(
        builder.GetMockUplinkBuffer()));

    // TODO(dingbenjamin): Move this to teardown
    RunnablePayloadProcessor::check_sequence = kCheckSequenceDefault;
    RunnablePayloadProcessor::check_hmac = kCheckHmacDefault;
    RunnablePayloadProcessor::use_fec = kUseFecDefault;
    RunnablePayloadProcessor::sequence = 0;
}
