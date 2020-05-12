#include"DP.h"

// 121. ������Ʊ�����ʱ��
int maxProfit(vector<int>& prices) {
	int n = prices.size(); if (n < 1) return 0;
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], -prices[i]); // ���ν���
	}
	return dp[n - 1][0];
}

// 122. ������Ʊ�����ʱ�� II
int maxProfit2(vector<int>& prices) {
	int n = prices.size(); if (n < 1) return 0;
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] -prices[i]); // ��ν���
	}
	return dp[n - 1][0];
}

// 123. ������Ʊ�����ʱ�� III
int maxProfit3(vector<int>& prices) {
	int n = prices.size(); if (n < 1) return 0;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
	dp[0][1][1] = -prices[0];
	dp[0][2][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
		dp[i][1][1] = max(dp[i - 1][1][1], -prices[i]);
		dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
		dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
	}
	return dp[n - 1][2][0];
}

// 188. ������Ʊ�����ʱ�� IV
int maxProfit(int k, vector<int>& prices) {
	int n = prices.size(); if (n < 1) return 0;
	if (k > n / 2) return maxProfit2(prices);
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i == 0) {
				dp[i][j][1] = -prices[0];
				continue;
			}
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
		}
	}
	return dp[n - 1][k][0];
}

// 309. ���������Ʊʱ�����䶳��
int maxProfit5(vector<int>& prices) {
	int n = prices.size(); if (n < 1) return 0;
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][1] = -prices[0];
	int temp = 0;
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], temp - prices[i]); // ��ν���
		temp = dp[i - 1][0];
	}
	return dp[n - 1][0];
}

// 714. ������Ʊ�����ʱ����������
int maxProfit(vector<int>& prices, int fee) {
	int n = prices.size(); if (n < 1) return 0;
	vector<vector<int>> dp(n, vector<int>(2));
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // ��ν���
	}
	return dp[n - 1][0];
}