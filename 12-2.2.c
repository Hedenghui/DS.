//移除元素
//给定一个数组 nums 和一个值 val
//你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间
//你必须在原地修改输入数组并时间复杂度O(n),空间复杂度0(1)
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
/*给定 nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int removeElement(int* nums, int numsSize, int val){
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	printf("移除后的元素：");
	for (int i = 0; i < dst; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	return dst;
}
int main()
{
	int nums[] = {0,1,2,2,3,0,4,2};
	int val=2;
	removeElement(nums, sizeof(nums) / sizeof(int), val);
	system("pause");
	return 0;
}
