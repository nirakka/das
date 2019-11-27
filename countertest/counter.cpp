#include <iostream>

#include "counter.h"

// 暫定
int countdown(Counter& c)
{

	if (c.preset == 0){
		return -1;
	}

	bool f1 = (c.current == 0);
	bool f2 = (c.current > c.preset );
	bool f3 = (--c.current == 0);
	if (!f1 && !f2){
		if (!f3) return 0;
	}
	c.current = c.preset;
	return (f3)?1:0;
}

int countdownarray(CounterArray& c)
{
	return 0;
}
