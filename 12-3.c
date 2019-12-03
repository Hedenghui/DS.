#include<stdio.h>
#include<stdlib.h>
int removeDuplicates(int* nums, int numsSize){
	int dst = 0;
	int src = 0;
	for (src = 1; src<numsSize; src++)
	{
		if (nums[src] != nums[dst])
		{
			nums[++dst] = nums[src];
		}//                              dst    src
	}//0, 0, 1, 1, 1, 2, 2, 3, 3, 4       0      1
     //0, 1, 1, 1, 1, 2, 2, 3, 3, 4       1      2
	 //0, 1, 2, 1, 1, 2, 2, 3, 3, 4       2      5
	 //0, 1, 2, 3, 1, 2, 2, 3, 3, 4       3      7
	 //0, 1, 2, 3, 4, 2, 2, 3, 3, 4       4      9
	printf("ÒÆ³ýºóµÄÔªËØ£º");
	for (int i = 0; i <=dst; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return dst+1;
}
int main()
{
	int nums[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	removeDuplicates(nums, sizeof(nums) / sizeof(int));
	system("pause");
	return 0;
}