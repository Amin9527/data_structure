#define _CRT_SECURE_NO_WARNINGS 1

#include"ComplexMaze.h"

// 入栈 
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		DataType* Newarray = (DataType*)realloc(s->_array, ADD*(sizeof(DataType)));
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

// 获取栈顶元素 
DataType StackTop(Stack* s)
{
	assert(s);
	//printf("栈顶元素为%d\n", s->_array[s->_top - 1]);
	return s->_array[s->_top - 1];
}

// 出栈 
void StackPop(Stack* s)
{
	assert(s);
	s->_top--;
	return;
}

//初始化栈
void StackInit(Stack* s)
{
	(*s)._array = NULL;
	(*s)._array = (DataType*)malloc(Size*sizeof(DataType));
	(*s)._capacity = Size;
	(*s)._top = 0;
}

//判断栈是否为空
int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return 0;
	else
		return 1;
}
// 初始化迷宫地图数据 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
{
	if (m == NULL)
	{
		printf("迷宫为空！\n");
		return;
	}
	int i = 0, j = 0;
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
		{
			m->_map[i][j] = map[i][j];
		}
	}
}

// 检测迷宫的入口是否有效 
int IsValidEnter(Maze* m, Position enter)
{
	assert(m);
	if (m->_map[enter._x][enter._y] == 1)
		return 1;
	else
		return 0;
}

// 检测cur位置是否为迷宫的出口 
int IsMazeExit(Maze* m, Position cur, Position enter)
	{
		assert(m);
		if ((cur._x == 0 || cur._x == MAX_ROW - 1
			|| cur._y == 0 || cur._y == MAX_COL - 1)
			&& cur._x != enter._x && cur._y != enter._y)
			return 1;
		else
			return 0;
	}

// 保存最短路径 
void SaveShortPath(Stack* path, Stack* shortPath)
{
	int i = 0;
	if (shortPath->_top != 0)
		shortPath->_top = 0;
	for (i = 0; i < path->_top; i++)
		StackPush(shortPath, path->_array[i]);
}

// 检测当前位置的下一步是否能够走通 
int IsNextPass(Maze* m, Position cur, Position next, Position entry)
{
	assert(m);
	if (next._x >= 0 && next._x < MAX_ROW && next._y >= 0 && next._y<MAX_COL)
	{
		if (m->_map[next._x][next._y] == 1 || m->_map[next._x][next._y] > m->_map[cur._x][cur._y])
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

// 走迷宫 
void PassMaze(Maze* m, Position enter, Stack* path,Stack* shortPath)
{
	assert(m);
	if (!IsValidEnter(m, enter))
	{
		printf("入口无效！\n");
		return;
	}
	_PassMaze(m, enter, enter, path, shortPath);
}

// 具体走迷宫方式 
void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath)
{
	Position next = cur;
	if (!StackEmpty(path))
		m->_map[cur._x][cur._y] = 2;
	StackPush(path, cur);
	if (IsMazeExit(m, cur, entry))
	{
		if (path->_top < shortPath->_top || shortPath->_top==0)
		{
			SaveShortPath(path, shortPath);
		}
	}

	//向上走
	next._x =cur._x - 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//向左走
	next = cur;
	next._y =cur._y - 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//向右走
	next = cur;
	next._y = cur._y + 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//向下走
	next = cur;
	next._x = cur._x + 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	StackPop(path);
	return;
}

// 打印迷宫地图数据 
void PrintMap(Maze* m)
{
	assert(m);
	int i = 0, j = 0;
	for (i = 0; i < MAX_ROW; i++)
	{
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", m->_map[i][j]);
		printf("\n");
	}
}

// 打印路径 
void PrintPath(Stack* s)
{
	while (s->_top - 1)
	{
		printf("(%d,%d)<--", s->_array[s->_top - 1]._x, s->_array[s->_top - 1]._y);
		StackPop(s);
	}
	printf("(%d,%d)", s->_array[s->_top - 1]._x, s->_array[s->_top - 1]._y);
	StackPop(s);
	printf("\n");
	return;
}

