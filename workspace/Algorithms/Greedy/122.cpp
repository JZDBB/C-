#include"Greedy.h"

// 122. ������Ʊ�����ʱ�� II
int maxProfit(vector<int>& prices) {
	// ������� ���� �м����ӵ�һ�� >= ��ߵ�-��͵�
	// ̰���㷨�㷨���̣�
	// ����������Ʊ�����ռ۸��б� price���������������ǽ����ն�������׬���������󣩣�
	// �����½������ն���������������Ǯ����
	// �� tmp Ϊ�� i - 1 ��������� i ������׬ȡ�����󣬼� tmp = prices[i] - prices[i - 1] ��
	// ����������Ϊ�� tmp > 0����������������� profit��������Ϊ 00 ��Ϊ������ֱ��������
	// ������ɺ󣬷��������� profit��

	int total = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1]) total += prices[i] - prices[i - 1];
	}
	return total;
}