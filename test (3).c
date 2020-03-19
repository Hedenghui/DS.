#include"BinaryTree.h"


int main()
{
	char a[100] ="abc##de#g##f###";

	int i = 0;
	BTNode* root=BinaryTreeCreate(a,&i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	BinaryTreeComplete(root);
	BinaryTreeDestory(root);
	system("pause");
	return 0;
}
