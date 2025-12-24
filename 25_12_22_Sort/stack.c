#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void STInit(ST* pst)
{
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)realloc(pst->a,sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		pst->capacity = newcapacity;
		pst->a = tmp;
	}

	pst->a[pst->top++] = x;
}
void STPop(ST* pst)
{
	assert(pst && pst->top>0);
	pst->top--;
}

bool isEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

STDataType STTop(ST* pst)
{
	assert(pst && pst->top > 0);
	return pst->a[pst->top - 1];
}
