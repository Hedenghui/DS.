//给定一个链表，判断链表中是否有环。
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
     int val;  
	 struct ListNode *next;
};
typedef struct ListNode Node;
int hasCycle(struct ListNode *head) {
	Node* slow = head, *fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	system("pause");
	return 0;
}