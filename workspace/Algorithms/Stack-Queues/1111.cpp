#include"Stack.h"

// 1111. ��Ч���ŵ�Ƕ�����
vector<int> maxDepthAfterSplit(string seq) {
	stack<char> Stack;
	vector<int> res(seq.size(), 0);
	int flag = 1;
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == '(') {
			if (Stack.size() % 2 != 0) flag = 1;
			else flag = 0;
			res[i] = flag;
			Stack.push(seq[i]);
		}
		else {
			res[i] = Stack.top().first;
			Stack.pop();
		}
	}
	return res;
}