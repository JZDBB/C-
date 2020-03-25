#include"doublePointer.h"

// 680. ��֤�����ַ��� �� ����һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����
bool isPalindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])  return false;
	}
	return true;
}

bool validPalindrome(string s) {
	// �жϻ����ַ��� I
	/*int left = 0;
	int right = s.size() - 1;
	while (left <= right) { // <= ��ע��
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;*/

	// �жϻ����ַ��� I ���� me
	// ���⣺����ж�ɾ��˫ָ������һ����ָ��Ԫ��
	/*int left = 0;
	int right = s.size() - 1;
	bool flag = 0;
	while (left <= right) {
		if (s[left] != s[right]) {
			if (flag) return false;
			if (s[left + 1] == s[right]) { // �������ڣ����жϵ���ɾ����û�кͺ���һ���Ͽ���
				flag = 1;
				left++;
			} else if (s[left] == s[right - 1]) {
				flag = 1;
				right--;
			}
			else return false;
		}
		left++;
		right--;
	}
	return true;*/

	// ������
	// ������������߶�ɾ�����������������������Ҫ�ж����Σ����ܺķ�ʱ���
	int left = 0;
	int right = s.size() - 1;
	while (left <= right) {
		if (s[left] != s[right]) {
			return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}