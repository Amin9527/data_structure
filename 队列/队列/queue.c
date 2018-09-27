#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

// ���еĳ�ʼ�� 
void QueueInit(Queue* q)
{
	
	q->_pTail= NULL;
	q->_pHead = NULL;

}

// ����� 
void QueuePush(Queue* q, QDataType data)
{
	PNode Node=PHead;
	Node = (PNode)malloc(sizeof(Node));
	if (NULL == Node)
	{
		printf("�����ʧ�ܣ�\n");
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

// ������ 
void QueuePop(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("����Ϊ�գ�\n");
		return;
	}
	q->_pHead = q->_pHead->_pNext;
}

// ȡ��ͷԪ�� 
QDataType QueueFront(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("����Ϊ�գ�\n");
		return NULL;
	}
	//printf("��ͷԪ��Ϊ%d\n", q->_pHead->_data);
	return q->_pHead->_data;
}

// ȡ��βԪ�� 
QDataType QueueBack(Queue* q)
{
	if (q->_pHead == NULL)
	{
		printf("����Ϊ�գ�\n");
		return NULL;
	}
	//printf("��βԪ��Ϊ%d\n", q->_pTail->_data);
	return q->_pTail->_data;
}

// ��ȡ������Ԫ�صĸ��� 
int QueueSize(Queue* q)
{
	if (q->_pHead == NULL)
	{
		printf("������Ԫ�ظ���Ϊ0!");
		return 0;
	}
	int count = 1;
	PNode n = q->_pHead;
	while (n != q->_pTail)
	{
		n = n->_pNext;
		count++;
	}
	printf("������Ԫ�صĸ���Ϊ%d\n", count);
	return count;
}

// �������Ƿ�Ϊ�� 
int QueueEmpty(Queue* q)
{
	if (q->_pHead == NULL)
	{
		//printf("����Ϊ�գ�\n");
		return 0;
	}
	else
	{
		//printf("���в�Ϊ�գ�\n");
		return 1;
	}
}