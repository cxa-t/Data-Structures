#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 队尾插入
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
// 队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

// 取队头和队尾的数据
QDataType QueueFront(Queue* pq)
{
	assert(pq && pq->phead);
	return pq->phead->val;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->ptail);
	return pq->ptail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}

