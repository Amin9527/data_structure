#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"


// 初始化二叉搜索树 
void InitBSTree(BSTNode* pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

//创建新结点
BSTNode CreateNewBSTNode(data)
{
	BSTNode Node = (BSTNode)malloc(sizeof(BStreeNode));
	if (Node == NULL)
	{
		printf("结点创建失败！\n");
		return NULL;
	}
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

// 插入值为data的元素 
void InsertBSTree(BSTNode* pRoot, DataType data)
{
	BSTNode cur = *pRoot,parent=NULL;
	assert(pRoot);
	if (*pRoot == NULL)
		*pRoot=CreateNewBSTNode(data);
	else
	{
		while (cur)
		{
			if (data < cur->data)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (data > cur->data)
			{
				parent = cur;
				cur = cur->right;
			}
			else
				return;
		}
		if (data < parent->data)
			parent->left = CreateNewBSTNode(data);
		else
			parent->right = CreateNewBSTNode(data);
	}
}

// 删除值为data的结点 
void DeleteBSTree(BSTNode* pRoot, DataType data)
{
	BSTNode cur = *pRoot, parent = *pRoot, child = (*pRoot)->right,index=NULL;
	assert(pRoot);
	while (cur)
	{
		if (data == cur->data)
		{
			if (cur == parent->right ||(cur==parent && (parent->left && parent->right)))
			{
				if (cur->right && cur->left == NULL)
				{
					parent->right = cur->right;
					return;
				}
				else if (cur->left && cur->right == NULL)
				{
					parent->right = cur->left;
					return;
				}
				else if (cur->left && cur->right)
				{
					child = cur->right;
					if (!child->left)
					{
						cur->data = child->data;
						cur->right = child->right;
						return;
					}
					while (child->left)
					{
						index = child;
						child = child->left;
					}
					cur->data = child->data;
					index->left = child->right;
					return;
				}
				else
					parent->right = cur->right;
			}
			else if (cur == parent->left)
			{
				if (cur->right && cur->left == NULL)
				{
					parent->left = cur->right;
					return;
				}
				else if (cur->left && cur->right == NULL)
				{
					parent->left = cur->left;
					return;
				}
				else if (cur->left && cur->right)
				{
					child = cur->right;
					if (!child->right)
					{
						cur->data = child->data;
						cur->right = child->left;
						return;
					}
					while (child->right)
					{
						index = child;
						child = child->right;
					}
					cur->data = child->data;
					index->left = child->right;
				}
				else
					parent->left = cur->right;
			}
			else
			{
				if (cur->left)
				{
					*pRoot = (*pRoot)->left;
					break;
				}
				else
				{
					*pRoot = (*pRoot)->right;
					break;
				}
			}
		}
		else if (data < cur->data)
		{
			parent = cur;
			cur = cur->left;
		}
		else
		{
			parent = cur;
			cur = cur->right;
		}
	}
}

// 在二叉搜索树中查找值为data的结点 
BSTNode FindBSTree(BSTNode pRoot, DataType data)
{
	assert(pRoot);
	while (pRoot)
	{
		if (pRoot->data == data)
			return pRoot;
		else if (data < pRoot->data)
			pRoot = pRoot->left;
		else
			pRoot = pRoot->right;
	}
	return NULL;
}

// 中序遍历二叉搜索树 
void PreOrder(BSTNode pRoot)
{
	if (pRoot == NULL)
		return;
	PreOrder(pRoot->left);
	printf("%d ", pRoot->data);
	PreOrder(pRoot->right);
}

// 销毁二叉搜索树 
void DestroyBSTree(BSTNode* pRoot)
{
	if (*pRoot == NULL)
		return;
	DestroyBSTree(&((*pRoot)->left));
	DestroyBSTree(&((*pRoot)->right));
	free(*pRoot);
	*pRoot = NULL;
}

//2. 递归实现二叉搜索树中查找、插入和删除方法
// 以递归方式实现二叉搜索树 

//查找二叉搜索树中的值--递归
BSTNode FindBSTreeRecursion(BSTNode pRoot, DataType data)
{
	assert(pRoot);
	if (pRoot == NULL)
		return NULL;
	if (pRoot->data = data)
		return pRoot;
	else if (data < pRoot->data)
		return FindBSTreeRecursion(pRoot->left, data);
	
	else
	    return FindBSTreeRecursion(pRoot->right, data);
}

//在二叉搜索树中插入值--递归
int InsertBSTreeRecursion(BSTNode* pRoot, DataType data)
{
	assert(pRoot);
	if ((*pRoot) == NULL)
	{
		CreateNewBSTNode(data);
		return 1;
	}
	else if (data < (*pRoot)->data)
	{
		if ((*pRoot)->left == NULL)
		{
			(*pRoot)->left = CreateNewBSTNode(data);
			return 1;
		}
		else
		{
			InsertBSTreeRecursion(&((*pRoot)->left), data);
			return 1;
		}
	}
	else if (data >(*pRoot)->data)
	{
		if ((*pRoot)->right == NULL)
		{
			(*pRoot)->right = CreateNewBSTNode(data);
			return 1;
		}
		else
		{
			InsertBSTreeRecursion(&((*pRoot)->right), data);
			return 1;
		}
	}
	else
		return 0;
}

int InsertBSTreeRecursion2(BSTNode* pRoot, DataType data)
{
	assert(pRoot);
	if ((*pRoot) == NULL)
	{
		*pRoot = CreateNewBSTNode(data);
		return 1;
	}
	else
	{
		if (data == (*pRoot)->data)
			return 0;
		else if (data < (*pRoot)->data)
			return InsertBSTreeRecursion2(&((*pRoot)->left),data);
		else
			return InsertBSTreeRecursion2(&((*pRoot)->right), data);
	}
}
//删除二叉搜索树中的值--递归
int DeleteBSTreeRecursion(BSTNode* pRoot, DataType data)
{
	if (*pRoot == NULL)
		return 0;
	if (data < (*pRoot)->data)
		return DeleteBSTreeRecursion(&((*pRoot)->left), data);
	else if (data > (*pRoot)->data)
		return DeleteBSTreeRecursion(&((*pRoot)->right), data);
	else
	{
		BSTNode Del = *pRoot;
		if (Del->right == NULL)
		{
			(*pRoot) = Del->left;
			free(Del);
			return 1;
		}
		else if (Del->left == NULL)
		{
			(*pRoot) = Del->right;
			free(Del);
			return 1;
		}
		else
		{
			BSTNode Del = (*pRoot);

			while (Del->left)
				Del = Del->left;
			 
			(*pRoot)->data = Del->data;

			return DeleteBSTreeRecursion(&(Del->right), Del->data);
		}
	}
}


//3. 整理二叉搜索树中的应用


//4. 分析二叉搜索树性能
/*只有当二叉搜索树是平衡二叉树时，其性能类似折半查找*/

//5. 了解平衡树AVL树和红黑树
/*平衡树：每一棵树的左右子树的高度的绝对值差不超过一*/
/*红黑树：每个节点都带有颜色的二叉树
          1.结点是红色或者黑色
		 2.根结点是黑色
		 3.每个叶子结点是黑色（这里的叶子结点是NULL结点）
		 4.每个红色结点的子结点是黑色（每个叶子结点到根结点的路径上不能有两个连续的红色结点）
		 5.从任意一个结点到其每个叶子结点的路径上所包含的黑色结点数目相同
*/
