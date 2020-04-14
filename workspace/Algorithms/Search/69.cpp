#include"Search.h"

// 69. x ��ƽ����
int mySqrt(int x) {
	if (x < 2) return x;
	if (x >= 2147395600) return 46340;

	// ���ֲ���
	/*
	int left = 0;
	int right = x / 2;
	while (left <= right) {
		int mi = left + (right - left) / 2;
		if (mi > 46340) mi = 46340;
		int sqrt = mi * mi;
		if (sqrt == x) return mi;
		else if (sqrt > x) right = mi - 1;
		else left = mi + 1;
	}
	return left - 1;*/

	// ֱ�Ӽ���
	/*int left = int(exp(0.5*log(x)));
	int right = left + 1;
	return right * right > x ? left : right;*/

	// ţ�ٷ�
	// x(k + 1)= 0.5[x(k)+x/x(k)] ��� x0 = x���������� sqrt{ x }
	// ������С�� 1 ʱ����������
	// �������ݶ��½�
	double x0 = x;
	double x1 = (x0 + double(x) / x0) / 2;
	while (abs(x0 - x1) >= 1) {
		x0 = x1;
		x1 = (x0 + double(x) / x0) / 2;
	}
	return int(x1);
}