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
		/*if (begin == max_pos)
			max_pos = min_pos;*/
		
		Swap(&(a[max_pos]), &a[end]);

		++begin;
		--end;
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&(a[j]), &(a[j + 1]));
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	//假设左孩子大
	int child = parent * 2 + 1;

	while (child < n)
	{
		//找出真正大的那个孩子
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&(a[parent]), &(a[child]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	//n代表元素个数
	//最后一个父节点应该是最后一个下标值减1
	int parent = (n - 1 - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&(a[0]), &(a[end]));
		//这里传的是需要调整堆的元素个数
		AdjustDown(a, end, 0);
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

//hoare版本
int singleTripSort(int* a, int left, int right)
{
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
	return begin;
}

//int FBPoint(int* a, int left, int right)
//{
//	int midi = getMidi(a, left, right);
//	Swap(&(a[midi]), &(a[left]));
//
//	int last = left;
//	int prev = left + 1;
//	int key_pos = left;
//	while (prev <= right)
//	{
//		if (a[prev] < a[key_pos])
//		{
//			last++;
//			Swap(&(a[prev]), &(a[last]));
//		}
//		prev++;
//	}
//	Swap(&(a[last]), &(a[key_pos]));
//	return last;
//}

//前后指针
int PartSort3(int* a, int left, int right)
{
	// 1. 三数取中优化：从左、中、右三个位置选出中间值
	// 目的：防止在处理有序数组时快排退化为 O(N^2)
	int midi = getMidi(a, left, right);
	// 将选出的中间值交换到左边界，作为基准值(key)
	Swap(&(a[midi]), &(a[left]));

	int key_pos = left;   // 记录基准值的位置
	int prev = left;      // prev 指向小于 key 区域的最后一个元素
	int cur = left + 1;   // cur 作为探路指针，寻找比 key 小的元素

	// 2. 探路阶段：cur 遍历整个区间
	while (cur <= right)
	{
		// 如果 cur 发现了一个比基准值小的数
		if (a[cur] < a[key_pos])
		{
			// 小于 key 的区域向后扩展一位
			prev++;
			// 将 cur 发现的小数交换到 prev 的新位置
			// 只有在 prev 和 cur 不相等时才交换，减少无效自换
			if (prev != cur)
			{
				Swap(&(a[cur]), &(a[prev]));
			}
		}
		// cur 无论是否发现小数，都继续向后探测
		cur++;
	}
	// 3. 基准值归位
	// 此时 prev 及其左边都是小于 key 的数，prev 右边都是大于等于 key 的数
	// 将基准值交换到 prev 的位置，使其回到序列正中间
	Swap(&(a[prev]), &(a[key_pos]));
	// 返回基准值的正确下标，用于后续递归分裂区间
	return prev;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int midi = getMidi(a, left, right);
	Swap(&(a[midi]), &(a[left]));
	int hole = left;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if ((right - left + 1) < 10)
	{
		InsertSort(a + left, (right - left + 1));
	}
	else
	{
		int key_pos = singleTripSort(a, left, right);
		//int key_pos = FBPoint(a, left, right);
		QuickSort(a, left, key_pos - 1);
		QuickSort(a, key_pos + 1, right);
	}
}

//快排基础版本
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int begin = left;
//	int end = right;
//	int key_pos = left;//分割位置下标
//
//	while (begin < end)
//	{
//		while (begin < end && a[end] >= a[key_pos])
//		{
//			end--;
//		}
//		while (begin < end && a[begin] <= a[key_pos])
//		{
//			begin++;
//		}
//		Swap(&(a[begin]), &(a[end]));
//	}
//	Swap(&(a[begin]), &(a[key_pos]));
//	key_pos = begin;
//	QuickSort(a, left, key_pos - 1);
//	QuickSort(a, key_pos + 1, right);
//}

#include "Stack.h"
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	//先进区间右边界，然后左边界
	STPush(&st, right);
	STPush(&st, left);

	while (!isEmpty(&st))
	{
		//先拿出来的一定是左边界，然后是右边界
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int key_pos = singleTripSort(a, begin, end);
		//先进右半部分  再进左半部分
		if (key_pos + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, key_pos + 1);
		}
		if (key_pos - 1 > begin)
		{
			STPush(&st, key_pos - 1);
			STPush(&st, begin);
		}
	}

	STDestroy(&st);
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int midi = left + (right - left) / 2;
	// left midi midi+1 right
	_MergeSort(a, tmp, left, midi);
	_MergeSort(a, tmp, midi+1, right);

	//归并操作
	int left_first = left;
	int right_first = midi;
	int left_second = midi + 1;
	int right_second = right;
	int i = left;

	while (left_first <= right_first && left_second <= right_second)
	{
		if (a[left_first] <= a[left_second])
		{
			tmp[i++] = a[left_first++];
		}
		else
		{
			tmp[i++] = a[left_second++];
		}
	}
	while(left_first <= right_first)
		tmp[i++] = a[left_first++];
	while (left_second <= right_second)
		tmp[i++] = a[left_second++];

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	_MergeSort(a, tmp, 0, n-1);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//归并操作
			int left_first = i;
			int right_first = i + gap - 1;
			int left_second = i + gap;
			int right_second = i + 2 * gap - 1;
			int j = i;

			if (left_second >= n)
				break;

			if (right_second >= n)
				right_second = n - 1;

			while (left_first <= right_first && left_second <= right_second)
			{
				if (a[left_first] <= a[left_second])
					tmp[j++] = a[left_first++];
				else
					tmp[j++] = a[left_second++];
			}
			while (left_first <= right_first)
				tmp[j++] = a[left_first++];
			while (left_second <= right_second)
				tmp[j++] = a[left_second++];
			memcpy(a + i, tmp + i, sizeof(int) * (right_second - i + 1));
		}
		gap *= 2;
	}
}

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	int* tmp = (int*)calloc(range, sizeof(int));
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}

}
