#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

int main()
{
	PNode PHead;
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePop(&queue);
	QueueFront(&queue);
	QueueBack(&queue);
	QueueSize(&queue);
	QueueEmpty(&queue);
	system("pause");
	return 0;
}