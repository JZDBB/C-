#include"List_func.h"
#include<vector>

// 234. ��������
bool isPalindrome(ListNode* head) {
	// ��������
	/*ListNode* newlist = reverseList(head);
	while (head) {
		if (newlist->val != head->val) return false;

	}
	return true;*/

	// ������������ж�
	/*vector<int> a;
	while (head) {
		a.insert(a.end(), head->val);
		head = head->next;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != a[a.size() - i - 1]) return false;
	}
	return true;*/

	// �е㷴ת
	if (head->next == NULL) return true;
	ListNode* pre = NULL;
	ListNode* slow = head;
	while (head&&head->next) { // ���е��ͬʱ��תǰ���
		head = head->next->next;
		ListNode* next = slow->next;
		slow->next = pre;
		pre = slow;
		slow = next;
	}
	//���������˫������һ��!!!
	if (head) {
		slow = slow->next;
	}
	while (slow&& pre) {
		if (head->val != slow->val) return false;
		head = head->next;
		slow = slow->next;
	}
	return true;

}