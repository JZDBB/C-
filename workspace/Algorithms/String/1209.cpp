#include"string_func.h"

// 1209. ɾ���ַ����е����������ظ��� II
string removeDuplicates(string s, int k) {
	if (k == 1) return "";

	// ��ʱ
	/*string ans = "";
	while (true) {
		for (int i = 0; i < s.size()-1; i++) {
			if (s[i] == s[i + 1]) {
				int m = i;
				while (m < s.size() && s[m] == s[i]) m++;
				if (m - i >= k) {
					ans = s.substr(0, i) + s.substr(i + k);
					break;
				}
			}
		}
		if (ans=="") break;
		else {
			s = ans;
			ans = "";
		}
	}
	return s;*/

	// ������
	vector<int> count(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i - 1] != s[i]) count[i] = 1;
		else {
			count[i] = count[i - 1] + 1;
			if (count[i] == k) {
				s.erase(i - k + 1, k);
				i = i - k;
			}
		}
	}
	return s;
}