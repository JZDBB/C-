#include"tree_func.h"

// 94. ��������������� ���� 0/1��ǣ����ʣ�����������ǰ���С���������������൱��ģ��ݹ�
vector<int> inorderTraversal(TreeNode* root) {
	if (!root) return {};
	vector<int> res;
	
	// 0/1��ǣ����ʣ�
	/*stack<pair<bool, TreeNode*>> s;
	s.push(pair<bool, TreeNode*>(0, root));
	while (!s.empty()) {
		bool flag = s.top().first;
		TreeNode* p = s.top().second;
		s.pop();
		if (!p) continue;
		if (!flag) {
			s.push(pair<bool, TreeNode*>(0, p->right));
			s.push(pair<bool, TreeNode*>(1, p));
			s.push(pair<bool, TreeNode*>(0, p->left));
		}
		else res.push_back(p->val);
	}*/

	// ��ͨ����
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p || !s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		res.push_back(p->val);
		p = p->right;
	}

	return res;
}