//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���ַ���Ϊ        We Are Happy.
//�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
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