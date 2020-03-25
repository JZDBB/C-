#include"doublePointer.h"

// 633. ƽ����֮��
bool judgeSquareSum(int c) {
	// ���� ʱ�临�Ӷ� O(sqrt(n)) ��ʵ�ϻ��һЩ
	for (int i = 1; pow(i, 2) <= c / 2; i++) {
		double diff = c - pow(i, 2);
		if (sqrt(diff) - int(sqrt(diff)) == 0) return true;
	}
	return false;

	// ˫ָ�� ʱ�临�Ӷ� O(sart(n))
	int left = 0;
	int right = (int)sqrt(c);
	while (left < right) { // ������
		long sum = pow(left, 2) + pow(right, 2); // �����ͷ���� ���� 64λ����ϵͳ��intռ���ֽڣ�longռ8�ֽڣ�long���ݷ�Χ��Ϊ��-2^63~2^63-1
		if (sum < c) left++;
		else if (sum > c)right--;
		else return true;
	}
	return false;

}