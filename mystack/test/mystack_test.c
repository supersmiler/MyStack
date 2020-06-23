#include <string.h>
#include <stdio.h>

#include "mystack.h"
#include "unity.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
}

void tearDown(void)
{
	destroy_stack();
}

void test_mystack_pop_failure(void)
{
	int handle = mystack_create(sizeof(int));
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int result = 0;
	TEST_ASSERT_EQUAL(-1, mystack_pop(handle, &result));
	
	mystack_push(handle, &value3);
	mystack_push(handle, &value2);
	mystack_push(handle, &value1);
	
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value1, result);
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value2, result);
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value3, result);
	mystack_destroy(handle);
}

void test_mystack_create_and_delete(void)
{
	int handle1 = mystack_create(sizeof(int));
	int handle2 = mystack_create(sizeof(int));
	int handle3 = mystack_create(sizeof(int));
	TEST_ASSERT_EQUAL(1, handle1);
	TEST_ASSERT_EQUAL(2, handle2);
	TEST_ASSERT_EQUAL(3, handle3);
	mystack_destroy(handle2);
	int value1 = 1;
	TEST_ASSERT_EQUAL(-1, mystack_push(handle2, &value1));
	mystack_destroy(handle1);
	mystack_destroy(handle3);
}

void test_mystack_pop_succes(void)
{
	int handle = mystack_create(sizeof(int));
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	mystack_push(handle, &value3);
	mystack_push(handle, &value2);
	mystack_push(handle, &value1);
	int result = 0;
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value1, result);
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value2, result);
	TEST_ASSERT_EQUAL(0, mystack_pop(handle, &result));
	TEST_ASSERT_EQUAL(value3, result);
	mystack_destroy(handle);
}

void test_mystack_nofelem(void)
{
	int handle = mystack_create(sizeof(int));
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	mystack_push(handle, &value3);
	mystack_push(handle, &value2);
	mystack_push(handle, &value1);
	TEST_ASSERT_EQUAL(3, mystack_nofelem(handle));
	mystack_destroy(handle);
}

int main(int argc, char *argv[])
{
	UnityBegin();

	MY_RUN_TEST(test_mystack_pop_succes);
	MY_RUN_TEST(test_mystack_create_and_delete);
	MY_RUN_TEST(test_mystack_nofelem);
	MY_RUN_TEST(test_mystack_pop_failure);

	return UnityEnd();
}
