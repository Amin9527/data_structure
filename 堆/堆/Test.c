#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
int main()
{
	int i = 0;
	Heap hp;
	//PriorityQueue q;
	int array[] = { 98, 8, 13, 96, 11, 9, 999,520,1314 };
	int size = sizeof(array) / sizeof(array[0]);
	InitHeap(&hp,NULL);
	//CreateHeap(&hp, array, size,Greater);
	/*InsertHeap(&hp, 100);
	DeleteHeap(&hp);
	DestroyHeap(&hp);*/
	/*PriorityQueueInit(&q, Greater);
	PriorityQueuePush(&q, 3);
	PriorityQueuePush(&q, 5);
	PriorityQueuePush(&q, 1);
	PriorityQueuePush(&q, 4);
	PriorityQueuePush(&q, 2);
	PriorityQueueSize(&q);
	PriorityQueuePop(&q);
	PriorityQueueSize(&q);*/
	/*SortHeap(&hp, array,size, Greater);
	for (; i < size;i++)
	printf("%d ", hp._array[i]);*/
	top_k(&hp,array,size,6,Less);
	SortHeap(&hp, hp._array, hp._size, Less);
	printf("从大到下的前%d个数为：\n", hp._size);
	for (; i < hp._size; i++)
		printf("%d ", hp._array[i]);
	system("pause");
	return 0;
}