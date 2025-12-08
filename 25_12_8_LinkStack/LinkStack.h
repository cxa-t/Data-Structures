#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// 栈中存储的数据类型
typedef int LSTDataType;

// 链栈的节点结构
typedef struct LinkStackNode
{
    LSTDataType data;             // 数据域
    struct LinkStackNode* next;   // 指针域，指向下一个节点
}LSNode;

// 链栈的结构体（仅包含栈顶指针）
typedef struct LinkStack
{
    LSNode* top;                  // 栈顶指针，指向栈顶元素（链表的第一个节点）
    int size;                     // 记录栈中元素个数
}LST;


// --- 链栈 ADT 基本操作声明 ---

// 初始化
void LSTInit(LST* plst);

// 销毁栈
void LSTDestroy(LST* plst);

// 入栈 (头插法)
void LSTPush(LST* plst, LSTDataType x);

// 出栈 (头删除法)
void LSTPop(LST* plst);

// 获取栈顶元素
LSTDataType LSTTop(LST* plst);

// 判断栈是否为空
bool LSTIsEmpty(LST* plst);

// 获取元素个数
int LSTSize(LST* plst);
