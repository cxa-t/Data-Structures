#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkStack.h"

// 初始化链栈
void LSTInit(LST* plst)
{
    // 断言检查指针
    assert(plst);
    // 栈顶指针置空
    plst->top = NULL;
    // 元素个数置零
    plst->size = 0;
}

// 销毁链栈
void LSTDestroy(LST* plst)
{
    assert(plst);

    // 遍历链表，依次释放所有节点内存
    LSNode* current = plst->top;
    LSNode* next;

    while (current)
    {
        next = current->next; // 记录下一个节点
        free(current);        // 释放当前节点
        current = next;       // 移动到下一个节点
    }

    // 重置栈状态
    plst->top = NULL;
    plst->size = 0;
}

// 入栈 (Push) - 时间复杂度 O(1)
// 相当于单链表的头插法
void LSTPush(LST* plst, LSTDataType x)
{
    assert(plst);

    // 1. 创建新节点
    LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
    if (newNode == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }

    // 2. 填充数据
    newNode->data = x;

    // 3. 执行头插操作：
    // 新节点的 next 指向原栈顶节点
    newNode->next = plst->top;

    // 4. 更新栈顶指针：
    // 栈顶指针指向新节点
    plst->top = newNode;

    // 5. 更新栈大小
    plst->size++;
}

// 出栈 (Pop) - 时间复杂度 O(1)
// 相当于单链表的头删除法
void LSTPop(LST* plst)
{
    // 断言：栈指针非空，且栈非空 (plst->top != NULL)
    assert(plst && !LSTIsEmpty(plst));

    // 1. 暂存原栈顶节点（待删除的节点）
    LSNode* tmp = plst->top;

    // 2. 更新栈顶指针：
    // 栈顶指针指向原栈顶节点的下一个节点
    plst->top = plst->top->next;

    // 3. 释放原栈顶节点的内存
    free(tmp);
    tmp = NULL; // 避免野指针

    // 4. 更新栈大小
    plst->size--;
}

// 获取栈顶元素 - 时间复杂度 O(1)
LSTDataType LSTTop(LST* plst)
{
    // 断言：栈指针非空，且栈非空
    assert(plst && !LSTIsEmpty(plst));

    // 返回栈顶节点的数据域
    return plst->top->data;
}

// 判断栈是否为空 - 时间复杂度 O(1)
bool LSTIsEmpty(LST* plst)
{
    assert(plst);
    // 栈顶指针为 NULL 则栈为空
    return plst->top == NULL;
}

// 获取元素个数 - 时间复杂度 O(1)
int LSTSize(LST* plst)
{
    assert(plst);
    return plst->size;
}