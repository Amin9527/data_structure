#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	StackEmpty(&s);
	/*StackPush(&s, 5);
	StackPush(&s, 2);
	StackPush(&s, 0);
	StackPush(&s, 5);
	StackPush(&s, 2);
	StackPush(&s, 0);
	StackPush(&s, 5);
	StackPush(&s, 2);
	StackPush(&s, 0); 
	StackPush(&s, 5);
	StackPush(&s, 2);
	StackPush(&s, 0);*/
	//StackPop(&s);
	//StackTop(&s);
	StackSize(&s);
	StackEmpty(&s);

	//char arr[] = "((())(abc)))(({[]})";
	//int size=sizeof(arr)-1;
	//StackMatchBrackets(&s, arr, size);

	int arr1[] = { 1996,11,9,'*','-',1998,'+',8,13,'*','+' };
	int number = sizeof(arr1) / sizeof(int);
	StackSuffixExpression(&s, arr1, number);


	system("pause");
	return 0;
}