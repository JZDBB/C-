#include"string_func.h"

// 76. ��С�����Ӵ�
bool check(string t, unordered_map<char, int> m) {
	for (int i = 0; i < t.length(); i++) {
		if (m[t[i]] == 0) return false;
	}
	return true;
}
string minWindow(string s, string t) {
	int left = 0, right = 0, start = 0, minLen = INT_MAX;
	unordered_map<char, int> need;
	unordered_map<char, int> window;
	for (char c : t) need[c]++; // Ŀ���ַ���
	int match = 0;
	while (right < s.size()) { // ������ʼ
		char c1 = s[right];
		if (need.count(c1)) { // ��ǰ�ַ�ΪĿ���ַ�
			window[c1]++; // ���´������ַ���
			if (window[c1] == need[c1]) { // �����ַ��Ĵ������ַ��� = ��Ҫ��Ŀ���ַ�����ƥ���ַ�����һ
				match++;
			}
		}
		right++; // ��������
		while (match == need.size()) { // �������ڵ������ַ�����ƥ����ɣ���ʼ�����������
			if (right - left < minLen) { // ���µ�ǰ������Сֵ��������ʼλ��
				minLen = right - left;
				start = left;
			}
			char c2 = s[left];
			if (need.count(c2)) { // ������ַ�ΪĿ���ַ�
				window[c2]--; // ���´������ַ�ͳ��
				if (window[c2] < need[c2]) { // ���ڱ��������Ŀ���ַ���Ҫ��ƥ���ַ�����һ��ѭ�����������¿�ʼ��һ������
					match--;
				}
			}
			left++; // ��������
		}
	}
	return minLen == INT_MAX ? "" : s.substr(start, minLen);
}