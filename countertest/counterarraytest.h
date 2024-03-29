#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class counterarraytest : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (counterarraytest);
	CPPUNIT_TEST (test01);
	CPPUNIT_TEST (test02);
	CPPUNIT_TEST (test03);
	CPPUNIT_TEST (test04);
	CPPUNIT_TEST (test05);
	CPPUNIT_TEST (test06);
	CPPUNIT_TEST (test07);
	CPPUNIT_TEST (test08);
	CPPUNIT_TEST (test09);
	CPPUNIT_TEST (test10);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void test01 (void);
		void test02 (void);
		void test03 (void);
		void test04 (void);
		void test05 (void);
		void test06 (void);
		void test07 (void);
		void test08 (void);
		void test09 (void);
		void test10 (void);
	private:
	// add private values
};
