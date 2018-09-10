#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqDList.h"

void SeqListDInit(PSeqListD ps)//初始化
{
	int i = 0;
	ps->_array = (DataType *)malloc(List_Init_Size*sizeof(DataType));
	if (ps->_array == NULL)
	{
		printf("申请空间失败！\n");
		return;
	}
	for (i = 0; i < List_Init_Size; i++)
	{
		ps->_array[i] = NULL;
	}
	ps->_capacity = 8;
	ps->_size = 0;
}
void SeqListDPushBack(PSeqListD ps, DataType data)//尾插
{
	if (ps->_size == ps->_capacity)
	{
		int * pp = (DataType *)realloc(ps->_array, (List_Init_Size + ListIncrement)*sizeof(DataType));
		if (pp == NULL)
		{
			printf("扩容失败！\n");
			return;
		}
		ps->_array = pp;
		ps->_capacity = ps->_capacity + ListIncrement;
	}
	ps->_array[ps->_size]=data;
	ps->_size++;
	return;
}

void SeqListDPopBack(PSeqListD ps)//尾删
{
	ps->_array[ps->_size - 1] = NULL;
	ps->_size--;
}

void SeqListDPrint(PSeqListD ps)//打印顺序表
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\n元素个数为%d!\n", ps->_size);
	printf("顺序表容量为%d!\n", ps->_capacity);
}

int SeqListDEmpty(PSeqListD ps)//判断是否为空链表
{
	if (0 == ps->_size)
	{
		printf("此动态顺序表为空！\n");
		return;
	}
	else
	{
		printf("此动态顺序表不为空！\n");
		return;
	}
}
int SeqListDSize(PSeqListD ps)//顺序表中元素的个数
{
	printf("动态顺序表中的元素个数为%d！\n", ps->_size);
}
// 清空顺序表中的所有元素，注意不改变底层空间的大小 
void SeqListDClear(PSeqListD ps)
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = NULL;
	}
}
int SeqListDCapacity(PSeqListD ps)
{
	printf("动态顺序表的容量为%d!\n", ps->_capacity);
	return;
}

// 销毁顺序表 
void SeqListDDestroy(PSeqListD ps)
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		ps->_array[i] = NULL;
	}
	ps->_capacity = 0;
	ps->_size = 0;
	free(ps->_array);
	return;
}

// 检测顺序表是否需要增容 
int CheckCapacity(PSeqListD ps)
{
	if (ps->_size >= ps->_capacity)
	{
		printf("容量不足，需要扩容！\n");
		return;
	}
	else
	{
		printf("还有容量，不需扩容！\n");
		return;
	}
}