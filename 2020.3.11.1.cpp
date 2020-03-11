//给定一个二叉树，检查它是否是镜像对称的。

//例如，二叉树[1, 2, 2, 3, 4, 4, 3] 是对称的。

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (p == NULL||q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	return _isSymmetric(root->left, root->right);

}
int main()
{
	system("pause");
	return 0;
}