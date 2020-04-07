#include"tree_func.h"

// 230. �����������е�KС��Ԫ��
int nodeCount(TreeNode* root) {
	if (!root) return 0;
	return nodeCount(root->left) + nodeCount(root->right) + 1;
}

int kthSmallest(TreeNode* root, int k) {
	// ���η�
	/*int n = nodeCount(root->left);
	if (n + 1 == k) return root->val;
	else if (n + 1 < k) return kthSmallest(root->right, k - n - 1);
	else return kthSmallest(root->left, k);*/

	// �������
	stack<TreeNode*> s;
	TreeNode* p = root;
	vector<int> v;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		v.push_back(p->val);
		p = p->right;
	}
	return v[k - 1];
}