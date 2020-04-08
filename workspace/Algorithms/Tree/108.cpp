#include"tree_func.h"

// 108. ����������ת��Ϊ����������
TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
	if (start > end) return nullptr;
	int p = (end + start) / 2;
	TreeNode* root = new TreeNode(nums[p]);
	root->left = sortedArrayToBST(nums, start, p - 1);
	root->right = sortedArrayToBST(nums, p + 1, end);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	// �ݹ�
	//return sortedArrayToBST(nums, 0, nums.size() - 1);

	// ����
	if (nums.size() == 0) return nullptr;
	queue<pair<TreeNode*, vector<int>>> Q;
	int end = nums.size() - 1;
	TreeNode* root = new TreeNode(-1);
	Q.push(pair<TreeNode*, vector<int>>(root, { 0, end }));
	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; i++) {
			TreeNode* p = Q.front().first;
			int start = Q.front().second[0];
			int end = Q.front().second[1];
			Q.pop();
			int mi = start + (end - start) / 2;
			p->val = nums[mi];
			if (mi != start) {
				p->left = new TreeNode(-1);
				Q.push(pair<TreeNode*, vector<int>>(p->left, { start, mi - 1 }));
			}
			if (mi != end) {
				p->right = new TreeNode(-1);
				Q.push(pair<TreeNode*, vector<int>>(p->right, { mi + 1, end }));
			}
		}
	}
	return root;

}