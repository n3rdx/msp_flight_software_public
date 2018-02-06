#include <src/telecomms/lithium_configuration.h>
#include <src/uart/uart.h>

LithiumConfiguration::LithiumConfiguration() : baud_rate(Uart::kBaud9600) {}

SerialisedMessage LithiumConfiguration::SerialiseTo(byte *serial_buffer) {
    // TODO(dingbenjamin): Implement
}

uint32_t LithiumConfiguration::GetBaud() const { return baud_rate; }

uint16_t LithiumConfiguration::GetSerialisedSize() const {
    // TODO(dingbenjamin): Implement
    return 1;
}
