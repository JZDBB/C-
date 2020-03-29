#include"string_func.h"

// 242. ��Ч����ĸ��λ��
bool isAnagram(string s, string t) {
	if (s.size() != t.size()) return false; // �ж��������

	// me ���� O(n^2)
	/*for (int i = 0; i < s.size(); i++) {
		int iter = t.find(s[i]); // find��ʱ��
		if (iter != -1) t.erase(iter, 1);
		else return false;
	}
	if (t != "") return false;
	return true;*/

	// ���� ���� O(nlogn)
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;

	 
	// ��ϣ�� O(n)
	vector<int> a(26, 0);
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
		a[t[i] - 'a']--;
	}
	for (int i : a) {
		if (i != 0) return false;
	}
	return true;

}