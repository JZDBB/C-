#include"tree_func.h"


int main() {
	/*TreeNode* root1 = new TreeNode(1);
	TreeNode* p = root1;
	p->left = new TreeNode(3);
	p->right = new TreeNode(2);
	p = p->left;
	p->left = new TreeNode(5);
	p->right = new TreeNode(2);
	TreeNode* root2 = new TreeNode(2);
	p = root2;
	p->left = new TreeNode(1);
	p->right = new TreeNode(3);
	p->right->right = new TreeNode(7);
	p->left->right = new TreeNode(2);

	TreeNode* a = mergeTrees(root1, root2);*/
	//TreeNode* root1 = new TreeNode(10);
	//TreeNode* p = root1;
	//// p->left = new TreeNode(5);
	//p->right = new TreeNode(2);
	//p->right->left = new TreeNode(3);
	/*p->left->right = new TreeNode(2);
	p->right->right = new TreeNode(11);
	p->left->left->left = new TreeNode(3);
	p->left->left->right = new TreeNode(2);
	p->left->right->right = new TreeNode(1);*/

	//vector<int> a = postorderTraversal(root1);

	int a[] = { -10, -3, 0, 5, 9 };
	vector<int> m(a, a + 5);
	TreeNode* p = sortedArrayToBST(m);


	return 0;
}