#include <external/etl/exception.h>
#include <src/board/board.h>
#include <src/config/satellite.h>
#include <src/messages/TemperatureReading.pb.h>
#include <src/messages/serialised_message.h>
#include <src/sensors/measurable_manager.h>
#include <src/telecomms/lithium.h>
#include <src/telecomms/lithium_commands/get_configuration_command.h>
#include <src/telecomms/lithium_commands/lithium_command.h>
#include <src/telecomms/lithium_commands/lithium_command_codes.h>
#include <src/telecomms/lithium_commands/no_op_command.h>
#include <src/telecomms/lithium_commands/reset_system_command.h>
#include <src/telecomms/lithium_commands/telemetry_query_command.h>
#include <src/telecomms/lithium_commands/transmit_command.h>
#include <src/telecomms/lithium_commands/write_flash_command.h>
#include <src/telecomms/lithium_configuration.h>
#include <src/telecomms/lithium_utils.h>
#include <src/util/data_types.h>
#include <src/util/task_utils.h>
#include <ti/drivers/GPIO.h>
#include <xdc/runtime/Log.h>

Lithium* Lithium::instance = NULL;
uint8_t Lithium::tx_count = 0;
uint8_t Lithium::rx_count = 0;
uint8_t Lithium::command_success_count = 0;

Lithium::Lithium()
    : uart(TELECOMS),
      lithium_transmit_enabled(!kLithiumTransmitOnlyWhenGroundCommanded),
      state(kLithiumTempNominal) {
    // Ensure Lithium is not in reset
    GPIO_write(nCOMMS_RST, 1);

    uart.SetBaudRate(Uart::kBaud9600)
        ->SetReadMode(UART_MODE_BLOCKING)
        ->SetWriteMode(UART_MODE_BLOCKING)
        ->SetWriteTimeout(TaskUtils::MilliToCycles(kUartWriteTimeoutMilli))
        ->SetReadTimeout(TaskUtils::MilliToCycles(kUartReadTimeoutMilli))
        ->Open();

    Mailbox_Params_init(&command_response_mailbox_params);
    command_response_mailbox_handle =
        Mailbox_create(kMaxReceivedLithiumResponseSize, 1,
                       &command_response_mailbox_params, NULL);
    if (command_response_mailbox_handle == NULL) {
        etl::exception e("Unable to create Lithium command response mailbox",
                         __FILE__, __LINE__);
        throw e;
    }

    Mailbox_Params_init(&header_mailbox_params);
    header_mailbox_handle =
        Mailbox_create(kLithiumHeaderSize, 1, &header_mailbox_params, NULL);
    if (header_mailbox_handle == NULL) {
        etl::exception e("Unable to create Lithium header mailbox", __FILE__,
                         __LINE__);
        throw e;
    }

    Mailbox_Params_init(&uplink_mailbox_params);
    uplink_mailbox_handle =
        Mailbox_create(kMaxReceivedUplinkSize, kMaxNumberOfPayloads,
                       &uplink_mailbox_params, NULL);
    if (uplink_mailbox_handle == NULL) {
        etl::exception e("Unable to create Lithium uplink mailbox", __FILE__,
                         __LINE__);
        throw e;
    }
}

bool Lithium::Transmit(TransmitPayload* transmit_payload) {
    UpdateState();
    if (!lithium_transmit_enabled) {
        Log_info0("Attempted to transmit, but transmit disabled");
        return false;
    }

    TransmitCommand transmit_command(transmit_payload);
    if (Lithium::GetInstance()->DoCommand(&transmit_command)) {
        tx_count = tx_count == 255 ? 0 : tx_count + 1;
        return true;
    }
    return false;
}

bool Lithium::DoCommand(LithiumCommand* command) const {
    uint16_t serialised_size = command->GetSerialisedSize();
    if (serialised_size >= kMaxOutgoingCommandSize) {
        return false;
    }
    byte command_buffer[kMaxOutgoingCommandSize];
    SerialisedMessage serial_command = command->SerialiseTo(command_buffer);

    if (!uart.PerformWriteTransaction(serial_command.GetBuffer(),
                                      serial_command.GetSize())) {
        return false;
    }

    byte ack_buffer[kLithiumHeaderSize] = {NULL};
    if (!Mailbox_pend(header_mailbox_handle, &ack_buffer,
                      TaskUtils::MilliToCycles(kWaitForAckMilli))) {
        // Timed out waiting for a response
        return false;
    }
    // TODO(dingbenjamin): Figure out why this is needed
    TaskUtils::SleepMilli(kInterCommandTimeMilli);

    if ((!LithiumUtils::IsValidHeader(ack_buffer)) ||
        (LithiumUtils::GetCommandCode(ack_buffer) !=
         command->GetCommandCode())) {
        return false;
    }

    if (command->GetReplyPayloadSize() == 0) {
        // No response payload is expected
        if (LithiumUtils::IsAck(ack_buffer)) {
            return true;
        } else if (LithiumUtils::IsNack(ack_buffer)) {
            // TODO(dingbenjamin): Received nack - back off and try again
            return false;
        } else {
            // TODO(dingbenjamin): Something unexpected happened, reset
            return false;
        }
    } else {
        // Expecting more than just an ack from the Lithium
        if (LithiumUtils::GetPayloadSize(ack_buffer) ==
            command->GetReplyPayloadSize()) {
            return Mailbox_pend(command_response_mailbox_handle,
                                command->GetReplyBuffer(),
                                kWaitForReplyPayloadMilli);
        } else {
            return false;
        }
    }
}

