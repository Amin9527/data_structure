#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef char BTDataType;

typedef struct PBTNode
{
	struct PBTNode * Left;
	struct PBTNode * right;
	BTDataType data;
}BTNode,*PBTNode;

void CreateBinTree(PBTNode* PBTNode,BTDataType* str, int size, int* count);//����������
PBTNode CreateTreeNode(BTDataType str);//�������
void FrontprintBinTree(PBTNode PRoot);//�ݹ�--ǰ�����
void MidprintBinTree(PBTNode PRoot);//�ݹ�--�������
void LastprintBinTree(PBTNode PRoot);//�ݹ�--��������
// ���������� 
PBTNode CopyBinTree(PBTNode pRoot);


// ǰ�����---�ǵݹ� 
void PreOrderNor(PBTNode pRoot);


// �������---�ǵݹ� 
void InOrderNor(PBTNode pRoot);


// ��������---�ǵݹ� 
void PostOrderNor(PBTNode pRoot);

// ������� 
void LevelOrder(PBTNode pRoot);

// ������������ 
void DetroyBinTree(PBTNode* pRoot);

// �������ľ���---�ǵݹ� 
void MirrorBinTreeNor(PBTNode pRoot);

// �������ľ���---�ݹ� 
void MirrorBinTree(PBTNode pRoot);

// ��������н��ĸ��� 
int BinTreeSize(PBTNode pRoot);

// ���������Ҷ�ӽ��ĸ��� 
int BinTreeLeaf(PBTNode pRoot);

// ��������е�K����ĸ��� 
int BinTreeKLevelNode(PBTNode pRoot, int K);

// ��������ĸ߶� 
int BinTreeHeight(PBTNode pRoot);

// �ڶ������в���ֵΪdata�Ľ�㣬�ҵ����ظý�㣬���򷵻ؿ� 
PBTNode Find(PBTNode pRoot, BTDataType data);

// ���һ���ڵ��Ƿ��ڶ������� 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// ���һ�����Ƿ�Ϊ��ȫ������ 
int IsCompleteBinTree(PBTNode pRoot);