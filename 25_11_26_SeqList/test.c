#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 4);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);
	SLInsert(&sl, 0, 9);
	SLInsert(&sl, sl.size, 9);
	SLInsert(&sl, 2, 9);
	SLPrint(&sl);
	SLErase(&sl, 0);
	SLErase(&sl, sl.size-1);
	SLErase(&sl, 2);
	SLPrint(&sl);
	SLDestroy(&sl);
}

// 测试顺序表的基础操作
void TestSeqList1()
{
	SL sl;
	SLInit(&sl); // 初始化

	printf("--- 1. 尾插操作 ---\n");
	SLPushBack(&sl, 10);
	SLPushBack(&sl, 20);
	SLPushBack(&sl, 30);
	SLPushBack(&sl, 40); // 此时触发第一次扩容
	SLPrint(&sl); // 输出: 10 20 30 40 
	printf("Length: %d, Capacity: %d\n", SLGetLength(&sl), sl.capacity); // 4, 4/8

	SLPushBack(&sl, 50); // 触发扩容
	SLPushBack(&sl, 60);
	SLPrint(&sl); // 输出: 10 20 30 40 50 60 
	printf("Length: %d, Capacity: %d\n", SLGetLength(&sl), sl.capacity); // 6, 8

	printf("--- 2. 头插操作 ---\n");
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 1);
	SLPrint(&sl); // 输出: 1 5 10 20 30 40 50 60
	printf("Length: %d, Capacity: %d\n", SLGetLength(&sl), sl.capacity); // 8, 8 (如果初始容量是4，此时会再次扩容到16)

	printf("--- 3. 任意位置插入 (pos=2, 888) ---\n");
	SLInsert(&sl, 2, 888);
	SLPrint(&sl); // 输出: 1 5 888 10 20 30 40 50 60 

	printf("--- 4. 按值查找 (Find 30) ---\n");
	int pos = SLFind(&sl, 30);
	if (pos != -1)
		printf("Element 30 found at index: %d\n", pos); // 5

	printf("--- 5. 尾删和头删 ---\n");
	SLPopBack(&sl); // 删 60
	SLPopFront(&sl); // 删 1
	SLPrint(&sl); // 输出: 5 888 10 20 30 40 50 

	printf("--- 6. 任意位置删除 (pos=1, 删 888) ---\n");
	SLErase(&sl, 1);
	SLPrint(&sl); // 输出: 5 10 20 30 40 50 

	printf("--- 7. 顺序表反转 ---\n");
	SLReverse(&sl);
	SLPrint(&sl); // 输出: 50 40 30 20 10 5 

	printf("--- 8. 清空和销毁 ---\n");
	SLClear(&sl);
	printf("Is Empty: %s\n", SLIsEmpty(&sl) ? "True" : "False");
	SLDestroy(&sl); // 释放内存
}


int main()
{
	//test01();
	TestSeqList1();
	return 0;
}