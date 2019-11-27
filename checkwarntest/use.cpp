#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <typedef.h>

std::string fmt32(uint_t v)
{
	std::stringsteam ss;
	ss << std::hex << std::setw(8) << std::setfill('0') << v;
	return ss.str();
}

std::string fmt16(uint16_t v)
{
	std::stringstream ss;
	ss << std::hex << std::setw(4) << std::setfill('0') << v;
	return ss.str();
}

static SensorValueArray sva(10);
static CounterArray ca(8);

void useSensorValue(void)
{
	SensorValue sv;
	sv.setv16(0, 0x1000);
	sva[0] = sv;
	
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(sva[0].getv16(0) << std::endl;
}

void useCounter(void)
{
	Counter c0(10,3);
	ca[0] = c0;
	
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(ca[0].preset ) << " ";
	std::cout << fmt16(ca[0].current) << std::endl;
}

static Collection col(X(1),10);
static Condition cond(X(1), 3000, 1);
static Action act(B(1), 1);
static Warn wa(&cond, &act);

static CounterArray cla(10);

static RawValueArray rva(10);
static WarnValueArray wva(10);

void useCollection(void)
{
	cla[0] = col;
	
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(cla[0].sensor) << " ";
	std::cout << fmt16(cla[0]duration) << " ";
	std::cout << cla[0].str() << std::endl;
}

void useCondition(void)
{
	std::cout << std::string(__FUNCTION___) << ":";
	std::cout << fmt16(cond.no) << " ";
	std::cout << fmt16(cond.arg) << " ";
	std::cout << cond.str() << std::endl;
}

void useAction(void)
{
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(act.no) << " ";
	std::cout << fmt16(act.arg) << " # ";
	std::cout << act.str() << std::endl;
}

void useWarn(void)
{
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(wa.getSensorNo()) << " ";
	std::cout << fmt16(wa.getSensorArg()) << " ";
	std::cout << fmt16(wa.getActuatorNo()) << " ";
	std::cout << fmt16(wa.getActuatorArg()) << " ";
	std::cout << wa.str() << std::endl;
}

void useWarnValue(void)
{
	WarnValue wv(X(1), 3400,B(1), 1);
	wv.setWarn(&wa);
	wva[0] = wv;
	
	std::cout << std::string(__FUNCTION__) << ":";
	std::cout << fmt16(wva[0].cond.no) << " ";
	std::cout << fmt16(wva[0].cond.arg) << " ";
	std::cout << fmt16(wva[0].act.no) << " ";
	std::cout << fmt16(wva[0].act.arg) << " # ";
	std::cout << wva[0].str() << std::endl;
}	


