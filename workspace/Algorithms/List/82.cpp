#include"List_func.h"

// 82. ɾ�����������е��ظ�Ԫ�� II
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* newhead = new ListNode(-1);
	newhead->next = head;
	ListNode* prev = newhead;
	ListNode* cur = head;
	while (cur) {
		if (cur&&cur->next&& cur->val == cur->next->val) {
			int val = cur->val;
			while (cur&&cur->val == val) {
				cur = cur->next;
			}
			prev->next = cur;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
	return newhead->next;
}