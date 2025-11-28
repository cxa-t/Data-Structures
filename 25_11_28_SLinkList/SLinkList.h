#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//单链表数据类型
typedef int SLinkListDataType;
//单链表结构体定义
typedef struct SLinkList
{
	SLinkListDataType data;
	struct SLinkList* next;
}SLNode;


//打印链表
void SLNodePrint(SLNode* phead);
//尾插
void SLNodePushBack(SLNode** pphead, SLinkListDataType x);
//头插
void SLNodePushFront(SLNode** pphead, SLinkListDataType x);
//尾删
void SLNodePopBack(SLNode** pphead);
//头删
void SLNodePopFront(SLNode** pphead);
//查找
SLNode* SLNodeFind(SLNode* phead, SLinkListDataType x);
//指定位置前插入
void SLNodeInsert(SLNode** pphead, SLNode* pos, SLinkListDataType x);
//指定位置后插入
void SLNodeInsertAfter(SLNode* pos, SLinkListDataType x);
//删除pos节点
void SLNodeErasw(SLNode** pphead, SLNode* pos);
//删除pos之后的节点
void SLNodeEraseAfter(SLNode* pos);
//销毁链表
void SLNodeDestroy(SLNode** pphead);
