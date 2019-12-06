#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	ListNode*prev = NULL;
	ListNode*cur = head;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			ListNode*next = cur->next;
			free(cur);
			if (cur == head)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
	printf("%d", head->val);
}
int main()
{
	ListNode*Node1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode*Node2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode*Node3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode*Node4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode*Node5 = (ListNode*)malloc(sizeof(ListNode));
	Node1->next = Node2; Node1->val = 1;
	Node2->next = Node3; Node2->val = 2;
	Node3->next = Node4; Node3->val = 3;
	Node4->next = Node5; Node4->val = 4;
	Node5->next = NULL; Node5->val = 5;
	struct ListNode* removeElements(Node1, 6);
	system("pause");
	return 0;
}