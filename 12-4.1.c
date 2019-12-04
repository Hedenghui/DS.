//合并两个有序数组
#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1;//1 2 3
	int end2 = n - 1;//2 5 6
	int end = m + n - 1;//1 2 2 3 5 6
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1]>nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
	for (int i = 0; i <=m+n-1; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
}
int main()
{
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	merge(nums1, sizeof(nums1) / sizeof(int), 3, nums2, sizeof(nums2) / sizeof(int), 3);
	system("pause");
	return 0;
}