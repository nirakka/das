#include <iostream>

#include "typedef.h"
#include "counter.h"
#include "counterarraytest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (counterarraytest);

/*
	Counter[]
*/

static CounterArray ca0(2);
static CounterArray cai1{Counter(10,  1),Counter(20, 3)};// 1, 0
static CounterArray cao1{Counter(10, 10),Counter(20, 2)};
static CounterArray cai2{Counter(10,  4),Counter(20, 1)};// 0, 1
static CounterArray cao2{Counter(10,  3),Counter(20,20)};

static CounterArray cai3{Counter(10,  1),Counter(20, 1)};// 1, 1
static CounterArray cao3{Counter(10, 10),Counter(20, 20)};
static CounterArray cai4{Counter(10,  4),Counter(20, 3)};// 0, 0
static CounterArray cao4{Counter(10,  3),Counter(20,2 )};

static CounterArray cai5{Counter(0,   1),Counter(20, 3)};// -1, 0
static CounterArray cao5{Counter(0,   0),Counter(20, 2)};
static CounterArray cai6{Counter(10,  4),Counter( 0, 3)};// 0, -1
static CounterArray cao6{Counter(10,  3),Counter( 0, 0)};

static CounterArray cai7{Counter(10,  1),Counter( 0, 3)};// 1, -1
static CounterArray cao7{Counter(10, 10),Counter( 0, 0)};
static CounterArray cai8{Counter(0,   4),Counter(20, 1)};//-1, 1 
static CounterArray cao8{Counter(0,   0),Counter(20,20)};

static CounterArray cai9{Counter(10,  4),Counter( 0, 3)};// 0, -1
static CounterArray cao9{Counter(10,  3),Counter( 0, 0)};
static CounterArray cai10{Counter(0,  4),Counter(10, 3)};// -1, 0 
static CounterArray cao10{Counter(0,  0),Counter(10, 2)};

static CounterArray inputs[]  = {ca0, cai1, cai2, cai3, cai4, cai5, cai6, cai7, cai8, cai9, cai10};
static CounterArray outputs[] = {ca0, cao1, cao2, cao3, cao4, cao5, cao6, cao7, cao8, cao9, cao10};

static int     results[] = {0, 1, 2, 3, 0, 0, 0, 1, 2, 0, 0};

void counterarraytest :: setUp (void)
{
	// set up test environment (initializing objects)
}

void counterarraytest :: tearDown (void) 
{
	// finally delete objects
}

void testsub(int n)
{
	CounterArray temp(inputs[n]);
	CounterArray r(outputs[n]);
	CPPUNIT_ASSERT_EQUAL ( results[n], countdownarray(temp));
	CPPUNIT_ASSERT(r == temp);

}
void counterarraytest :: test01 (void)
{
	testsub(1);
}

void counterarraytest :: test02 (void)
{
	testsub(2);
}


void counterarraytest :: test03 (void)
{
	testsub(3);
}

void counterarraytest :: test04 (void)
{
	testsub(4);
}

void counterarraytest :: test05 (void)
{
	testsub(5);
}

void counterarraytest :: test06 (void)
{
	testsub(6);
}


void counterarraytest :: test07 (void)
{
	testsub(7);
}

void counterarraytest :: test08 (void)
{
	testsub(8);
}

void counterarraytest :: test09 (void)
{
	testsub(9);
}

void counterarraytest :: test10 (void)
{
	testsub(10);
}
