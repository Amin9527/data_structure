#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

int main()
{
	seqlist ListS;
	SeqListInit(&ListS);
	PrintList(&ListS);
	SeqListPushBack(&ListS, 5);
	SeqListPushBack(&ListS, 2);
	SeqListPushBack(&ListS, 3);
	SeqListPushBack(&ListS, 4);
	SeqListPushBack(&ListS, 4);
	SeqListPushBack(&ListS, 9);
	SeqListPushBack(&ListS, 6);
	SeqListPushBack(&ListS, 1);



	PrintList(&ListS);
	SeqListPopBack(&ListS);
	PrintList(&ListS);
	SeqListPushFront(&ListS, 4);
	PrintList(&ListS);
	SeqListPopFront(&ListS);
	PrintList(&ListS);
	SeqListInsert(&ListS, 2, 9);
	PrintList(&ListS);
	SeqListErase(&ListS, 2);
	PrintList(&ListS);
	SeqListFind(&ListS, 8);
	PrintList(&ListS);
	//SeqListRemove(&ListS, 4);
	//PrintList(&ListS);
	SeqListRemoveAll(&ListS, 4);
	PrintList(&ListS);
	SeqListEmpty(&ListS);
	SeqListSize(&ListS);
	//BubbleSort(&ListS);
	//PrintList(&ListS);
	SelectSort(&ListS);
	PrintList(&ListS);
	SelectSort_Op(&ListS);


	system("pause");
	return 0;
}