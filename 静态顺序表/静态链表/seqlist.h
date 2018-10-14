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

void SeqListInit(PSeqList ps);//初始化
void SeqListPushBack(PSeqList ps, DataType data);//尾插
void SeqListPopBack(PSeqList ps);//尾删
void SeqListPushFront(PSeqList ps, DataType data);//头插
void SeqListPopFront(PSeqList ps);//头删
void SeqListInsert(PSeqList ps, size_t pos, DataType data);//任意位置插入值为data的元素
void SeqListErase(PSeqList ps, size_t pos);//删除任意位置的元素
int  SeqListFind(PSeqList ps, DataType data);//在顺序表中查找值为data的元素，返回该元素在顺序表中的下标
void SeqListRemove(PSeqList ps, DataType data);//删除顺序表中值为data的元素
void SeqListRemoveAll(PSeqList ps, DataType data);//删除顺序表中所有值为data的元素
int SeqListEmpty(PSeqList ps);//判断顺序表是否为空
int SeqListSize(PSeqList ps);//获取顺序表中元素个数
/////////////////////////////////////////////////////////////////////////////////辅助操作
void printSeqList(PSeqList ps);//打印顺序表中的元素
void BubbleSort(PSeqList ps);//用冒泡排序对顺序表中的元素进行排序
void SelectSort(PSeqList ps);//用选择排序对顺序表中的元素进行排序
void SelectSort_Op(PSeqList ps);//选择排序优化——一次找出最大最小元素所在位置


