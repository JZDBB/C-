#include"doublePointer.h"

// 88. �ϲ������������� ������Ҫע��鲢������ǰ��յ�����
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// ��һ��
	/*int last = (m--) + (n--) - 1;
	while (n >= 0) {
		nums1[last--] = m >= 0 && nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}*/

	// 0ms �� ���� �����������һ����˵Ҫ����һ���ĺ�ʱ��m��n�������Լ�Ҳ��ʱ
	int last = m + n - 1;
	while (n) {
		nums1[last--] = m == 0 || nums1[m - 1] <= nums2[n - 1] ? nums2[--n] : nums1[--m];
	}
}