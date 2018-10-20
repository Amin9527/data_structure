#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

// �����ʼ�� 
void SListInit(PNode* pHead)
{
	*pHead = NULL;
	assert(pHead);
}

// β�� 
void SListPushBack(PNode* pHead, DataType data)
{
	PNode phead = *pHead;
	PNode NextNode = NULL;
	if (*pHead == NULL)
	{
		*pHead = (PNode)malloc(sizeof(Node));
		if (*pHead == NULL)
		{
			printf("���ٿռ�ʧ�ܣ�\n");
			return;
		}
		(*pHead)->_pNext = NULL;
		(*pHead)->_data = data;

	}
	else
	{
		while (phead->_pNext)
		{
			phead = phead->_pNext;
		}
		NextNode = (PNode)malloc(sizeof(Node));
		if (NULL == NextNode)
		{
			printf("���ٿռ�ʧ�ܣ�\n");
			return;
		}
		phead->_pNext = NextNode;
		NextNode->_data = data;
		NextNode->_pNext = NULL;
	}
}

// βɾ 
void SListPopBack(PNode* pHead)
{
	PNode phead = *pHead;
	PNode PNode = NULL;
	while (phead->_pNext!=NULL)
	{
		PNode = phead;
		phead = phead->_pNext;
	}
	phead->_data = NULL;
	PNode->_pNext = NULL;
	return;
}

// ͷ�� 
void SListPushFront(PNode* pHead, DataType data)
{
	PNode phead = *pHead;
	*pHead = NULL;
	*pHead = (PNode)malloc(sizeof(Node));
	(*pHead)->_data = data;
	(*pHead)->_pNext = phead;
}

// ͷɾ 
void SListPopFront(PNode* pHead)
{
	PNode pNode = *pHead;
	pNode->_data = NULL;
	pNode = pNode->_pNext;
	*pHead = pNode;
	pNode = NULL;
}

// ����ֵΪdata�Ľ�㣬���ظý���������е�λ�� 
PNode SListFind(PNode* pHead, DataType data)
{
	PNode phead = NULL;
	phead=*pHead;
	while (phead->_pNext != NULL)
	{
		if (data == phead->_data)
		{
			return phead;
		}
		phead = phead->_pNext;
	}
}

// ������posλ�ú������data 
void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode NewNode = NULL;
	NewNode = (PNode)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("�½ڵ�Ŀռ俪��ʧ�ܣ�\n");
		return;
	}

	NewNode->_data = data;
	NewNode->_pNext = pos->_pNext;
	pos->_pNext = NewNode;
}

// ɾ������posλ���ϵĽ�� 
void SListErase(PNode pos)
{
	if (pos->_pNext == NULL)
	{
		printf("�ýڵ�Ϊβ�ڵ㣡");
		return;
	}
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
	
}

// ���ٵ����� 
void SListDestroy(PNode* pHead)
{
	PNode phead = (*pHead)->_pNext;
	(*pHead) = NULL;
	free(*pHead);
	while (phead != NULL&&(*pHead)!=NULL)
	{
		(*pHead) = phead->_pNext;
		phead = NULL;
		free(phead);
		phead = (*pHead)->_pNext;
		*pHead = NULL;
		free(*pHead);

	}

}

// �������н��ĸ��� 
int SListSize(PNode pHead)
{
	if (NULL == pHead)
	{
		printf("������Ϊ0!\n");
		return;
	}
	int count = 0;
	PNode phead = pHead;
	while (phead != NULL)
	{
		phead = phead->_pNext;
		count++;
	}
	printf("������Ϊ%d\n", count);
	return;
}

