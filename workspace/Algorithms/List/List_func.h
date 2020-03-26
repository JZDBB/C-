#pragma once
#include<stdio.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

bool hasCycle(ListNode* head);

ListNode* reverseList(ListNode* head);

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

ListNode* removeNthFromEnd(ListNode* head, int n);

ListNode* swapPairs(ListNode* head);