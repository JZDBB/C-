#include"tree_func.h"

// 108. ����������ת��Ϊ����������
TreeNode* sortedArrayToBST(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return nullptr;
	TreeNode* root = new TreeNode(nums[n / 2]);
	vetor<int> left;
	root->left = sortedArrayToBST();
}