#include"List_func.h"

// �����ж��Ƿ��л� �����޻��򷵻�false���л���������ѭ������Ҫ�Ż���
bool hasCycle(ListNode* head) {
	while (head != NULL)
		head = head->next;
	return false;
};