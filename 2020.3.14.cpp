//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。
//s 也可以看做它自身的一棵子树。

#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};
bool a_gain(struct TreeNode* s, struct TreeNode* t) //判同
{
	if (s == NULL&&t == NULL) return true;
	if (s == NULL || t == NULL) return false;
	if (s->val != t->val) return false;
	return a_gain(s->left, t->left) && a_gain(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL&&t != NULL) return false;
	return a_gain(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);  //判同 判左 判右
}
int main()
{
	system("pause");
	return 0;
}