
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

#define MAX_ROW 6
#define MAX_COL 6

#define Size 10
#define ADD 5
typedef struct Position
{
	int _x;
	int _y;
}Position;

typedef Position DataType;

typedef struct stack
{
	DataType* _array;
	int _top;
	int _capacity;
}Stack;
//Stack s;

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;
Maze m;

// ��ջ 
void StackPush(Stack* s, DataType data);


// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* s);


// ��ջ 
void StackPop(Stack* s);


//��ʼ��ջ
void StackInit(Stack* s);

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s);

// ��ʼ���Թ���ͼ���� 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// ����Թ�������Ƿ���Ч 
int IsValidEnter(Maze* m, Position enter);

// ���curλ���Ƿ�Ϊ�Թ��ĳ��� 
int IsMazeExit(Maze* m, Position cur, Position enter);

// �������·�� 
void SaveShortPath(Stack* path, Stack* shortPath);

// ��⵱ǰλ�õ���һ���Ƿ��ܹ���ͨ 
int IsNextPass(Maze* m, Position cur, Position next, Position entry);

// ���Թ� 
void PassMaze(Maze* m, Position enter, Stack* Path, Stack* shortPath);

// �������Թ���ʽ 
void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath);

// ��ӡ�Թ���ͼ���� 
void PrintMap(Maze* m);

// ��ӡ·�� 
void PrintPath(Stack* s);