// �������еĽ����� 
void SListClear(PNode* pHead)
{
	if (NULL == *pHead)
	{
		printf("�������\n");
		return;
	}
		PNode pNode = *pHead;
		PNode phead = (*pHead)->_pNext;
		while (phead != NULL && pNode != NULL)
		{
			pNode = phead->_pNext;
			phead = NULL;
			free(phead);
			phead = pNode->_pNext;
			pNode = NULL;
			free(pNode);
		}
		(*pHead)->_pNext = NULL;
		(*pHead)->_data = NULL;
}

// ��ȡ��� 
PNode BuySListNode(DataType data)
{
	PNode NewNode = NULL;
	NewNode = (PNode)malloc(sizeof(Node));
	NewNode->_data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}

// ��ȡ�����е����һ����㣬���ظý��ĵ�ַ 
PNode SListBack(PNode pHead)
{
	if (NULL == pHead)
	{
		printf("�������\n");
		return;
	}
	PNode EndNode = pHead;
	while (EndNode->_pNext != NULL)
	{
		EndNode = EndNode->_pNext;
	}
	return EndNode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// ����������⣬��Ҫ����Ҫ������Ҫ������ 

//��ͷ��β��ӡ������
void PrintListFromTail2Head(PNode pHead)
{
	while (pHead != NULL)
	{
		printf("%d ", pHead->_data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}
// ɾ������ķ�β��㣬Ҫ���ܱ������� 
void DeleteNotTailNode(PNode pos)
{
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
}

// ������posλ��ǰ����ֵΪdata�Ľ�� 
void InsertPosFront(PNode pos, DataType data)
{
	PNode NewNode = BuySListNode(data);
	NewNode->_data = pos->_data;
	pos->_data = data;
	NewNode->_pNext = pos->_pNext;
	pos->_pNext = NewNode;
}

// Լɪ�� 
void JosephCircle(PNode* pHead, const int M)
{
	int i = 0;
	PNode phead = *pHead;
	PNode Node = *pHead;
	while ((*pHead)->_pNext != NULL)
	{
		*pHead = (*pHead)->_pNext;
	}
	(*pHead)->_pNext = phead;
	while ((*pHead)->_pNext != *pHead)
	{
		*pHead = (*pHead)->_pNext;
		i++;
		if (M == i)
		{
			SListErase(*pHead);
			i = 1;
		}
	}
}

// ʹ��ð�ݷ�ʽ�Ե������������ 
void BubbleSort(PNode pHead)
{
	PNode count = pHead;
	int i = 0;
	while (count != NULL)
	{
		count = count->_pNext;
		i++;
	}
	PNode phead = pHead;
	PNode Per = pHead;
	int tmp = 0;
	while (i != 1)
	{
		int j = i;
		while (j!=1)
		{
			if (phead->_data > phead->_pNext->_data)
			{
				tmp = phead->_data;
				phead->_data = phead->_pNext->_data;
				phead->_pNext->_data = tmp;
			}
			phead = phead->_pNext;
			j--;
		}
		phead = pHead;
		i--;
	}
}

// �����������---����ָ�� 
void ReverseSList(PNode* pHead)
{
	PNode End = *pHead;
	PNode Per = *pHead;
	PNode Node = *pHead;
	int tmp = 0;
	while (End->_pNext != NULL)
	{
		Node = End;
		End = End->_pNext;
	}
	while (Per!=End && Per->_pNext!=End && End->_pNext!=Per)
	{
		while (Node->_pNext == End)
		{
			tmp = End->_data;
			End->_data = Per->_data;
			Per->_data = tmp;
			End = Node;
			Per = Per->_pNext;
			Node = Per;
		}
		Node = Node->_pNext;
	}

}

// �����������---ʹ��ͷ�巨 
PNode ReverseSListOP(PNode *pHead)
{
	PNode Node = (*pHead)->_pNext;
	while (Node != NULL)
	{
		SListPushFront(pHead, Node->_data);
		if (NULL == Node->_pNext)
		{
			SListPopBack(pHead);
			return;
		}
		SListErase(Node);
	}

}

// �ϲ��������������ϲ�������ȻҪ���� 
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pHead3 = NULL;
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->_data < pHead2->_data)
		{
			SListPushBack(&pHead3, pHead1->_data);
			pHead1 = pHead1->_pNext;
		}
		else 
		{
			SListPushBack(&pHead3, pHead2->_data);
			pHead2 = pHead2->_pNext;
		}
	}
	while (pHead1 != NULL || pHead2 != NULL)
	{
		if (NULL == pHead1 && NULL != pHead2)
		{
			SListPushBack(&pHead3, pHead2->_data);
			pHead2 = pHead2->_pNext;
		}
		else if (NULL == pHead2 && pHead1 != NULL)
		{
			SListPushBack(&pHead3, pHead1->_data);
			pHead1 = pHead1->_pNext;
		}
	}
	return pHead3;
}

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead)
{
	assert(pHead);
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while (pFast->_pNext != NULL && pFast->_pNext->_pNext!=NULL)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}

