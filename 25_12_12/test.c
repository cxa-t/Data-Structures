#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

int main()
{
	HP heap;
	HPInit(&heap);
	int a[] = { 32,4,525,252,52,1,7 };
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; i++)
	{
		HPPush(&heap, a[i]);
	}
	int k = 4;
	while (k--)
	{
		if (!HPEmpty(&heap))
		{
			printf("%d ", HPTop(&heap));
			HPPop(&heap);
		}
	}
	return 0;
}
