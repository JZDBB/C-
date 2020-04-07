#include"tree_func.h"

// 538. �Ѷ���������ת��Ϊ�ۼ���
TreeNode* convertBST(TreeNode* root) {
	if (!root) return root;
	TreeNode* p = root;
	stack<TreeNode*> s;
	int sum = 0;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->right;
		}
		p = s.top();
		p->val += sum;
		sum = p->val;
		s.pop();
		p = p->left;
	}
	return root;
}