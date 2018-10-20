#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

// 链表初始化 
void SListInit(PNode* pHead)
{
	*pHead = NULL;
	assert(pHead);
}

// 尾插 
void SListPushBack(PNode* pHead, DataType data)
{
	PNode phead = *pHead;
	PNode NextNode = NULL;
	if (*pHead == NULL)
	{
		*pHead = (PNode)malloc(sizeof(Node));
		if (*pHead == NULL)
		{
			printf("开辟空间失败！\n");
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
			printf("开辟空间失败！\n");
			return;
		}
		phead->_pNext = NextNode;
		NextNode->_data = data;
		NextNode->_pNext = NULL;
	}
}

// 尾删 
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

// 头插 
void SListPushFront(PNode* pHead, DataType data)
{
	PNode phead = *pHead;
	*pHead = NULL;
	*pHead = (PNode)malloc(sizeof(Node));
	(*pHead)->_data = data;
	(*pHead)->_pNext = phead;
}

// 头删 
void SListPopFront(PNode* pHead)
{
	PNode pNode = *pHead;
	pNode->_data = NULL;
	pNode = pNode->_pNext;
	*pHead = pNode;
	pNode = NULL;
}

// 查找值为data的结点，返回该结点在链表中的位置 
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

// 在链表pos位置后插入结点data 
void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode NewNode = NULL;
	NewNode = (PNode)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("新节点的空间开辟失败！\n");
		return;
	}

	NewNode->_data = data;
	NewNode->_pNext = pos->_pNext;
	pos->_pNext = NewNode;
}

// 删除链表pos位置上的结点 
void SListErase(PNode pos)
{
	if (pos->_pNext == NULL)
	{
		printf("该节点为尾节点！");
		return;
	}
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
	
}

// 销毁单链表 
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

// 求链表中结点的个数 
int SListSize(PNode pHead)
{
	if (NULL == pHead)
	{
		printf("结点个数为0!\n");
		return;
	}
	int count = 0;
	PNode phead = pHead;
	while (phead != NULL)
	{
		phead = phead->_pNext;
		count++;
	}
	printf("结点个数为%d\n", count);
	return;
}

// 将链表中的结点清空 
void SListClear(PNode* pHead)
{
	if (NULL == *pHead)
	{
		printf("链表错误！\n");
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

// 获取结点 
PNode BuySListNode(DataType data)
{
	PNode NewNode = NULL;
	NewNode = (PNode)malloc(sizeof(Node));
	NewNode->_data = data;
	NewNode->_pNext = NULL;
	return NewNode;
}

// 获取链表中的最后一个结点，返回该结点的地址 
PNode SListBack(PNode pHead)
{
	if (NULL == pHead)
	{
		printf("链表错误！\n");
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
// 链表的面试题，重要！重要！！重要！！！ 

//从头到尾打印单链表
void PrintListFromTail2Head(PNode pHead)
{
	while (pHead != NULL)
	{
		printf("%d ", pHead->_data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}
// 删除链表的非尾结点，要求不能遍历链表 
void DeleteNotTailNode(PNode pos)
{
	pos->_data = pos->_pNext->_data;
	pos->_pNext = pos->_pNext->_pNext;
}

// 在链表pos位置前插入值为data的结点 
void InsertPosFront(PNode pos, DataType data)
{
	PNode NewNode = BuySListNode(data);
	NewNode->_data = pos->_data;
	pos->_data = data;
	NewNode->_pNext = pos->_pNext;
	pos->_pNext = NewNode;
}

// 约瑟夫环 
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

// 使用冒泡方式对单链表进行排序 
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

// 单链表的逆序---三个指针 
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

// 单链表的逆序---使用头插法 
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

// 合并两个有序链表，合并起来依然要有序 
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

// 查找链表的中间结点，要求只能遍历一次链表 
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

// 查找链表的倒数第K个结点 
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

//删除链表的倒数第K个节点
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
// 判断两个单链表是否相交---链表不带环 
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

// 如果相交 获取交点 
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

// 判断链表是否带环 
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
			printf("带环！\n");
			return pSlow;
		}
	}
	printf("不带环！\n");
	return 0;
}

// 求环的长度 
int GetCircleLen(PNode pHead)
{
	PNode Node = IsCircle(pHead);
	if (NULL == Node)
	{
		printf("不带环！\n");
		return 0;
	}
	PNode Next = Node->_pNext;
	int length = 1;
	while (Next != Node)
	{
		Next = Next->_pNext;
		length++;
	}
	printf("环的长度为%d\n", length);
	return length;
}

// 求环的入口点--注意推断过程 
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


// 复杂链表的复制 
//PCListNode CopyComplexList(PCListNode pHead); 