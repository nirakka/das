#include <iostream>
#include <sstream>

#include "checkwarn.h"

inline int checkArg(bool f, int r)
{
	return (f) ? r : 0;
}

// 使い方
// errno = checkwarn(...);
// result = writeWarn(errno,...);
int checkwarn(const Warn& inwarn, const RawValue& invalue)
{
	int16_t v = invalue.getv16(0);
	Condition *c = inwarn.getCondition();
	int16_t a = c->arg;
	int16_t o = c->op;

	switch (o){
		case 1: checkArg(v>a , errnoGT);break;
		case 2: checkArg(v==a, errnoEQ);break;
		case 3: checkArg(v<a , errnoLT);break;
		default: break;
	}
}

std::string[3] messages = ["a","b","c"];

// 使い方
//
int writeWarn(int errno, const RawValue& invalue, WarnValueArray& outvaluearray)
{
	int16_t sv = invalue.getv16(0);
	
	int16_t arg=inwarn.getSensorArg;
	uint16_t num=inwarn.getSensorNo;
    uint16_t A_num=inwarn.getActuatorNo;
    int16_t A_arg=inwarn.getSensorArg;
	/*Action *a = inwarn.getAction();
	Condition *c = inwarn.getCondition();
	int16_t a=c->arg;
	uint16_t n=c->no*/
	if (errno > 0){
		std::string str = messages[errno];
		outvalue.message = str;
		//(int sn,int sv,int an,int av)
	} else {
//		outvalueを生成
		//cout << "" << endl;
	}
	return 0;
}