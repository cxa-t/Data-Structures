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


void testOP()
{
	srand((unsigned int)time(NULL));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);

	free(a1);
	free(a2);
}


int main()
{
	//testInsertSort();
	//testShellSort();
	testOP();
	return 0;
}