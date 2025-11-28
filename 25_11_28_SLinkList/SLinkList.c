#define _CRT_SECURE_NO_WARNINGS 1

#include"SLinkList.h"

//打印链表
void SLNodePrint(SLNode* phead)
{
	//记录当前节点
	SLNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//申请新节点
SLNode* SLNodeBuyNode(SLinkListDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
}

//尾插
void SLNodePushBack(SLNode** pphead, SLinkListDataType x)
{
	assert(pphead);
	//如果为空链表
	SLNode* newnode = SLNodeBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//当前节点
		SLNode* pcur = *pphead;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

//头插
void SLNodePushFront(SLNode** pphead, SLinkListDataType x)
{
	assert(pphead);
	SLNode* newnode = SLNodeBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SLNodePopBack(SLNode** pphead)
{
	assert(pphead && *pphead);
	//链表只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//链表有多个节点
	{
		//首先找到尾节点，释放尾节点空间
		//记录尾节点前一节点作为新的尾节点
		SLNode* ptail = *pphead;
		SLNode* newtail = *pphead;

		while (ptail->next)
		{
			newtail = ptail;
			ptail = ptail->next;
		}

		free(ptail);
		ptail = NULL;
		//尾节点已经释放，新的尾节点next指针空间已经不可用
		newtail->next = NULL;
	}
}

//头删
void SLNodePopFront(SLNode** pphead)
{
	assert(pphead && *pphead);
	//释放当前节点，更新新的头节点地址
	SLNode* newhead = (*pphead)->next;
	free(*pphead);
	*pphead = newhead;
}

//按data查找
SLNode* SLNodeFind(SLNode* phead, SLinkListDataType x)
{
	assert(phead);
	SLNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

//指定位置前插入
void SLNodeInsert(SLNode** pphead, SLNode* pos, SLinkListDataType x)
{
	assert(pphead && *pphead && pos);
	SLNode* newnode = SLNodeBuyNode(x);
	if (*pphead == pos)//说明是头插
	{
		SLNodePushFront(pphead, x);
	}
	else
	{
		//找到pos前一节点位置
		SLNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
		newnode->next = pos;
	}
}

//指定位置后插入
void SLNodeInsertAfter(SLNode* pos, SLinkListDataType x)
{
	assert(pos);
	SLNode* newnode = SLNodeBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SLNodeErasw(SLNode** pphead, SLNode* pos)
{
	assert(pphead && *pphead && pos);
	if (*pphead == pos)//说明是头删
	{
		SLNodePopFront(pphead);
	}
	else
	{
		//找到pos前一节点位置
		SLNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLNodeEraseAfter(SLNode* pos)
{
	assert(pos && pos->next);
	SLNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;

}

//销毁链表
void SLNodeDestroy(SLNode** pphead)
{
	assert(pphead && *pphead);
	//销毁的节点
	SLNode* pcur = *pphead;
	while (pcur)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//链表已经全部销毁，头节点空间已经不可用
	*pphead = NULL;
}

