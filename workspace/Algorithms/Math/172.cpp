#include"Math.h"

// 172. �׳˺���� ���� 5�Ĺ��������ٸ�
int trailingZeroes(int n) {
	int count = 0;
	// ��ʱ��

	//for (int i = 0; i <= n; i += 5) {
	//	int N = i; // i��������Ķ�
	//	while (N) {
	//		if (N % 5 == 0) {
	//			count++;
	//			N /= 5;
	//		}
	//		else break;
	//	}
	//}

	// �Ľ��� 
	// count = n/5+n/25+n/125...;ÿһ��5�ı������ڳ���һ��5��
	while (n) {
		count += n / 5;
		n = n / 5;
	}

	return count;
}