#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int* array;
	int  n;//数组空间大小
	int  front;//表示队头
	int  rear;//表示队尾
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);//引用
bool myCircularQueueIsFull(MyCircularQueue* obj);//引用
//循环队列创建
MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->array = (int*)malloc(sizeof(int)*(k + 1));
	cq->n = k + 1;//放K个数据，留一个位置
	cq->front = 0;
	cq->rear = 0;

	return cq;
}

//入队列
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
	if (myCircularQueueIsFull(obj))//前面已调用
		return false;

	obj->array[obj->rear] = value;
	obj->rear++;

	if (obj->rear == obj->n)
		obj->rear = 0;
	//obj->rear%=obj->n;

	return true;
}

//出队列
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->front++;
	if (obj->front == obj->n)
		obj->front = 0;
	return true;
}

/** Get the front item from the queue. */
//队列头元素
int myCircularQueueFront(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->array[obj->front];
}

/** Get the last item from the queue. */
//队列尾元素
int myCircularQueueRear(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	int prevRear = obj->rear - 1;

	if (obj->rear == 0)
		prevRear = obj->n - 1;
	return obj->array[prevRear];
}

/** Checks whether the circular queue is empty or not. */
//判空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
//判满
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
	int rearNext = obj->rear + 1;
	rearNext %= obj->n;

	return rearNext == obj->front;
}

//销毁队列
void myCircularQueueFree(MyCircularQueue* obj) 
{
	free(obj->array);
	free(obj);
}


int main()
{
	system("pause");
	return 0;
}