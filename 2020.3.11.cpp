//������������������дһ�����������������Ƿ���ͬ��

//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
int main()
{
	system("pause");
	return 0;
}