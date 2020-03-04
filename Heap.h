#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;
void AdjustDown(HpDataType* a, size_t n, int root);
void HeapCreate(Heap* hp, HpDataType* a, size_t n);
void HeapPush(Heap*hp, HpDataType x);
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);
void HeapPrint(Heap* hp);
