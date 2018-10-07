
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

// 入栈 
void StackPush(Stack* s, DataType data);


// 获取栈顶元素 
DataType StackTop(Stack* s);


// 出栈 
void StackPop(Stack* s);


//初始化栈
void StackInit(Stack* s);

//判断栈是否为空
int StackEmpty(Stack* s);

// 初始化迷宫地图数据 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL]);

// 检测迷宫的入口是否有效 
int IsValidEnter(Maze* m, Position enter);

// 检测cur位置是否为迷宫的出口 
int IsMazeExit(Maze* m, Position cur, Position enter);

// 保存最短路径 
void SaveShortPath(Stack* path, Stack* shortPath);

// 检测当前位置的下一步是否能够走通 
int IsNextPass(Maze* m, Position cur, Position next, Position entry);

// 走迷宫 
void PassMaze(Maze* m, Position enter, Stack* Path, Stack* shortPath);

// 具体走迷宫方式 
void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath);

// 打印迷宫地图数据 
void PrintMap(Maze* m);

// 打印路径 
void PrintPath(Stack* s);
