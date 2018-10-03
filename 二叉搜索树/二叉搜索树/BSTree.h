#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* left;
	struct BSTreeNode* right;
	DataType data;
}*BSTNode,BStreeNode;

// ��ʼ������������ 
void InitBSTree(BSTNode* pRoot);

//�����½��
BSTNode CreateNewBSTNode(DataType data);

// ����ֵΪdata��Ԫ�� 
void InsertBSTree(BSTNode* pRoot, DataType data);

// ɾ��ֵΪdata�Ľ�� 
void DeleteBSTree(BSTNode* pRoot, DataType data);

// �ڶ����������в���ֵΪdata�Ľ�� 
BSTNode FindBSTree(BSTNode pRoot, DataType data);

// ����������������� 
void PreOrder(BSTNode pRoot);

// ���ٶ��������� 
void DestroyBSTree(BSTNode* pRoot);

//2. �ݹ�ʵ�ֶ����������в��ҡ������ɾ������
// �Եݹ鷽ʽʵ�ֶ��������� 

//���Ҷ����������е�ֵ--�ݹ�
BSTNode FindBSTreeRecursion(BSTNode pRoot, DataType data);

//�ڶ����������в���ֵ--�ݹ�
int InsertBSTreeRecursion(BSTNode* pRoot, DataType data);
int InsertBSTreeRecursion2(BSTNode* pRoot, DataType data);
//ɾ�������������е�ֵ--�ݹ�
int DeleteBSTreerecursion(BSTNode* pRoot, DataType data);