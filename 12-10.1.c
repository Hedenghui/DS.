//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode*next;
};
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	Node*head = NULL;
	Node*tail = NULL;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			if (tail == NULL)
			{
				head = tail = l1;
			}
			else
			{
				tail->next = l1;
				tail = l1;
			}
			l1 = l1->next;
		}
		else
		{
			if (tail == NULL)
			{
				head = tail = l2;
			}
			else
			{
				tail->next = l2;
				tail = l2;
			}
			l2 = l2->next;
		}
		if (l1)
		{
			tail->next = l1;
		}
		if (l2)
		{
			tail->next = l2;
		}
	}
	return head;
}