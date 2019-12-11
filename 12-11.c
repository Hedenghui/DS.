#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
ListNode* partition(ListNode* pHead, int x) {
	ListNode* cur = pHead;
	ListNode *lessHead, *lessTail, *greaterHead, *greaterTail;
	lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode));
	greaterHead = greaterTail = (ListNode*)malloc(sizeof(ListNode));
	lessTail->next = NULL;//��ʼ��
	greaterTail->next = NULL;
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;//β��
			lessTail = cur;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = cur;
		}
		cur = cur->next;
	}
	lessTail->next = greaterHead->next;//С��β�������ͷ����һ����HeadҪfree
	greaterTail->next = NULL;//���봦�����β
	ListNode* List = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return List;
}