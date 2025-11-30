#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void ListTest01()
{
	//LTNode* plist = NULL;
	//LTInit(&plist);
	LTNode* plist = LTInit();

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPrint(plist);

	LTNode* find = LTFind(plist, 3);
	//LTInsert(find, 66);
	LTErase(find);
	find = NULL;

	LTPrint(plist);
	LTDesTroy(plist);
	//plist = NULL;


	//if (find == NULL)
	//{
	//	printf("’“≤ªµΩ£°\n");
	//}
	//else {
	//	printf("’“µΩ¡À£°\n");
	//}

	//LTPushFront(plist, 1);
	//LTPrint(plist);
	//LTPushFront(plist, 2);
	//LTPrint(plist);
	//LTPushFront(plist, 3);
	// 
	//
	////≤‚ ‘Œ≤…æ
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);

	////≤‚ ‘Õ∑…æ
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopFront(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);
}

int main()
{
	ListTest01();
	return 0;
}