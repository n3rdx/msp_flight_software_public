/* AUTOGENERATED FILE. DO NOT EDIT. */

#ifndef TEST_RUNNERS_MESSAGE_TESTS_H_
#define TEST_RUNNERS_MESSAGE_TESTS_H_

#include "unity.h"
#include <src/messages/serialised_message_builder.h>
#include <src/messages/temperature_message.h>
#include <src/messages/test_container_message.h>
#include <src/messages/test_message.h>
#include <src/util/data_types.h>
#include <src/util/message_codes.h>
#include <test_runners/message_tests.h>

void TestTestMessageSerialise(void);
void TestTempMessageSerialise(void);
void TestContainerMessageSerialise(void);
void TestSerialisedMessageBuilder(void);
void TestRebuildableMessageFieldIterator(void);

#endif  // TEST_RUNNERS_MESSAGE_TESTS_H_
