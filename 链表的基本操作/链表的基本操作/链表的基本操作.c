#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

int main()
{
	PNode pHead,pHead1,pHead3;
	SListInit(&pHead);
	SListInit(&pHead1);
	SListInit(&pHead3);

	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 8);

	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintListFromTail2Head(pHead);
	PNode p1 = SListBack(pHead);
	p1->_pNext = SListFind(&pHead1, 6);
	PrintListFromTail2Head(pHead);
	DeleteLastKNode(pHead, 7);
	PrintListFromTail2Head(pHead);

	//SListPushBack(&pHead, 7);

	

	//SListPopBack(&pHead);
	//SListPushFront(&pHead, 4);
	//SListPushBack(&pHead, 3);
	//SListPopFront(&pHead);
	//SListPushBack(&pHead, 5);
	//SListFind(&pHead, 3);
	//SListInsert(&pHead, SListFind(&pHead, 3), 2);
	//SListErase(SListFind(&pHead, 2));
	//SListDestroy(&pHead);
	//SListSize(pHead);
	//SListClear(&pHead);
	//BuySListNode(7);
	//SListBack(pHead);
	//InsertPosFront(SListFind(&pHead,6), 2);
	//BubbleSort(pHead);
	//JosephCircle(&pHead, 3);
	//ReverseSList(&pHead);
	//ReverseSListOP(&pHead);
	IsCircle(pHead);
	pHead3=MergeSList(pHead, pHead1);
	PNode Mid=FindMiddleNode(pHead3);
	PNode LastK = FindLastKNode(pHead3, 4);
	
	int i=IsCrossWithoutCircle(pHead, pHead1);
	PNode CNode = GetCrossNode(pHead, pHead1);
	PNode p2 = SListBack(pHead);
	p2->_pNext = SListFind(&pHead, 4);
	IsCircle(pHead);
	GetCircleLen(pHead);
	PNode EnterNode=GetEnterNode(pHead, IsCircle(pHead));
	printf("%d\n", EnterNode->_data);



	system("pause");
	return 0;
}