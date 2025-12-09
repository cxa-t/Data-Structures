#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
//销毁队列
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

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	newNode->next = NULL;
	newNode->val = x;

	if (pq->phead == NULL)
	{
		pq->phead = newNode;
		pq->ptail = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
	pq->size++;
}
//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	//只有一个节点
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
//取出队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq && pq->phead);
	return pq->phead->val;
}
//取出队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->ptail);
	return pq->ptail->val;
}
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}
//队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
