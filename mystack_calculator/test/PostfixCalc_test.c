#include <string.h>
#include <stdio.h>

#include "PostfixCalc.h"
#include "unity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

PostfixCalc* calc = NULL;

void setUp(void)
{
    calc = InitializePostfixCalc();
}

void tearDown(void)
{
    DestroyPostfixCalc(&calc);
}

void Calculate_illegal_argument_test(void)
{
    double testData = 0;
    TEST_ASSERT_EQUAL(-1, Calculate(NULL, NULL, 0, NULL));
    TEST_ASSERT_EQUAL(-1, Calculate(calc, NULL, 0, NULL));
    TEST_ASSERT_EQUAL(-1, Calculate(calc, "23+", 4, NULL));
}

void Calculate_calculations_test(void)
{
    double testData = 0;
    TEST_ASSERT_EQUAL(0, Calculate(calc, "23+", 4, &testData));
    TEST_ASSERT_EQUAL(5, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "23*", 4, &testData));
    TEST_ASSERT_EQUAL(6, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "23-", 4, &testData));
    TEST_ASSERT_EQUAL(-1, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "42/", 4, &testData));
    TEST_ASSERT_EQUAL(2, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "123*+", 6, &testData));
    TEST_ASSERT_EQUAL(7, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "569v-+", 7, &testData));
    TEST_ASSERT_EQUAL(8, testData);
    TEST_ASSERT_EQUAL(0, Calculate(calc, "53*4++", 7, &testData));
    TEST_ASSERT_EQUAL(19, testData);
}

void Clear_illegal_input_test(void)
{
    TEST_ASSERT_EQUAL(-1, Clear(NULL));
}

void Clear_clear_calculator_test(void)
{
    double testData = 0;
    TEST_ASSERT_EQUAL(0, Calculate(calc, "23+", 4, &testData));
    TEST_ASSERT_EQUAL(5, testData);
    TEST_ASSERT_EQUAL(0, GetAnswer(calc, &testData));
    TEST_ASSERT_EQUAL(5, testData);

    TEST_ASSERT_EQUAL(0, Clear(calc));
    TEST_ASSERT_EQUAL(0, GetAnswer(calc, &testData));
    TEST_ASSERT_EQUAL(0, testData);
}

void GetAnswer_illegal_argument_test(void)
{
    TEST_ASSERT_EQUAL(-1, GetAnswer(NULL, NULL));
    TEST_ASSERT_EQUAL(-1, GetAnswer(calc, NULL));
}

void GetAnswer_get_correct_answer_test(void)
{
    double testData = 0;
    double answer = 0;
    TEST_ASSERT_EQUAL(0, Calculate(calc, "53*4++", 7, &testData));
    TEST_ASSERT_EQUAL(19, testData);

    TEST_ASSERT_EQUAL(0, GetAnswer(calc, &answer));
    TEST_ASSERT_EQUAL(19, answer);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(Calculate_illegal_argument_test);
    MY_RUN_TEST(Calculate_calculations_test);

    MY_RUN_TEST(Clear_illegal_input_test);
    MY_RUN_TEST(Clear_clear_calculator_test);

    MY_RUN_TEST(GetAnswer_illegal_argument_test);
    MY_RUN_TEST(GetAnswer_get_correct_answer_test);

    return UnityEnd();
}
