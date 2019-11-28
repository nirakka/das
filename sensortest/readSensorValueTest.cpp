#include <iostream>
#include <sstream>

#include "readSensorValue.h"
#include "readSensorValuetest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (readSensorValuetest);

void readSensorValuetest :: setUp (void)
{
	// set up test environment (initializing objects)
}

void readSensorValuetest :: tearDown (void) 
{
	// finally delete objects
}

static uint8_t uint8_inv = UINT8_MAX; 
static int16_t int16_inv = INT16_MAX;

static uint8_t settings[] = {0,
	0b00000000, 0b00000001, 0b00000010, 0b00000011
};

static Values in01_v1{ 1,  0,  0,  1};
static Values in16_v1{10, 20, 30, 40};

static Values *inputs01[] = { 0, 
	&in01_v1
};
static Values *inputs16[] = { 0, 
	&in16_v1
};

static Values out01_v0(uint8_inv);
static Values out16_v0(int16_inv);

static Values out16_v1{10, int16_inv, int16_inv , int16_inv};
static Values out16_v2{int16_inv, 20, int16_inv , int16_inv};
static Values out16_v3{10, 20, int16_inv , int16_inv};

static Values *outputs16[] = { 0, 
	&out16_v0,  &out16_v1, &out16_v2, &out16_v3
};

#if 0
bool cmp(int16_t out[], RawValue rv){
	bool f = true;
	for (int i=0;i<4;i++){
		int v=rv.getv16(i);
		if (out[i] != v)
			return false;
	}	
	return f;
}

void rvclear(RawValue& rv){
	for (int i=0;i<4;i++){
		rv.setv01(i, uint8_inv);
		rv.setv16(i, int16_inv);
	}
}
#endif

void readSensorValuetest :: test01 (void) {
	RawValue rv(int16_inv);	
	readSensorValue(settings[1], *inputs01[1], *inputs16[1], rv);
	CPPUNIT_ASSERT ( *outputs16[1] == rv.v16 );
}

void readSensorValuetest :: test02 (void) {
	RawValue rv(int16_inv);
	readSensorValue(settings[2], *inputs01[1], *inputs16[1], rv);
	CPPUNIT_ASSERT ( *outputs16[2] == rv.v16 );
}

void readSensorValuetest :: test03 (void) {
	RawValue rv(int16_inv);
	readSensorValue(settings[3], *inputs01[1], *inputs16[1], rv);
	CPPUNIT_ASSERT ( *outputs16[3] == rv.v16 );
}

void readSensorValuetest :: test04 (void) {
	RawValue rv(int16_inv);
	readSensorValue(settings[4], *inputs01[1], *inputs16[1], rv);
	CPPUNIT_ASSERT ( *outputs16[4] == rv.v16 );
}