// ��������ĵ�����K����� 
PNode FindLastKNode(PNode pHead, int K)
{
	assert(pHead);
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while (K != 1)
	{
		pFast = pFast->_pNext;
		K--;
	}
	while (pFast->_pNext != NULL)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}

//ɾ������ĵ�����K���ڵ�
PNode DeleteLastKNode(PNode pHead,int K)
{
	PNode per = pHead;
	PNode end = pHead;
	while (K != 1)
	{
		per = per->_pNext;
		K--;
	}
	while (per->_pNext != NULL)
	{
		per = per->_pNext;
		end = end->_pNext;
	}
	SListErase(end);
}
// �ж������������Ƿ��ཻ---�������� 
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	assert(pHead1);
	assert(pHead2);
	while (pHead1->_pNext != NULL)
		pHead1 = pHead1->_pNext;
	while (pHead2->_pNext != NULL)
		pHead2 = pHead2->_pNext;
	if (pHead1 == pHead2)
		return 1;
	else
		return 0;
}

// ����ཻ ��ȡ���� 
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	PNode pHead = pHead1;
	PNode pHead0 = pHead2;
	int i = 1, j = 1,k=0;
	while (pHead->_pNext != NULL)
	{
		pHead = pHead->_pNext;
		i++;
	}
	while (pHead0->_pNext != NULL)
	{
		pHead0 = pHead0->_pNext;
		j++;
	}
	if (i > j)
	{
		k = i - j;
		while (k != 0)
		{
			pHead1 = pHead1->_pNext;
			k--;
		}
	}
	else
	{
		k = j - i;
		while (k != 0)
		{
			pHead2 = pHead2->_pNext;
			k--;
		}
	}
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->_pNext;
		pHead2 = pHead2->_pNext;
	}
	return pHead1;

}

// �ж������Ƿ���� 
PNode IsCircle(PNode pHead)
{
	assert(pHead);
	PNode pFast = pHead;
	PNode pSlow = pHead;
	while (pFast != NULL && pFast->_pNext!=NULL)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pFast == pSlow)
		{
			printf("������\n");
			return pSlow;
		}
	}
	printf("��������\n");
	return 0;
}

// �󻷵ĳ��� 
int GetCircleLen(PNode pHead)
{
	PNode Node = IsCircle(pHead);
	if (NULL == Node)
	{
		printf("��������\n");
		return 0;
	}
	PNode Next = Node->_pNext;
	int length = 1;
	while (Next != Node)
	{
		Next = Next->_pNext;
		length++;
	}
	printf("���ĳ���Ϊ%d\n", length);
	return length;
}

// �󻷵���ڵ�--ע���ƶϹ��� 
PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode p1 = pHead;
	PNode p2 = pMeetNode;
	while (p1 != p2)
	{
		p1 = p1->_pNext;
		p2 = p2->_pNext;
	}
	return p1;
}


// ��������ĸ��� 
//PCListNode CopyComplexList(PCListNode pHead); 