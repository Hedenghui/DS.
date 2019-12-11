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
	lessTail->next = NULL;//初始化
	greaterTail->next = NULL;
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;//尾插
			lessTail = cur;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = cur;
		}
		cur = cur->next;
	}
	lessTail->next = greaterHead->next;//小的尾链到大的头的下一个，Head要free
	greaterTail->next = NULL;//必须处理这个尾
	ListNode* List = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return List;
}