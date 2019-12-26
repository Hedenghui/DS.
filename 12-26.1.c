//��������в�������

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	//û�н�����ֻ��һ�����
	if (head == NULL || head->next == NULL)
		return head;

	Node*sortHead = (Node*)malloc(sizeof(Node));
	sortHead->next = head;
	head = head->next;
	//�����ÿգ��������head��������ʱ��head��Ȼָ��head->next
	sortHead->next->next = NULL;

	//ȡhead����Ľ����в���
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
		//��cur�ߵ�NULLʱ
		if (cur == NULL)
		{
			prev->next = head;
			head->next = NULL;
		}

		head = headNext;
	}
	return sortHead->next;
}