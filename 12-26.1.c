//对链表进行插入排序。

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	//没有结点或者只有一个结点
	if (head == NULL || head->next == NULL)
		return head;

	Node*sortHead = (Node*)malloc(sizeof(Node));
	sortHead->next = head;
	head = head->next;
	//必须置空，否则当你把head拿下来的时候head仍然指向head->next
	sortHead->next->next = NULL;

	//取head链表的结点进行插入
	while (head)
	{
		Node*headNext = head->next;
		Node*prev = sortHead;
		Node*cur = sortHead->next;

		while (cur)
		{
			if (cur->val>head->val)
			{
				prev->next = head;
				head->next = cur;
				break;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		//当cur走到NULL时
		if (cur == NULL)
		{
			prev->next = head;
			head->next = NULL;
		}

		head = headNext;
	}
	return sortHead->next;
}