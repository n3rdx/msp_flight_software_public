#ifndef SRC_UTIL_MESSAGE_CODES_H_
#define SRC_UTIL_MESSAGE_CODES_H_

// This needs to be kept current with the Python decoder in the DebugClient
// folder
// TODO(rskew) make a DebugClient python function that can parse this file
// automatically for synchronising endpoints
enum DebugMessageType {
    // TODO(rskew) check if these are still used
    kMockTemperatureSensor = 0,
    kMockRadiationSensor = 1,
    kMockTestContainer = 2,
    kMockTestSensor = 3,
    kPopMessageQueue = 4,
    kAntenna = 5,

    // A message code of zero looks like a read timeout to the DebugClient
    kNoMessage = 0x00,
    kBms1InputCurrentReadingCode = 0x01,
    kBms1InputVoltageReadingCode = 0x02,
    kPrimaryMcuRegulatorCurrentReadingCode = 0x03,
    kMagnetorquerXCurrentReadingCode = 0x04,
    kAdcsSystemStateReadingCode = 0x05,
    kMagnetometerReadingRequestCode = 0x06,
    kTorqueOutputReadingCode = 0x07,
    kMagnetometerReadingCode = 0x08,
    kTestSensorReadingCode = 0x09,
    kTestSensorReadingRequestCode = 0x0A,
    kTestRequestCode = 0x0B,
    kTleRequestCode = 0x0C,
    kLocationReadingCode = 0x0D,
    kPwmOutputReadingCode = 0x0E,
    kCalibratedMagnetometerReadingCode = 0x0F,
    kPayloadProcessorInjection = 0x10,
    kBDotEstimateCode = 0x11
};

// This needs to be kept current with the Python decoder in the DebugClient
// folder
enum DebugMessageVersion { kV1 = 0 };

enum PayloadType {
    kMspTestPayloadCode = 4,
    kBeaconPayloadCode = 5,
    kTestOnesPayloadCode = 6,
    kSciencePayloadCode = 7
};

enum Commands {
    kNoCommand = 0,
    kTestCommand = 1,
    kLithiumEnableCommand = 2,
    kTleUpdateCommand = 3,
    kForceResetCommand = 4,
    kLithiumBeaconPeriodCommand = 5,
    kScienceDataCommand = 6,
    kLithiumFastPaCommand = 7,
    kLithiumTestCommand = 8,
    kDeployAntennaCommand = 9,
    kEnableDataloggerCommand = 10,
    kFormatSdCommand = 11,
    kCommandsLength
};

#endif  // SRC_UTIL_MESSAGE_CODES_H_
