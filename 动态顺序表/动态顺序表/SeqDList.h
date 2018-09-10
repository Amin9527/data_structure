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
	size_t _capacity; // 底层空间的大小 
	size_t _size; // 有效元素的个数 
}SeqListD, *PSeqListD;


///////////////////////////////////////////////// 
void SeqListDInit(PSeqListD ps);//初始化
void SeqListDPushBack(PSeqListD ps, DataType data);//尾插
void SeqListDPopBack(PSeqListD ps);//尾删
void SeqListDPrint(PSeqListD ps);//打印顺序表
int SeqListDEmpty(PSeqListD ps);//判断是否为空顺序表
int SeqListDSize(PSeqListD ps);//顺序表中元素的个数

// 清空顺序表中的所有元素，注意不改变底层空间的大小 
void SeqListDClear(PSeqListD ps);
int SeqListDCapacity(PSeqListD ps);//查看容量

// 销毁顺序表 
void SeqListDDestroy(PSeqListD ps);

// 检测顺序表是否需要增容 
int CheckCapacity(PSeqListD ps);