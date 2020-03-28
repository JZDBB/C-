#include"hash.h"

// 1.������
vector<int> twoSum(vector<int>& nums, int target) {
	// ����
	/*for (int i = 0; i < nums.size(); i++) {
		int diff = target - nums[i];
		for (int j = i+1; j < nums.size(); j++) {
			if ((j != i) && (nums[j] == diff)) return { i, j };
		}
	}*/

	// ��ϣ
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(target - nums[i]) != m.end()) return { m[target - nums[i]], i };
		m[nums[i]] = i;
	}

	return {};
}