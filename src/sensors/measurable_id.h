#ifndef SRC_SENSORS_MEASURABLE_ID_H_
#define SRC_SENSORS_MEASURABLE_ID_H_

// Append to the bottom of this list only. DO NOT add entries midway or change
// the numbers. Add to the bottom only and give an incrementing number.
enum MeasurableId {
    kComInV1 = 0,
    kComOutV1 = 1,
    kComInV2 = 2,
    kComOutV2 = 3,
    kComInI1 = 4,
    kComOutI1 = 5,
    kComInI2 = 6,
    kComOutI2 = 7,
    kComT1 = 8,
    kComT2 = 9,
    kComRxBytes = 10,
    kComTxBytes = 11,
    kComAntennaFlags = 12,
    kComLithiumOps = 13,
    kComLithiumRssi = 14,
    kComLithiumT = 15,
    kComLithiumTime = 16,
    kEpsT1 = 17,
    kEpsT2 = 18,
    kEpsBmsDieT1 = 19,
    kEpsBmsDieT2 = 20,
    kEpsBmsBatT1 = 21,
    kEpsBmsBatT2 = 22,
    kEpsAdcBatV1 = 23,
    kEpsBoostOutV1 = 24,
    kEpsBoostInI1 = 25,
    kEpsLoadI1 = 26,
    kEpsAdcBatV2 = 27,
    kEpsBoostOutV2 = 28,
    kEpsLoadI2 = 29,
    kEpsBoostInI2 = 30,
    kEpsRail1 = 31,
    kEpsRail2 = 32,
    kEpsTopPanelV = 33,
    kEpsTopPanelI = 34,
    kEpsTopSolarV = 35,
    kEpsTopSolarI = 36,
    kEpsBmsReadings1 = 37,
    kEpsBmsReadings2 = 38,
    kEpsBmsBatV1 = 39,
    kEpsBmsBatI1 = 40,
    kEpsBmsSysV1 = 41,
    kEpsBmsInV1 = 42,
    kEpsBmsInI1 = 43,
    kEpsBmsJeitaRegion1 = 44,
    kEpsBmsSystemStatus1 = 45,
    kEpsBmsChargerState1 = 46,
    kEpsBmsChargeIndicator1 = 47,
    kEpsBmsRechargeThreshold1 = 48,
    kEpsBmsChargerConfig1 = 49,
    kEpsBmsCxThreshold1 = 50,
    kEpsBmsVChargeSet1 = 51,
    kEpsBmsIChargeTarget1 = 52,
    kEpsBmsConfig1 = 53,
    kEpsBmsQCount1 = 54,
    kEpsBmsQCountScale1 = 55,
    kEpsBmsTelemetryValid1 = 56,
    kEpsBmsBatV2 = 57,
    kEpsBmsBatI2 = 58,
    kEpsBmsSysV2 = 59,
    kEpsBmsInV2 = 60,
    kEpsBmsInI2 = 61,
    kEpsBmsJeitaRegion2 = 62,
    kEpsBmsSystemStatus2 = 63,
    kEpsBmsChargerState2 = 64,
    kEpsBmsChargeIndicator2 = 65,
    kEpsBmsRechargeThreshold2 = 66,
    kEpsBmsChargerConfig2 = 67,
    kEpsBmsCxThreshold2 = 68,
    kEpsBmsVChargeSet2 = 69,
    kEpsBmsIChargeTarget2 = 70,
    kEpsBmsConfig2 = 71,
    kEpsBmsQCount2 = 72,
    kEpsBmsQCountScale2 = 73,
    kEpsBmsTelemetryValid2 = 74,
    kFsTorquerXI = 75,
    kFsTorquerTotalI = 76,
    kFsTorquerYI = 77,
    kFsTorquerZI = 78,
    kFsTorquerXAV = 79,
    kFsTorquerXBV = 80,
    kFsTorquerYAV = 81,
    kFsTorquerYBV = 82,
    kFsTorquerZAV = 83,
    kFsTorquerZBV = 84,
    kFsHbXT = 85,
    kFsHbYT = 86,
    kFsHbZT = 87,
    kFsImuGyro1 = 88,
    kFsImuAccel1 = 89,
    kFsImuT1 = 90,
    kFsImuMagno1 = 91,
    kFsImuGyro2 = 92,
    kFsImuAccel2 = 93,
    kFsImuT2 = 94,
    kFsImuMagno2 = 95,
    kFsRad1 = 96,
    kUtilT = 97,
    kCdhT = 98,
    kXPosT1 = 99,
    kXPosT2 = 100,
    kYPosT1 = 101,
    kYPosT2 = 102,
    kXNegT1 = 103,
    kXNegT2 = 104,
    kYNegT1 = 105,
    kYNegT2 = 106,
    kZNegT1 = 107,
    kZNegT2 = 108,
    kZPosT = 109,
    kXPosV = 110,
    kXPosI = 111,
    kXPosSolarV = 112,
    kXPosSolarI = 113,
    kYPosV = 114,
    kYPosI = 115,
    kYPosSolarV = 116,
    kYPosSolarI = 117,
    kXNegV = 118,
    kXNegI = 119,
    kXNegSolarV = 120,
    kXNegSolarI = 121,
    kYNegV = 122,
    kYNegI = 123,
    kYNegSolarV = 124,
    kYNegSolarI = 125,
    kZNegV = 126,
    kZNegI = 127,
    kZNegSolarV = 128,
    kZNegSolarI = 129,
    kXPosSun = 130,
    kXPosIr = 131,
    kXPosRad = 132,
    kYPosSun = 133,
    kYPosIr = 134,
    kXNegSun = 135,
    kXNegIr = 136,
    kYNegSun = 137,
    kYNegIr = 138,
    kZNegSun = 139,
    kZNegIr1 = 140,
    kZNegIr2 = 141,
    kZPosSun = 142,
    kCdhTime = 143,
    kUtilNtcV1 = 144,
    kUtilNtcV2 = 145,
    kUtilHeatV = 146,
    kSwFsAngularVelocity1 = 147,
    kSwFsAngularVelocity2 = 148,
    kSwFsAngularVelocity3 = 149,
    kSwFsAttitudeCov = 150,
    kSwFsAttitudeDistance = 151,
    kSwFsAttitudeQuaternion1 = 152,
    kSwFsAttitudeQuaternion2 = 153,
    kSwFsAttitudeQuaternion3 = 154,
    kSwFsAttitudeQuaternion4 = 155,
    kSwFsControl1 = 156,
    kSwFsControl2 = 157,
    kSwFsControl3 = 158,
    kSwFsNadir1 = 159,
    kSwFsNadir2 = 160,
    kSwFsNadir3 = 161,
    kSwFsHealthFlags = 162,
    kSwFsAttitudeFlags = 163,
    kSwFsFlags = 164,
    kSwFsLocation = 165,
    kSwFsIr = 166,
    kSwCdhBusFault = 167,
    kSwCdhHeartbeat = 168,
    kSwCdhLastReboot = 169,
    kSwCdhMemory = 170,
    kSwCdhMemoryAvailable = 171,
    kSwCdhRtcStatus = 172,
    kSwCdhMcu1 = 173,
    kSwCdhMcu2 = 174,
    kSwMcuReCount = 175,
    kConsoleMessage = 176,
    kSdCardDumpMessage = 177,
    // Add new measurables below this line only
    kEpsBmsChargingInfoReading1 = 178,
    kEpsBmsCurrentsReading1 = 179,
    kEpsBmsOperationValuesReading1 = 180,
    kEpsBmsSettingsReading1 = 181,
    kEpsBmsTemperatureReading1 = 182,
    kEpsBmsVoltagesReading1 = 183,
    kEpsBmsChargingInfoReading2 = 184,
    kEpsBmsCurrentsReading2 = 185,
    kEpsBmsOperationValuesReading2 = 186,
    kEpsBmsSettingsReading2 = 187,
    kEpsBmsTemperatureReading2 = 188,
    kEpsBmsVoltagesReading2 = 189,
    kTestCurrent = 190,
    kMeasurableIdEnd
};

#endif  // SRC_SENSORS_MEASURABLE_ID_H_
