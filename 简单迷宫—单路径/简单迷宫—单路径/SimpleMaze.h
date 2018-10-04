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
	int _top; // 表示有效元素个数 表示栈顶位置 
	int _capacity; // 底层空间的总大小 
}Stack;
Stack s;
typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;
Maze m;
//初始化栈
void StackInit(Stack* s);
//出栈
void StackPop(Stack* s);
// 初始化迷宫地图数据 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// 检测迷宫的入口是否有效 
int IsValidEnter(Maze* m, Position enter);

// 检测cur位置是否为迷宫的出口 
int IsMazeExit(Maze* m, Position cur, Position enter);

// 检测当前位置是否为通路 
int IsPass(Maze* m, Position cur);

// 走迷宫 
void PassMazeNor(Maze* m, Position enter, Stack* s);

// 打印迷宫地图数据 
void PrintMap(Maze* m);

// 打印路径 
void PrintPath(Stack* s);

//>> 用递归的方式求解简单迷宫问题
//#define MAX_ROW 10 
//#define MAX_COL 10 

// 初始化迷宫地图数据 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// 检测迷宫的入口是否有效 
int IsValidEnter(Maze* m, Position enter);

// 检测cur位置是否为迷宫的出口 
int IsMazeExit(Maze* m, Position cur, Position enter);

// 检测当前位置是否是通路 
int IsPass(Maze* m, Position cur);

// 走迷宫 
void PassMaze(Maze* m, Position enter,Stack* s);

// 真正走迷宫的操作 
int _PassMaze(Maze* m, Position entry, Position cur,Stack* s);

// 打印迷宫地图数据 
void PrintMap(Maze* m);

// 打印走过的路径 
void PrintPath(Stack* s);
