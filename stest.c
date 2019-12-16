#include<stdio.h>
#include<stdlib.h>
#include"List.h"
void TestList1()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);
	ListPopBack(list);
	ListPopBack(list);
	ListPopBack(list);
	ListPopBack(list);
	ListPrint(list);
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPrint(list);
	ListPopFront(list);
	ListPopFront(list);
	ListPrint(list);
	ListDestory(list);
	ListPrint(list);
}
int main()
{
	TestList1();
	system("pause");
	return 0;
}