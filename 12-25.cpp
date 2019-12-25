//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//
//Ҫ�󷵻��������������
#include<stdio.h>
#include<stdlib.h>
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		//1.�����ڵ㣬������ԭ�ڵ�ĺ���
		Node*cur = head;
		while (cur)
		{
			Node*next = cur->next;
			Node*copyNode = (Node*)malloc(sizeof(Node));
			copyNode->val = cur->val;
			copyNode->next = NULL;
			copyNode->random = NULL;

			cur->next = copyNode;
			copyNode->next = next;

			cur = next;
		}

		//�ÿ����ڵ�random
		cur = head;
		while (cur)
		{
			Node*copyNode = cur->next;
			if (cur->random)
				copyNode->random = cur->random->next;
			else
				copyNode->random = NULL;
			cur = cur->next->next;
		}
		//3.��
		Node* copyHead = NULL, *copyTail = NULL;//����ͷ
		cur = head;
		while (cur)
		{
			Node*copyNode = cur->next;
			Node*next = copyNode->next;

			//β�嵽��������
			if (copyTail == NULL)
			{
				copyHead = copyTail = copyNode;
			}
			else
			{
				copyTail->next = copyNode;
				copyTail = copyNode;

			}
			cur->next = next;//��ԭ����������

			cur = next;
		}
		return copyHead;
	}
};


int main()
{
	system("pause");
	return 0;
}