//反转一个单链表。
//
//示例 :
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head)
{
	Node*cur = head;
	Node*newhead = NULL;
	while (cur)
	{
		Node*next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
