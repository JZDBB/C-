#include"doublePointer.h"

//167. ����֮�� II - ������������
vector<int> twoSum(vector<int>& numbers, int target) {
	// ˫ָ�롪�����������ռ�
	int index1 = 1, index2 = numbers.size();
	while (index1 < index2) {
		int sum = numbers[index1 - 1] + numbers[index2 - 1];
		if (sum == target) return vector<int>{index1, index2};
		else if (sum > target) index2--;
		else index1++;
	}
	return {};
}