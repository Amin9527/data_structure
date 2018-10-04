#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#define MAX_ROW 6 
#define MAX_COL 6 
typedef struct position
{
	int _x;
	int _y;
}Position;

//typedef struct stack
//{
//	Position array[MAX_ROW][MAX_COL];
//	int top;
//	int _capacity
//
//}Stack;

#define Size 10
#define ADD 5
typedef Position DataType;

typedef struct Stack
{
	DataType *_array;
	int _top; // ��ʾ��ЧԪ�ظ��� ��ʾջ��λ�� 
	int _capacity; // �ײ�ռ���ܴ�С 
}Stack;
Stack s;
typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;
Maze m;
//��ʼ��ջ
void StackInit(Stack* s);
//��ջ
void StackPop(Stack* s);
// ��ʼ���Թ���ͼ���� 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// ����Թ�������Ƿ���Ч 
int IsValidEnter(Maze* m, Position enter);

// ���curλ���Ƿ�Ϊ�Թ��ĳ��� 
int IsMazeExit(Maze* m, Position cur, Position enter);

// ��⵱ǰλ���Ƿ�Ϊͨ· 
int IsPass(Maze* m, Position cur);

// ���Թ� 
void PassMazeNor(Maze* m, Position enter, Stack* s);

// ��ӡ�Թ���ͼ���� 
void PrintMap(Maze* m);

// ��ӡ·�� 
void PrintPath(Stack* s);

//>> �õݹ�ķ�ʽ�����Թ�����
//#define MAX_ROW 10 
//#define MAX_COL 10 

// ��ʼ���Թ���ͼ���� 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// ����Թ�������Ƿ���Ч 
int IsValidEnter(Maze* m, Position enter);

// ���curλ���Ƿ�Ϊ�Թ��ĳ��� 
int IsMazeExit(Maze* m, Position cur, Position enter);

// ��⵱ǰλ���Ƿ���ͨ· 
int IsPass(Maze* m, Position cur);

// ���Թ� 
void PassMaze(Maze* m, Position enter,Stack* s);

// �������Թ��Ĳ��� 
int _PassMaze(Maze* m, Position entry, Position cur,Stack* s);

// ��ӡ�Թ���ͼ���� 
void PrintMap(Maze* m);

// ��ӡ�߹���·�� 
void PrintPath(Stack* s);
