#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#if 0

//堆的初始化
void InitHeap(Heap* hp)
{
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// 创建堆 
void CreateHeap(Heap* hp, DataType* array, int size)
{
	int n = 0;
	hp->_array = (DataType*)malloc(size*sizeof(DataType));
	for (n=0; n<size; n++)
		hp->_array[n] = array[n];
	hp->_capacity = size;
	hp->_size = size;
	//调整堆
	int parent = ((size - 2)/2);
	AdjustDown(hp, parent);
}
//调整堆
void AdjustDown(Heap* hp, int parent)
{
	int child = 0, index = parent;;
	while (index>=0)
	{
		parent = index;
		child = parent * 2 + 1;
		while (child<hp->_size)
		{
			if (child + 1 < hp->_size && hp->_array[child] > hp->_array[child + 1])
				child = child + 1;
			if (hp->_array[child] < hp->_array[parent])
			{
				Swap(&hp->_array[child], &hp->_array[parent]);
				parent = child;
				child = (parent * 2) + 1;
			}
			else
			{
				parent = child;
				child = (parent * 2) + 1;
			}
		}
		index--;
	}
	return;
}
void Swap(DataType* a, DataType* b)
{
	DataType c;
	c = *a;
	*a = *b;
	*b = c;
}
// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data)
{
	if (hp == NULL)
		return;
	if (hp->_size == hp->_capacity)
	{
		hp->_array = (DataType*)realloc(hp->_array, 2 * hp->_capacity*sizeof(DataType));
		hp->_capacity = 2 * hp->_capacity;
	}
	hp->_array[hp->_size] = data;
	hp->_size++;
	int child = hp->_size - 1;
	AdjustUp(hp, child);
}

//向上调整
void AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) / 2;
	if (hp == NULL)
		return;
	while (child)
	{
		if (child+1 < hp->_size && hp->_array[child] > hp->_array[child + 1])
			child++;
		if (hp->_array[child] < hp->_array[parent])
		{
			Swap(&hp->_array[child], &hp->_array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
// 获取堆顶元素 
DataType TopHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return NULL;
	}
	return hp->_array[0];
}

// 检测一个堆是否为空堆 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
		return 0;
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// 获取堆中元素的个数 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return 0;
	}
	return hp->_size;
}

// 删除堆顶元素 
void DeleteHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;
	int parent = 0;
	AdjustDown(hp, parent);
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_array);
	hp = NULL;
}

#endif

//2. 对堆进行优化，一份代码既可以创建最大堆也可以创建最小堆


// 堆的初始化 
void InitHeap(Heap* hp, Compare com)
{
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_com = com;
}
// 创建堆 
void CreateHeap(Heap* hp, DataType* array, int size, Compare com)
{
	int n = 0;
	hp->_array = (DataType*)malloc(size*sizeof(DataType));
	for (n = 0; n<size; n++)
		hp->_array[n] = array[n];
	hp->_capacity = size;
	hp->_size = size;
	hp->_com = com;
	//调整堆
	int parent = ((size - 2) / 2);
	for (; parent >= 0;parent--)
		AdjustDown(hp, hp->_size, parent);
}

//调整堆--向下调整
//void AdjustDown(Heap* hp, int parent)
//{
//	int child = 0, index = parent;
//	while (index >= 0)
//	{
//		parent = index;
//		child = parent * 2 + 1;
//		while (child<hp->_size)
//		{
//			if (child + 1 < hp->_size && hp->_com(hp->_array[child+1] , hp->_array[child]))
//				child = child + 1;
//			if (hp->_com(hp->_array[child] , hp->_array[parent]))
//			{
//				Swap(&hp->_array[child], &hp->_array[parent]);
//				parent = child;
//				child = (parent * 2) + 1;
//			}
//			else
//			{
//				parent = child;
//				child = (parent * 2) + 1;
//			}
//		}
//		index--;
//	}
//	return;
//}

void Swap(DataType* a, DataType* b)
{
	DataType c;
	c = *a;
	*a = *b;
	*b = c;
}

