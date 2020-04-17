#include"Math.h"

// 367. ��Ч����ȫƽ����
// 1 4=1+3 9=1+3+5 16=1+3+5+7 ����
bool isPerfectSquare(int num) {
	if (num < 2) return true;
	int x = num / 2;
	while (x*x>num) {
		x = (x + num / x) / 2;
	}
	return x * x == num;
}