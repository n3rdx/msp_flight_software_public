#ifndef SRC_SENSORS_MEASURABLE_ID_H_
#define SRC_SENSORS_MEASURABLE_ID_H_

enum MeasurableId {
    // Telecomms
    kCommsRegulator1InputVoltage,
    kCommsRegulator1OutputVoltage,
    kCommsRegulator2InputVoltage,
    kCommsRegulator2OutputVoltage,
    kCommsRegulator1InputCurrent,
    kCommsRegulator1OutputCurrent,
    kCommsRegulator2InputCurrent,
    kCommsRegulator2OutputCurrent,
    kCommsTemp1,
    kCommsTemp2,
    // EPS
    kPowerBoostInCurrent1,
    kPowerLoadCurrent1,
    kPowerLoadCurrent2,
    kPowerBoostInCurrent2,
    kPowerTemp1,
    kPowerTemp2,
    kPowerBmsDieTemp1,
    kPowerBmsDieTemp2,
    kPowerBmsBatteryTemp1,
    kPowerBmsBatteryTemp2,
    kEpsBatVoltage1,
    kEpsBoostOutVoltage1,
    kEpsBoostInCurrent1,
    kEpsLoadCurrent1,
    kEpsBatVoltage2,
    kEpsBoostOutVoltage2,
    kEpsLoadCurrent2,
    kEpsBoostInCurrent2,
    kEps5VRail1,
    kEps5VRail2,
    // Flight Systems
    kFsTorquerCurrentX,
    kFsTorquerCurrentTotal,
    kFsTorquerCurrentY,
    kFsTorquerCurrentZ,
    kFsMagTorqAX,
    kFsMagTorqBX,
    kFsMagTorqAY,
    kFsMagTorqBY,
    kFsMagTorqAZ,
    kFsMagTorqBZ,
    kFsTempHbX,
    kFsTempHbY,
    kFsTempHbZ,
    kFsImuGyro1,
    kFsImuAccelerometer1,
    kFsImuTemperature1,
    kFsImuMagnetometer1,
    kFsImuGyro2,
    kFsImuAccelerometer2,
    kFsImuTemperature2,
    kFsImuMagnetometer2,
    kUtilAdc2,
    kUtilTemp1,
    kCdhSysTemp,
    kCdhRtc,
    // Panels
    kPowerPanel1Temp1,
    kPowerPanel1Temp2,
    kPowerPanel2Temp1,
    kPowerPanel2Temp2,
    kPowerPanel3Temp1,
    kPowerPanel3Temp2,
    kPowerPanel4Temp1,
    kPowerPanel4Temp2,
    kPowerPanel5Temp1,
    kPowerPanel5Temp2,
    kPowerPanel6Temp1,
    kPowerPanelVoltage1,
    kPowerPanelCurrent1,
    kPowerSolarVoltage1,
    kPowerSolarCurrent1,
    kPowerPanelVoltage2,
    kPowerPanelCurrent2,
    kPowerSolarVoltage2,
    kPowerSolarCurrent2,
    kPowerPanelVoltage3,
    kPowerPanelCurrent3,
    kPowerSolarVoltage3,
    kPowerSolarCurrent3,
    kPowerPanelVoltage4,
    kPowerPanelCurrent4,
    kPowerSolarVoltage4,
    kPowerSolarCurrent4,
    kPowerPanelVoltage5,
    kPowerPanelCurrent5,
    kPowerSolarVoltage5,
    kPowerSolarCurrent5,
    kPowerTopPanelVoltage,
    kPowerTopPanelCurrent,
    kPowerTopSolarVoltage,
    kPowerTopSolarCurrent,
    kMeasurableIdEnd
};

#endif  // SRC_SENSORS_MEASURABLE_ID_H_
