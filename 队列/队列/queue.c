#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

// 队列的初始化 
void QueueInit(Queue* q)
{
	
	q->_pTail= NULL;
	q->_pHead = NULL;

}

// 入队列 
void QueuePush(Queue* q, QDataType data)
{
	PNode Node=PHead;
	Node = (PNode)malloc(sizeof(Node));
	if (NULL == Node)
	{
		printf("入队列失败！\n");
		return;
	}
	Node->_data = data;
	Node->_pNext = NULL;
	if (q->_pHead == NULL)
	{
		q->_pHead = Node;
		q->_pTail = Node;
	}
	else
	{
		q->_pTail->_pNext = Node;
		q->_pTail = Node;
	}
}

// 出队列 
void QueuePop(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("队列为空！\n");
		return;
	}
	q->_pHead = q->_pHead->_pNext;
}

// 取队头元素 
QDataType QueueFront(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("队列为空！\n");
		return NULL;
	}
	//printf("队头元素为%d\n", q->_pHead->_data);
	return q->_pHead->_data;
}

// 取队尾元素 
QDataType QueueBack(Queue* q)
{
	if (q->_pHead == NULL)
	{
		printf("队列为空！\n");
		return NULL;
	}
	//printf("队尾元素为%d\n", q->_pTail->_data);
	return q->_pTail->_data;
}

// 获取队列中元素的个数 
int QueueSize(Queue* q)
{
	if (q->_pHead == NULL)
	{
		printf("队列中元素个数为0!");
		return 0;
	}
	int count = 1;
	PNode n = q->_pHead;
	while (n != q->_pTail)
	{
		n = n->_pNext;
		count++;
	}
	printf("队列中元素的个数为%d\n", count);
	return count;
}

// 检测队列是否为空 
int QueueEmpty(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("队列为空！\n");
		return 0;
	}
	else
	{
		//printf("队列不为空！\n");
		return 1;
	}
}