#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h" // 假设你的头文件名为 SeqList.h

// 测试1：测试尾插、尾删、扩容机制、打印、销毁
void TestSeqList1()
{
    printf("========== 开始测试1：尾部操作与自动扩容 ==========\n");
    SL s1;
    SLInit(&s1);

    // 1. 测试尾插 (PushBack)
    // 初始容量是4，我们要插入5个数据，测试是否会自动扩容
    SLPushBack(&s1, 1);
    SLPushBack(&s1, 2);
    SLPushBack(&s1, 3);
    SLPushBack(&s1, 4);
    SLPushBack(&s1, 5); // 这里应该触发扩容

    printf("期望结果: 1 2 3 4 5\n");
    printf("实际结果: ");
    SLPrint(&s1);

    // 2. 测试尾删 (PopBack)
    SLPopBack(&s1);
    SLPopBack(&s1);

    printf("期望结果: 1 2 3\n");
    printf("实际结果: ");
    SLPrint(&s1);

    // 3. 测试销毁
    SLDestroy(&s1);
    // 销毁后通常建议将 size 和 capacity 置为 0，a 置为 NULL
    // 这里打印出来应该是空的或者报错（取决于你的实现是否允许打印空表）
    printf("销毁完成。\n\n");
}

// 测试2：测试头插、头删
void TestSeqList2()
{
    printf("========== 开始测试2：头部操作 ==========\n");
    SL s2;
    SLInit(&s2);

    // 1. 测试头插 (PushFront)
    SLPushBack(&s2, 10);
    SLPushBack(&s2, 20); // 先放两个底子: 10 20

    SLPushFront(&s2, 100); // 变成: 100 10 20
    SLPushFront(&s2, 200); // 变成: 200 100 10 20

    printf("期望结果: 200 100 10 20\n");
    printf("实际结果: ");
    SLPrint(&s2);

    // 2. 测试头删 (PopFront)
    SLPopFront(&s2); // 删掉 200
    printf("期望结果: 100 10 20 (头删一次)\n");
    printf("实际结果: ");
    SLPrint(&s2);

    SLPopFront(&s2); // 删掉 100
    SLPopFront(&s2); // 删掉 10
    SLPopFront(&s2); // 删掉 20

    printf("期望结果: NULL (或者空行)\n");
    printf("实际结果: ");
    SLPrint(&s2);

    SLDestroy(&s2);
    printf("\n");
}

// 测试3：测试任意位置插入(Insert)、删除(Erase)、查找(Find)
void TestSeqList3()
{
    printf("========== 开始测试3：任意位置插入/删除与查找 ==========\n");
    SL s3;
    SLInit(&s3);

    SLPushBack(&s3, 1);
    SLPushBack(&s3, 2);
    SLPushBack(&s3, 3);
    SLPushBack(&s3, 4);
    // 当前: 1 2 3 4

    // 1. 测试 SLInsert
    // 在下标 2 的位置插入 30 -> 1 2 30 3 4
    SLInsert(&s3, 2, 30);
    printf("在下标2插入30 -> 期望: 1 2 30 3 4\n实际: ");
    SLPrint(&s3);

    // 头插等同于 Insert pos=0
    SLInsert(&s3, 0, 999);
    printf("在下标0插入999 -> 期望: 999 1 2 30 3 4\n实际: ");
    SLPrint(&s3);

    // 2. 测试 SLFind
    int pos = SLFind(&s3, 30);
    if (pos != -1)
    {
        printf("找到了数值30，下标为: %d (期望是3)\n", pos);
        // 测试修改
        s3.a[pos] = 3000;
        printf("将找到的数修改为3000。\n");
    }
    else
    {
        printf("未找到数值30！(测试失败)\n");
    }

    // 3. 测试 SLErase
    // 当前假定: 999 1 2 3000 3 4
    // 删除下标为0的数
    SLErase(&s3, 0);
    printf("删除下标0 -> 期望: 1 2 3000 3 4\n实际: ");
    SLPrint(&s3);

    // 删除刚才找到的那个位置 (注意：因为头部删除了一个，原来的下标3变成了2)
    // 重新查找一下比较安全，或者手动计算
    pos = SLFind(&s3, 3000);
    if (pos != -1)
    {
        SLErase(&s3, pos);
    }
    printf("删除3000后 -> 期望: 1 2 3 4\n实际: ");
    SLPrint(&s3);

    SLDestroy(&s3);
    printf("\n");
}

