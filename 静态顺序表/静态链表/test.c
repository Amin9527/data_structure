#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SeqListInit(PSeqList ps)//初始化
{
	DataType i = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		ps->array[i] =NULL;
	}
	ps->size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//尾插
{
	int i = 0;
	while (ps->array[i] != NULL)
	{
		i++;
		if (i >= MAX_SIZE)
		{
			printf("空间已满！");
			return;
		}
	}
	ps->array[i] = data;
	ps->size++;
}

void SeqListPopBack(PSeqList ps)//尾删
{
	ps->size = --ps->size;
	ps->array[ps->size] = NULL;
}

void PrintList(PSeqList ps)//打印函数
{
	for (int i = 0; i < ps->size; i++)
	{
		printf(" %d", ps->array[i]);
	}
	printf("\n元素个数：%d", ps->size);
	printf("\n");
}
void SeqListPushFront(PSeqList ps, DataType data)//头插
{
	int i = ps->size;
	while (i > 0)
	{
		ps->array[i] = ps->array[i-1];
		i--;
	}
	ps->array[i] = data;
	ps->size++;
}

void SeqListPopFront(PSeqList ps)//头删
{
	int i = 0;
	while (i < ps->size)
	{
		ps->array[i] = ps->array[i + 1];
		i++;
	}
	ps->size--;
}

void SeqListInsert(PSeqList ps, size_t pos, DataType data)//任意位置插入值为data的元素
{
	if (pos<=0 || pos>ps->size)
	{
		printf("插入位置错误！\n");
		return ;
	}
	int i = 0;
	i = ps->size;
	while (i >= pos)
	{
		ps->array[i] = ps->array[i - 1];
		i--;
	}
	ps->array[i] = data;
	ps->size++;
}

void SeqListErase(PSeqList ps, size_t pos)//删除任意位置的元素
{
	if (pos <= 0 || pos > ps->size)
	{
		printf("删除位置错误！\n");
		return 0;
	}
	while (pos <= ps->size)
	{
		ps->array[pos - 1] = ps->array[pos];
		pos++;
	}
	ps->size--;
}

int  SeqListFind(PSeqList ps, DataType data)//在顺序表中查找值为data的元素，返回该元素在顺序表中的下标
{
	int i = 0,j=0;
	while (i < ps->size)
	{
		if (ps->array[i] == data)
		{
			printf("%d的下标为%d\n", data,i + 1);
			j++;
        }
		i++;
	}
	if (0 == j)
	{
		printf("查无此数！\n");
	}
}

void SeqListRemove(PSeqList ps, DataType data)//删除顺序表中值为data的元素
{
	int i = 0;
	while (i < ps->size)
	{
		if (data == ps->array[i])
		{
			while (i < ps->size)
			{
				ps->array[i] = ps->array[i + 1];
				i++;
			}
			ps->size--;
			return;
		}
		i++;
	}
	printf("查无此数！\n");
}

void SeqListRemoveAll(PSeqList ps, DataType data)//删除顺序表中所有值为data的元素
{
flag:;
	int i = 0;
	while (i < ps->size)
	{
		if (data == ps->array[i])
		{
			while (i < ps->size)
			{
				ps->array[i] = ps->array[i + 1];
				i++;
			}
			ps->size--;
			goto flag;
		}
		i++;
	}
	printf("查无此数！\n");
}

int SeqListEmpty(PSeqList ps)//判断顺序表是否为空
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] != NULL)
		{
			printf("顺序表不为空！\n");
			return 0;
		}
	}
	printf("此顺序表为空顺序表！\n");
}

int SeqListSize(PSeqList ps)//获取顺序表中元素个数
{
	printf("元素表中的个数为%d个！\n", ps->size);
}

/////////////////////////////////////////////////////////////////////////////////辅助操作


void BubbleSort(PSeqList ps)//用冒泡排序对顺序表中的元素进行排序
{
	int i = 0, j = 0,tmp=0;
	for (i = ps->size-1; i>0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (ps->array[j]>ps->array[j + 1])
			{
				tmp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = tmp;
				
			}
		}
	}

}

void SelectSort(PSeqList ps)//用选择排序对顺序表中的元素进行排序
{
	int i = 0,tmp=0,j=0;
	for (i = 0; i < ps->size-1; i++)
	{
		for (j = i+1; j < ps->size; j++)
		{
			if (ps->array[j] < ps->array[i])
			{
				tmp = ps->array[j];
				ps->array[j] = ps->array[i];
				ps->array[i] = tmp;
			}
		}
	}

}

void SelectSort_Op(PSeqList ps)//选择排序优化——一次找出最大最小元素所在位置
{
	int TmpMax = ps->array[0],i=0,TmpMin=ps->array[0];
	for (i = 0; i < ps->size; i++)
	{
		if (TmpMin<ps->array[i])
		{
			TmpMin = TmpMin;
		}
		else
		{
			TmpMin = ps->array[i];
		}
	}
	for (i = 0; i < ps->size; i++)
	{
		if (TmpMin == ps->array[i])
		{
			printf("%d为最小元素！下标为%d！\n", TmpMin, i + 1);
		}
	}
	for (i = 0; i < ps->size; i++)
	{
		if (TmpMax>ps->array[i])
		{
			TmpMax = TmpMax;
		}
		else
		{
			TmpMax = ps->array[i];
		}
	}
	for (i = 0; i < ps->size; i++)
	{
		if (TmpMax == ps->array[i])
		{
			printf("%d为最大元素！下标为%d！\n", TmpMax, i + 1);
		}
	}
	
}
