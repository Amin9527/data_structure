
#include"BinTree.h"
//#include"stack.h"

////////////////����������

void CreateBinTree(PBTNode* PHead,BTDataType* str, int size, int* count)
{
	if (PHead == NULL)
	{
		printf("BinTree Error��\n");
		return;
	}
	if (*count<size && str[*count]!='#')
	{
		*PHead=CreateTreeNode(str[*count]);
		(*count)++;
		CreateBinTree(&(*PHead)->Left,str, size, count);
		(*count)++;
		CreateBinTree(&(*PHead)->right, str, size, count);
	}
}

///////////////�������
PBTNode CreateTreeNode(BTDataType data)
{

	PBTNode PRoot = (PBTNode)malloc(sizeof(BTNode));
	if (PRoot == NULL)
	{
		printf("���ٿռ�ʧ�ܣ�\n");
		return NULL;
	}
	(PRoot)->data = data;
	(PRoot)->Left = NULL;
	(PRoot)->right = NULL;
	return (PRoot);
}

////////////////////��ӡ������

void FrontprintBinTree(PBTNode PRoot)//�ݹ�--ǰ��
{
	if (PRoot == NULL)
		return;

		printf("%c  ", PRoot->data);
		FrontprintBinTree((PRoot)->Left);
		FrontprintBinTree((PRoot)->right);
}

void MidprintBinTree(PBTNode PRoot)//�ݹ�--����
{
	if (PRoot == NULL)
		return;

	MidprintBinTree((PRoot)->Left);
	printf("%c  ", PRoot->data);
	MidprintBinTree((PRoot)->right);
}

void LastprintBinTree(PBTNode PRoot)//�ݹ�--����
{
	if (PRoot == NULL)
		return;

	LastprintBinTree((PRoot)->Left);
	LastprintBinTree((PRoot)->right);
	printf("%c  ", PRoot->data);
}

// ���������� 
PBTNode CopyBinTree(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		printf("������Ϊ�գ�\n");
		return NULL;
	}
	BTNode* NewBTNode = CreateTreeNode(pRoot->data);
	if (pRoot->Left != NULL)
		NewBTNode->Left=CopyBinTree(pRoot->Left);
	if (pRoot->right != NULL)
		NewBTNode->right = CopyBinTree(pRoot->right);
	return NewBTNode;

}


// ǰ�����---�ǵݹ� 
void PreOrderNor(PBTNode pRoot)
{
	Stack s;
	if (pRoot == NULL)
	{
		printf("����������\n");
		return;
	}
	PBTNode cur = pRoot;
	StackInit(&s);
	printf("%c ", cur->data);
	if (cur->right != NULL)
		StackPush(&s, cur->right);
	if (cur->Left != NULL)
		StackPush(&s, cur->Left);
	while (StackEmpty(&s))
	{
		PBTNode Top = StackTop(&s);
		printf("%c ", Top->data);
		StackPop(&s);
		if (Top->right != NULL)
			StackPush(&s, Top->right);
		if (Top->Left!=NULL)
			StackPush(&s, Top->Left);
	}
}


// �������---�ǵݹ� 
void InOrderNor(PBTNode pRoot)
{
	if (pRoot==NULL)
	{
		printf("����������\n");
		return;
	}
	Stack s;
	StackInit(&s);
	PBTNode cur = pRoot;
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->Left;
		}
		cur= StackTop(&s);
		printf("%c ", cur->data);
		StackPop(&s);
		cur = cur->right;
	}
	
}


// ��������---�ǵݹ� 
void PostOrderNor(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		printf("����������\n");
		return;
	}
	Stack s;
	StackInit(&s);
	PBTNode cur = pRoot,Top=NULL,prev=NULL;
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->Left;
		}
		Top = StackTop(&s);
		if (Top->right == NULL || Top->right==prev)
		{
			printf("%c ", Top->data);
			prev = Top;
			StackPop(&s);
		}
		else
			cur = Top->right;
	}
	
}

