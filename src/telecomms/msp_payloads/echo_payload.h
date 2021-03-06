#ifndef SRC_TELECOMMS_MSP_PAYLOADS_ECHO_PAYLOAD_H_
#define SRC_TELECOMMS_MSP_PAYLOADS_ECHO_PAYLOAD_H_

#include <external/etl/array.h>
#include <src/messages/message.h>
#include <src/payload_processor/payload_processor.h>
#include <src/telecomms/msp_payloads/transmit_payload.h>
#include <src/util/data_types.h>

class EchoPayload : public TransmitPayload {
   public:
    static constexpr uint8_t kEchoMessageLength =
        PayloadProcessor::kUplinkArgumentsMaxLength;
    explicit EchoPayload(const char* echo_message_in);
    explicit EchoPayload(byte* echo_message_in);
    SerialisedMessage SerialiseTo(byte* serial_buffer) const;
    uint16_t GetSerialisedSize() const;
    uint8_t GetPayloadCode() const;

   private:
    /* Add one byte to length to allow for a null character at end of buffer.
     * This allows for printing as a C string.*/
    static constexpr uint8_t kEchoMessageBufferLength = kEchoMessageLength + 1;
    etl::array<byte, kEchoMessageBufferLength> echo_message;
};

#endif /* SRC_TELECOMMS_MSP_PAYLOADS_ECHO_PAYLOAD_H_ */
