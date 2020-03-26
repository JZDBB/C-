#include"List_func.h"

// 206. ��ת����
//����: 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
ListNode* reverseList(ListNode* head) {
	// me ���� ˫ָ��
	ListNode newhead(-1);
	newhead.next = head;
	ListNode* p = &newhead;
	ListNode node(-1);
	ListNode* res = &node;
	while (p->next) {
		ListNode* ptr = p->next;
		p->next = ptr->next;
		ptr->next = res->next;
		res->next = ptr;
	}
	return (&node)->next;

	// ˫ָ���Ż���
	ListNode* pre = head;
	ListNode* cur = NULL;
	while (pre != NULL) {
		ListNode* t = pre->next;
		pre->next = cur;
		cur = pre;
		pre = t;
	}
	return cur;

	// �ݹ��
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode* ret = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return ret;	
}