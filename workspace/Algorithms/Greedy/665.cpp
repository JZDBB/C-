#include"Greedy.h"

// 665. �ǵݼ�����
// �ڳ��� nums[i] < nums[i - 1] ʱ����Ҫ���ǵ���Ӧ���޸�������ĸ�����
// ʹ�ñ����޸���ʹ i ֮ǰ�������Ϊ�ǵݼ����飬����**��Ӱ������Ĳ���** ��
bool checkPossibility(vector<int>& nums) {
	int count = 0;
	for (int i = 1; i < nums.size() && count < 2; i++) {
		if (nums[i] >= nums[i - 1]) continue;
		count++;
		if (i - 2 >= 0 && nums[i] < nums[i - 2]) nums[i] = nums[i - 1];
		else nums[i - 1] = nums[i];
	}
	return count <= 1;
}