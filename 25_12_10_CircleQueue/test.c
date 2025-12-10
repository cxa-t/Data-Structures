#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

////Ñ­»·¶ÓÁÐ
//typedef struct
//{
//	int* a;
//	int head;
//	int tail;
//	int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	obj->k = k;
//	obj->a = (int*)malloc(sizeof(int) * (k + 1));
//	obj->head = obj->tail = 0;
//	return obj;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//	assert(obj);
//	return obj->head == obj->tail;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//	assert(obj);
//	int rear = (obj->tail + 1) % (obj->k + 1);
//	return rear == obj->head;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//	if (myCircularQueueIsFull(obj))
//		return false;
//	obj->a[obj->tail] = value;
//	obj->tail = (obj->tail + 1) % (obj->k + 1);
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return false;
//	obj->head = (obj->head + 1) % (obj->k + 1);
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//	assert(obj);
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	else
//		return obj->a[obj->head];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//	assert(obj);
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	else
//		return obj->a[(obj->tail + obj->k) % (obj->k + 1)];
//}
//
//
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//	assert(obj);
//	free(obj->a);
//	free(obj);
//}
//
///**
// * Your MyCircularQueue struct will be instantiated and called as such:
// * MyCircularQueue* obj = myCircularQueueCreate(k);
// * bool param_1 = myCircularQueueEnQueue(obj, value);
//
// * bool param_2 = myCircularQueueDeQueue(obj);
//
// * int param_3 = myCircularQueueFront(obj);
//
// * int param_4 = myCircularQueueRear(obj);
//
// * bool param_5 = myCircularQueueIsEmpty(obj);
//
// * bool param_6 = myCircularQueueIsFull(obj);
//
// * myCircularQueueFree(obj);
//*/
//
typedef int QNodeDataType;
typedef struct QNode
{
	QNodeDataType val;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* obj)
{
	assert(obj);
	obj->phead = obj->ptail = NULL;
	obj->size = 0;
}

void QueuePush(Queue* obj, QNodeDataType x)
{
	assert(obj);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->val = x;
	newnode->next = NULL;
	if (obj->phead == NULL)
	{
		obj->phead = obj->ptail = newnode;
	}
	else
	{
		obj->ptail->next = newnode;
		obj->ptail = newnode;
	}
	obj->size++;
}

void QueuePop(Queue* obj)
{
	assert(obj);
	assert(obj->phead);
	if (obj->phead->next == NULL)
	{
		free(obj->phead);
		obj->phead = obj->ptail = NULL;
	}
	else
	{
		QNode* next = obj->phead->next;
		free(obj->phead);
		obj->phead = next;
	}
	obj->size--;
}

QNodeDataType QueueFront(Queue* obj)
{
	return obj->phead->val;
}

QNodeDataType QueueBack(Queue* obj)
{
	return obj->ptail->val;
}

bool QueueIsEmpty(Queue* obj)
{
	return (obj->phead == NULL && obj->ptail == NULL);
}

int QueueSize(Queue* obj)
{
	return obj->size;
}

void QueueDestroy(Queue* obj)
{
	assert(obj);
	QNode* cur = obj->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

typedef struct MyStack
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() 
{
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	if (obj == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	QueueInit(&(obj->q1));
	QueueInit(&(obj->q2));
	return obj;
}

void myStackPush(MyStack* obj, int x) 
{
	if (QueueIsEmpty(&(obj->q1)))
	{
		QueuePush(&(obj->q2), x);
	}
	else
	{
		QueuePush(&(obj->q1), x);
	}
}

int myStackPop(MyStack* obj) 
{
	Queue* empty = &(obj->q1);
	Queue* nonempty = &(obj->q2);
	if (!QueueIsEmpty(empty))
	{
		empty = &(obj->q2);
		nonempty = &(obj->q1);
	}

	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}

	int top = QueueFront(nonempty);
	QueuePop(nonempty);

	return top;
}

int myStackTop(MyStack* obj) 
{
	if (!QueueIsEmpty(&(obj->q1)))
	{
		return QueueBack(&(obj->q1));
	}
	else
	{
		return QueueBack(&(obj->q2));
	}
}

bool myStackEmpty(MyStack* obj) 
{
	return (QueueIsEmpty(&(obj->q1)) && QueueIsEmpty(&(obj->q2)));
}

void myStackFree(MyStack* obj) 
{
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
