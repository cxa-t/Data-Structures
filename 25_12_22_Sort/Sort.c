#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void Swap(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void InsertSort(int* a,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap>1)
	{
		// +1保证最后一个gap一定是1
		// gap > 1时是预排序
		// gap == 1时是插入排序
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int min_pos = begin;
		int max_pos = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (a[i] > a[max_pos])
				max_pos = i;
			if (a[i] < a[min_pos])
				min_pos = i;
		}

		Swap(&(a[min_pos]), &a[begin]);
		//9,1,2,5,7,4,6,3
		//最大：0  最小：1
		//互换后：1,9,2,5,7,4,6,3  但此时最大值下标依然是0 所以在更换最大值之前，需要对最大值下标进行处理
		if (begin == max_pos)
			max_pos = min_pos;
		
		Swap(&(a[max_pos]), &a[end]);

		++begin;
		--end;
	}
}

int getMidi(int* a, int left, int right)
{
	int midi = left + (right - left) / 2;
	//left midi right
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
			return midi;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[midi] > a[right])
			return midi;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

void QuickSort(int* a, int left, int right)
{

	if (left >= right)
		return;

	int midi = getMidi(a, left, right);
	Swap(&(a[midi]), &(a[left]));

	int begin = left;
	int end = right;
	int key_pos = left;//分割位置下标

	while (begin < end)
	{
		while (begin < end && a[end] >= a[key_pos])
		{
			end--;
		}
		while (begin < end && a[begin] <= a[key_pos])
		{
			begin++;
		}
		Swap(&(a[begin]), &(a[end]));
	}
	Swap(&(a[begin]), &(a[key_pos]));
	key_pos = begin;
	QuickSort(a, left, key_pos - 1);
	QuickSort(a, key_pos + 1, right);
}
