#pragma once
#include<vector>
#include<queue>
using namespace std;

class MonotonicQueue {
public:
	// �ڶ�β���Ԫ�� n
	void push(int n) {
		while (!Q.empty() && Q.back() < n) Q.pop_back();
		Q.push_back(n);
	}
	// ���ص�ǰ�����е����ֵ
	int max() {
		return Q.front();
	}
	// ��ͷԪ������� n��ɾ����
	void pop(int n) {
		if (!Q.empty() && Q.front() == n) Q.pop_front();
	}
private:
	deque<int> Q;// ˫�˶��� ���������ڶ�ͷ��β��push��pop
};

vector<int> maxSlidingWindow(vector<int>& nums, int k);