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
#include "matrix_tests.h"

/*=======External Functions This Runner Calls=====*/
extern void SetUp(void);
extern void TearDown(void);
extern void TestGetNRows();
extern void TestGetNColumns();
extern void TestIsSquare();
extern void TestGet();
extern void TestSet();
extern void TestDoubleIsEqual();
extern void TestIsEqual();
extern void TestSameSize();
extern void TestSameNRows();
extern void TestSameNColumns();
extern void TestTranspose();
extern void TestAdd();
extern void TestSubtract();
extern void TestMultiply();
extern void TestMultiplyScalar();
extern void TestFill();
extern void TestIdentity();
extern void TestConcatenateHorizontally();
extern void TestConcatenateVertically();
extern void TestAddRows();
extern void TestMultiplyRow();
extern void TestSwitchRows();
extern void TestRowReduce();


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
void resetTest_matrix_tests_runner(void);
void resetTest_matrix_tests_runner(void)
{
  TearDown();
  SetUp();
}


/*=======MAIN=====*/
 int matrix_tests_runner(void);
int matrix_tests_runner(void)
{
  suite_setup();
  UnityBegin("src/util/tests/matrix_tests.cpp");
  RUN_TEST(TestGetNRows, 6);
  RUN_TEST(TestGetNColumns, 13);
  RUN_TEST(TestIsSquare, 20);
  RUN_TEST(TestGet, 30);
  RUN_TEST(TestSet, 41);
  RUN_TEST(TestDoubleIsEqual, 58);
  RUN_TEST(TestIsEqual, 67);
  RUN_TEST(TestSameSize, 79);
  RUN_TEST(TestSameNRows, 91);
  RUN_TEST(TestSameNColumns, 103);
  RUN_TEST(TestTranspose, 115);
  RUN_TEST(TestAdd, 126);
  RUN_TEST(TestSubtract, 141);
  RUN_TEST(TestMultiply, 156);
  RUN_TEST(TestMultiplyScalar, 172);
  RUN_TEST(TestFill, 185);
  RUN_TEST(TestIdentity, 196);
  RUN_TEST(TestConcatenateHorizontally, 207);
  RUN_TEST(TestConcatenateVertically, 222);
  RUN_TEST(TestAddRows, 237);
  RUN_TEST(TestMultiplyRow, 250);
  RUN_TEST(TestSwitchRows, 262);
  RUN_TEST(TestRowReduce, 273);

  return suite_teardown(UnityEnd());
}