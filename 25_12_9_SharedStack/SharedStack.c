#define _CRT_SECURE_NO_WARNINGS 1

#include "SharedStack.h"

// 初始化共享栈
void SSTInit(SST* psst, int totalCapacity)
{
    assert(psst);
    if (totalCapacity <= 0)
    {
        totalCapacity = 2;
    }

    // 分配数组内存
    psst->a = (SSTDataType*)malloc(sizeof(SSTDataType) * totalCapacity);
    if (psst->a == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }

    psst->capacity = totalCapacity;

    // 【关键】初始化栈顶指针：
    // 栈 1 (top1) 指向栈 1 栈顶元素，栈空时为 -1
    psst->top1 = -1;
    // 栈 2 (top2) 指向栈 2 栈顶元素，栈空时为 capacity (数组越界后的第一个位置)
    psst->top2 = totalCapacity;
}

// 销毁共享栈
void SSTDestroy(SST* psst)
{
    assert(psst);
    if (psst->a)
    {
        free(psst->a);
        psst->a = NULL;
    }
    psst->capacity = 0;
    psst->top1 = -1;
    psst->top2 = 0;
}

// 检查共享栈是否满
bool SSTIsFull(SST* psst)
{
    assert(psst);
    // 【关键】栈满条件：栈 1 的栈顶指针紧挨着栈 2 的栈顶指针
    // 即 top1 的下一个位置 (top1 + 1) 等于 top2 的位置
    return (psst->top1 + 1 == psst->top2);
}

// 判断栈是否为空 (stackID: 1 或 2)
bool SSTIsEmpty(SST* psst, int stackID)
{
    assert(psst);
    if (stackID == 1)
    {
        return psst->top1 == -1;
    }
    else if (stackID == 2)
    {
        return psst->top2 == psst->capacity;
    }
    // 错误处理... (此处省略，假定调用正确)
    return false;
}

// 入栈操作 (Push)
void SSTPush(SST* psst, int stackID, SSTDataType x)
{
    assert(psst);

    // 检查共享栈是否已满
    if (SSTIsFull(psst))
    {
        fprintf(stderr, "Error: Shared Stack is Full.\n");
        return;
    }

    if (stackID == 1)
    {
        // 【栈 1 入栈】：top1 增大 (向右移动)
        psst->top1++;
        psst->a[psst->top1] = x;
    }
    else if (stackID == 2)
    {
        // 【栈 2 入栈】：top2 减小 (向左移动)
        psst->top2--;
        psst->a[psst->top2] = x;
    }
}

// 出栈操作 (Pop)
void SSTPop(SST* psst, int stackID)
{
    assert(psst);

    if (stackID == 1)
    {
        if (SSTIsEmpty(psst, 1))
        {
            fprintf(stderr, "Error: Stack 1 is Empty, cannot pop.\n");
            return;
        }
        // 【栈 1 出栈】：top1 减小 (向左移动)
        psst->top1--;
    }
    else if (stackID == 2)
    {
        if (SSTIsEmpty(psst, 2))
        {
            fprintf(stderr, "Error: Stack 2 is Empty, cannot pop.\n");
            return;
        }
        // 【栈 2 出栈】：top2 增大 (向右移动)
        psst->top2++;
    }
}

// 获取栈顶元素 (Top)
SSTDataType SSTTop(SST* psst, int stackID)
{
    assert(psst);

    if (stackID == 1)
    {
        if (SSTIsEmpty(psst, 1))
        {
            fprintf(stderr, "Error: Stack 1 is Empty.\n");
            exit(-1);
        }
        // 栈 1 栈顶元素位于 top1 处
        return psst->a[psst->top1];
    }
    else if (stackID == 2)
    {
        if (SSTIsEmpty(psst, 2))
        {
            fprintf(stderr, "Error: Stack 2 is Empty.\n");
            exit(-1);
        }
        // 栈 2 栈顶元素位于 top2 处
        return psst->a[psst->top2];
    }
    
    return (SSTDataType)-1;
}