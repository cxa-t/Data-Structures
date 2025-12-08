#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//初始化
void STInit(ST* pst)
{
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;//top指向栈顶元素下一个位置
}
//销毁栈
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

//入栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top)
	{
		int newcapacity = (pst->capacity == 0) ? 4 : (2 * pst->capacity);
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top++] = x;
}

//出栈
void STPop(ST* pst)
{
	assert(pst && pst->top > 0);
	pst->top--;
}

//获取栈顶元素
STDataType STTop(ST* pst)
{
	assert(pst && pst->top > 0);
	return pst->a[pst->top - 1];
}
//获取元素个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

//判断栈是否为空
bool STIsEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
