#include"List.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
//创建返回链表的头节点
ListNode* ListCreate()
{
	ListNode*head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}
//双向链表打印
void ListPrint(ListNode* phead)
{
	ListNode*cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	ListNode*tail = phead->prev;
	//phead  tail   newNode
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}
//双向链表尾删
void ListPopBack(ListNode* phead)
{
	ListNode*tail = phead->prev;
	ListNode*prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
}
//双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	ListNode*next = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next = next;
	next->prev = newNode;
}
//双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead->next!=phead);
	ListNode*first = phead->next;
	ListNode*second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
}
//双向链表销毁
void ListDestory(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	//phead = NULL;
}
//双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}

	return NULL;
}
//双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}
//双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}