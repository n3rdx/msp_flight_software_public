/* AUTOGENERATED FILE. DO NOT EDIT. */

#ifndef TEST_RUNNERS_SENSOR_STATE_LOGIC_TESTS_H_
#define TEST_RUNNERS_SENSOR_STATE_LOGIC_TESTS_H_

#include "unity.h"
#include <src/config/unit_tests.h>
#include <src/sensors/test_sensors/test_i2c_sensor.h>
#include <src/system/sensor_state_machines/battery_charge_state_machine.h>
#include <src/system/sensor_state_machines/battery_temp_state_machine.h>
#include <src/system/sensor_state_machines/telecoms_temp_state_machine.h>
#include <src/system/state_definitions.h>
#include <src/system/state_manager.h>
#include <test_runners/sensor_state_logic_tests.h>
#include <string>
#include <src/util/memory_troubleshooter.h>
#include <external/etl/exception.h>

void TestBatteryChargeStateFlow(void);
void TestBatteryTempStateFlow(void);
void TestTelecomsTempStateFlow(void);

#endif  // TEST_RUNNERS_SENSOR_STATE_LOGIC_TESTS_H_
