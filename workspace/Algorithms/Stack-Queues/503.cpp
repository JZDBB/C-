#include"Stack.h"

// 503. ��һ������Ԫ�� II ���� ѭ��+����ջ
vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int> s;
	int len = nums.size();
	vector<int> res(nums.size(), 0);
	for (int i = 2 * nums.size() - 1; i >= 0; i--) {
		while (!s.empty() && nums[i%len] >= s.top()) s.pop();
		res[i% len] = s.empty() ? -1 : s.top();
		s.push(nums[i%len]);
	}
	return res;
}