/* AUTOGENERATED FILE. DO NOT EDIT. */

#ifndef TEST_RUNNERS_SYSTEM_STATE_LOGIC_TESTS_H_
#define TEST_RUNNERS_SYSTEM_STATE_LOGIC_TESTS_H_

#include "unity.h"
#include <src/config/unit_tests.h>
#include <src/system/state_definitions.h>
#include <src/system/state_machine.h>
#include <src/system/state_manager.h>
#include <src/system/system_state_machines/adcs_state_machine.h>
#include <src/system/system_state_machines/power_state_machine.h>
#include <src/system/system_state_machines/telecoms_state_machine.h>
#include <src/util/memory_troubleshooter.h>

void TestPowerStateLogic(void);
void TestTelecomsStateLogic(void);
void TestAdcsStateLogic(void);

#endif  // TEST_RUNNERS_SYSTEM_STATE_LOGIC_TESTS_H_
