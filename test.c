#include"SList.h"

void testSList()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);
	//SListPushFront(&pList, 1);
	///*SListPushFront(&pList, 2);
	//SListPushFront(&pList, 3);
	//SListPushFront(&pList, 4);*/
	//SListPrint(pList);
	///*SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPopBack(&pList);
	//SListPrint(pList);*/
	/*SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);*/
	//SListNode* ret = SListFind(pList, 3);
	//ret->data = 30;
	//SListPrint(pList);
	//SListNode*ret = SListFind(pList, 3);
	//SListInsertAfter(ret, 30);
	//SListPrint(pList);
	//SListErasaAfter(ret);
	//SListPrint(pList);
	SListDestory(&pList);
	SListPrint(pList);
}
int main()
{
	testSList();
	system("pause");
	return 0;
}
