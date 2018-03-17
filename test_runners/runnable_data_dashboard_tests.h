/* AUTOGENERATED FILE. DO NOT EDIT. */

#ifndef TEST_RUNNERS_RUNNABLE_DATA_DASHBOARD_TESTS_H_
#define TEST_RUNNERS_RUNNABLE_DATA_DASHBOARD_TESTS_H_

#include "unity.h"
#include <external/nanopb/pb_decode.h>
#include <external/nanopb/pb_encode.h>
#include <src/data_dashboard/runnable_data_dashboard.h>
#include <src/debug_interface/debug_stream.h>
#include <src/messages/SensorReading.pb.h>
#include <src/util/data_types.h>
#include <src/util/message_codes.h>
#include <test_runners/runnable_data_dashboard_tests.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <src/config/unit_tests.h>

void TestTransmitMessage(void);

#endif  // TEST_RUNNERS_RUNNABLE_DATA_DASHBOARD_TESTS_H_
