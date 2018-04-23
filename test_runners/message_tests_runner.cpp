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
#include "message_tests.h"

/*=======External Functions This Runner Calls=====*/
extern void SetUp(void);
extern void TearDown(void);
extern void TestTestMessageSerialise(void);
extern void TestTempMessageSerialise(void);
extern void TestContainerMessageSerialise(void);
extern void TestSerialisedMessageBuilder(void);
extern void TestPadWithZero(void);
extern void TestSerialiseEtlArray();
extern void TestSerialiseArray();
extern void TestRebuildableMessageFieldIterator(void);


/*=======Suite Setup=====*/
static MemoryTroubleshooter *suite_setup(void)
{
  MemoryTroubleshooter *mem_test = new MemoryTroubleshooter();
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
  return mem_test;
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures, MemoryTroubleshooter *mem_test)
{
    if(mem_test->MemoryLeakTest()){
        UNITY_PRINT_EOL();
        UnityPrint(memoryLeakMessage);
        UNITY_PRINT_EOL();
    }
    mem_test->~MemoryTroubleshooter();
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest_message_tests_runner(void);
void resetTest_message_tests_runner(void)
{
  TearDown();
  SetUp();
}


/*=======MAIN=====*/
 int message_tests_runner(void);
int message_tests_runner(void)
{
  MemoryTroubleshooter *mem_test = suite_setup();
  try {
  UnityBegin("src/messages/tests/message_tests.cpp");
    RUN_TEST(TestTestMessageSerialise, 13);
    RUN_TEST(TestTempMessageSerialise, 27);
    RUN_TEST(TestContainerMessageSerialise, 46);
    RUN_TEST(TestSerialisedMessageBuilder, 67);
    RUN_TEST(TestPadWithZero, 92);
    RUN_TEST(TestSerialiseEtlArray, 116);
    RUN_TEST(TestSerialiseArray, 129);
    RUN_TEST(TestRebuildableMessageFieldIterator, 142);
  } catch (etl::exception e) {
    TEST_FAIL_MESSAGE("Uncaught exception in test");
  }

  return suite_teardown(UnityEnd(), mem_test);
}
