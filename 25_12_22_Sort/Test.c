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

void testOP()
{
	srand((unsigned int)time(NULL));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
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

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("QuickSort:%d\n", end4 - begin4);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
}


int main()
{
	//testInsertSort();
	//testShellSort();
	//testSelectSort();
	//testQuickSort();
	testOP();
	return 0;
}