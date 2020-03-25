#include"doublePointer.h"

// 345. ��ת�ַ����е�Ԫ����ĸ
string reverseVowels(string s) {
	// me (42ms)
	int left = 0;
	int right = s.size() - 1;
	while (left < right) {
		if (find(Vowels.begin(), Vowels.end(), s[left]) != Vowels.end()) {
			if (find(Vowels.begin(), Vowels.end(), s[right]) != Vowels.end()) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
			else right--;
		}
		else left++;
	}

	// �Ľ��� 
	// 1.����Ƕ��ѭ��������һ��ʱ�� (32ms)
	// 2.��������find������Ϊ���жϣ���ż�����һ��ʱ�䡣(16ms)
	// 3.���ж��еģ�=��&&�ֱ��Ϊ==��||�ּ�����һ��ʱ�䡣(8ms)
	left = 0;
	right = s.size() - 1;
	bool flag1 = 0, flag2 = 0;
	while (left < right) {
		if (s[left] == 'a' || s[left] == 'o' || s[left] == 'e' || s[left] == 'i' || s[left] == 'u' || s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') {
			flag1 = 1;
		}
		else left++;
		if (s[right] == 'a' || s[right] == 'o' || s[right] == 'e' || s[right] == 'i' || s[right] == 'u' || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U') {
			flag2 = 1;
		}
		else right--;
		if (flag1&&flag2) {
			swap(s[left], s[right]);
			left++;
			right--;
			flag1 = flag2 = 0;
		}
	}

	return s;
}