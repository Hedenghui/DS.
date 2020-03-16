//编一个程序，读入用户输入的一串先序遍历字符串，
//根据此字符串建立一个二叉树（以指针方式存储）。
//例如如下的先序遍历字符串：
//ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
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

	//根据先序遍历的顺序重建二叉树
	int i = 0;
	TreeNode* root = ReBuild(a, &i);

	//中序输出
	Inorder(root);
	return 0;
}