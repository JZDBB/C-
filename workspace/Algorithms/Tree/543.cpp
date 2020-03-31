#include"tree_func.h"

// 543. ��������ֱ��
int height(TreeNode* root) {
	if (!root) return 0;
	return max(height(root->left), height(root->right)) + 1;
}
int length = 0;
int len(TreeNode* root) {
	if (!root) return 0;
	int L = len(root->left);
	int R = len(root->right);
	length = max(L + R, length);
	return max(L, R) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
	// �ݹ�����
	/*if (!root) return 0;
	int max = 0;
	stack<TreeNode*> Stack;
	TreeNode* p = root;
	Stack.push(root);
	while (!Stack.empty()) {
		p = Stack.top();
		int length = height(p->left) + height(p->right);
		if (length > max) max = length;
		Stack.pop();
		if (p->right) Stack.push(p->right);
		if (p->left) Stack.push(p->left);		
	}
	return max;*/

	// �Ż��ĵݹ�����
	// ʱ�临�Ӷȣ�O(N)��ÿ�����ֻ������һ�Ρ�
	// �ռ临�Ӷȣ�O(Height)������ Height Ϊ�������ĸ߶ȡ�
	// ���ڵݹ麯���ڵݹ��������ҪΪÿһ��ݹ麯������ջ�ռ䣬
	// ����������Ҫ����Ŀռ��Ҹÿռ�ȡ���ڵݹ����ȣ����ݹ�������ȻΪ�������ĸ߶ȣ�
	// ����ÿ�εݹ���õĺ�������ֻ���˳�������������������ռ临�Ӷ�Ϊ O(Height) ��
	len(root);
	return length;
}