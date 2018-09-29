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
	printf("ǰ��ǵݹ飺\n");
	PreOrderNor(PNode);
	printf("\n����ǵݹ飺\n");
	InOrderNor(PNode);
	printf("\n�����ǵݹ飺\n");
	PostOrderNor(PNode);
	printf("\n���������\n");
	LevelOrder(PNode);
	printf("\n�������ǵݹ飺\n");
	MirrorBinTreeNor(PNode);
	printf("\n����--�ݹ�\n");
	MirrorBinTree(PNode);
	//printf("\n���������\n");
	LevelOrder(PNode);
    printf("\n�������н��ĸ���Ϊ%d\n", BinTreeSize(PNode));
	printf("��������Ҷ�ӽ��ĸ���Ϊ%d\n", BinTreeLeaf(PNode));
	printf("��������K����ĸ���Ϊ%d\n", BinTreeKLevelNode(PNode, 3));
	PBTNode Cur = Find(PNode, 'G');
	int zm = IsNodeInBinTree(PNode, Cur);
	printf("%d\n", zm);
#endif
	printf("��������K����ĸ���Ϊ%d\n", BinTreeKLevelNode(PNode, 3));
	printf("�������ĸ߶�Ϊ%d\n", BinTreeHeight(PNode));
	printf("�������ĸ߶�Ϊ%d\n", BinTreeHeightNor(PNode));
	//printf("%d\n", IsCompleteBinTree(PNode));
	//DetroyBinTree(&PNode);
	system("pause");
	return 0;
}