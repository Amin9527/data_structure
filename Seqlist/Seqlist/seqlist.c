#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqDList.h"

int main()
{
	SeqListD ListD;
	SeqListDInit(&ListD);
	SeqListDPushBack(&ListD, 1);
	SeqListDPushBack(&ListD, 2);
	SeqListDPushBack(&ListD, 2);
	SeqListDPushBack(&ListD, 2);
	SeqListDPushBack(&ListD, 2);
	SeqListDPushBack(&ListD, 2);
	SeqListDPushBack(&ListD, 2);
	SeqListDPrint(&ListD);
	CheckCapacity(&ListD);
	SeqListDPopBack(&ListD);//βɾ
	SeqListDPrint(&ListD);
	SeqListDEmpty(&ListD);//�ж��Ƿ�Ϊ������
	SeqListDPushBack(&ListD, 5);
	CheckCapacity(&ListD);
	SeqListDPushBack(&ListD, 8);
	SeqListDPushBack(&ListD, 6);
	SeqListDPrint(&ListD);
	SeqListDDestroy(&ListD);
	SeqListDPrint(&ListD);
	system("pause");
	return 0;
}