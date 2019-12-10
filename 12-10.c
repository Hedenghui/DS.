//输入一个链表，输出该链表中倒数第k个结点。
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
int val;
struct ListNode *next;
};
typedef struct ListNode Node;

Node* FindKthToTail(Node* pListHead, unsigned int k) {
		Node*fast = pListHead;
		Node*slow = pListHead;

		while (k--)
		{
			if (fast == NULL)//注意K过大
				return NULL;
			fast = fast->next;
		}
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
}
