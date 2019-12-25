//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//
//要求返回这个链表的深拷贝。
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
		//1.拷贝节点，并插入原节点的后面
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

		//置拷贝节点random
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
		//3.拆
		Node* copyHead = NULL, *copyTail = NULL;//不带头
		cur = head;
		while (cur)
		{
			Node*copyNode = cur->next;
			Node*next = copyNode->next;

			//尾插到拷贝链表
			if (copyTail == NULL)
			{
				copyHead = copyTail = copyNode;
			}
			else
			{
				copyTail->next = copyNode;
				copyTail = copyNode;

			}
			cur->next = next;//将原链表返回正常

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