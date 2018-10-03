#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"


// ��ʼ������������ 
void InitBSTree(BSTNode* pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}

//�����½��
BSTNode CreateNewBSTNode(data)
{
	BSTNode Node = (BSTNode)malloc(sizeof(BStreeNode));
	if (Node == NULL)
	{
		printf("��㴴��ʧ�ܣ�\n");
		return NULL;
	}
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

// ����ֵΪdata��Ԫ�� 
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

// ɾ��ֵΪdata�Ľ�� 
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

// �ڶ����������в���ֵΪdata�Ľ�� 
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

// ����������������� 
void PreOrder(BSTNode pRoot)
{
	if (pRoot == NULL)
		return;
	PreOrder(pRoot->left);
	printf("%d ", pRoot->data);
	PreOrder(pRoot->right);
}

// ���ٶ��������� 
void DestroyBSTree(BSTNode* pRoot)
{
	if (*pRoot == NULL)
		return;
	DestroyBSTree(&((*pRoot)->left));
	DestroyBSTree(&((*pRoot)->right));
	free(*pRoot);
	*pRoot = NULL;
}

//2. �ݹ�ʵ�ֶ����������в��ҡ������ɾ������
// �Եݹ鷽ʽʵ�ֶ��������� 

//���Ҷ����������е�ֵ--�ݹ�
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

//�ڶ����������в���ֵ--�ݹ�
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
//ɾ�������������е�ֵ--�ݹ�
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


//3. ��������������е�Ӧ��


//4. ������������������
/*ֻ�е�������������ƽ�������ʱ�������������۰����*/

//5. �˽�ƽ����AVL���ͺ����
/*ƽ������ÿһ���������������ĸ߶ȵľ���ֵ�����һ*/
/*�������ÿ���ڵ㶼������ɫ�Ķ�����
          1.����Ǻ�ɫ���ߺ�ɫ
		 2.������Ǻ�ɫ
		 3.ÿ��Ҷ�ӽ���Ǻ�ɫ�������Ҷ�ӽ����NULL��㣩
		 4.ÿ����ɫ�����ӽ���Ǻ�ɫ��ÿ��Ҷ�ӽ�㵽������·���ϲ��������������ĺ�ɫ��㣩
		 5.������һ����㵽��ÿ��Ҷ�ӽ���·�����������ĺ�ɫ�����Ŀ��ͬ
*/
