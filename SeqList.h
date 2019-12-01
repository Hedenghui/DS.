#pragma once//保证头文件只被包含一次
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType *a;//指向一个数组
	size_t size;//size_t == unsigned int//这个数组有多少个有效数据
	size_t capacity;//容量
}SeqList;
//对数据的管理  增删查改
void SeqListInit(SeqList *ps);
void SeqListDestory(SeqList *ps);
void SeqListPrint(SeqList* ps);//打印
void SeqListPushBack(SeqList* ps,SLDateType x);//尾插
void SeqListPushFrout(SeqList* ps,SLDateType x);//头插
void SeqListPopFrout(SeqList* ps);//头删
void SeqListPopBack(SeqList* ps);//尾删
int SeqListFind(SeqList*psl, SLDateType x);//顺序表查找
void SeqListInsert(SeqList*psl, size_t pos, SLDateType x);//顺序表在pos位置插入x
void SeqListErase(SeqList* psl, size_t pos);//顺序表删除