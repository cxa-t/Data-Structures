#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"


void test01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d \n", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}


void TestCase_BasicOperations() 
{
    printf("=== 测试用例 1：基本操作 (入队、出队、查看) ===\n");
    Queue q;
    QueueInit(&q);

    // 测试空队列属性
    printf("队列是否为空? %s\n", QueueEmpty(&q) ? "是" : "否");
    printf("队列大小: %d\n", QueueSize(&q));

    // 连续入队
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);
    printf("入队 10, 20, 30 后，队列大小: %d\n", QueueSize(&q));
    printf("队头元素: %d\n", QueueFront(&q));
    printf("队尾元素: %d\n", QueueBack(&q));

    // 出队一次
    QueuePop(&q);
    printf("出队一次后，队头元素: %d\n", QueueFront(&q));
    printf("队列大小: %d\n", QueueSize(&q));

    // 继续入队出队
    QueuePush(&q, 40);
    printf("再入队 40 后，队尾元素: %d\n", QueueBack(&q));

    printf("当前队列内容 (从头到尾): ");
    while (!QueueEmpty(&q)) {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
    printf("队列清空后大小: %d\n", QueueSize(&q));

    QueueDestroy(&q);
    printf("测试通过！\n\n");
}

void TestCase_EdgeConditions() 
{
    printf("=== 测试用例 2：边界条件 ===\n");
    Queue q;
    QueueInit(&q);

    // 测试单元素队列
    QueuePush(&q, 99);
    printf("插入单元素 99 后:\n");
    printf("  队头: %d, 队尾: %d\n", QueueFront(&q), QueueBack(&q)); // 应该相同
    printf("  大小: %d\n", QueueSize(&q));

    QueuePop(&q); // 弹出后队列应为空
    printf("弹出后，队列是否为空? %s\n", QueueEmpty(&q) ? "是" : "否");

    // 测试连续插入删除后的再插入
    for (int i = 0; i < 5; ++i) 
    {
        QueuePush(&q, i * 100);
    }
    while (!QueueEmpty(&q)) {
        QueuePop(&q);
    }
    // 此时队列再次为空，测试是否能正确接受新元素
    QueuePush(&q, 999);
    printf("队列清空后重新插入 999，队头: %d\n", QueueFront(&q));

    QueueDestroy(&q);
    printf("边界条件测试通过！\n\n");
}

void TestCase_DestroyAndReinit() 
{
    printf("=== 测试用例 3：销毁与重新初始化 ===\n");
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    printf("初始化并插入数据后大小: %d\n", QueueSize(&q));

    QueueDestroy(&q); // 显式销毁
    printf("销毁后大小: %d\n", QueueSize(&q)); // 应打印出 Destroy 函数设置的 0

    // 重新初始化并使用
    QueueInit(&q); // 关键步骤：内存已释放，结构体可以重新初始化
    QueuePush(&q, 3);
    printf("重新初始化并插入 3 后，队头: %d\n", QueueFront(&q));

    QueueDestroy(&q); // 再次销毁
    printf("重复销毁测试通过！\n\n");
}

// 此函数用于演示 assert 触发的错误情况（运行时需注意）
void TestCase_ErrorConditions() 
{
    printf("=== 测试用例 4：错误条件 (Assert 触发) ===\n");
    printf("(以下测试预期会触发断言失败，正常情况不应执行)\n");
    Queue q;
    QueueInit(&q);

    // 1. 对空队列进行 Pop 操作 (应触发 assert)
    // QueuePop(&q); // 取消注释以测试

    // 2. 对空队列获取 Front/Back (应触发 assert)
    // int val = QueueFront(&q); // 取消注释以测试
    // int val = QueueBack(&q);  // 取消注释以测试

    QueuePush(&q, 42);

    // 3. 传递 NULL 指针给队列函数 (应触发 assert)
    // QueuePush(NULL, 100); // 取消注释以测试
    // QueueFront(NULL);     // 取消注释以测试

    QueueDestroy(&q);
    printf("错误条件测试说明完毕。\n\n");
}

int main() 
{
    TestCase_BasicOperations();   // 测试基本功能
    TestCase_EdgeConditions();    // 测试边界情况
    TestCase_DestroyAndReinit();  // 测试销毁与复用
    TestCase_ErrorConditions();   // 说明错误情况

    printf("所有测试用例执行完毕！\n");
    return 0;
}
