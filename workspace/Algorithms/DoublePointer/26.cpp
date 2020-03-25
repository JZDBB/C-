#include"doublePointer.h"

// 26. ɾ�����������е��ظ��� ���� ԭ���޸��������� ����ʹ�� O(1) ����ռ�
int removeDuplicates(vector<int>& nums) {
	// me

	//if (nums.size() == 0) return 0;
	//int head = 0;
	//int tailer = 1;
	//while (tailer < nums.size()) {
	//	if (nums[head] == nums[tailer]) tailer++;
	//	else {
	//		nums[++head] = nums[tailer++];
	//	}
	//}
	//return head + 1; // �������鳤��

	// �Ľ��桪�� ���Ӽ��
	if (nums.size() < 2) return nums.size();
	int head = 0;
	for (int tailer = 0; tailer < nums.size(); tailer++) {
		if (nums[head] != nums[tailer]) nums[++head] = nums[tailer];
	}
	return ++head;
}

//  ɾ�����������е��ظ��� II ����ÿ��Ԫ������������
int removeDuplicates2(vector<int>& nums) { // �����ͼ�� ȥ��II.gif
	if (nums.size() <= 2) return nums.size();
	int head = 1;
	for (int tailer = 2; tailer < nums.size(); tailer++) {
		if (nums[head - 1] != nums[tailer]) nums[++head] = nums[tailer];
	}
	return ++head;
}