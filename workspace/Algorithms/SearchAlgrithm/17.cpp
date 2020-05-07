#include"Search.h"

// 17. �绰�������ĸ���
void dfs17(string digits, string comb, vector<string> &ans, vector<string> &map) {
	int len = digits.length();
	if (len == 0) {
		ans.push_back(comb);
		return;
	}
	int num = digits[0] - '0';
	for (int i = 0; i < map[num].size(); i++) {
		comb.push_back(map[num][i]);
		dfs17(digits.substr(1), comb, ans, map);
		comb.pop_back(); // comb��ѭ���л���Ҫ�á�
	}

}
vector<string> letterCombinations(string digits) {
	vector<string> map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> res;
	if (digits.size() != 0) {
		dfs17(digits, "", res, map);
	}
	return res;
}