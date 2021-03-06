//用栈实现队列

//使用栈实现队列的下列操作：
//
//push(x) --将一个元素放入队列的尾部。
//pop() --从队列首部移除元素。
//peek() --返回队列首部的元素。
//empty() --返回队列是否为空。

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;    //栈顶
	int _capacity;   //容量
}Stack;

//初始化栈
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//入栈
void StackPush(Stack*ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	--ps->_top;
}
//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//检测栈是否为空,如果为空返回非零（1），如果不为空返回（0）；
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
//销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}



typedef struct {
	Stack pushst;//入栈
	Stack popst;//从入栈出来保存数据的栈
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue*q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushst);
	StackInit(&q->popst);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {//入栈
	StackPush(&obj->pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {//出栈

	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));//将pushst的TOP值给popst入值
			StackPop(&obj->pushst);//将pushst的TOP值出栈
		}
	}
	int front = StackTop(&obj->popst);
	StackPop(&obj->popst);

	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {//取队头数据
	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));//将pushst的TOP值给popst入值
			StackPop(&obj->pushst);//将pushst的TOP值出栈
		}
	}

	return StackTop(&obj->popst);

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushst) && StackEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushst);
	StackDestroy(&obj->popst);
	free(obj);
}
int main()
{
	system("pause");
	return 0;
}