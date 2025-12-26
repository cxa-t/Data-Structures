#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//初始化和销毁
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SLPrint(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("NULL");
	}
	else
	{
		for (int i = 0; i < ps->size; i++)
		{
			printf("%d ", ps->a[i]);
		}
		puts(" ");
	}
}
//扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? INIT_CAPACITY : (2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

//头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size++] = x;
}
void SLPopBack(SL* ps)
{
	assert(ps && ps->size > 0);
	ps->size--;
}
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SLPopFront(SL* ps)
{
	assert(ps);
	for (int i = 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}


//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

