#include <Board.h>
#include <src/config/unit_tests.h>
#include <src/sensors/i2c_sensors/rtc.h>
#include <test_runners/rtc_tests.h>
#include <test_runners/unity.h>
#include <time.h>

static const byte kTestRtcAddr = 0x68;

void TestRtcReadTransaction(void) {
#ifdef RTC_TESTS_IGNORED
    TEST_IGNORE_MESSAGE("Hardware test ignored");
#endif
    I2c test_i2c_bus(Board_I2C_TMP);
    Rtc test_rtc(&test_i2c_bus, kTestRtcAddr, "ab_rtcmc_32");

    bool success = test_rtc.TakeReading();

    TEST_ASSERT(success);
}
