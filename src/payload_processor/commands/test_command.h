#ifndef SRC_PAYLOAD_PROCESSOR_COMMANDS_TEST_COMMAND_H_
#define SRC_PAYLOAD_PROCESSOR_COMMANDS_TEST_COMMAND_H_

#include <src/payload_processor/commands/command.h>
#include <external/etl/array.h>

class TestCommand : public Command {
public:
    TestCommand(byte* payload, uint8_t command_argument_start_index);
    bool ExecuteCommand();
    static const byte kTestValue1 = 0xFF;
    static const byte kTestValue2 = 0xA5;

private:
    static const uint8_t kEchoCommandArgumentLength = 2;
    etl::array<byte, kEchoCommandArgumentLength> command_arguments;
};

#endif  //  SRC_PAYLOAD_PROCESSOR_COMMANDS_TEST_COMMAND_H_