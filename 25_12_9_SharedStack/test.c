#define _CRT_SECURE_NO_WARNINGS 1

#include "SharedStack.h"

void test_sharedstack()
{
    // 初始化一个总容量为 10 的共享栈
    SST sst;
    int capacity = 10;
    SSTInit(&sst, capacity);
    printf("共享栈初始化，总容量为 %d。\n\n", capacity);

    // 栈 1 入栈 (top1: -1 -> 0 -> 1 -> 2)
    printf("--- 栈 1 操作 (top1 向右增长) ---\n");
    SSTPush(&sst, 1, 10); // top1 = 0
    SSTPush(&sst, 1, 20); // top1 = 1
    SSTPush(&sst, 1, 30); // top1 = 2
    printf("栈 1 栈顶: %d, top1 索引: %d\n", SSTTop(&sst, 1), sst.top1);

    // 栈 2 入栈 (top2: 10 -> 9 -> 8)
    printf("\n--- 栈 2 操作 (top2 向左增长) ---\n");
    SSTPush(&sst, 2, 90); // top2 = 9
    SSTPush(&sst, 2, 80); // top2 = 8
    printf("栈 2 栈顶: %d, top2 索引: %d\n", SSTTop(&sst, 2), sst.top2);

    // 继续让栈 1 和栈 2 靠近，直到栈满
    SSTPush(&sst, 1, 40); // top1 = 3
    SSTPush(&sst, 2, 70); // top2 = 7
    SSTPush(&sst, 1, 50); // top1 = 4
    SSTPush(&sst, 2, 60); // top2 = 6

    // 此时栈 1 占用索引 0-4 (5个元素), 栈 2 占用索引 6-9 (4个元素)
    // 数组索引 5 是空闲的。 top1=4, top2=6
    printf("\n--- 状态检查 ---\n");
    printf("当前 top1 索引: %d, top2 索引: %d\n", sst.top1, sst.top2);
    printf("栈满检查 (top1 + 1 == top2): %s\n", SSTIsFull(&sst) ? "是" : "否"); // 4 + 1 != 6 -> 否

    // 关键入栈，使栈满
    SSTPush(&sst, 1, 55); // top1 = 5
    // 此时 top1=5, top2=6. 栈满 (5 + 1 == 6)
    printf("再次入栈 55， top1 索引: %d\n", sst.top1);
    printf("栈满检查: %s\n", SSTIsFull(&sst) ? "是" : "否"); // 是

    // 尝试在栈满时入栈
    printf("\n--- 栈满时入栈测试 ---\n");
    SSTPush(&sst, 1, 99); // 打印错误信息

    // 栈 2 出栈 (top2: 6 -> 7)
    printf("\n--- 栈 2 出栈测试 (top2 向右移动) ---\n");
    SSTPop(&sst, 2); // 60 出栈
    printf("栈 2 新栈顶: %d, top2 新索引: %d\n", SSTTop(&sst, 2), sst.top2); // 70, 索引 7
    printf("栈满检查: %s\n", SSTIsFull(&sst) ? "是" : "否"); // 5 + 1 != 7 -> 否

    // 销毁栈
    SSTDestroy(&sst);
    printf("\n共享栈销毁。\n");
}


int main()
{
    test_sharedstack();
    return 0;
}
