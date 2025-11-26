#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//顺序表初始化
void SLInit(SL* ps)
{
	assert(ps);
	//避免野指针
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//销毁顺序表
void SLDestroy(SL* ps)
{
	assert(ps);
	free(ps->arr);//释放堆上的空间
	ps->arr = NULL;//避免野指针
	ps->size = 0;
	ps->capacity = 0;
}

//检查容量，不允许被外部调用
static void SLCheckCapacity(SL* ps)
{
	assert(ps);
	//容量不够
	if (ps->capacity == ps->size)
	{
		//计算新容量
		int new_capacity = ps->capacity == 0 ? INIT_CAPACITY : 2 * ps->capacity;
		//申请空间
		//这里一定不能用arr直接接收，因为还有申请失败的可能
		//如果申请失败，不仅得不到新地址，还会将原来的空间也丢掉
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, new_capacity * sizeof(SLDataType));
		//申请失败，退出
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		//申请成功后赋值新地址，更新容量
		ps->arr = tmp;
		ps->capacity = new_capacity;
	}
}

//尾插法
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//assert(ps);//断言顺序表不能为空

	ps->arr[ps->size++] = x;//将x放在顺序表最后一个位置，且有效个数加1
}

//头插法
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//将元素从前往后挪
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	//插入元素
	ps->arr[0] = x;
	//元素个数自增
	++ps->size;
}


//尾删法
void SLPopBack(SL* ps)
{
	//有元素才能删除
	assert(ps && ps->size);
	ps->size--;
}


//头删
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	//将后面的元素往前挪，覆盖掉首元素
	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	--ps->size;
}

//打印顺序表
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	puts(" ");
}

//按值查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	//从头开始遍历查找
	for (int i = 0; i < ps->size; i++)
		if (ps->arr[i] == x)
			return i;//找到返回下标
	return -1;//没扎到
}

//在指定位置插入元素
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	//判断插入位置是否合法
	assert(pos >= 0 && pos <= ps->size);
	//检查容量
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		//     pos   size
		//0  1  2  3
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	++ps->size;
}

//在指定位置删除元素
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	//将pos之后的元素往前挪
	for (int i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

//清空顺序表
void SLClear(SL* ps)
{
	assert(ps);
	//只把元素有效个数置为0，空间留下，后续继续使用
	ps->size = 0;
}

//按值删除第一个匹配的元素
void SLEraseByValue(SL* ps, SLDataType x)
{
	assert(ps);
	assert(ps->size);
	//找到值在顺序表中的下标
	int index = SLFind(ps, x);
	if (index != -1)//找到了
	{
		int i = 0;
		for (i = index; i < ps->size - 1; i++)
		{
			//将后续元素往前移动
			ps->arr[i] = ps->arr[i + 1];
		}
		//更新元素个数
		--ps->size;
	}
}


//按下标访问，随机访问，直接获取指定位置元素地址
SLDataType* SLGetByIndex(SL* ps, int index)
{
	assert(ps);
	assert(index >= 0 && index < ps->size);
	return &(ps->arr[index]);
}

//判断是否包含指定值
bool SLContainsValue(SL* ps, SLDataType x)
{
	assert(ps);
	bool result = false;
	//找到了 修改结果
	if (SLFind(ps, x) != -1)
	{
		result = true;
	}
	return result;
}

//获取顺序表长度
int SLGetLength(SL* ps)
{
	assert(ps);
	return ps->size;
}

//更新顺序表元素 修改指定位置的元素值
void SLUpdateByIndex(SL* ps, int index, SLDataType value)
{
	assert(ps);
	ps->arr[index] = value;
}

//判断表空
bool SLIsEmpty(SL* ps)
{
	assert(ps);
	bool result = false;
	if (ps->size == 0)
		result = true;
	return result;
}

//判断表满
bool SLIsFull(SL* ps)
{
	assert(ps);
	bool result = false;
	if (ps->size == ps->capacity)
		result = true;
	return result;
}

//顺序表反转
void SLReverse(SL* ps)
{
	assert(ps);
	int left = 0, right = ps->size - 1;
	while (left < right)
	{
		SLDataType tmp = ps->arr[left];
		ps->arr[left] = ps->arr[right];
		ps->arr[right] = tmp;
		++left; 
		--right;
	}
}
