#include"Heap.h"

void Swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
//小堆
//条件是左右子树都是小堆
void AdjustDown(HpDataType* a, size_t n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		//找出小的孩子
		if (child+1< n&&a[child + 1] < a[child])
		{
			++child;
		}
		//1.孩子比父亲小
		//2.孩子比父亲大
		if (a[parent]>a[child])
		{
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp,HpDataType* a, size_t n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
void HeapPush(Heap*hp, HpDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a,sizeof(HpDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整，调成堆
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
	hp->_a = NULL;
}
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;

	AdjustDown(hp->_a, hp->_size, 0);
}
HpDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}


//topK问题
// 最大十个数
void PrintTopK(int* a, int n, int k)
{
	// k个数的小堆
	Heap hp;
	HeapCreate(&hp, a, k);

	for (int i = k; i < n; ++i)
	{
		// 比堆顶的数据要大，就替代它
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[15] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 30;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[760] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}