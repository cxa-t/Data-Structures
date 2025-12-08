#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkStack.h"

void test_linkstack()
{
    LST s;
    LSTInit(&s);

    printf("Pushing: 1, 2, 3, 4\n");
    LSTPush(&s, 1);
    LSTPush(&s, 2);
    LSTPush(&s, 3);
    LSTPush(&s, 4);

    printf("Stack size: %d\n", LSTSize(&s)); // Output: 4
    printf("Stack top: %d\n", LSTTop(&s));   // Output: 4 (LIFO)

    printf("Popping...\n");
    LSTPop(&s);
    printf("New stack top: %d\n", LSTTop(&s)); // Output: 3

    printf("Traversing and popping all elements:\n");
    // 遍历栈：不断检查栈是否为空，然后弹出元素并打印
    while (!LSTIsEmpty(&s))
    {
        printf("%d ", LSTTop(&s)); // 先取顶
        LSTPop(&s);                // 后弹出
    }
    printf("\n"); // Output: 3 2 1 

    printf("Is stack empty? %s\n", LSTIsEmpty(&s) ? "Yes" : "No"); // Output: Yes

    LSTDestroy(&s);
    printf("Stack destroyed.\n");
}

int main()
{
    test_linkstack();
    return 0;
}