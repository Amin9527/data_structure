#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;




// 
//typedef struct Heap
//{
//	DataType* _array;
//	int _capacity;
//	int _size;
//}Heap;
//Heap hp;
////初始化堆
//void InitHeap(Heap* hp);
//
////交换数值
//void Swap(DataType* a, DataType* b);
//
////向下调整
//void AdjustDown(Heap* hp, int parent);
//
//// 创建堆 
//void CreateHeap(Heap* hp, DataType* array, int size);
//
////向上调整
//void AdjustUp(Heap* hp, int child);
//
//// 在堆中插入值为data的元素 
//void InsertHeap(Heap* hp, DataType data);
//
//// 获取堆顶元素 
//DataType TopHeap(Heap* hp);
//
//// 检测一个堆是否为空堆 
//int EmptyHeap(Heap* hp);
//
//// 获取堆中元素的个数 
//int SizeHeap(Heap* hp);
//
//// 删除堆顶元素 
//void DeleteHeap(Heap* hp);
//
//// 销毁堆 
//void DestroyHeap(Heap* hp);

//2. 对堆进行优化，一份代码既可以创建最大堆也可以创建最小堆
#if 1
typedef int(*Compare)(DataType, DataType);

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare _com;
}Heap;

// 堆的初始化 
void InitHeap(Heap* hp, Compare com);

// 创建堆 
void CreateHeap(Heap* hp, DataType* array, int size, Compare com);

//交换数值
void Swap(DataType* a, DataType* b);

//向下调整
//void AdjustDown(Heap* hp, int parent);

//向上调整
void AdjustUp(Heap* hp, int child);

// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data);

// 检测堆是否为空 
int EmptyHeap(Heap* hp);

// 获取堆中元素的个数 
int SizeHeap(Heap* hp);

// 获取堆顶元素 
DataType TopHeap(Heap* hp);

// 删除堆顶的元素 
void DeleteHeap(Heap* hp);

// 销毁堆 
void DestroyHeap(Heap* hp);

// 用于元素比较的比较器 
// 小于号 
int Less(DataType left, DataType right);

// 大于好 
int Greater(DataType left, DataType right);

#endif

#if 0
//3. 堆的应用之优先级队列，用堆封装优先级队列
typedef struct PriorityQueue
{
	Heap _hp;
}PriorityQueue;
PriorityQueue q;
// 优先级队列初始化 
void PriorityQueueInit(PriorityQueue* q, Compare com);

// 向队列中插入元素 
void PriorityQueuePush(PriorityQueue* q, DataType data);

// 删除优先级最高的元素 
void PriorityQueuePop(PriorityQueue* q);

// 获取队列中优先级最高的元素 
int PriorityQueueSize(PriorityQueue* q);

// 检测优先级队列是否为空 
int PriorityQueueEmpty(PriorityQueue* q);

// 获取堆顶的元素 
DataType PriorityQueueTop(PriorityQueue* q);

// 销毁优先级队列 
void PriorityQueueDestroy(PriorityQueue* q);
#endif
//4. 用堆的思想实现堆排序，给出代码实现
void SortHeap(Heap* hp, DataType* array,int size, Compare com);
void AdjustDown(Heap* hp, int size, int parent);
//5. 用堆解决top - K问题，给出代码实现
void top_k(Heap* hp, DataType* array, int size, int k, Compare com);