// ������� 
void LevelOrder(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		printf("����������\n");
		return;
	}
	PBTNode cur = pRoot,Top=NULL;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, cur);
	while (cur)
	{
		printf("%c ", cur->data);
		QueuePop(&q);
		if (cur->Left)
			QueuePush(&q, cur->Left);
		if (cur->right)
			QueuePush(&q, cur->right);
		cur = QueueFront(&q);

	}
}

// ������������ 
void DetroyBinTree(PBTNode* pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DetroyBinTree(&(*pRoot)->Left);
		DetroyBinTree(&(*pRoot)->right);
		free(*pRoot);
		*pRoot = NULL;
	}
}

// �������ľ���---�ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		printf("������Ϊ�գ�\n");
		return;
	}
	PBTNode exchange = NULL;
	PBTNode cur = pRoot;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, cur);
	while (cur)
	{
		if ((cur)->Left)
			QueuePush(&q, (cur)->Left);
		if ((cur)->right)
			QueuePush(&q, (cur)->right);
		if ((cur)->Left != NULL || (cur)->right != NULL)
		{
			exchange = (cur)->Left;
			(cur)->Left = (cur)->right;
			(cur)->right = exchange;
		}
		QueuePop(&q);
		(cur) = QueueFront(&q);
	}
	LevelOrder(pRoot);
}

// �������ľ���---�ݹ� 
void MirrorBinTree(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	PBTNode Swap = NULL;
	Swap = pRoot->Left;
	pRoot->Left = pRoot->right;
	pRoot->right = Swap;
	MirrorBinTree(pRoot->Left);
	MirrorBinTree(pRoot->right);

}

// ��������н��ĸ��� 
int BinTreeSize(PBTNode pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	return BinTreeSize(pRoot->Left) + BinTreeSize(pRoot->right) + 1;
}

// ���������Ҷ�ӽ��ĸ��� 
int BinTreeLeaf(PBTNode pRoot)
{
	if (pRoot == NULL)
		return 0;
	else if (pRoot->Left == NULL && pRoot->right == NULL)
		return 1;
	return BinTreeLeaf(pRoot->Left) + BinTreeLeaf(pRoot->right);
}
//��������е�K����ĸ���--�ݹ�
int BinTreeKLevelNode(PBTNode pRoot,int K)
{
	if (pRoot == NULL || K <= 0)
		return 0;
	if (K == 1)
		return 1;
	return BinTreeKLevelNode(pRoot->Left, K - 1) + BinTreeKLevelNode(pRoot->right, K - 1);
}
//��������е�K����ĸ���--�ǵݹ�
int BinTreeKLevelNodeNor(PBTNode pRoot, int K)
{
	Stack s;
	int n = 1, count = 0;
	PBTNode Top = NULL;
	if (pRoot == NULL)
		return 0;
	StackInit(&s);
	Queue q;
	QueueInit(&q);
	StackPush(&s, pRoot);
	//Top = StackTop(&s);
	for (n = 1; n < K; n++)
	{
		if (!QueueEmpty(&q))
		{
		
			while (StackEmpty(&s))
			{
				Top = StackTop(&s);
				if (Top->Left)
					QueuePush(&q, Top->Left);
				if (Top->right)
					QueuePush(&q, Top->right);
				StackPop(&s);
			}
		}
		else if (!StackEmpty(&s))
		{
			while (QueueEmpty(&q))
			{
				Top = QueueFront(&q);
				if (Top->Left)
					StackPush(&s, Top->Left);
				if (Top->right)
					StackPush(&s, Top->right);
				QueuePop(&q);
			}
		}
	}
	while(StackEmpty(&s))
	{
		StackPop(&s);
		count++;
	}
	while (QueueEmpty(&q))
	{
		QueuePop(&q);
		count++;
	}
	return count;
}
//��������ĸ߶�--�ݹ�
int BinTreeHeight(PBTNode pRoot)
{
	int LeftHeight = 0, RightHeight = 0;
	if (pRoot == NULL)
		return 0;
	if (pRoot->Left == NULL && pRoot->right == NULL)
		return 1;
	LeftHeight = BinTreeHeight(pRoot->Left);
	RightHeight = BinTreeHeight(pRoot->right);
	return LeftHeight > RightHeight ? (LeftHeight + 1) : (RightHeight + 1);
}
// ��������ĸ߶�--�ǵݹ�
int BinTreeHeightNor(PBTNode pRoot)
{
	Stack s;
	Queue q;
	PBTNode Top = NULL;
	int Level = 0;
	StackInit(&s);
	QueueInit(&q);
	if (pRoot == NULL)
		return 0;
	StackPush(&s, pRoot);
	while (QueueEmpty(&q) || StackEmpty(&s))
	{
		if (!QueueEmpty(&q))
		{
			while (StackEmpty(&s))
			{
				Top = StackTop(&s);
				if (Top->Left)
					QueuePush(&q, Top->Left);
				if (Top->right)
					QueuePush(&q, Top->right);
				StackPop(&s);
			}
		}
		else if (!StackEmpty(&s))
		{
			while (QueueEmpty(&q))
			{
				Top = QueueFront(&q);
				if (Top->Left)
					StackPush(&s, Top->Left);
				if (Top->right)
					StackPush(&s, Top->right);
				QueuePop(&q);
			}
		}
		Level++;
	}
	return Level;
}

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ� 
PBTNode Find(PBTNode pRoot, BTDataType data)
{
	Queue q;
	PBTNode Top = NULL;
	if (pRoot == NULL)
		return NULL;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (QueueEmpty(&q))
	{
		Top = QueueFront(&q);
		if (Top->data == data)
			return Top;
		QueuePop(&q);
		if (Top->Left)
			QueuePush(&q, Top->Left);
		if (Top->right)
			QueuePush(&q, Top->right);
	}
	return NULL;
}
// ���һ���ڵ��Ƿ��ڶ������� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot == pNode)
		return 1;
	return IsNodeInBinTree(pRoot->Left,pNode) + IsNodeInBinTree(pRoot->right,pNode);
}

