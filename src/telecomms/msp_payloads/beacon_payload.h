#ifndef SRC_TELECOMMS_MSP_PAYLOADS_MVP_BEACON_PAYLOAD_H_
#define SRC_TELECOMMS_MSP_PAYLOADS_MVP_BEACON_PAYLOAD_H_

#include <external/etl/array.h>
#include <src/messages/message.h>
#include <src/telecomms/msp_payloads/transmit_payload.h>
#include <src/util/data_types.h>

class BeaconPayload : public TransmitPayload {
   public:
    const static uint8_t kFsHealthFlagByteCount = 20;
    const static uint8_t kFsFsAttitudeFlagByteCount = 2;
    const static uint8_t kFsLocationFloatCount = 2;

    BeaconPayload();
    SerialisedMessage SerialiseTo(byte* serial_buffer) const;
    uint16_t GetSerialisedSize() const;
    uint8_t GetPayloadCode() const;

    // TODO(dingbenjamin): Change autogenned args to snake case
    BeaconPayload* SetCdhBusFault(uint16_t cdhBusFault);
    BeaconPayload* SetCdhHeartbeat(uint16_t cdhHeartbeat);
    BeaconPayload* SetCdhLastReboot(const RTime& cdhLastReboot);
    BeaconPayload* SetCdhMcuTemp1(byte cdhMcuTemp1);
    BeaconPayload* SetCdhMcuTemp2(byte cdhMcuTemp2);
    BeaconPayload* SetCdhMemory(uint16_t cdhMemory);
    BeaconPayload* SetCdhMemoryAvailable(uint16_t cdhMemoryAvailable);
    BeaconPayload* SetCdhRegCurrent1(byte cdhRegCurrent1);
    BeaconPayload* SetCdhRegCurrent2(byte cdhRegCurrent2);
    BeaconPayload* SetCdhRegCurrent3(byte cdhRegCurrent3);
    BeaconPayload* SetCdhRegTemp1(byte cdhRegTemp1);
    BeaconPayload* SetCdhRegTemp2(byte cdhRegTemp2);
    BeaconPayload* SetCdhRegTemp3(byte cdhRegTemp3);
    BeaconPayload* SetCdhRegVoltage1(byte cdhRegVoltage1);
    BeaconPayload* SetCdhRegVoltage2(byte cdhRegVoltage2);
    BeaconPayload* SetCdhRegVoltage3(byte cdhRegVoltage3);
    BeaconPayload* SetCdhRtcStatus(byte cdhRtcStatus);
    BeaconPayload* SetCdhTime(const RTime& cdhTime);
    BeaconPayload* SetCommsAntennaFlags(byte commsAntennaFlags);
    BeaconPayload* SetCommsBytesReceived(uint32_t commsBytesReceived);
    BeaconPayload* SetCommsBytesTransmitted(uint32_t commsBytesTransmitted);
    BeaconPayload* SetCommsCurrent1(byte commsCurrent1);
    BeaconPayload* SetCommsCurrent2(byte commsCurrent2);
    BeaconPayload* SetCommsCurrent3(byte commsCurrent3);
    BeaconPayload* SetCommsLithiumOpCount(uint16_t commsLithiumOpCount);
    BeaconPayload* SetCommsLithiumRssi(uint16_t commsLithiumRssi);
    BeaconPayload* SetCommsLithiumTemp(uint16_t commsLithiumTemp);
    BeaconPayload* SetCommsLithiumTime(byte commsLithiumTime);
    BeaconPayload* SetCommsTemp1(byte commsTemp1);
    BeaconPayload* SetCommsTemp2(byte commsTemp2);
    BeaconPayload* SetCommsVoltage1(byte commsVoltage1);
    BeaconPayload* SetCommsVoltage2(byte commsVoltage2);
    BeaconPayload* SetFsAngularVelocity1(float fsAngularVelocity1);
    BeaconPayload* SetFsAngularVelocity2(float fsAngularVelocity2);
    BeaconPayload* SetFsAngularVelocity3(float fsAngularVelocity3);
    BeaconPayload* SetFsAttitudeCov(uint8_t fsAttitudeCov);
    BeaconPayload* SetFsAttitudeDistance(uint8_t fsAttitudeDistance);
    BeaconPayload* SetFsAttitudeFlags(
        etl::array<byte, kFsFsAttitudeFlagByteCount> fsAttitudeFlags);
    BeaconPayload* SetFsAttitudeQuaternion1(float fsAttitudeQuaternion1);
    BeaconPayload* SetFsAttitudeQuaternion2(float fsAttitudeQuaternion2);
    BeaconPayload* SetFsAttitudeQuaternion3(float fsAttitudeQuaternion3);
    BeaconPayload* SetFsAttitudeQuaternion4(float fsAttitudeQuaternion4);
    BeaconPayload* SetFsControl1(uint8_t fsControl1);
    BeaconPayload* SetFsControl2(uint8_t fsControl2);
    BeaconPayload* SetFsControl3(uint8_t fsControl3);
    BeaconPayload* SetFsFlags(byte fsFlags);
    BeaconPayload* SetFsHealthFlags(
        etl::array<byte, kFsHealthFlagByteCount> fs_health_flags);
    BeaconPayload* SetFsNadir1(float fsNadir1);
    BeaconPayload* SetFsNadir2(float fsNadir2);
    BeaconPayload* SetFsNadir3(float fsNadir3);
    BeaconPayload* SetFsTorquerCurrent1(float fsTorquerCurrent1);
    BeaconPayload* SetFsTorquerCurrent2(float fsTorquerCurrent2);
    BeaconPayload* SetFsTorquerCurrent3(float fsTorquerCurrent3);
    BeaconPayload* SetFsTorquerTemp1(byte fsTorquerTemp1);
    BeaconPayload* SetFsTorquerTemp2(byte fsTorquerTemp2);
    BeaconPayload* SetFsTorquerTemp3(byte fsTorquerTemp3);
    BeaconPayload* SetMcuResetCount1(uint8_t mcuResetCount1);
    BeaconPayload* SetMcuResetCount2(uint8_t mcuResetCount2);
    BeaconPayload* SetPowerBatCurrent1(uint16_t powerBatCurrent1);
    BeaconPayload* SetPowerBatCurrent2(uint16_t powerBatCurrent2);
    BeaconPayload* SetPowerBatTemp1(uint16_t powerBatTemp1);
    BeaconPayload* SetPowerBatTemp2(uint16_t powerBatTemp2);
    BeaconPayload* SetPowerBatVoltage1(uint16_t powerBatVoltage1);
    BeaconPayload* SetPowerBatVoltage2(uint16_t powerBatVoltage2);
    BeaconPayload* SetPowerCdhCurrent(byte powerCdhCurrent);
    BeaconPayload* SetPowerCharge1(uint16_t powerCharge1);
    BeaconPayload* SetPowerCharge2(uint16_t powerCharge2);
    BeaconPayload* SetPowerChargerState1(uint16_t powerChargerState1);
    BeaconPayload* SetPowerChargerState2(uint16_t powerChargerState2);
    BeaconPayload* SetPowerCommsCurrent(byte powerCommsCurrent);
    BeaconPayload* SetPowerEpsTemp1(byte powerEpsTemp1);
    BeaconPayload* SetPowerEpsTemp2(byte powerEpsTemp2);
    BeaconPayload* SetPowerFsCurrent(byte powerFsCurrent);
    BeaconPayload* SetPowerInCurrent1(uint16_t powerInCurrent1);
    BeaconPayload* SetPowerInCurrent2(uint16_t powerInCurrent2);
    BeaconPayload* SetPowerInVoltage1(uint16_t powerInVoltage1);
    BeaconPayload* SetPowerInVoltage2(uint16_t powerInVoltage2);
    BeaconPayload* SetPowerPanelCurrent1(byte powerPanelCurrent1);
    BeaconPayload* SetPowerPanelCurrent2(byte powerPanelCurrent2);
    BeaconPayload* SetPowerPanelCurrent3(byte powerPanelCurrent3);
    BeaconPayload* SetPowerPanelCurrent4(byte powerPanelCurrent4);
    BeaconPayload* SetPowerPanelCurrent5(byte powerPanelCurrent5);
    BeaconPayload* SetPowerPanelCurrent6(byte powerPanelCurrent6);
    BeaconPayload* SetPowerPanelTemp1(byte powerPanelTemp1);
    BeaconPayload* SetPowerPanelTemp2(byte powerPanelTemp2);
    BeaconPayload* SetPowerSoc1(uint16_t powerSoc1);
    BeaconPayload* SetPowerSoc2(uint16_t powerSoc2);
    BeaconPayload* SetPowerSolarCurrent1(byte powerSolarCurrent1);
    BeaconPayload* SetPowerSolarCurrent2(byte powerSolarCurrent2);
    BeaconPayload* SetPowerSolarCurrent3(byte powerSolarCurrent3);
    BeaconPayload* SetPowerSolarCurrent4(byte powerSolarCurrent4);
    BeaconPayload* SetPowerSolarCurrent5(byte powerSolarCurrent5);
    BeaconPayload* SetPowerSolarCurrent6(byte powerSolarCurrent6);
    BeaconPayload* SetPowerSolarVoltage1(byte powerSolarVoltage1);
    BeaconPayload* SetPowerSolarVoltage2(byte powerSolarVoltage2);
    BeaconPayload* SetPowerSolarVoltage3(byte powerSolarVoltage3);
    BeaconPayload* SetPowerSolarVoltage4(byte powerSolarVoltage4);
    BeaconPayload* SetPowerSolarVoltage5(byte powerSolarVoltage5);
    BeaconPayload* SetPowerSolarVoltage6(byte powerSolarVoltage6);
    BeaconPayload* SetPowerSysCurrent1(byte powerSysCurrent1);
    BeaconPayload* SetPowerSysCurrent2(byte powerSysCurrent2);
    BeaconPayload* SetPowerSysVoltage1(uint16_t powerSysVoltage1);
    BeaconPayload* SetPowerSysVoltage2(uint16_t powerSysVoltage2);
    BeaconPayload* SetPowerSystem1(uint16_t powerSystem1);
    BeaconPayload* SetPowerSystem2(uint16_t powerSystem2);
    BeaconPayload* SetPowerUtilCurrent(byte powerUtilCurrent);
    BeaconPayload* SetFsLocation(
        etl::array<float, kFsLocationFloatCount> fsLocation);
    BeaconPayload* SetFsIr(uint8_t fsIr);

