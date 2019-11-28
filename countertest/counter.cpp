#include <iostream>

#include "counter.h"

// 暫定
// return 1 => currentが0なのでをpresetに更新
// return 0 => countdownだけ行う,
//             currentの値がおかしければpresetの値を入れる
// return -1=> presetが0の場合currentも0にする
int countdown(Counter& c)
{

	if (c.preset == 0){
		c.current = 0;
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

static int mask[] = {1, 2, 4, 8, 16, 32, 64, 128};

// result 0 => どっちもca内の値がすべて1以外
// result 1 => 一つ目のセンサのcurrentが1
// result 2 => 二つ目のセンサのcurrentが1
// result 3 => 両方のセンサのcurrentが1
int countdownarray(CounterArray& ca)
{
	int result = 0;
	for (int i=0;i<4;i++){
		if (countdown(ca[i])==1) result |= mask[i];
	}
	return result;
}
