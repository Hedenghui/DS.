//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为        We Are Happy.
//则经过替换之后的字符串为We%20Are%20Happy。
#include<stdio.h>
#include<stdlib.h>
void ReplaceSpace(char*str, int length)
{
	int Space_num = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			Space_num++;
		}
	}
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			Space_num--;
			str[i + Space_num * 2] = '%';
			str[i + Space_num * 2 + 1] = '2';
			str[i + Space_num * 2 + 2] = '0';
		}
		else
		{
			str[i + Space_num * 2] = str[i];
		}
	}
}
int main()
{
	char str[13] = "we are happy";
	ReplaceSpace(str, 13);
	printf("%s\n", str);
	system("pause");
	return 0;
}