#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef unsigned int size_t;
#define List_Init_Size 8
#define ListIncrement 2

typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity; // �ײ�ռ�Ĵ�С 
	size_t _size; // ��ЧԪ�صĸ��� 
}SeqListD, *PSeqListD;


///////////////////////////////////////////////// 
void SeqListDInit(PSeqListD ps);//��ʼ��
void SeqListDPushBack(PSeqListD ps, DataType data);//β��
void SeqListDPopBack(PSeqListD ps);//βɾ
void SeqListDPrint(PSeqListD ps);//��ӡ˳���
int SeqListDEmpty(PSeqListD ps);//�ж��Ƿ�Ϊ��˳���
int SeqListDSize(PSeqListD ps);//˳�����Ԫ�صĸ���

// ���˳����е�����Ԫ�أ�ע�ⲻ�ı�ײ�ռ�Ĵ�С 
void SeqListDClear(PSeqListD ps);
int SeqListDCapacity(PSeqListD ps);//�鿴����

// ����˳��� 
void SeqListDDestroy(PSeqListD ps);

// ���˳����Ƿ���Ҫ���� 
int CheckCapacity(PSeqListD ps);