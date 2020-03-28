#include"hash.h"

// 560.��ΪK��������
int subarraySum(vector<int>& nums, int k) {
	// ����
	/*int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		int sum = nums[i];
		if (sum == k) count++;
		for (int j = i+1; j < nums.size(); j++) {
			sum += nums[j];
			if (sum == k) count++;
		}
	}*/

	// ��ϣ
	int count = 0;
	int sum = 0;
	unordered_map<int, int> m;
	m[0] = 1;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (m.find(sum - k) != m.end()) count += m[sum - k];
		m[sum] ++;
	}
	return count;
}