#define _CRT_SECURE_NO_WARNINGS 1

#include"SLinkList.h"

void test01()
{
	//≤‚ ‘Õ∑≤ÂŒ≤≤Â¥Ú”°
	SLNode* head = NULL;
	SLNodePrint(head);
	SLNodePushBack(&head, 1);
	SLNodePrint(head);
	SLNodePushBack(&head, 2);
	SLNodePrint(head);
	SLNodePushBack(&head, 3);
	SLNodePrint(head);
	SLNodePushBack(&head, 4);
	SLNodePrint(head);

	SLNodePushFront(&head, 5);
	SLNodePrint(head);
	SLNodePushFront(&head, 6);
	SLNodePrint(head);
	SLNodePushFront(&head, 7);
	SLNodePrint(head);
	SLNodePushFront(&head, 8);
	SLNodePrint(head);

	SLNodePopBack(&head);
	SLNodePrint(head);
	SLNodePopBack(&head);
	SLNodePrint(head);

	SLNodePopFront(&head);
	SLNodePrint(head);
	SLNodePopFront(&head);
	SLNodePrint(head);

	SLNode* find = SLNodeFind(head, 1);
	SLNodeInsert(&head, find, 88);
	SLNodePrint(head);
	find = SLNodeFind(head, 1);
	SLNodeInsertAfter(find, 99);
	SLNodePrint(head);

	find = SLNodeFind(head, 1);
	SLNodeErasw(&head, find);
	SLNodePrint(head);
	find = SLNodeFind(head, 88);
	SLNodeEraseAfter(find);
	SLNodePrint(head);

	SLNodeDestroy(&head);
}

int main()
{
	test01();
	return 0;
}
