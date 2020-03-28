#include<stdio.h>
#include<stdlib.h>
void PrintArray(int*a, int n)
{
	for (size_t i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void CountSort(int* a,int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* countArr = malloc(range*sizeof(int));
	memset(countArr, 0, sizeof(int)*range);
	//1.统计次数
	for (int j = 0; j< n; j++)
	{
		int k = a[j] - min;
		countArr[k]++;
	}
	//2.根据次数进行排序
	int h = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			a[h++] = i + min;
		}
	}
}
void TestSort()
{
	int a[] = { 2,2,99,86,57,3,6 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	TestSort();
	system("pause");
	return 0;
}