Lithium* Lithium::GetInstance() {
    if (instance == NULL) {
        instance = new Lithium();
    }
    return instance;
}

uint8_t Lithium::GetTxCounter() { return Lithium::tx_count; }

uint8_t Lithium::GetRxCounter() { return Lithium::rx_count; }

uint8_t Lithium::GetCommandSuccessCounter() {
    return Lithium::command_success_count;
}

LithiumTelemetry Lithium::ReadLithiumTelemetry() const {
    LithiumTelemetry invalid_telemetry = {0, 0, {0, 0, 0}, 0, 0, 0};
    TelemetryQueryCommand query;

    if (!DoCommand(&query)) return invalid_telemetry;

    // Sometimes the Lithium returns a telemetry packet filled with
    // zeroes, if this is the case we should query again
    if (!TelemetryQueryCommand::CheckValidTelemetry(
            query.GetParsedResponse())) {
        // Try again if we get an invalid telemetry
        if (!DoCommand(&query)) return invalid_telemetry;
        if (!TelemetryQueryCommand::CheckValidTelemetry(
                query.GetParsedResponse()))
            return invalid_telemetry;
    }
    // We have received a valid telemetry
    return query.GetParsedResponse();
}

LithiumConfiguration Lithium::ReadLithiumConfiguration() const {
    LithiumConfiguration invalid_configuration = {
        0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0},
        0, 0, 0, 0};
    GetConfigurationCommand config_command;

    if (!DoCommand(&config_command)) return invalid_configuration;

    return config_command.GetParsedResponse();
}

void Lithium::UnlockState(LithiumShutoffCondition condition) {
    state = state & ~static_cast<uint8_t>(condition);

    if (state == kLithiumOnCondition) {
        lithium_transmit_enabled = true;
    }
}
void Lithium::LockState(LithiumShutoffCondition condition) {
    state = state | static_cast<uint8_t>(condition);

    if (state != kLithiumOnCondition) {
        lithium_transmit_enabled = false;
    }
}

bool Lithium::IsStateLocked(LithiumShutoffCondition condition) {
    return (state & static_cast<uint8_t>(condition)) != kLithiumOnCondition;
}

void Lithium::ForceUnlock(){
    state = kLithiumOnCondition;
}


void Lithium::UpdateState() {
    // TODO(dingbenjamin): Use the Lithium internal temperature sensor
    float telecomms_1_temp =
        MeasurableManager::GetInstance()
            ->ReadNanopbMeasurable<TemperatureReading>(kComT1, 10000)
            .temp;
    float telecomms_2_temp =
        MeasurableManager::GetInstance()
            ->ReadNanopbMeasurable<TemperatureReading>(kComT2, 10000)
            .temp;
    void UpdateState();

    // Disregard invalid sensor readings
    if (telecomms_1_temp == kInvalidDouble)
        telecomms_1_temp = kLithiumTempOperationalNominal;
    if (telecomms_2_temp == kInvalidDouble)
        telecomms_2_temp = kLithiumTempOperationalNominal;

    switch (state) {
        case kLithiumTempCriticalLow:
            if ((telecomms_1_temp > kLithiumTempOperationalMin) &&
                (telecomms_2_temp > kLithiumTempOperationalMin)) {
                Log_info0(
                    "Telecomms temperature nominal: turning on "
                    "Lithium");
                Lithium::GetInstance()->UnlockState(
                    Lithium::kCriticalTempCondition);
            }
            break;
        case kLithiumTempNominal:
            if ((telecomms_1_temp > kLithiumTempOperationalMax + kHysteresis) ||
                (telecomms_2_temp > kLithiumTempOperationalMax + kHysteresis)) {
                Log_info0(
                    "Telecomms temperature critical high: Shutting off "
                    "Lithium");
                Lithium::GetInstance()->LockState(
                    Lithium::kCriticalTempCondition);

            } else if ((telecomms_1_temp <
                        kLithiumTempOperationalMin - kHysteresis) ||
                       (telecomms_1_temp <
                        kLithiumTempOperationalMin - kHysteresis)) {
                Log_info0(
                    "Telecomms temperature critical low: Shutting off "
                    "Lithium");
                Lithium::GetInstance()->LockState(
                    Lithium::kCriticalTempCondition);
            }
            break;
        case kLithiumTempCriticalHigh:
            if ((telecomms_1_temp < kLithiumTempOperationalMax) &&
                (telecomms_2_temp < kLithiumTempOperationalMax)) {
                Log_info0(
                    "Telecomms temperature nominal: turning on "
                    "Lithium");
                Lithium::GetInstance()->UnlockState(
                    Lithium::kCriticalTempCondition);
            }
            break;
    }
}

Uart* Lithium::GetUart() { return &uart; }

Mailbox_Handle Lithium::GetUplinkMailbox() const {
    return uplink_mailbox_handle;
}

Mailbox_Handle Lithium::GetHeaderMailbox() const {
    return header_mailbox_handle;
}

Mailbox_Handle Lithium::GetCommandResponseMailbox() const {
    return command_response_mailbox_handle;
}

void Lithium::SetTransmitEnabled(bool lithium_enabled) {
    lithium_transmit_enabled = lithium_enabled;
}

bool Lithium::IsTransmitEnabled() { return lithium_transmit_enabled; }
