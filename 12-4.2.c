#include<stdio.h>
#include<stdlib.h>
void reverse(int*num, int first, int last)
{
	int temp;
	while (first<last)
	{
		temp = num[first];
		num[first] = num[last];
		num[last] = temp;
		first++;
		last--;
	}
}
void rotate(int* nums, int numsSize, int k){
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}
int main()
{
	int nums[] = {1,2,3,4,5,6,7};
	rotate(nums, sizeof(nums) / sizeof(int), 3);
	system("pause");
	return 0;
}