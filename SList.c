#include"SList.h"

void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
void SListPushBack(SListNode** ppList, SLTDataType x)//尾插
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else//找到最后一个Node,将它指向newNode
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void SListPushFront(SListNode** ppList,SLTDataType x)//头插
{
		SListNode*newNode = (SListNode*)malloc(sizeof(SListNode));
		newNode->data = x;
		newNode->next = NULL;
		newNode->next = *ppList;
		*ppList = newNode;
}
void SListPopBack(SListNode**ppList)//尾删
{
	//NULL
	//一个
	//多个
	if (*ppList == NULL)
	{
		return *ppList;
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		SListNode*prev = NULL;
		SListNode*tail = *ppList;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void SListPopFront(SListNode**ppList)//头删
{
	if (*ppList == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*ppList)->next;
		free(*ppList);
		*ppList = next;
	}
}
SListNode* SListFind(SListNode* pList, SLTDataType x)
{
	SListNode*cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	/*SListNode*newNode = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = newNode;
	newNode->next = next;*/
	SListNode*newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListErasaAfter(SListNode*pos)
{
	SListNode*next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}
void SListDestory(SListNode** ppList)
{
	SListNode* cur = *ppList;
	while (cur)
	{
		SListNode*next = cur->next;
		free(cur);
		cur = next;
	}
	*ppList = NULL;
}
