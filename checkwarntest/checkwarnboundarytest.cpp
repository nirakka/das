#include <iostream>
#include <sstream>

#include "checkwarn.h"
#include "checkwarnboundarytest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (checkwarnboundarytest);

static Condition cond01 = Condition(X(1),3000,1); // >
static Condition cond02 = Condition(X(1),3000,2); // ==
static Condition cond03 = Condition(X(1),3000,3); // <

static Action act = Action(B(1),1);
static Warn inwarn001(&cond01,&act);
static Warn inwarn002(&cond02,&act);
static Warn inwarn003(&cond03,&act);

// 要素0は使用せず
static Warn*      inwarnTbl2[]  = { 0, &inwarn001, &inwarn002, &inwarn003 };
static uint8_t  a01[] = { 0, 0, 0, 0};
static int16_t a16_01[] = { 2999, 0, 0, 0 };
static int16_t a16_02[] = { 3000, 0, 0, 0 };
static int16_t a16_03[] = { 3001, 0, 0, 0 };

static RawValue invalue01(a01, a16_01);
static RawValue invalue02(a01, a16_02);
static RawValue invalue03(a01, a16_03);


static RawValue *values001[] = { 0, &invalue01, &invalue02, &invalue03 };
static int      results001[] = { 0,          0,          0,    errnoGT };

static RawValue *values002[] = { 0, &invalue01, &invalue02, &invalue03 };
static int      results002[] = { 0,          0,    errnoEQ,          0 };

static RawValue *values003[] = { 0, &invalue01, &invalue02, &invalue03 };
static int      results003[] = { 0,    errnoLT,          0,          0 };

// 2次允E�E表
static RawValue** invalueTbl2[] = { 0, values001,  values002,  values003  };
static int*	      resultsTbl2[] = { 0, results001, results002, results003 };

inline void testXY(int x,int y)
{
  CPPUNIT_ASSERT_EQUAL ( resultsTbl2[x][y], checkwarn(*inwarnTbl2[x], *invalueTbl2[x][y]));
}


void checkwarnboundarytest :: setUp (void)
{
	// set up test environment (initializing objects)
}

void checkwarnboundarytest :: tearDown (void) 
{
	// finally delete objects
}

void checkwarnboundarytest :: test11 (void) { testXY(1,1); }
void checkwarnboundarytest :: test12 (void) { testXY(1,2); }
void checkwarnboundarytest :: test13 (void) { testXY(1,3); }
void checkwarnboundarytest :: test21 (void) { testXY(2,1); }
void checkwarnboundarytest :: test22 (void) { testXY(2,2); }
void checkwarnboundarytest :: test23 (void) { testXY(2,3); }
void checkwarnboundarytest :: test31 (void) { testXY(3,1); }
void checkwarnboundarytest :: test32 (void) { testXY(3,2); }
void checkwarnboundarytest :: test33 (void) { testXY(3,3); }
