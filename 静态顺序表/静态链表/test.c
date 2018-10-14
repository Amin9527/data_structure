#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void SeqListInit(PSeqList ps)//��ʼ��
{
	DataType i = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		ps->array[i] =NULL;
	}
	ps->size = 0;
}

void SeqListPushBack(PSeqList ps, DataType data)//β��
{
	int i = 0;
	while (ps->array[i] != NULL)
	{
		i++;
		if (i >= MAX_SIZE)
		{
			printf("�ռ�������");
			return;
		}
	}
	ps->array[i] = data;
	ps->size++;
}

void SeqListPopBack(PSeqList ps)//βɾ
{
	ps->size = --ps->size;
	ps->array[ps->size] = NULL;
}

void PrintList(PSeqList ps)//��ӡ����
{
	for (int i = 0; i < ps->size; i++)
	{
		printf(" %d", ps->array[i]);
	}
	printf("\nԪ�ظ�����%d", ps->size);
	printf("\n");
}
void SeqListPushFront(PSeqList ps, DataType data)//ͷ��
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

void SeqListPopFront(PSeqList ps)//ͷɾ
{
	int i = 0;
	while (i < ps->size)
	{
		ps->array[i] = ps->array[i + 1];
		i++;
	}
	ps->size--;
}

void SeqListInsert(PSeqList ps, size_t pos, DataType data)//����λ�ò���ֵΪdata��Ԫ��
{
	if (pos<=0 || pos>ps->size)
	{
		printf("����λ�ô���\n");
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

void SeqListErase(PSeqList ps, size_t pos)//ɾ������λ�õ�Ԫ��
{
	if (pos <= 0 || pos > ps->size)
	{
		printf("ɾ��λ�ô���\n");
		return 0;
	}
	while (pos <= ps->size)
	{
		ps->array[pos - 1] = ps->array[pos];
		pos++;
	}
	ps->size--;
}

int  SeqListFind(PSeqList ps, DataType data)//��˳����в���ֵΪdata��Ԫ�أ����ظ�Ԫ����˳����е��±�
{
	int i = 0,j=0;
	while (i < ps->size)
	{
		if (ps->array[i] == data)
		{
			printf("%d���±�Ϊ%d\n", data,i + 1);
			j++;
        }
		i++;
	}
	if (0 == j)
	{
		printf("���޴�����\n");
	}
}

void SeqListRemove(PSeqList ps, DataType data)//ɾ��˳�����ֵΪdata��Ԫ��
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
	printf("���޴�����\n");
}

void SeqListRemoveAll(PSeqList ps, DataType data)//ɾ��˳���������ֵΪdata��Ԫ��
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
	printf("���޴�����\n");
}

int SeqListEmpty(PSeqList ps)//�ж�˳����Ƿ�Ϊ��
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] != NULL)
		{
			printf("˳���Ϊ�գ�\n");
			return 0;
		}
	}
	printf("��˳���Ϊ��˳���\n");
}

int SeqListSize(PSeqList ps)//��ȡ˳�����Ԫ�ظ���
{
	printf("Ԫ�ر��еĸ���Ϊ%d����\n", ps->size);
}

/////////////////////////////////////////////////////////////////////////////////��������


void BubbleSort(PSeqList ps)//��ð�������˳����е�Ԫ�ؽ�������
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

void SelectSort(PSeqList ps)//��ѡ�������˳����е�Ԫ�ؽ�������
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

void SelectSort_Op(PSeqList ps)//ѡ�������Ż�����һ���ҳ������СԪ������λ��
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
			printf("%dΪ��СԪ�أ��±�Ϊ%d��\n", TmpMin, i + 1);
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
			printf("%dΪ���Ԫ�أ��±�Ϊ%d��\n", TmpMax, i + 1);
		}
	}
	
}
