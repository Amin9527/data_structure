#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
#define LISTINCREMENT 5
typedef int DataType;
typedef unsigned int size_t;
typedef struct seqlist
{
	DataType array[MAX_SIZE];
	DataType size;

}seqlist,*PSeqList;

void SeqListInit(PSeqList ps);//��ʼ��
void SeqListPushBack(PSeqList ps, DataType data);//β��
void SeqListPopBack(PSeqList ps);//βɾ
void SeqListPushFront(PSeqList ps, DataType data);//ͷ��
void SeqListPopFront(PSeqList ps);//ͷɾ
void SeqListInsert(PSeqList ps, size_t pos, DataType data);//����λ�ò���ֵΪdata��Ԫ��
void SeqListErase(PSeqList ps, size_t pos);//ɾ������λ�õ�Ԫ��
int  SeqListFind(PSeqList ps, DataType data);//��˳����в���ֵΪdata��Ԫ�أ����ظ�Ԫ����˳����е��±�
void SeqListRemove(PSeqList ps, DataType data);//ɾ��˳�����ֵΪdata��Ԫ��
void SeqListRemoveAll(PSeqList ps, DataType data);//ɾ��˳���������ֵΪdata��Ԫ��
int SeqListEmpty(PSeqList ps);//�ж�˳����Ƿ�Ϊ��
int SeqListSize(PSeqList ps);//��ȡ˳�����Ԫ�ظ���
/////////////////////////////////////////////////////////////////////////////////��������
void printSeqList(PSeqList ps);//��ӡ˳����е�Ԫ��
void BubbleSort(PSeqList ps);//��ð�������˳����е�Ԫ�ؽ�������
void SelectSort(PSeqList ps);//��ѡ�������˳����е�Ԫ�ؽ�������
void SelectSort_Op(PSeqList ps);//ѡ�������Ż�����һ���ҳ������СԪ������λ��


