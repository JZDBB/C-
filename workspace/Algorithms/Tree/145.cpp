#include"tree_func.h"

// 145. �������ĺ������ ���� ������
void traverse(TreeNode* root, vector<int> &res) {
	if (!root) return;
	traverse(root->left, res);
	traverse(root->right, res);
	res.insert(res.end(), root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	if (!root) return {};
	vector<int> res;
	// �ݹ�
	// traverse(root, res);

	// ���� ���� ��ǰ�����˳��ת��Ϊroot->right->left��˳�����ת��

	//stack<TreeNode*> s;
	//TreeNode *cur = root;
	//while (cur || !s.empty()) {
	//	while (cur) {
	//		res.push_back(cur->val);
	//		s.push(cur);
	//		cur = cur->right;         //�޸�1���ȱ���������
	//	}
	//	cur = s.top()->left;          //�޸�2���ٱ���������
	//	s.pop();
	//}
	//reverse(res.begin(), res.end());

	// ����2 ���� ����һ��ָ��ǰһ�ڵ��ָ�룬����Һ����Ƿ񱻷���
	TreeNode* cur = root;
	TreeNode* pre = NULL;
	stack<TreeNode*> s;
	while (cur || !s.empty()) {
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		if (!cur->right || cur->right == pre) {
			res.push_back(cur->val);
			s.pop();
			pre = cur->right;
			cur = NULL;
		}
		else cur = cur->right;
	}

	return res;
}