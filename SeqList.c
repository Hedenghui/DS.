#include"SeqList.h"

void SeqListInit(SeqList *ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)//尾插
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a,newcapacity*sizeof(SLDateType));
		//多少个数据*每个数据大小，不加这个sizeof...就越界了
		ps->capacity = newcapacity;
	}
	ps->a[ps->size] = x;//0 1 2 3 4 5 6 7 8 9 x  //ps->size=x
	ps->size++;
}
void SeqListPushFrout(SeqList* ps, SLDateType x)//头插
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity*sizeof(SLDateType));
		//多少个数据*每个数据大小，不加这个sizeof...就越界了
		ps->capacity = newcapacity;
	}
	size_t end = ps->size;//end指向5后面的位置
	while (end>0)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	++ps->size;
}
void SeqListPopFrout(SeqList* ps)//头删法
{
	assert(ps);
	size_t start = 0;               //       ps->size-1
	while (start < ps->size-1)//例如 1 2 3 4     5     ps->size
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	--ps->size;
}
void SeqListPopBack(SeqList* ps)//尾删法
{
	assert(ps);
	ps->size--;
}
int SeqListFind(SeqList*ps, SLDateType x)//顺序表查找
{
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return 1;
		}
	}
	return -1;
}
void SeqListInsert(SeqList*ps, size_t pos, SLDateType x)//顺序表在pos位置插入x
{
	assert(ps);
	assert(pos < ps->size);
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity*sizeof(SLDateType));
		//多少个数据*每个数据大小，不加这个sizeof...就越界了
		ps->capacity = newcapacity;
	}
	int  end = ps->size - 1;
	while (end >=(int)pos)//pos是size_t 无符号，当在0位置加时会死循环
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)//顺序表删除pos位置的值
{
	assert(ps&&pos<ps->size);
	size_t start = pos;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}