// ���һ�����Ƿ�Ϊ��ȫ������ 
      //����һ
//int IsCompleteBinTree(PBTNode pRoot)
//{
//	Queue q;
//	PBTNode Top = NULL,Node=pRoot;
//	if (pRoot == NULL)
//	{
//		printf("������Ϊ�գ�\n");
//		return 1;
//	}
//	QueueInit(&q);
//	QueuePush(&q, pRoot);
//	while (QueueEmpty(&q))
//	{
//		Top = QueueFront(&q);
//		QueuePop(&q);
//		if (Top->Left && Node == NULL)
//			return 0;
//		if (Top->Left && Node==pRoot)
//		{
//			QueuePush(&q, Top->Left);
//			if (Top->right == NULL)
//				Node = NULL;
//		}
//
//		if (Top->Left == NULL)
//		{
//			if (Top->right)
//				return 0;
//			else
//				Node = NULL;
//		}
//		if (Top->right && Node==pRoot)
//		{
//			QueuePush(&q, Top->right);
//		}
//	}
//	return 1;
//}
    //������
int IsCompleteBinTree(PBTNode pRoot)
{
	Queue q;
	PBTNode Top = NULL;
	int i = 0;
	if (pRoot == NULL)
	{
		printf("������Ϊ�գ�\n");
		return 1;
	}
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (QueueEmpty(&q))
	{
		Top = QueueFront(&q);
		if (i)
		{
			if (Top->Left || Top->right)
				return 0;
		}
		else
		{
			if (Top->Left && Top->right)
			{
				QueuePush(&q, Top->Left);
				QueuePush(&q, Top->right);
			}
			else if (Top->Left)
			{
				QueuePush(&q, Top->Left);
				i = 1;
			}
			else if (Top->right)
			{
				return 0;
			}
			else
				i = 1;
			QueuePop(&q);
		}
		
	}
	return 1;
}