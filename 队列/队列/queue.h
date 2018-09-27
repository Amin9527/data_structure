#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
extern struct PBTNode;
typedef struct PBTNode* QDataType;
//typedef int QDataType;
typedef struct Node
{
	QDataType _data;
	struct Node* _pNext;
}Node, *PNode;

PNode PHead;
typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;

// 队列的初始化 
void QueueInit(Queue* q);

// 入队列 
void QueuePush(Queue* q, QDataType data);

// 出队列 
void QueuePop(Queue* q);

// 取队头元素 
QDataType QueueFront(Queue* q);

// 取队尾元素 
QDataType QueueBack(Queue* q);

// 获取队列中元素的个数 
int QueueSize(Queue* q);

// 检测队列是否为空 
int QueueEmpty(Queue* q);