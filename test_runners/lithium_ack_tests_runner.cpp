/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      SetUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    TearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#ifdef __WIN32__
#define UNITY_INCLUDE_SETUP_STUBS
#endif
#include "unity.h"
#ifndef UNITY_EXCLUDE_SETJMP_H
#include <setjmp.h>
#endif
#include <stdio.h>
#include "lithium_ack_tests.h"

/*=======External Functions This Runner Calls=====*/
extern void SetUp(void);
extern void TearDown(void);
extern void TestNoOpAck();
extern void TestGetConfigAck();
extern void TestResetSystemAck();
extern void TestTransmitAck();
extern void TestFailNoOpAck();
extern void TestFailGetConfigAckParse();


/*=======Suite Setup=====*/
static void suite_setup(void)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest_lithium_ack_tests_runner(void);
void resetTest_lithium_ack_tests_runner(void)
{
  TearDown();
  SetUp();
}


/*=======MAIN=====*/
 int lithium_ack_tests_runner(void);
int lithium_ack_tests_runner(void)
{
  suite_setup();
  UnityBegin("src/telecomms/tests/lithium_ack_tests.cpp");
  RUN_TEST(TestNoOpAck, 7);
  RUN_TEST(TestGetConfigAck, 12);
  RUN_TEST(TestResetSystemAck, 25);
  RUN_TEST(TestTransmitAck, 30);
  RUN_TEST(TestFailNoOpAck, 35);
  RUN_TEST(TestFailGetConfigAckParse, 50);

  return suite_teardown(UnityEnd());
}
