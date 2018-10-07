#define _CRT_SECURE_NO_WARNINGS 1

#include"ComplexMaze.h"

int main()
{
	Stack path;
	Stack shortPath;
	Position enter;
	enter._x = 3;
	enter._y = 0;
	int map[MAX_ROW][MAX_COL] = { { 0, 0, 0, 0, 0, 0 },
	                           { 0, 0, 1, 0, 0, 0 },
	                           { 0, 0, 1, 1, 1, 0 },
	                           { 1, 1, 1, 0, 1, 0 },
	                           { 0, 0, 1, 1, 1, 1 },
	                           { 0, 0, 0, 0, 0, 0 } };
	StackInit(&path);
	StackInit(&shortPath);
	InitMap(&m, map);
	PrintMap(&m);
	IsValidEnter(&m, enter);
	PassMaze(&m, enter, &path,&shortPath);
	PrintMap(&m);
	PrintPath(&shortPath);
	//getchar();
	system("pause");
	return 0;
}