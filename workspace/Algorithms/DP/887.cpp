#include"DP.h"

// 887. ��������
int superEggDrop(int K, int N) { // ��ʱ
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i <= N; i++) dp[i][1] = i;
	for (int i = 1; i <= N; i++) {
		for (int k = 2; k <= K; k++) {
			int res = INT_MAX;
			for (int j = 1; j <= i; j++) {
				res = min(res, max(dp[j - 1][k - 1], dp[i - j][k]) + 1);
			}
			dp[i][k] = res;
		}
	}
	return dp[N][K];
}
	

// min(max(dp[i-1][k-1], dp[N-i][k]))
// dp[i-1][k-1]��������������������СֵΪdp[0][k-1]Ϊ0�����ֵΪdp[N-1][k-1]
// dp[N-i][k]���������ݼ���������СֵΪdp[0][k]Ϊ0�����ֵΪdp[N-1][k]
// ������������һ��������[1,N]��һ�����ڽ��㣬�����㲻һ�����������㣬������������㣬����Ҫ
int superEggDropBS(int K, int N) {
	if (K == 1) return N;
	if (N == 1) return 1;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) dp[i][1] = i;
	for (int k = 1; k <= K; k++) dp[1][k] = 1;

	for (int i = 2; i <= N; i++) {
		for (int k = 2; k <= K; k++) {
			// ��һ�θ��ö��ֲ��ң�������1ö�ٵ�i
			int start = 1, end = i, mid;
			int res = INT_MAX;
			while (start <= end) {
				mid = start + (end - start) / 2;
				if (dp[mid - 1][k - 1] == dp[i - mid][k]) {
					res = min(res, dp[mid - 1][k - 1] + 1);
					break;
				}
				else if (dp[mid - 1][k - 1] > dp[i - mid][k]) {
					end = mid - 1;
					res = min(res, dp[mid - 1][k - 1] + 1);
				}
				else {
					start = mid + 1;
					res = min(res, dp[i - mid][k] + 1);
				}
			}
			dp[i][k] = res;
		}
	}
	return dp[N][K];
}

// ��̬�滮��dp����������ⶨ��ȷ����dp���ƹ�ʽ����ͬ�ĽǶȿ����в�ͬ��dp�ⷨ
// ���Ҵ���ʱ�临�Ӷȡ��ռ临�Ӷ��ϵĲ���
// ����dp���������벻���ģ�����еĴ���ţ��
// ����������ֵ�dp�Ƕȵ��������
//
// 1�����������Ĳ�¥�Ӽ���������ֻ����ˤ�����ûˤ�飬���˵Ļ��Ͳ�¥�£�û��Ļ��Ͳ�¥�ϡ�
// 2����������¥������¥���ܵ�¥���� = ¥�ϵ�¥���� + ¥�µ�¥���� + 1����ǰ���¥����
// ��������ص㣬����д�������״̬ת�Ʒ��̣�
// dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1
// dp[k][m - 1] ����¥�ϵ�¥��������Ϊ�������� k ���䣬Ҳ���Ǽ���û�飬�Ӽ������� m ��һ��
// dp[k - 1][m - 1] ����¥�µ�¥��������Ϊ�������� k ��һ��Ҳ���Ǽ������ˣ�ͬʱ�Ӽ������� m ��һ��
// �������ƹ�ʽ����������⣬һ���Ӽ����������Ʋ�1��¥��ʣ��m-1���Ӽ�����ֱ�����Ʋ�dp[k-1][m-1]��dp[k][m-1]��¥
// dp[k-1][m-1]��ʾ�������Ӽ������ˣ���ôֻʣ��k-1��������m-1���Ӽ����Ļ������̽�⵽�����¥����
// dp[k][m-1]��ʾ����Ӽ���û���ţ���ʣ��k��������m-1���Ӽ����������̽�⵽�����¥����
// ͬʱ���б����Ӽ�������һ��¥
// һ���ܹ��Ʋ��¥�������������֮��

int superEggDropDP2(int K, int N) {
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
	int m = 0;
	for (; dp[K][m] < N;) {
		m++;
		for (int k = 1; k <= K; k++)
			dp[k][m] = 1 + dp[k - 1][m - 1] + dp[k][m - 1];
	}
	return m;
}