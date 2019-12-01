#include"SeqList.h"
void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListPushFrout(&s, 1);
	SeqListPushFrout(&s, 2);
	SeqListPushFrout(&s, 3);
	SeqListPushFrout(&s, 4);
	SeqListPushFrout(&s, 5);
	SeqListPrint(&s);
	SeqListPopFrout(&s);
	SeqListPopFrout(&s);
	SeqListPopFrout(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 20);
	SeqListPrint(&s);
	SeqListErase(&s, 2, 20);
	SeqListPrint(&s);
}
int main()
{
	TestSeqList();
	system("pause");
	return 0;
}