   private:
    const static uint8_t kOutreachMessageSize = 27;

    // TODO(dingbenjamin): Create custom data types for certain readings
    float fs_attitude_quaternion_1;
    float fs_attitude_quaternion_2;
    float fs_attitude_quaternion_3;
    float fs_attitude_quaternion_4;
    float fs_angular_velocity_1;
    float fs_angular_velocity_2;
    float fs_angular_velocity_3;
    uint8_t fs_attitude_cov;
    uint8_t fs_attitude_distance;
    byte fs_torquer_temp_1;
    byte fs_torquer_temp_2;
    byte fs_torquer_temp_3;
    byte fs_flags;
    etl::array<byte, kFsFsAttitudeFlagByteCount> fs_attitude_flags;
    etl::array<byte, kFsHealthFlagByteCount> fs_health_flags;
    etl::array<float, kFsLocationFloatCount> fs_location;
    float fs_nadir_1;
    float fs_nadir_2;
    float fs_nadir_3;
    uint8_t fs_ir;
    uint8_t fs_control_1;
    uint8_t fs_control_2;
    uint8_t fs_control_3;
    float fs_torquer_current_1;
    float fs_torquer_current_2;
    float fs_torquer_current_3;
    RTime cdh_time;
    uint8_t mcu_reset_count_1;
    uint8_t mcu_reset_count_2;
    uint16_t cdh_memory;
    uint16_t cdh_memory_available;
    byte cdh_mcu_temp_1;
    byte cdh_mcu_temp_2;
    byte cdh_reg_voltage_1;
    byte cdh_reg_current_1;
    byte cdh_reg_temp_1;
    byte cdh_reg_voltage_2;
    byte cdh_reg_current_2;
    byte cdh_reg_temp_2;
    byte cdh_reg_voltage_3;
    byte cdh_reg_current_3;
    byte cdh_reg_temp_3;
    uint16_t cdh_bus_fault;
    RTime cdh_last_reboot;
    byte cdh_rtc_status;
    uint16_t cdh_heartbeat;
    char* comms_outreach;  // 27 bytes
    byte comms_temp_1;
    byte comms_temp_2;
    byte comms_current_1;
    byte comms_current_2;
    byte comms_current_3;
    byte comms_voltage_1;
    byte comms_voltage_2;
    uint16_t comms_lithium_op_count;
    uint16_t comms_lithium_temp;
    byte comms_lithium_time;
    uint16_t comms_lithium_rssi;
    uint32_t comms_bytes_received;
    uint32_t comms_bytes_transmitted;
    byte comms_antenna_flags;
    byte power_solar_voltage_1;
    byte power_solar_voltage_2;
    byte power_solar_voltage_3;
    byte power_solar_voltage_4;
    byte power_solar_voltage_5;
    byte power_solar_voltage_6;
    byte power_solar_current_1;
    byte power_solar_current_2;
    byte power_solar_current_3;
    byte power_solar_current_4;
    byte power_solar_current_5;
    byte power_solar_current_6;
    byte power_panel_current_1;
    byte power_panel_current_2;
    byte power_panel_current_3;
    byte power_panel_current_4;
    byte power_panel_current_5;
    byte power_panel_current_6;
    uint16_t power_in_voltage_1;
    uint16_t power_in_voltage_2;
    uint16_t power_in_current_1;
    uint16_t power_in_current_2;
    uint16_t power_bat_voltage_1;
    uint16_t power_bat_voltage_2;
    uint16_t power_bat_current_1;
    uint16_t power_bat_current_2;
    uint16_t power_sys_voltage_1;
    uint16_t power_sys_voltage_2;
    byte power_sys_current_1;
    byte power_sys_current_2;
    byte power_comms_current;
    byte power_fs_current;
    byte power_cdh_current;
    byte power_util_current;
    uint16_t power_bat_temp_1;
    uint16_t power_bat_temp_2;
    byte power_panel_temp_1;
    byte power_panel_temp_2;
    byte power_eps_temp_1;
    byte power_eps_temp_2;
    uint16_t power_charger_state_1;
    uint16_t power_charger_state_2;
    uint16_t power_charge_1;
    uint16_t power_charge_2;
    uint16_t power_system_1;
    uint16_t power_system_2;
    uint16_t power_soc_1;
    uint16_t power_soc_2;
};

#endif  // SRC_TELECOMMS_MSP_PAYLOADS_MVP_BEACON_PAYLOAD_H_
