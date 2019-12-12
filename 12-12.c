#include<stdio.h>
#include<stdlib.h>

//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true
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
			//头插
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