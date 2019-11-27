#include <iostream>

#include "counter.h"

// 暫定
// return 1 => currentが0なのでをpresetに更新
// return 0 => countdownだけ行う,
//             currentの値がおかしければpresetの値を入れる
// return -1=> presetが0なので何もしない
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

// result 0 => どっちもca内の値がすべて1以外
// result 1 => 一つ目のセンサのcurrentが1
// result 2 => 二つ目のセンサのcurrentが1
// result 3 => 両方のセンサのcurrentが1
int countdownarray(CounterArray& ca)
{
	int result = 0;
	if (countdown(ca[0])==1) result |= 1;
	if (countdown(ca[1])==1) result |= 2;

	return result;
}
