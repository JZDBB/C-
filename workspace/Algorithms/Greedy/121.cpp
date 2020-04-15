#include"Greedy.h"

// 121. ������Ʊ�����ʱ��
int maxProfit(vector<int>& prices) {
	if (prices.size() < 2) return 0;
	int max = 0;
	int min = prices[0];
	for (int price : prices) {
		max = max > price - min ? max : price - min;
		min = min < price ? min : price;
	}
	return max;
}