#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#if 0

//�ѵĳ�ʼ��
void InitHeap(Heap* hp)
{
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
// ������ 
void CreateHeap(Heap* hp, DataType* array, int size)
{
	int n = 0;
	hp->_array = (DataType*)malloc(size*sizeof(DataType));
	for (n=0; n<size; n++)
		hp->_array[n] = array[n];
	hp->_capacity = size;
	hp->_size = size;
	//������
	int parent = ((size - 2)/2);
	AdjustDown(hp, parent);
}
//������
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
// �ڶ��в���ֵΪdata��Ԫ�� 
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

//���ϵ���
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
// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return NULL;
	}
	return hp->_array[0];
}

// ���һ�����Ƿ�Ϊ�ն� 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
		return 0;
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return 0;
	}
	return hp->_size;
}

// ɾ���Ѷ�Ԫ�� 
void DeleteHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;
	int parent = 0;
	AdjustDown(hp, parent);
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_array);
	hp = NULL;
}

#endif

//2. �Զѽ����Ż���һ�ݴ���ȿ��Դ�������Ҳ���Դ�����С��


// �ѵĳ�ʼ�� 
void InitHeap(Heap* hp, Compare com)
{
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_com = com;
}
// ������ 
void CreateHeap(Heap* hp, DataType* array, int size, Compare com)
{
	int n = 0;
	hp->_array = (DataType*)malloc(size*sizeof(DataType));
	for (n = 0; n<size; n++)
		hp->_array[n] = array[n];
	hp->_capacity = size;
	hp->_size = size;
	hp->_com = com;
	//������
	int parent = ((size - 2) / 2);
	for (; parent >= 0;parent--)
		AdjustDown(hp, hp->_size, parent);
}

//������--���µ���
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

//���ϵ���
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
// �ڶ��в���ֵΪdata��Ԫ�� 
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

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return NULL;
	}
	return hp->_array[0];
}

// ���һ�����Ƿ�Ϊ�ն� 
int EmptyHeap(Heap* hp)
{
	if (hp == NULL)
		return 0;
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// ��ȡ����Ԫ�صĸ��� 
int SizeHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return 0;
	}
	return hp->_size;
}

// ɾ���Ѷ�Ԫ�� 
void DeleteHeap(Heap* hp)
{
	if (hp == NULL)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;
	int parent = 0;
	AdjustDown(hp,hp->_size, parent);
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	free(hp->_array);
	hp = NULL;
}

// ����Ԫ�رȽϵıȽ��� 
// С�ں� 
int Less(DataType left, DataType right)
{
	return left < right;
}

// ���ں�
int Greater(DataType left, DataType right)
{
	return left > right;
}
#if 0
//3. �ѵ�Ӧ��֮���ȼ����У��öѷ�װ���ȼ�����
//typedef struct PriorityQueue
//{
//	Heap _hp;
//}PriorityQueue;

// ���ȼ����г�ʼ�� 
void PriorityQueueInit(PriorityQueue* q, Compare com)
{
	InitHeap(&q->_hp, com);
}

// ������в���Ԫ�� 
void PriorityQueuePush(PriorityQueue* q, DataType data)
{
	InsertHeap(&q->_hp, data);
}

// ɾ�����ȼ���ߵ�Ԫ�� 
void PriorityQueuePop(PriorityQueue* q)
{
	DeleteHeap(&q->_hp);
}

// ��ȡ���ȼ����е�Ԫ�ظ��� 
int PriorityQueueSize(PriorityQueue* q)
{
	return SizeHeap(&q->_hp);
}

// ������ȼ������Ƿ�Ϊ�� 
int PriorityQueueEmpty(PriorityQueue* q)
{
	return EmptyHeap(&q->_hp);
}
// ��ȡ�Ѷ���Ԫ�� 
DataType PriorityQueueTop(PriorityQueue* q)
{
	return TopHeap(&q->_hp);
}

// �������ȼ����� 
void PriorityQueueDestroy(PriorityQueue* q)
{
	DestroyHeap(&q->_hp);
}
#endif
//4. �öѵ�˼��ʵ�ֶ����򣬸�������ʵ��
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
//5. �öѽ��top - K���⣬��������ʵ��
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