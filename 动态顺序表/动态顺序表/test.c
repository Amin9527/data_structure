#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqDList.h"

void SeqListDInit(PSeqListD ps)//��ʼ��
{
	int i = 0;
	ps->_array = (DataType *)malloc(List_Init_Size*sizeof(DataType));
	if (ps->_array == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		return;
	}
	for (i = 0; i < List_Init_Size; i++)
	{
		ps->_array[i] = NULL;
	}
	ps->_capacity = 8;
	ps->_size = 0;
}
void SeqListDPushBack(PSeqListD ps, DataType data)//β��
{
	if (ps->_size == ps->_capacity)
	{
		int * pp = (DataType *)realloc(ps->_array, (List_Init_Size + ListIncrement)*sizeof(DataType));
		if (pp == NULL)
		{
			printf("����ʧ�ܣ�\n");
			return;
		}
		ps->_array = pp;
		ps->_capacity = ps->_capacity + ListIncrement;
	}
	ps->_array[ps->_size]=data;
	ps->_size++;
	return;
}

void SeqListDPopBack(PSeqListD ps)//βɾ
{
	ps->_array[ps->_size - 1] = NULL;
	ps->_size--;
}

void SeqListDPrint(PSeqListD ps)//��ӡ˳���
{
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\nԪ�ظ���Ϊ%d!\n", ps->_size);
	printf("˳�������Ϊ%d!\n", ps->_capacity);
}

int SeqListDEmpty(PSeqListD ps)//�ж��Ƿ�Ϊ������
{
	if (0 == ps->_size)
	{
		printf("�˶�̬˳���Ϊ�գ�\n");
		return;
	}
	else
	{
		printf("�˶�̬˳���Ϊ�գ�\n");
		return;
	}
}
int SeqListDSize(PSeqListD ps)//˳�����Ԫ�صĸ���
{
	printf("��̬˳����е�Ԫ�ظ���Ϊ%d��\n", ps->_size);
}
// ���˳����е�����Ԫ�أ�ע�ⲻ�ı�ײ�ռ�Ĵ�С 
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
	printf("��̬˳��������Ϊ%d!\n", ps->_capacity);
	return;
}

// ����˳��� 
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

// ���˳����Ƿ���Ҫ���� 
int CheckCapacity(PSeqListD ps)
{
	if (ps->_size >= ps->_capacity)
	{
		printf("�������㣬��Ҫ���ݣ�\n");
		return;
	}
	else
	{
		printf("�����������������ݣ�\n");
		return;
	}
}