#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void testInsertSort()
{
	int a[] = { 2,24,6,2,1,6,4367,8 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
}

void testShellSort()
{
	int a[] = { 2,24,6,2,1,6,4367,8 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
}

void testSelectSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
}

void testQuickSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
}

void testBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
}

void testHeapSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
}

void testMergeSort()
{
	int a[] = { 9,1,2,5,7,4,6,3 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
}

void testOP()
{
	srand((unsigned int)time(NULL));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a1, N);
	int end3 = clock();

	int begin4 = clock();
	QuickSort(a1, 0,N-1);
	int end4 = clock();

	int begin5 = clock();
	BubbleSort(a1, N);
	int end5 = clock();

	int begin6 = clock();
	HeapSort(a1, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("QuickSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("HeapSort:%d\n", end5 - begin5);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}


int main()
{
	//testInsertSort();
	//testShellSort();
	testSelectSort();
	//testQuickSort();
	//testBubbleSort();
	//testHeapSort();
	//testOP();
	return 0;
}