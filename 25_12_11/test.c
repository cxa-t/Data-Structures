#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// 初始化和销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
}
// 入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top++] = x;
}
void STPop(ST* pst)
{
	assert(pst && pst->top > 0);
	pst->top--;
}

// 取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst && pst->top > 0);
	return pst->a[(pst->top) - 1];
}

// 判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
// 获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}


typedef struct MyQueue 
{
	ST s1;//push
	ST s2;//pop
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	if (obj == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	STInit(&(obj->s1));
	STInit(&(obj->s2));
	return obj;
}

bool myQueueEmpty(MyQueue* obj)
{
	return (STEmpty(&(obj->s1)) && STEmpty(&(obj->s2)));
}

void myQueuePush(MyQueue* obj, int x) 
{
	assert(obj);
	STPush(&(obj->s1),x);
}

int myQueuePeek(MyQueue* obj)
{
	assert(obj);
	if (STEmpty(&(obj->s2)))
	{
		//倒数据
		int x = STSize(&(obj->s1));
		while (x--)
		{
			STPush(&(obj->s2), STTop(&(obj->s1)));
			STPop(&(obj->s1));
		}
	}
	return STTop(&(obj->s2));
}

int myQueuePop(MyQueue* obj) 
{
	assert(obj);
	int ret = myQueuePeek(obj);
	STPop(&(obj->s2));
	return ret;
}



void myQueueFree(MyQueue* obj) 
{
	STDestroy(&(obj->s1));
	STDestroy(&(obj->s2));
	free(obj);
}


int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	int param_3 = myQueuePeek(obj);
	printf("%d\n", param_3);
	return 0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
