//��ջʵ�ֶ���

//ʹ��ջʵ�ֶ��е����в�����
//
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;    //ջ��
	int _capacity;   //����
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
//��ջ
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
//��ջ
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	--ps->_top;
}
//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//���ջ�Ƿ�Ϊ��,���Ϊ�շ��ط��㣨1���������Ϊ�շ��أ�0����
int StackEmpty(Stack*ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}



typedef struct {
	Stack pushst;//��ջ
	Stack popst;//����ջ�����������ݵ�ջ
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue*q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushst);
	StackInit(&q->popst);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {//��ջ
	StackPush(&obj->pushst, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {//��ջ

	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));//��pushst��TOPֵ��popst��ֵ
			StackPop(&obj->pushst);//��pushst��TOPֵ��ջ
		}
	}
	int front = StackTop(&obj->popst);
	StackPop(&obj->popst);

	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {//ȡ��ͷ����
	if (StackEmpty(&obj->popst))
	{
		while (!StackEmpty(&obj->pushst))
		{
			StackPush(&obj->popst, StackTop(&obj->pushst));//��pushst��TOPֵ��popst��ֵ
			StackPop(&obj->pushst);//��pushst��TOPֵ��ջ
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