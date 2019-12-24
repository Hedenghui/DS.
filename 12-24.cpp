#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int* array;
	int  n;//����ռ��С
	int  front;//��ʾ��ͷ
	int  rear;//��ʾ��β
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);//����
bool myCircularQueueIsFull(MyCircularQueue* obj);//����
//ѭ�����д���
MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->array = (int*)malloc(sizeof(int)*(k + 1));
	cq->n = k + 1;//��K�����ݣ���һ��λ��
	cq->front = 0;
	cq->rear = 0;

	return cq;
}

//�����
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
	if (myCircularQueueIsFull(obj))//ǰ���ѵ���
		return false;

	obj->array[obj->rear] = value;
	obj->rear++;

	if (obj->rear == obj->n)
		obj->rear = 0;
	//obj->rear%=obj->n;

	return true;
}

//������
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
//����ͷԪ��
int myCircularQueueFront(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->array[obj->front];
}

/** Get the last item from the queue. */
//����βԪ��
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
//�п�
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
//����
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
	int rearNext = obj->rear + 1;
	rearNext %= obj->n;

	return rearNext == obj->front;
}

//���ٶ���
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