#include"tree_func.h"

// 530. ��������������С���Բ�
int getMinimumDifference(TreeNode* root) {
	TreeNode* p = root;
	stack<TreeNode*> s;
	int temp;
	int min = INT_MAX;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		min = abs(p->val - temp) < min ? abs(p->val - temp) : min;
		temp = p->val;
		s.pop();
		p = p->right;
	}
	return min;
}