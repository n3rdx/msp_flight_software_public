/* AUTOGENERATED FILE. DO NOT EDIT. */

#ifndef TEST_RUNNERS_INTEGRATION_I2C_TESTS_H_
#define TEST_RUNNERS_INTEGRATION_I2C_TESTS_H_

#include "unity.h"
#include <external/etl/array.h>
#include <src/board/board.h>
#include <src/config/unit_tests.h>
#include <src/i2c/i2c.h>
#include <src/i2c/multiplexers/i2c_multiplexer.h>
#include <test_runners/integration_i2c_tests.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/std.h>
#include <src/util/memory_troubleshooter.h>
#include <external/etl/exception.h>

void TestEnumerateAllI2cDevices(void);

#endif  // TEST_RUNNERS_INTEGRATION_I2C_TESTS_H_
