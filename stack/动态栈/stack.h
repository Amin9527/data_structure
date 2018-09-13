#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define Size 10
#define ADD 5
extern struct PBTNode;
typedef struct PBTNode* SDataType;
//typedef int SDataType;

typedef struct Stack
{
	SDataType *_array;
	int _top; // 表示有效元素个数 表示栈顶位置 
	int _capacity; // 底层空间的总大小 
}Stack;
//Stack s;
//初始化
void StackInit(Stack* s);

// 入栈 
void StackPush(Stack* s, SDataType data);

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
SDataType StackTop(Stack* s);

// 有效元素的个数 
int StackSize(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);

// 栈的应用 
//2. 用栈解决括号匹配问题，测试用例见课件
int StackMatchBrackets(Stack* s, char arr[], int size);
//3. 用栈求解后缀表达式值
int StackSuffixExpression(Stack* s, int arr[], int number);