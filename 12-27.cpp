//��Ŀ����
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
				//ע��next�Ƿ�Ϊ��  ���� 1->2->3->3->3->3->3
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