#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
}

void swap(HDataType* p1, HDataType* p2)
{
	HDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUP(HDataType* a, int child)
{
	int parent = (child - 1) / 2;
	
	while (child > 0)
	{
		//小根堆
		if (a[parent] > a[child])
		{
			swap(&(a[parent]), &(a[child]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HDataType x)
{
	assert(php);

	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HDataType* tmp = (HDataType*)realloc(php->a,sizeof(HDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUP(php->a,php->size-1);
}

void AdjustDown(HDataType* a, int n,int parent)
{
	//假设左孩子小
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找到值小的孩子节点
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			swap(&(a[parent]), &(a[child]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a,php->size,0);
}

HDataType HPTop(HP* php)
{
	assert(php);
	return (php->a[0]);
}
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
