#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 栈中存储的数据类型
typedef int SSTDataType;
// 共享栈结构体
typedef struct SharedStack
{
    SSTDataType* a;  // 指向存储数据的数组
    int capacity;    // 数组的总容量
    int top1;        // 栈 1 的栈顶指针 (从 0 开始向右增长)
    int top2;        // 栈 2 的栈顶指针 (从 capacity-1 开始向左增长)
}SST;

// 初始化共享栈
void SSTInit(SST* psst, int totalCapacity);

// 销毁共享栈
void SSTDestroy(SST* psst);

// 入栈操作 (stackID: 1 或 2)
void SSTPush(SST* psst, int stackID, SSTDataType x);

// 出栈操作 (stackID: 1 或 2)
void SSTPop(SST* psst, int stackID);

// 获取栈顶元素 (stackID: 1 或 2)
SSTDataType SSTTop(SST* psst, int stackID);

// 判断栈是否为空 (stackID: 1 或 2)
bool SSTIsEmpty(SST* psst, int stackID);

// 检查共享栈是否满
bool SSTIsFull(SST* psst);