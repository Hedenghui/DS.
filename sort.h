#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void PrintArray(int*a, int n)
{
	for (size_t i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	//控制end的位置从0走到n-2
	for (int i = 0; i < n - 1; i++)
	{
		//单趟排序
		//[0，end]区间中插入tmp,依旧有序
		int end=i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void TestInsertSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//希尔排序  O(N^1.3)
void ShellSort(int*a, int n)
{
	//gap>1时为预排序          接近有序
	//gap==1时为直接插入排序   有序
	int gap = n; 
	while (gap > 1)
	{
		//间隔为gap的预排序
		gap = gap / 3 + 1;//+1保证最后一次一定是1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void TestShellSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//选择排序  O(N*N)
void SelectSort(int* a,int n)
{
	int begin = 0, end = n - 1;
	//[begin,end]选出一个最小的，选出一个最大的下标
	while (begin < end)
	{
		int mini = begin, maxi = end;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i]>a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		//修正(注意）
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
void TestSelectSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}


//堆排序
void AdjustDown(int*a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}
		//如果孩子比父亲大，交换，继续向下调整
		//2.如果孩子小于父亲，则调整结束
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int*a, int n)
{
	//排升序，建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//for (int i = 0; i<n; i++)
	//{
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void TestHeapSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//冒泡排序
void BubbleSort(int* a,int n)
{
	//单趟排序
	for (int end = n - 1; end > 0; --end)
	{
		int flag = 0;
		for (int i = 0; i < end; ++i)
		{
			if (a[i]>a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}
void TestBubbleSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//hoare法(左右指针)
int PartSort(int* a, int begin, int end)
{
	//右边做key，左边先走
	//左边做key，右边先走

	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		//begin找大
		while (begin<end&&a[begin] <=key)
		{
			++begin;
		}
		//end找小
		while (begin<end&&a[end]>=key)
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
//挖坑法
int PartSort2(int*a, int begin, int end)
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] < key)
		{
			++begin;
		}
		a[end] = a[begin];
		while (begin < end&&a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;	
}
//前后指针法
int PrevCur(int*a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = a[end];
	while (cur < end)//遇到key的位置就结束了
	{
		if (a[cur] < key&&++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
		++prev;
		Swap(&a[prev], &a[end]);
		return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int keyindex = PartSort(a, begin, end);
	//(begin,keyindex-1)  keyindex  (...)
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}
void TestQuickSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	QuickSort(a, 0,(sizeof(a) / sizeof(int)-1));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//非递归快排
#include"sortstack.h"
void QuickSortNonR(int* a, int begin, int end)
{
	//数据结构的栈来模拟递归
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int keyindex = PrevCur(a, left, right);
		if (left < keyindex)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex-1);
		}
		if (keyindex + 1 < right)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
}
void TestQuickSortNonRSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	QuickSortNonR(a, 0, (sizeof(a) / sizeof(int)-1));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//归并排序
void _MergeSort(int* a, int begin, int end, int*tmp)
{
	if (begin >= end)
	{
		return;
	}
	//先划分
	int mid = (begin + end) >> 1;
	//[begin,mid] [mid+1,end] //无序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//[begin,mid] [mid+1,end] //有序
	
	//归并两段有序区间
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	else
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	//将归并到tmp的数据归并到原数据
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));	
}
void MergeSort(int* a, int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1,tmp);
}
void TestMergeSort()
{
	int a[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}