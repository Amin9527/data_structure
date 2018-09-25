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
////��ʼ����
//void InitHeap(Heap* hp);
//
////������ֵ
//void Swap(DataType* a, DataType* b);
//
////���µ���
//void AdjustDown(Heap* hp, int parent);
//
//// ������ 
//void CreateHeap(Heap* hp, DataType* array, int size);
//
////���ϵ���
//void AdjustUp(Heap* hp, int child);
//
//// �ڶ��в���ֵΪdata��Ԫ�� 
//void InsertHeap(Heap* hp, DataType data);
//
//// ��ȡ�Ѷ�Ԫ�� 
//DataType TopHeap(Heap* hp);
//
//// ���һ�����Ƿ�Ϊ�ն� 
//int EmptyHeap(Heap* hp);
//
//// ��ȡ����Ԫ�صĸ��� 
//int SizeHeap(Heap* hp);
//
//// ɾ���Ѷ�Ԫ�� 
//void DeleteHeap(Heap* hp);
//
//// ���ٶ� 
//void DestroyHeap(Heap* hp);

//2. �Զѽ����Ż���һ�ݴ���ȿ��Դ�������Ҳ���Դ�����С��
#if 1
typedef int(*Compare)(DataType, DataType);

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare _com;
}Heap;

// �ѵĳ�ʼ�� 
void InitHeap(Heap* hp, Compare com);

// ������ 
void CreateHeap(Heap* hp, DataType* array, int size, Compare com);

//������ֵ
void Swap(DataType* a, DataType* b);

//���µ���
//void AdjustDown(Heap* hp, int parent);

//���ϵ���
void AdjustUp(Heap* hp, int child);

// �ڶ��в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data);

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp);

// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* hp);

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp);

// ɾ���Ѷ���Ԫ�� 
void DeleteHeap(Heap* hp);

// ���ٶ� 
void DestroyHeap(Heap* hp);

// ����Ԫ�رȽϵıȽ��� 
// С�ں� 
int Less(DataType left, DataType right);

// ���ں� 
int Greater(DataType left, DataType right);

#endif

#if 0
//3. �ѵ�Ӧ��֮���ȼ����У��öѷ�װ���ȼ�����
typedef struct PriorityQueue
{
	Heap _hp;
}PriorityQueue;
PriorityQueue q;
// ���ȼ����г�ʼ�� 
void PriorityQueueInit(PriorityQueue* q, Compare com);

// ������в���Ԫ�� 
void PriorityQueuePush(PriorityQueue* q, DataType data);

// ɾ�����ȼ���ߵ�Ԫ�� 
void PriorityQueuePop(PriorityQueue* q);

// ��ȡ���������ȼ���ߵ�Ԫ�� 
int PriorityQueueSize(PriorityQueue* q);

// ������ȼ������Ƿ�Ϊ�� 
int PriorityQueueEmpty(PriorityQueue* q);

// ��ȡ�Ѷ���Ԫ�� 
DataType PriorityQueueTop(PriorityQueue* q);

// �������ȼ����� 
void PriorityQueueDestroy(PriorityQueue* q);
#endif
//4. �öѵ�˼��ʵ�ֶ����򣬸�������ʵ��
void SortHeap(Heap* hp, DataType* array,int size, Compare com);
void AdjustDown(Heap* hp, int size, int parent);
//5. �öѽ��top - K���⣬��������ʵ��
void top_k(Heap* hp, DataType* array, int size, int k, Compare com);