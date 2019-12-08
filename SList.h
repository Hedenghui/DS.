#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pList);
void SListPushBack(SListNode** ppList, SLTDataType x);
void SListPushFront(SListNode** ppList, SLTDataType x);
void SListPopBack(SListNode** ppList);
void SListPopfront(SListNode** ppList);
SListNode* SListFind(SListNode* pList, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListErasaAfter(SListNode* pos);
void SListDestory(SListNode** ppList);

