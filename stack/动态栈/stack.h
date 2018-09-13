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
	int _top; // ��ʾ��ЧԪ�ظ��� ��ʾջ��λ�� 
	int _capacity; // �ײ�ռ���ܴ�С 
}Stack;
//Stack s;
//��ʼ��
void StackInit(Stack* s);

// ��ջ 
void StackPush(Stack* s, SDataType data);

// ��ջ 
void StackPop(Stack* s);

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* s);

// ��ЧԪ�صĸ��� 
int StackSize(Stack* s);

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(Stack* s);

// ջ��Ӧ�� 
//2. ��ջ�������ƥ�����⣬�����������μ�
int StackMatchBrackets(Stack* s, char arr[], int size);
//3. ��ջ����׺���ʽֵ
int StackSuffixExpression(Stack* s, int arr[], int number);