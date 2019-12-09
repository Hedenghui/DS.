//反转一个单链表。
//
//示例 :
//
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//第二种方法
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node*n1, *n2, *n3;
	n1 = NULL;
	n2 = head;
	n3 = n2->next;

	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;
}