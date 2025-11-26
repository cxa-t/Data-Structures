#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


//初始化容量
#define INIT_CAPACITY 4

//顺序表元素类型
typedef int SLDataType;

//// 静态顺序表
//// 定义数组的固定长度（容量）
//#define N 7      
//typedef struct SeqList 
//{
//	SLDataType a[N]; // 定长数组，用于存储数据 
//	int size;      // 记录顺序表中有效数据个数
//}SL;

//动态顺序表 --- 随时扩容
typedef struct SeqList
{
	SLDataType* arr;
	int size;//有效元素个数
	int capacity;//顺序表容量
}SL;

//初始化和销毁
void SLInit(SL * ps);
void SLDestroy(SL * ps);

//打印顺序表
void SLPrint(SL * ps);

//头部插⼊删除 / 尾部插⼊删除
void SLPushBack(SL * ps, SLDataType x);
void SLPopBack(SL * ps);
void SLPushFront(SL * ps, SLDataType x);
void SLPopFront(SL * ps);

//指定位置插⼊/删除数据
void SLInsert(SL * ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//按值查找
int SLFind(SL* ps, SLDataType x);

//清空顺序表
void SLClear(SL* ps);

//按值删除按值删除第一个匹配的元素
void SLEraseByValue(SL* ps, SLDataType x);

//按下标访问，随机访问，直接获取指定位置元素地址
SLDataType* SLGetByIndex(SL* ps, int index);

//判断是否包含指定值
bool SLContainsValue(SL* ps, SLDataType x);

//获取顺序表长度
int SLGetLength(SL* ps);

//更新顺序表元素 修改指定位置的元素值
void SLUpdateByIndex(SL* ps, int index, SLDataType value);

//判断表空
bool SLIsEmpty(SL* ps);

//判断表满
bool SLIsFull(SL* ps);

//原地反转顺序表
void SLReverse(SL* ps);