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

void CreateBinTree(PBTNode* PBTNode,BTDataType* str, int size, int* count);//创建二叉树
PBTNode CreateTreeNode(BTDataType str);//创建结点
void FrontprintBinTree(PBTNode PRoot);//递归--前序遍历
void MidprintBinTree(PBTNode PRoot);//递归--中序遍历
void LastprintBinTree(PBTNode PRoot);//递归--后续遍历
// 二叉树拷贝 
PBTNode CopyBinTree(PBTNode pRoot);


// 前序遍历---非递归 
void PreOrderNor(PBTNode pRoot);


// 中序遍历---非递归 
void InOrderNor(PBTNode pRoot);


// 后续遍历---非递归 
void PostOrderNor(PBTNode pRoot);

// 层序遍历 
void LevelOrder(PBTNode pRoot);

// 二叉树的销毁 
void DetroyBinTree(PBTNode* pRoot);

// 二叉树的镜像---非递归 
void MirrorBinTreeNor(PBTNode pRoot);

// 二叉树的镜像---递归 
void MirrorBinTree(PBTNode pRoot);

// 求二叉树中结点的个数 
int BinTreeSize(PBTNode pRoot);

// 求二叉树中叶子结点的个数 
int BinTreeLeaf(PBTNode pRoot);

// 求二叉树中第K层结点的个数 
int BinTreeKLevelNode(PBTNode pRoot, int K);

// 求二叉树的高度 
int BinTreeHeight(PBTNode pRoot);

// 在二叉树中查找值为data的结点，找到返回该结点，否则返回空 
PBTNode Find(PBTNode pRoot, BTDataType data);

// 检测一个节点是否在二叉树中 
int IsNodeInBinTree(PBTNode pRoot, PBTNode pNode);

// 检测一棵树是否为完全二叉树 
int IsCompleteBinTree(PBTNode pRoot);