//向上调整
void AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) / 2;
	if (hp == NULL)
		return;
	while (child)
	{
		if (child + 1 < hp->_size && hp->_com(hp->_array[child+1] , hp->_array[child]))
			child++;
		if (hp->_com(hp->_array[child] , hp->_array[parent]))
		{
			Swap(&hp->_array[child], &hp->_array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data)
{
	if (hp == NULL)
		return;
	if (hp->_size == hp->_capacity)
	{
		hp->_array = (DataType*)realloc(hp->_array, 2 * hp->_capacity*sizeof(DataType));
		hp->_capacity = 2 * hp->_capacity;
	}
	hp->_array[hp->_size] = data;
	hp->_size++;
	int child = hp->_size - 1;
	AdjustUp(hp, child);
}

// 获取堆顶元素 
DataType TopHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return NULL;
	}
	return hp->_array[0];
}

// 检测一个堆是否为空堆 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
		return 0;
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// 获取堆中元素的个数 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return 0;
	}
	return hp->_size;
}

// 删除堆顶元素 
void DeleteHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("堆为空！\n");
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;
	int parent = 0;
	AdjustDown(hp,hp->_size, parent);
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_array);
	hp = NULL;
}

// 用于元素比较的比较器 
// 小于号 
int Less(DataType left, DataType right)
{
	return left < right;
}

// 大于号
int Greater(DataType left, DataType right)
{
	return left > right;
}
#if 0
//3. 堆的应用之优先级队列，用堆封装优先级队列
//typedef struct PriorityQueue
//{
//	Heap _hp;
//}PriorityQueue;

// 优先级队列初始化 
void PriorityQueueInit(PriorityQueue* q, Compare com)
{
	InitHeap(&q->_hp, com);
}

// 向队列中插入元素 
void PriorityQueuePush(PriorityQueue* q, DataType data)
{
	InsertHeap(&q->_hp, data);
}

// 删除优先级最高的元素 
void PriorityQueuePop(PriorityQueue* q)
{
	DeleteHeap(&q->_hp);
}

// 获取优先级队列的元素个数 
int PriorityQueueSize(PriorityQueue* q)
{
	return SizeHeap(&q->_hp);
}

// 检测优先级队列是否为空 
int PriorityQueueEmpty(PriorityQueue* q)
{
	return EmptyHeap(&q->_hp);
}
// 获取堆顶的元素 
DataType PriorityQueueTop(PriorityQueue* q)
{
	return TopHeap(&q->_hp);
}

// 销毁优先级队列 
void PriorityQueueDestroy(PriorityQueue* q)
{
	DestroyHeap(&q->_hp);
}
#endif
//4. 用堆的思想实现堆排序，给出代码实现
void SortHeap(Heap* hp, DataType* array,int size ,Compare com)
{
	int parent = ((size - 2) >> 1);
	for (; parent >= 0; parent--)
		AdjustDown(hp,size, parent);
	while (size>0)
	{
		Swap(&hp->_array[size - 1], &hp->_array[0]);
		--size;
		AdjustDown(hp, size, 0);
	}
}

void AdjustDown(Heap* hp,int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && hp->_com(hp->_array[child + 1], hp->_array[child]))
			child += 1;
		if (hp->_com(hp->_array[child], hp->_array[parent]))
		{
			Swap(&hp->_array[child], &hp->_array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
//5. 用堆解决top - K问题，给出代码实现
void top_k(Heap* hp, DataType* array, int size, int k, Compare com)
{
	DataType* _array=(DataType*)malloc(k*sizeof(array[0]));
	int i = 0;
	for (; i < k; i++)
		_array[i] = array[i];
	CreateHeap(hp, _array, k, Less);
	while (k<size)
	{
		if (hp->_com(TopHeap(hp), array[k]))
		{
			Swap(&hp->_array[0], &array[k]);
			AdjustDown(hp, hp->_size, 0);
		}
		k++;
	}
}