#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _preorerTraversal(struct TreeNode* root, int* retA, int* pi)
{
	if (root == NULL)
	{
		return;
	}


	_preorerTraversal(root->left, retA, pi);
	retA[(*pi)++] = root->val;
	_preorerTraversal(root->right, retA, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* retA = malloc(sizeof(int)*size);
	*returnSize = size;
	int i = 0;
	_preorerTraversal(root, retA, &i);
	return retA;
}
int main()
{
	system("pause");
	return 0;
}