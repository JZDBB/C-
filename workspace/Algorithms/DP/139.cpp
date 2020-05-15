#include"DP.h"

// 139. ���ʲ��
unordered_set<string> wdict;
bool dfs(int u, string s) {
	if (u == s.size()) return true;
	for (int i = u; i < s.size(); i++)
		if (wdict.count(s.substr(u, i - u + 1)) && dfs(i + 1, s))
			return true;
	return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
	if (s == "") return false;
	for (auto i : wordDict) wdict.insert(i);
	// dfs ��ʱ
	return dfs(0, s);

	// ��̬�滮
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j]&&wdict.find(s.substr(j, i-j)) != wdict.end()) {
				dp[i] = true; // substr�÷�,s.substr(pos, n), nΪ����
				break;
			}
		}
	}
	return dp[s.size()];
}