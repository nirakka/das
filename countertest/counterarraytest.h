#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class counterarraytest : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (counterarraytest);
	CPPUNIT_TEST (test01);
	CPPUNIT_TEST (test02);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void test01 (void);
		void test02 (void);

	private:
	// add private values
};
