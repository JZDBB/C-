#include"doublePointer.h"

// 283. �ƶ���
void moveZeroes(vector<int>& nums) {

	// me: ����һ����Ϊ0�Ĳ���
	int head = 0, tailer = 0;
	for (; tailer < nums.size(); tailer++) {
		if (nums[tailer] != 0) nums[head++] = nums[tailer];
	}
	for (; head < nums.size(); head++) {
		nums[head] = 0;
	}

	// �Ľ��棺ֱ�ӽ�����0�𽥺���
	int flag = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) swap(nums[flag++], nums[i]);
	}
}