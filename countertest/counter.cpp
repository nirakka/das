#include <iostream>

#include "counter.h"

// �b��
// return 1 => current��0�Ȃ̂ł�preset�ɍX�V
// return 0 => countdown�����s��,
//             current�̒l�������������preset�̒l������
// return -1=> preset��0�̏ꍇcurrent��0�ɂ���
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

// result 0 => �ǂ�����ca���̒l�����ׂ�1�ȊO
// result 1 => ��ڂ̃Z���T��current��1
// result 2 => ��ڂ̃Z���T��current��1
// result 3 => �����̃Z���T��current��1
int countdownarray(CounterArray& ca)
{
	int result = 0;
	for (int i=0;i<4;i++){
		if (countdown(ca[i])==1) result |= mask[i];
	}
	return result;
}
