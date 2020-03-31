#include"vector_func.h"

// 645. ����ļ���
vector<int> findErrorNums(vector<int>& nums) {
	/*if (nums.size() < 2)  return {};
	unordered_map<int, int> m;
	int copy, found;
	for (int i = 0; i < nums.size(); i++) m[nums[i]]++;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(i + 1) == m.end()) found = i + 1;
		else if (m[i + 1] != 1) copy = i + 1;
	}
	return { copy, found };*/
	
	// ͳ�����ֵĻ�������ȹ�ϣ���һЩ��index����
	vector<int> m(nums.size() + 1);
	vector<int> ans(2);
	for (int i = 0; i < nums.size(); ++i) {
		m[nums[i]]++;
		if (m[nums[i]] == 2) {
			ans[0] = nums[i];
		}
	}
	for (int i = 1; i < m.size(); ++i) {
		if (m[i] == 0) {
			ans[1] = i;
		}
	}
	return ans;
}