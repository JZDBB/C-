#include"List_func.h"

// 328. ��ż���� ���� ����ı��֮�����ڿ��Ե�תָ��
ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* mi = even;
	while (even && even->next) {
		odd->next = odd->next->next;
		odd = even->next;
		even->next = even->next->next;
		even = odd->next;
	}
	odd->next = mi;
	return head;
}