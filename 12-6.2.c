//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
void ListPrint(ListNode* head)
{
	ListNode* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
struct ListNode* middleNode(struct ListNode* head){
	ListNode* slow = head, *fast = head;
	//while(!(fast == NULL || fast->next == NULL))
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
	void ListPrint(slow);
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
	struct ListNode* middleNode(Node1);
	system("pause");
	return 0;
}