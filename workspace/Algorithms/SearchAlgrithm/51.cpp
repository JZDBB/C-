#include"Search.h"

// 51. N�ʺ�
bool isValid(vector<string>& board, int row, int col) {
	int n = board.size();
	// ������Ƿ��лʺ����ͻ
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	// ������Ϸ��Ƿ��лʺ����ͻ
	for (int i = row - 1, j = col + 1;
		i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q')
			return false;
	}
	// ������Ϸ��Ƿ��лʺ����ͻ
	for (int i = row - 1, j = col - 1;
		i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q')
			return false;
	}
	return true;
}

void backtrack(vector<string>& board, int row, vector<vector<string>> &ans) {
	if (row == board.size()) {
		ans.push_back(board);
		return;
	}
	for (int col = 0; col < board[0].size(); col++) {
		if (!isValid(board, row, col)) continue;
		board[row][col] = 'Q';
		backtrack(board, row + 1, ans);
		board[row][col] = '.';
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> board(n, string(n, '.'));
	backtrack(board, 0, res);
	return res;
}