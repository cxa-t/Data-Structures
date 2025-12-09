#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//队列数据类型
typedef int QDataType;

//队列节点
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}QNode;

//队列结构体定义
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化队列
void QueueInit(Queue* pq);
//销毁队列
void QueueDestroy(Queue * pq);
//入队
void QueuePush(Queue * pq, QDataType x);
//出队
void QueuePop(Queue * pq);
//取出队头元素
QDataType QueueFront(Queue * pq);
//取出队尾元素
QDataType QueueBack(Queue * pq);
//判断队列是否为空
bool QueueEmpty(Queue * pq);
//队列中有效元素个数
int QueueSize(Queue * pq);

