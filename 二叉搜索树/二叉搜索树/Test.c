#define _CRT_SECURE_NO_WARNINGS 1
#include"BSTree.h"

int main()
{
	BSTNode pRoot;
	int array[] = { 2,1,4,9,8,6,5,7,0 };
	int i = 0;
	InitBSTree(&pRoot);
	for (; i < sizeof(array) / sizeof(array[0]); i++)
		InsertBSTree(&pRoot, array[i]);
	PreOrder(pRoot);
	printf("\n");
	//BSTNode index = FindBSTree(pRoot, 8);
	//printf("%d\n", FindBSTree(pRoot, 8)->data);
	PreOrder(pRoot);
	InsertBSTreeRecursion2(&pRoot, 3);
	printf("\n");
	//DeleteBSTree(&pRoot, 20);
	//DestroyBSTree(&pRoot);
	PreOrder(pRoot);
	printf("\n");
	DeleteBSTreeRecursion(&pRoot, 3);
	PreOrder(pRoot);
	system("pause");
	return 0;
}