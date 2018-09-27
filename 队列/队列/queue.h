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

// ���еĳ�ʼ�� 
void QueueInit(Queue* q);

// ����� 
void QueuePush(Queue* q, QDataType data);

// ������ 
void QueuePop(Queue* q);

// ȡ��ͷԪ�� 
QDataType QueueFront(Queue* q);

// ȡ��βԪ�� 
QDataType QueueBack(Queue* q);

// ��ȡ������Ԫ�صĸ��� 
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�� 
int QueueEmpty(Queue* q);