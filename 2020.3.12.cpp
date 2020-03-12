//给定一个二叉树，判断它是否是高度平衡的二叉树。

//本题中，一棵高度平衡二叉树定义为：

//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int Depth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}
int main()
{
	system("pause");
	return 0;
}