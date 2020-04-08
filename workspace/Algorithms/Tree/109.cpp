#include"tree_func.h"

// 109. ��������ת������������
TreeNode* sortedListToBST(ListNode* head) {
	// �������е�ݹ� ���� ʱ�临�Ӷȣ�O(NlogN)��
	if (!head) return nullptr;
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* pre = slow;
	while (fast && fast->next) {
		fast = fast->next->next;
		pre = slow;
		slow = slow->next;
	}
	TreeNode* root = new TreeNode(slow->val);
	root->right = sortedListToBST(slow->next);
	pre->next = NULL;
	if (head != slow) root->left = sortedListToBST(head);

	return root;

	// 
}