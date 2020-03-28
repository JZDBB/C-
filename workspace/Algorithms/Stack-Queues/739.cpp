#include"Stack.h"

// 739. ÿ���¶�
vector<int> dailyTemperatures(vector<int>& T) {
	// �����ƽ� 
	/*vector<int> res;
	bool flag;
	for (int i = 0; i < T.size(); i++) {
		flag = true;
		for (int j = i+1; j < T.size(); j++) {
			if (T[j] > T[i] && flag) { 
				res.insert(res.end(), j - i); 
				flag = false;
			}
		}
		if (flag) res.insert(res.end(), 0);
	}
	return res;*/

	 //Stackʵ�ַ��� ���� ����ջ��https://mp.weixin.qq.com/s/3kDSOHyd-qOw7apzj0Z9YQ��
	stack<int> nums, index;
	vector<int> res(T.size(), 0);
	for (int i = 0; i < T.size(); i++) {
		while (!nums.empty() && T[i] > nums.top()) {
			nums.pop();
			res[index.top()] = i - index.top();
			index.pop();
		}
		nums.push(T[i]);
		index.push(i);
	}
	return res;

}