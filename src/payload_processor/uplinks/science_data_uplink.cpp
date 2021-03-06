#include <external/nanopb/pb_decode.h>
#include <src/database/circular_buffer_nanopb.h>
#include <src/messages/AccelerometerReading.pb.h>
#include <src/messages/AntennaBurnerInfoReading.pb.h>
#include <src/messages/BmsChargingInfoReading.pb.h>
#include <src/messages/BmsCurrentsReading.pb.h>
#include <src/messages/BmsOperationValuesReading.pb.h>
#include <src/messages/BmsSettingsReading.pb.h>
#include <src/messages/BmsTemperatureReading.pb.h>
#include <src/messages/BmsVoltagesReading.pb.h>
#include <src/messages/CurrentReading.pb.h>
#include <src/messages/GyroscopeReading.pb.h>
#include <src/messages/LithiumTelemetryReading.pb.h>
#include <src/messages/MagnetometerReading.pb.h>
#include <src/messages/ResetInfoContainerReading.pb.h>
#include <src/messages/TemperatureReading.pb.h>
#include <src/messages/TorqueOutputReading.pb.h>
#include <src/messages/VoltageReading.pb.h>
#include <src/payload_processor/uplinks/science_data_uplink.h>
#include <src/sensors/measurable_id.h>
#include <xdc/runtime/Log.h>

ScienceDataUplink::ScienceDataUplink(byte* payload)
    : Uplink(kScienceUplinkArgumentLength),
      requested_id(payload[kMeasurableIdIndex] | payload[kMeasurableIdIndex + 1]
                                                     << 8),
      requested_time(NanopbDecode(Time)(payload + kRequestedTimeIndex)) {}

bool ScienceDataUplink::ExecuteUplink() {
    if (requested_id >= kMeasurableIdEnd) {
        Log_error1("Invalid measurable ID %d requested by Science Data Uplink",
                   requested_id);
        return false;
    }
    // TODO(dingbenjamin): Check if the id has a corresponding measurable that
    // is not null in the manager

    // Try all the different NanopbMessageTypes and use the one that works
    if (RetrieveAndSendDataMacro(VoltageReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(TemperatureReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(CurrentReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(AccelerometerReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(GyroscopeReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(MagnetometerReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(TorqueOutputReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(BmsChargingInfoReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(BmsCurrentsReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(BmsOperationValuesReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(BmsSettingsReading)(requested_id)) return true;
    if (RetrieveAndSendDataMacro(BmsTemperatureReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(ResetInfoContainerReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(LithiumTelemetryReading)(requested_id))
        return true;
    if (RetrieveAndSendDataMacro(AntennaBurnerInfoReading)(requested_id))
        return true;

    return true;

    Log_error1(
        "Could not find the correct nanopb message type/retrieve the nanopb "
        "for message %d",
        requested_id);
    return false;
}