#include "LinkList.h" // 务必包含你的头文件

// 辅助测试打印函数
void TestLog(const char* msg, SLTNode* phead)
{
    printf("[- %-20s -]: ", msg);
    SLTPrint(phead);
}

void Test1_Base()
{
    printf("========== 测试1: 基础 尾插/头插/尾删/头删 ==========\n");
    SLTNode* plist = NULL;

    // 1. 尾插
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    TestLog("尾插 1,2,3", plist); // 1->2->3->NULL

    // 2. 头插
    SLTPushFront(&plist, 10);
    SLTPushFront(&plist, 20);
    TestLog("头插 20,10", plist); // 20->10->1->2->3->NULL

    // 3. 头删
    SLTPopFront(&plist);
    TestLog("头删一次", plist);   // 10->1->2->3->NULL

    // 4. 尾删
    SLTPopBack(&plist);
    TestLog("尾删一次", plist);   // 10->1->2->NULL

    // 清理
    SListDesTroy(&plist);
}

void Test2_Pos_Operations()
{
    printf("\n========== 测试2: 指定位置 Insert / Erase ==========\n");
    SLTNode* plist = NULL;
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushBack(&plist, 4);
    // 当前: 1->2->3->4

    // --- Insert 测试 ---
    SLTNode* pos = SLTFind(plist, 3); // 找到3
    if (pos)
    {
        SLTInsert(&plist, pos, 30);
        TestLog("在3之前插入30", plist); // 1->2->30->3->4->NULL
    }

    // Insert 头插情况
    pos = SLTFind(plist, 1);
    if (pos)
    {
        SLTInsert(&plist, pos, 100);
        TestLog("在1之前插入100", plist); // 100->1->2->30->3->4->NULL
    }

    // --- Erase 测试 ---
    // 删除中间节点 30
    pos = SLTFind(plist, 30);
    if (pos)
    {
        SLTErase(&plist, pos);
        TestLog("删除30", plist); // 100->1->2->3->4->NULL
    }

    // 删除头节点 100 (验证特殊处理)
    pos = SLTFind(plist, 100);
    if (pos)
    {
        SLTErase(&plist, pos);
        TestLog("删除头节点100", plist); // 1->2->3->4->NULL
    }

    // 删除尾节点 4
    pos = SLTFind(plist, 4);
    if (pos)
    {
        SLTErase(&plist, pos);
        TestLog("删除尾节点4", plist); // 1->2->3->NULL
    }

    SListDesTroy(&plist);
}

void Test3_After_Operations()
{
    printf("\n========== 测试3: 指定位置后 InsertAfter / EraseAfter ==========\n");
    SLTNode* plist = NULL;
    SLTPushBack(&plist, 10);
    SLTPushBack(&plist, 20);
    // 10->20

    // 1. InsertAfter
    SLTNode* pos = SLTFind(plist, 10);
    if (pos)
    {
        SLTInsertAfter(pos, 15);
        TestLog("在10之后插15", plist); // 10->15->20->NULL
    }

    // 2. EraseAfter
    // pos 依然指向 10，它的 next 现在是 15
    SLTEraseAfter(pos);
    TestLog("删除10后面的节点", plist); // 10->20->NULL

    // 3. 测试尾部 EraseAfter (没有节点可删的情况)
    pos = SLTFind(plist, 20);
    if (pos)
    {
        SLTEraseAfter(pos);
        TestLog("删除尾部后(无变化)", plist); // 10->20->NULL
    }

    SListDesTroy(&plist);

    // 验证销毁
    if (plist == NULL)
        printf("\n[Check] 链表已销毁，指针已置空。\n");
    else
        printf("\n[Error] 链表指针未置空！\n");
}

// 辅助日志函数
void Log(const char* desc, SLTNode* phead)
{
    printf("[%-30s]: ", desc);
    if (phead == NULL)
        printf("(空表)\n");
    else
        SLTPrint(phead);
}

