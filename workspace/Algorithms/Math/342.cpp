#include"Math.h"

// 342. 4����
bool isPowerOfFour(int num) {
	if (num <= 0) return false;
	bool flag = false;
	while ((num & 3) == 0) num = num >> 2;
	return num == 1;
}