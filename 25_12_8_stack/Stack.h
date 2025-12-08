#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;


//初始化
void STInit(ST* pst);
//销毁栈
void STDestroy(ST* pst);

//入栈
void STPush(ST* pst, STDataType x);
//出栈
void STPop(ST* pst);

//获取栈顶元素
STDataType STTop(ST* pst);
//获取元素个数
int STSize(ST* pst);

//判断栈是否为空
bool STIsEmpty(ST* pst);