// 1. 测试空表的行为
// 目的：确保对空表进行查找、打印、销毁不会崩溃
void Test_Boundary_Empty()
{
    printf("\n>>> 边界测试 1: 空表操作 <<<\n");
    SLTNode* plist = NULL;

    // 1.1 打印空表
    Log("打印空表", plist);

    // 1.2 在空表中查找
    SLTNode* ret = SLTFind(plist, 10);
    printf("[空表查找] 期望: NULL, 实际: %s\n", ret == NULL ? "NULL" : "非空");

    // 1.3 销毁空表
    SListDesTroy(&plist);
    printf("[销毁空表] 执行完毕 (应无崩溃)\n");

    // 注意：不能测试对空表进行 Pop 或 Erase，因为你的代码中有 assert(*pphead)，会直接终止程序。
    // 这是正确的行为（防止非法操作），所以这里不进行测试。
}

// 2. 测试“单节点”的生死轮回
// 目的：只有一个节点时，它是头也是尾，删除后必须变回空表
void Test_Boundary_SingleNode()
{
    printf("\n>>> 边界测试 2: 单节点特殊场景 <<<\n");
    SLTNode* plist = NULL;

    // 2.1 尾插变单节点 -> 尾删变空
    SLTPushBack(&plist, 100);
    Log("尾插1个", plist);
    SLTPopBack(&plist);
    Log("尾删1个(应为空)", plist);

    // 2.2 头插变单节点 -> 头删变空
    SLTPushFront(&plist, 200);
    Log("头插1个", plist);
    SLTPopFront(&plist);
    Log("头删1个(应为空)", plist);

    // 2.3 插入1个 -> 指定位置删除(Erase)
    SLTPushBack(&plist, 300);
    SLTNode* pos = SLTFind(plist, 300);
    if (pos)
    {
        // 这里的边界在于：pos既是head也是tail，Erase必须处理好 head 指针更新
        SLTErase(&plist, pos);
        Log("Erase唯一节点(应为空)", plist);
    }
}

// 3. 测试头尾的精确 Insert/Erase
// 目的：验证在多节点情况下，操作两端是否破坏链表结构
void Test_Boundary_HeadTail()
{
    printf("\n>>> 边界测试 3: 头尾精确操作 <<<\n");
    SLTNode* plist = NULL;
    // 造一个 1->2->3 的链表
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    Log("初始链表", plist);

    // 3.1 删除尾节点 (Erase pos=tail)
    // 很多实现容易在这里出错（忘记把前一个节点的next置空）
    SLTNode* tail = SLTFind(plist, 3);
    if (tail)
    {
        SLTErase(&plist, tail);
        Log("Erase尾节点3", plist); // 期望: 1->2
    }

    // 3.2 删除头节点 (Erase pos=head)
    // 验证 pphead 是否正确更新
    SLTNode* head = SLTFind(plist, 1);
    if (head)
    {
        SLTErase(&plist, head);
        Log("Erase头节点1", plist); // 期望: 2
    }

    // 3.3 再次删除剩下的唯一节点 2
    head = SLTFind(plist, 2);
    if (head)
    {
        SLTErase(&plist, head);
        Log("Erase最后节点2", plist); // 期望: 空
    }
}

// 4. 测试 InsertAfter/EraseAfter 的边界
void Test_Boundary_After()
{
    printf("\n>>> 边界测试 4: After 系列边界 <<<\n");
    SLTNode* plist = NULL;
    SLTPushBack(&plist, 10); // 10

    // 4.1 在尾部之后插入 (InsertAfter Tail)
    SLTNode* tail = SLTFind(plist, 10);
    SLTInsertAfter(tail, 20);
    Log("尾部后插20", plist); // 10->20

    // 4.2 删除尾部之后 (EraseAfter Tail)
    // 此时 tail 是 20，后面是 NULL。EraseAfter 应该什么都不做，或者安全返回
    tail = SLTFind(plist, 20);
    SLTEraseAfter(tail);
    Log("删除尾部后(应无变化)", plist); // 10->20

    // 4.3 销毁
    SListDesTroy(&plist);
}

int main()
{
    //TestSeqList1();
    //TestSeqList2();
    //TestSeqList3();
    
    Test1_Base();
    Test2_Pos_Operations();
    Test3_After_Operations();

    Test_Boundary_Empty();
    Test_Boundary_SingleNode();
    Test_Boundary_HeadTail();
    Test_Boundary_After();

    return 0;
}