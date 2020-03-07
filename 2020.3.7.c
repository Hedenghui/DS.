//给定一个二叉树，找出其最大深度。

//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
#include<stdio.h>
#include<stdlib.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };



int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int main()
{
	system("pause");
	return 0;
}