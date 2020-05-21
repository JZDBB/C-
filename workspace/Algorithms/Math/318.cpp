#include"Math.h"

// 318. ��󵥴ʳ��ȳ˻�
int str2int(string s) {
	int res = 0;
	for (char c : s) res |= 1 << (c - 'a');
	return res;
}
int maxProduct(vector<string>& words) {
	if (words.size() < 2) return 0;
	vector<int> m(words.size(), 0);
	int res = 0;
	for (int i = 0; i < words.size();i++) m[i] = str2int(words[i]);
	for (int i = 1; i < words.size(); i++) {
		for (int j = 0; j < i; j++) {
			if ((m[i] & m[j]) == 0 && (words[i].size() * words[j].size() > res)) {
				res = words[i].size() * words[j].size();
			} // (m[i] & m[j]) == 0 ��m[i] & m[j] == 0 �����ͬ�����Ų�Ҫ©�����߼��жϵ�ʱ�� 
		}
	}
	return res;
}