#include<stdio.h>
#include<stdlib.h>
void severse(int* nums, int begin, int end)
{
	int tmd;
	while (begin < end)
	{
		tmd = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmd;
		begin++;
		end--;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int *returnSize)
{
	int*addRet = (int*)malloc(10001 * sizeof(int));
	int reti = 0;
	int ai = ASize - 1;
	int next = 0;
	while (ai >= 0 ||K > 0)
	{
		int x1 = 0;
		if (ai >= 0)
		{
			x1 = A[ai];
			--ai;
		}
		int x2 = 0;
		if (K > 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		int ret = x1 + x2 + next;
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		addRet[reti++] = ret;
	}
	if (next == 1)
	{
		addRet[reti++] = 1;
	}
	severse(addRet, 0, reti - 1);
	for (int i = 0; i < reti; i++)
	{
		printf("%d ", addRet[i]);
	}
	printf("\n");
	return addRet;
}
int main()
{
	int A[] = { 9, 9, 9, 9, 9, 9, 9, 9 };
	int K = 1;
	int n;
    addToArrayForm(A, sizeof(A) / sizeof(int), K,&n);
	system("pause");
	return 0;
}