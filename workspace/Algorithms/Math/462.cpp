#include"Math.h"

// 462. �����ƶ�����ʹ����Ԫ����� II
int minMoves2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int count = 0;
	int target = nums[nums.size() / 2];
	for (int num : nums) {
		count += abs(target - num);
	}
	return count;
}