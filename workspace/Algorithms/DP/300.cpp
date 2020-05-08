#include"DP.h"

// 300. �����������
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size());
	int res = 0;
	dp[0] = 1;
	for (int i = 1; i < dp.size(); i++) {
		int index = i - 1;
		while (index >= 0) {
			if (nums[index] < nums[i]) {
				dp[i] = max(dp[index] + 1, dp[i]);
			}
			index--;
		}
		dp[i] = max(1, dp[i]);
		res = res < dp[i] ? dp[i] : res;
	}
	return res;
	
	// ��չ�����˿���˼��
	vector<int> top(nums.size());
	int piles = 0;
	for (int i = 0; i < nums.size(); i++) {
		// Ҫ������˿���
		int poker = nums[i];
		/***** �������߽�Ķ��ֲ��� *****/
		int left = 0, right = piles;
		while (left < right) {
			int mid = (left + right) / 2;
			if (top[mid] > poker) {
				right = mid;
			}
			else if (top[mid] < poker) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		// û�ҵ����ʵ��ƶѣ��½�һ��
		if (left == piles) piles++;
		// �������Ʒŵ��ƶѶ�
		top[left] = poker;
	}
	// �ƶ������� LIS ����
	return piles;
	
}


