//����һ����������������е�����k����㡣
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
			if (fast == NULL)//ע��K����
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
