#include"DP.h"

// 322. ��Ǯ�һ�
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1); // ��ʼ����������жϣ�
	dp[0] = 0;
	for (int i = 1; i < dp.size(); i++) {
		for (int coin : coins) {
			if (i - coin < 0) continue;
			dp[i] = min(dp[i - coin] + 1, dp[i]);
		}
	}
	return dp[amount] == amount + 1 ? -1 : dp[amount];
}