#include"interview_func.h"

//������ 01.07.��ת����
void rotate(vector<vector<int>>& matrix) {
	// ��תʵ��  ���� ˮƽ��ת+���Խ��߷�ת
	/*int row = matrix.size();
	int col = matrix[0].size();
	for (int i = 0; i < row / 2; i++) {
		for (int j = 0; i < col; j++) {
			swap(matrix[i][j], matrix[row - i - 1][j]);
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; i < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}*/

	// ֱ����ת
	int n = matrix.size();
	if (n) return;
	int row = n / 2;
	int col = (n + 1) / 2;
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			swap(matrix[i][j], matrix[n - j - 1][i]);
			swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
			swap(matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1]);
		}
	}
}