#include"vector_func.h"

// 289. ������Ϸ
void gameOfLife(vector<vector<int>>& board) {
	int neighbors[3] = { 0, 1, -1 };
	for (int r = 0; r < board.size(); r++) {
		for (int c = 0; c < board[0].size(); c++) {
			int count = 0;
			// ������ⷨ
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
						int R = (r + neighbors[i]);
						int C = (c + neighbors[j]);

						if ((R < r && R >= 0) && (C < c && C >= 0) && (abs(board[R][C]) == 1)) {
							count += 1;
						}
					}
				}
			}
			// ���� 1 ����� 3 
			if ((board[r][c] == 1) && (count < 2 || count > 3)) {
				// -1 �������ϸ����ȥ�ǻ����������
				board[r][c] = -1;
			}
			// ���� 4
			if (board[r][c] == 0 && count == 3) {
				// 2 �������ϸ����ȥ���������ڻ���
				board[r][c] = 2;
			}

		}
	}

	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board[0].size(); col++) {
			if (board[row][col] > 0) board[row][col] = 1;
			else board[row][col] = 0;
		}
	}

}

