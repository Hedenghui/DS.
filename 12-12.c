#include<stdio.h>
#include<stdlib.h>

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//
//����������
//1->2->2->1
//���أ�true
struct ListNode {
int val;
struct ListNode *next;
};
	bool chkPalindrome(ListNode* A) {
		ListNode*copyA = NULL;
		ListNode*cur = A;
		while (cur)
		{
			ListNode*copycur = (ListNode*)malloc(sizeof(ListNode));
			copycur->val = cur->val;
			copycur->next = NULL;
			//ͷ��
			copycur->next = copyA;
			copyA = copycur;

			cur = cur->next;
		}
		cur = A;
		ListNode*copycur = copyA;
		while (cur)
		{
			if (cur->val != copycur->val)
				return false;
			cur = cur->next;
			copycur = copycur->next;
		}
		return true;
		
	}