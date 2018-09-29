#define _CRT_SECURE_NO_WARNINGS 1
#include"BinTree.h"

int main()
{
	PBTNode PNode;
	char* str = "ABDG####CE##F";
	int count = 0;
	//char C;
	CreateBinTree(&PNode,str, strlen(str), &count);
	//CopyBinTree(PNode);
	//FrontprintBinTree(PNode);
	//MidprintBinTree(PNode);
	//LastprintBinTree(PNode);
	//FrontprintBinTree(CopyBinTree(PNode));
#if 0
	printf("前序非递归：\n");
	PreOrderNor(PNode);
	printf("\n中序非递归：\n");
	InOrderNor(PNode);
	printf("\n后续非递归：\n");
	PostOrderNor(PNode);
	printf("\n层序遍历：\n");
	LevelOrder(PNode);
	printf("\n镜像层序非递归：\n");
	MirrorBinTreeNor(PNode);
	printf("\n镜像--递归\n");
	MirrorBinTree(PNode);
	//printf("\n层序遍历：\n");
	LevelOrder(PNode);
    printf("\n二叉树中结点的个数为%d\n", BinTreeSize(PNode));
	printf("二叉树中叶子结点的个数为%d\n", BinTreeLeaf(PNode));
	printf("二叉树第K层结点的个数为%d\n", BinTreeKLevelNode(PNode, 3));
	PBTNode Cur = Find(PNode, 'G');
	int zm = IsNodeInBinTree(PNode, Cur);
	printf("%d\n", zm);
#endif
	printf("二叉树第K层结点的个数为%d\n", BinTreeKLevelNode(PNode, 3));
	printf("二叉树的高度为%d\n", BinTreeHeight(PNode));
	printf("二叉树的高度为%d\n", BinTreeHeightNor(PNode));
	//printf("%d\n", IsCompleteBinTree(PNode));
	//DetroyBinTree(&PNode);
	system("pause");
	return 0;
}