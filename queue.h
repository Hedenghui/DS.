#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode*_front;
	struct QueueNode*_back;
}Queue;

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

//队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = data;
	newNode->_next = NULL;
	if (q->_back == NULL)
	{
		q->_front = q->_back = newNode;
	}
	else
	{
		q->_back->_next = newNode;
		q->_back = newNode;
	}
}

//队头出队列
void QueuePop(Queue*q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;//尾也需要处理，否则就是野指针问题
	}
	else
	{
		QueueNode*cur = q->_front->_next;
		free(q->_front);
		q->_front = cur;
	}
}
//获取队列队头元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

//获取队列队尾元素
QDataType QueueBack(Queue*q)
{
	assert(q);
	return q->_back->_data;
}

//获取队列中有效元素个数
int QueueSize(Queue*q)
{
	int n = 0;
	QueueNode*cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}

//检测队列是否为空，如果为空返回非零结果，如果非空返回0；
int QueueEmpty(Queue*q)
{
	return q->_front == NULL?1:0;
}

//销毁队列
void QueueDestory(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_back = NULL;
}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}