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

// 初始化二叉搜索树 
void InitBSTree(BSTNode* pRoot);

//创建新结点
BSTNode CreateNewBSTNode(DataType data);

// 插入值为data的元素 
void InsertBSTree(BSTNode* pRoot, DataType data);

// 删除值为data的结点 
void DeleteBSTree(BSTNode* pRoot, DataType data);

// 在二叉搜索树中查找值为data的结点 
BSTNode FindBSTree(BSTNode pRoot, DataType data);

// 中序遍历二叉搜索树 
void PreOrder(BSTNode pRoot);

// 销毁二叉搜索树 
void DestroyBSTree(BSTNode* pRoot);

//2. 递归实现二叉搜索树中查找、插入和删除方法
// 以递归方式实现二叉搜索树 

//查找二叉搜索树中的值--递归
BSTNode FindBSTreeRecursion(BSTNode pRoot, DataType data);

//在二叉搜索树中插入值--递归
int InsertBSTreeRecursion(BSTNode* pRoot, DataType data);
int InsertBSTreeRecursion2(BSTNode* pRoot, DataType data);
//删除二叉搜索树中的值--递归
int DeleteBSTreerecursion(BSTNode* pRoot, DataType data);