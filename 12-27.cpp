//题目描述
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;


		ListNode*cur = pHead;
		ListNode*next = cur->next;
		ListNode*newHead, *newTail;
		newHead = newTail = (ListNode*)malloc(sizeof(ListNode));
		newHead->next = NULL;
		while (next)
		{
			if (cur->val == next->val)
			{
				//注意next是否为空  举例 1->2->3->3->3->3->3
				while (next&&next->val == cur->val)
				{
					next = next->next;
				}
				cur = next;
				if (cur)
					next = cur->next;
			}
			else
			{
				newTail->next = cur;
				newTail = cur;
				newTail->next = NULL;

				cur = next;
				next = next->next;
			}
		}
		//1->2->3->3->4->4->5
		if (cur)
		{
			newTail->next = cur;
		}

		return newHead->next;
	}
};
int main()
{
	system("pause");
	return 0;
}