#include"doublePointer.h"

// 524. ͨ��ɾ����ĸƥ�䵽�ֵ��������
bool isSubsequence(string s, string d) { // �ж�s�ǲ��ǰ���d��������
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == d[j]) j++;
	}
	return d.size() == j; // ע�����õ�����ʲô����
}

bool isSmaller(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] > s2[i]) return false;
		else if (s1[i] < s2[i]) return true;
	}
	return false;
}

string findLongestWord(string s, vector<string>& d) {
	// me ���⣺û�а����ֵ�˳������ + �����Ӻ�����ʹ���������Ŷ��
	/*sort(d.begin(), d.end());
	int max = 0;
	int flag = 0;
	bool flag1;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < d.size(); i++) {
		flag1 = false;
		s1 = s2 = 0;
		while (s2 < d[i].size()) {
			if (s1 > s.size()) { flag1 = false; break; }
			if (s[s1] == d[i][s2]) {
				s1++; s2++;
				flag1 = true;
			}
			else s1++;
		}
		if (flag1 && d[i].size() > max) {
			flag = i;
			max = d[i].size();
		}
	}
	if (max == 0) return "";
	return d[flag];*/


	// �Ľ���
	string result;
	for (string str : d) { // ���������е�Ԫ��
		if (isSubsequence(s, str)) {
			if (str.size() > result.size()) result = str;
			else if (str.size() == result.size()) {
				if (isSmaller(str, result)) result = str;
			}
		}
	}
	if (result.empty()) return "";
	return result;

}
