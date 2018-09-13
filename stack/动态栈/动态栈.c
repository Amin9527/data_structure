#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"
//初始化
void StackInit(Stack* s)
{
	(*s)._array = NULL;
	(*s)._array = (SDataType*)malloc(Size*sizeof(SDataType));
	(*s)._capacity = Size;
	(*s)._top = 0;
}

// 入栈 
void StackPush(Stack* s, SDataType data)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		SDataType* Newarray = (SDataType*)realloc(s->_array, ADD*(sizeof(SDataType)));
		if (NULL == Newarray)
		{
			printf("扩容失败！\n");
			return;
		}
		s->_array = Newarray;
		s->_capacity += ADD;
	}
	s->_array[s->_top++] = data;

}

// 出栈 
void StackPop(Stack* s)
{
	assert(s);
	s->_array[--s->_top] = NULL;
}

// 获取栈顶元素 
SDataType StackTop(Stack* s)
{
	assert(s);
	//printf("栈顶元素为%d\n", s->_array[s->_top - 1]);
	return s->_array[s->_top - 1];
}

// 有效元素的个数 
int StackSize(Stack* s)
{
	assert(s);
	printf("有效元素个数为%d\n", s->_top);
	return s->_top;
}

// 检测栈是否为空 
int StackEmpty(Stack* s)
{
	assert(s);
	if (0 < s->_top)
	{
		//printf("栈不为空！\n");
		return 1;
	}
	else //if (0 == s->_top)
	{
		//printf("栈为空！\n");
		return 0;
	}
}

// 栈的应用 
//2. 用栈解决括号匹配问题，测试用例见课件
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
//		printf("左括号多于右括号！\n");
//		return 0;
//	}
//	else if (right > left)
//	{
//		printf("右括号多于左括号！\n");
//		return 0;
//	}
//	else if (left == right && left != 0)
//	{
//		printf("左右括号次序匹配不正确！\n");
//		return 0;
//	}
//	else
//	{
//		printf("左右括号匹配正确！\n");
//		return 1;
//	}
//}
//3. 用栈求解后缀表达式值
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
//	printf("后缀表达式的结果为%d\n",s->_array[s->_top-1]);
//	return s->_array[s->_top-1];
//}