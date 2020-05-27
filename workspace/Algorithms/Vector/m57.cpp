#include"vector_func.h"

// ������57. ��Ϊs����������
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_set<int> S;
	for (int item : nums) {
		if (S.count(target - item)) return { item, target - item };
		S.insert(item);
	}
	return {};

	// ˫ײָ��
	int l = 0;
	int r = nums.size() - 1;
	while (l < r) {
		int s = nums[l] + nums[r];
		if (s > target) r--;
		else if (s < target) l++;
		else return {l, r };
	}
	return {};
}