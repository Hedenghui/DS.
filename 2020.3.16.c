//��һ�����򣬶����û������һ����������ַ�����
//���ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
//�������µ���������ַ�����
//ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ������������������������������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
	char _ch;
	struct TreeNode* _left;
	struct TreeNode* _right;
}TreeNode;

TreeNode*  ReBuild(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->_ch = a[*pi];
		++(*pi);
		root->_left = ReBuild(a, pi);
		++(*pi);
		root->_right = ReBuild(a, pi);
		return root;
	}
}
void Inorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->_left);
	printf("%c ", root->_ch);
	Inorder(root->_right);
}

int main()
{
	char a[100];
	scanf("%s", a);

	//�������������˳���ؽ�������
	int i = 0;
	TreeNode* root = ReBuild(a, &i);

	//�������
	Inorder(root);
	return 0;
}