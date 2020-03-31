#include"vector_func.h"

// 566. ���ܾ���
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	if (nums.empty() || nums[0].empty()||nums.size()*nums[0].size() != r * c) return nums;
	int C = nums[0].size();
	int  N = r * c;
	vector<vector<int>>  res(r, vector<int>(c, 0)); // ��ά�����ʼ������
	for (int i = 0; i < N; i++) {
		res[i / c][i % c] = nums[i / C][i % C]; // �� �� ��
	}
	return res;
}