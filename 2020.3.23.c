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
void _postorderTraversal(struct TreeNode* root, int* retA, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	_postorderTraversal(root->left, retA, pi);
	_postorderTraversal(root->right, retA, pi);
	retA[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = TreeSize(root);
	int* retA = malloc(sizeof(int)*size);
	*returnSize = size;
	int i = 0;
	_postorderTraversal(root, retA, &i);
	return retA;
}
int main()
{
	system("pause");
	return 0;
}