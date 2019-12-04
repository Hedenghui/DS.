#include<stdio.h>
#include<stdlib.h>
int removeDuplicates(int* nums, int numsSize)
{
	int dst = 0;
	int src1 = 0;
	int src2 = 1;
	while (src2 < numsSize)
	{
		nums[dst] = nums[src1];
		++dst;
		if (nums[src1] != nums[src2])
		{
			src1++;
			src2++;
		}
		else
		{
			while (src2 < numsSize&&nums[src1] == nums[src2])
			{
				src2++;
			}
			src1 = src2;
			src2++;
		}
	}
	if (src1 < numsSize)
	{
		nums[dst] = nums[src1];
	}
	for (int i = 0; i <= dst; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return dst;
}
int main()
{
	int nums[] = {0,0,1,1,1,2,2,3,3,4};
	removeDuplicates(nums, sizeof(nums) / sizeof(int));
	system("pause");
	return 0;
}