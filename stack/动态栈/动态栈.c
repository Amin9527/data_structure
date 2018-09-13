#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
//��ʼ��
void StackInit(Stack* s)
{
	(*s)._array = NULL;
	(*s)._array = (SDataType*)malloc(Size*sizeof(SDataType));
	(*s)._capacity = Size;
	(*s)._top = 0;
}

// ��ջ 
void StackPush(Stack* s, SDataType data)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		SDataType* Newarray = (SDataType*)realloc(s->_array, ADD*(sizeof(SDataType)));
		if (NULL == Newarray)
		{
			printf("����ʧ�ܣ�\n");
			return;
		}
		s->_array = Newarray;
		s->_capacity += ADD;
	}
	s->_array[s->_top++] = data;

}

// ��ջ 
void StackPop(Stack* s)
{
	assert(s);
	s->_array[--s->_top] = NULL;
}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* s)
{
	assert(s);
	//printf("ջ��Ԫ��Ϊ%d\n", s->_array[s->_top - 1]);
	return s->_array[s->_top - 1];
}

// ��ЧԪ�صĸ��� 
int StackSize(Stack* s)
{
	assert(s);
	printf("��ЧԪ�ظ���Ϊ%d\n", s->_top);
	return s->_top;
}

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(Stack* s)
{
	assert(s);
	if (0 < s->_top)
	{
		//printf("ջ��Ϊ�գ�\n");
		return 1;
	}
	else //if (0 == s->_top)
	{
		//printf("ջΪ�գ�\n");
		return 0;
	}
}

// ջ��Ӧ�� 
//2. ��ջ�������ƥ�����⣬�����������μ�
//int StackMatchBrackets(Stack *s, char arr[],int size)
//{
//	int i = 0;
//	while (i != size)
//	{
//		if (0 == s->_top)
//		{
//			StackPush(s, arr[i]);
//			i++;
//		}
//		else
//		{
//			if (s->_array[s->_top - 1] == '(')
//			{
//				if (arr[i] == ')')
//				{
//					StackPop(s);
//					i++;
//				}
//				else if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' || arr[i] == ']' || arr[i] == '}')
//				{
//					StackPush(s, arr[i]);
//					i++;
//				}
//				else
//					i++;
//			}
//			else if (s->_array[s->_top - 1] == '{')
//			{
//				if (arr[i] == '}')
//				{
//					StackPop(s);
//					i++;
//				}
//				else if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' || arr[i] == ']' || arr[i] == ')')
//				{
//					StackPush(s, arr[i]);
//					i++;
//				}
//				else
//					i++;
//			}
//			else if (s->_array[s->_top - 1] == '[')
//			{
//				if (arr[i] == ']')
//				{
//					StackPop(s);
//					i++;
//				}
//				else if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[' || arr[i] == ')' || arr[i] == '}')
//				{
//					StackPush(s, arr[i]);
//					i++;
//				}
//				else
//					i++;
//			}
//			else
//			{
//				StackPush(s, arr[i]);
//				i++;
//			}
//		}
//
//	}
//	int left = 0, right = 0, other = 0;
//	while (s->_top != 0)
//	{
//		if (s->_array[s->_top-1] == '(' || s->_array[s->_top-1] == '{' || s->_array[s->_top-1] == '[')
//		{
//			left++;
//			StackPop(s);
//		}
//		else if (s->_array[s->_top-1] == ')' || s->_array[s->_top-1] == '}' || s->_array[s->_top-1] == ']')
//		{
//			right++;
//			StackPop(s);
//		}
//		else
//			StackPop(s);
//
//	}
//	if (left > right)
//	{
//		printf("�����Ŷ��������ţ�\n");
//		return 0;
//	}
//	else if (right > left)
//	{
//		printf("�����Ŷ��������ţ�\n");
//		return 0;
//	}
//	else if (left == right && left != 0)
//	{
//		printf("�������Ŵ���ƥ�䲻��ȷ��\n");
//		return 0;
//	}
//	else
//	{
//		printf("��������ƥ����ȷ��\n");
//		return 1;
//	}
//}
//3. ��ջ����׺���ʽֵ
//int StackSuffixExpression(Stack* s, int arr[], int number)
//{
//	int i = 0;
//	while (i != number)
//	{
//		switch (arr[i])
//		{
//		case '+':
//		{
//					int node = 0;
//					node = (s->_array[s->_top - 2]) + (s->_array[s->_top - 1]);
//					StackPop(s);
//					StackPop(s);
//					StackPush(s, node);
//					i++;
//		}break;
//		case '-':
//		{
//					int node = 0;
//					node = (s->_array[s->_top - 2]) - (s->_array[s->_top - 1]);
//					StackPop(s);
//					StackPop(s);
//					StackPush(s, node);
//					i++;
//		}break;
//		case '*':
//		{
//					int node = 0;
//					node = (s->_array[s->_top - 2]) * (s->_array[s->_top - 1]);
//					StackPop(s);
//					StackPop(s);
//					StackPush(s, node);
//					i++;
//		}break;
//		case '/':
//		{
//					int node = 0;
//					node = (s->_array[s->_top - 2]) / (s->_array[s->_top - 1]);
//					StackPop(s);
//					StackPop(s);
//					StackPush(s, node);
//					i++;
//		}break;
//		default:
//		{
//				   StackPush(s, arr[i]);
//				   i++;
//		}break;
//
//		}
//	}
//	printf("��׺���ʽ�Ľ��Ϊ%d\n",s->_array[s->_top-1]);
//	return s->_array[s->_top-1];
//}