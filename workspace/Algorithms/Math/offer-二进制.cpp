#include"Math.h"

// ��������1�ĸ���
int  NumberOf1(int n) {
	int cnt = 0;
	while (n) {
		cnt++;
		n &= (n - 1); // ������λ��1
	}
	return cnt;
}