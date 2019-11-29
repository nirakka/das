#include <iostream>

#include "typedef.h"
#include "counter.h"
#include "countertest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (countertest);

void countertest :: setUp (void)
{
	// set up test environment (initializing objects)
}

void countertest :: tearDown (void) 
{
	// finally delete objects
}

static Counter inputs[]  = { Counter(0,0), Counter(10, 1), Counter(10, 2),Counter(10,3), Counter(0,3), Counter(10, 0), Counter(10, 100)};
static Counter outputs[] = { Counter(0,0), Counter(10,10), Counter(10, 1),Counter(10,2), Counter(0,0), Counter(10, 10),Counter(10, 10)};
static int     results[] = {            0,              1,              0,            0,          -1 ,              0,              0};

void countertest :: test01 (void)
{
	Counter tmp(inputs[1]);
	CPPUNIT_ASSERT_EQUAL ( results[1], countdown(tmp));
	CPPUNIT_ASSERT (outputs[1] == tmp);
}

void countertest :: test02 (void)
{
	Counter tmp(inputs[2]);
	CPPUNIT_ASSERT_EQUAL ( results[2], countdown(tmp));
	CPPUNIT_ASSERT (outputs[2] == tmp);
}

void countertest :: test03 (void)
{
	Counter tmp(inputs[3]);
	CPPUNIT_ASSERT_EQUAL ( results[3], countdown(tmp));
	CPPUNIT_ASSERT (outputs[3] == tmp);
}

void countertest :: test04 (void)
{
	Counter tmp(inputs[4]);
	CPPUNIT_ASSERT_EQUAL ( results[4], countdown(tmp));
	CPPUNIT_ASSERT (outputs[4] == tmp);
}

void countertest :: test05 (void)
{
	Counter tmp(inputs[5]);
	CPPUNIT_ASSERT_EQUAL ( results[5], countdown(tmp));
	CPPUNIT_ASSERT (outputs[5] == tmp);
}

void countertest :: test06 (void)
{
	Counter tmp(inputs[6]);
	CPPUNIT_ASSERT_EQUAL ( results[6], countdown(tmp));
	CPPUNIT_ASSERT (outputs[6] == tmp);
}
