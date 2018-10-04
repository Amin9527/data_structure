#define _CRT_SECURE_NO_WARNINGS 1

#include"SimpleMaze.h"

int main()
{
	int map[MAX_ROW][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
	                           { 0, 0, 1, 0, 0, 0 },
	                           { 0, 0, 1, 0, 0, 0 },
	                           { 0, 0, 1, 1, 1, 0 },
	                           { 0, 0, 1, 0, 1, 1 },
	                           { 0, 0, 1, 0, 0, 0 } };
	Stack s;
	StackInit(&s);
	InitMap(&m, map);
	PrintMap(&m);
	Position enter;
	enter._x = 5; enter._y = 2;
	IsValidEnter(&m, enter);
	PassMaze(&m, enter,&s);
	PrintMap(&m);
	PrintPath(&s);
	system("pause");
	return 0;
}
