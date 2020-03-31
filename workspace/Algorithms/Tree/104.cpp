#include"tree_func.h"

//104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root) {
	// �ݹ��㷨 ���� ȱ����������㼶����ᱨ�������ʱ����������ջ�����
	/*if (!root) return 0;
	return maxDepth(root->left) + 1 > maxDepth(root->right) + 1 ? maxDepth(root->left) + 1 : maxDepth(root->right) + 1;*/

	// DFS ���� ��һ�����������ջ������
	if (root == NULL) return 0;
	stack<pair<TreeNode*, int>> Stack;
	TreeNode* p = root;
	int res = 0;
	int deep = 0;
	while (!Stack.empty() || p != NULL) {
		while (p != NULL) { // ��һֱ����������������ջ��
			Stack.push(pair<TreeNode*, int>(p, ++deep));
			p = p->left;
		}
		p = Stack.top().first; // ��¼���ڵ㣬�����������
		deep = Stack.top().second;
		if (res < deep) res = deep;
		Stack.pop(); // �������ڵ�
		p = p->right; // ����������
	}
	return res;

	// BFS ���� ���б���
	/*if (root == NULL) return 0;
	queue<TreeNode*> Queue;
	TreeNode* p = root;
	Queue.push(root);
	int res = 0;
	while (!Queue.empty()) {
		res++;
		int size = Queue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Queue.front();
			Queue.pop();
			if (p->left) Queue.push(p->left);
			if (p->right) Queue.push(p->right);
		}
	}
	return res;*/
}
