#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"

SLTNode* BuyNode(SLTDataType x)
{
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//头部插入删除/尾部插入删除
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* tmp = BuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = tmp;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = tmp;
	}
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* tmp = BuyNode(x);

	tmp->next = *pphead;
	*pphead = tmp;
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* cur = *pphead;
	*pphead = cur->next;
	free(cur);
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	if (*pphead == pos)
		SLTPushFront(pphead, x);
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
			cur = cur->next;
		SLTNode* tmp = BuyNode(x);
		tmp->next = pos;
		cur->next = tmp;
	}
}
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == *pphead)
		SLTPopFront(pphead);
	else
	{
		SLTNode* cur = *pphead;
		while (cur && cur->next != pos)
			cur = cur->next;

		cur->next = pos->next;
		free(pos);
	}
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* tmp = BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	SLTNode* del = pos->next;
	if (del != NULL)
		pos->next = del->next;
	else
		pos->next = NULL;
	free(del);
	del = NULL;
}
//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}