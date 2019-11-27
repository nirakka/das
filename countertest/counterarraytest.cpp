#include <iostream>

#include "typedef.h"
#include "counter.h"
#include "counterarraytest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (counterarraytest);

/*
	Counter[]
*/

static CounterArray ca0(10);
static CounterArray cai1{Counter(10,  1),Counter(20, 3)};
static CounterArray cao1{Counter(10, 10),Counter(20, 2)};
static CounterArray cai2{Counter(10,  4),Counter(20, 1)};
static CounterArray cao2{Counter(10,  3),Counter(20,20)};

static CounterArray inputs[]  = {ca0, cai1, cai2};
static CounterArray outputs[] = {ca0, cao1, cao2};

static int     results[] = {0, 0, 0};

void counterarraytest :: setUp (void)
{
	// set up test environment (initializing objects)
}

void counterarraytest :: tearDown (void) 
{
	// finally delete objects
}
void counterarraytest :: test01 (void)
{
    cout << "cai1=" << cai1.str() << endl;

	CounterArray temp(inputs[1]);
	CounterArray r(outputs[1]);
	CPPUNIT_ASSERT_EQUAL ( results[1], countdownarray(temp));
	CPPUNIT_ASSERT(r == temp);
}

void counterarraytest :: test02 (void)
{
	CounterArray temp(inputs[2]);
	CounterArray r(outputs[2]);
	CPPUNIT_ASSERT_EQUAL ( results[2], countdownarray(temp));
	CPPUNIT_ASSERT(r == temp);
}
