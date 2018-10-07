#define _CRT_SECURE_NO_WARNINGS 1

#include"ComplexMaze.h"

// ��ջ 
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		DataType* Newarray = (DataType*)realloc(s->_array, ADD*(sizeof(DataType)));
		if (NULL == Newarray)
		{
			printf("����ʧ�ܣ�\n");
			return;
		}
		s->_array = Newarray;
		s->_capacity += ADD;
	}
	s->_array[s->_top++] = data;

}

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* s)
{
	assert(s);
	//printf("ջ��Ԫ��Ϊ%d\n", s->_array[s->_top - 1]);
	return s->_array[s->_top - 1];
}

// ��ջ 
void StackPop(Stack* s)
{
	assert(s);
	s->_top--;
	return;
}

//��ʼ��ջ
void StackInit(Stack* s)
{
	(*s)._array = NULL;
	(*s)._array = (DataType*)malloc(Size*sizeof(DataType));
	(*s)._capacity = Size;
	(*s)._top = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return 0;
	else
		return 1;
}
// ��ʼ���Թ���ͼ���� 
void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
{
	if (m == NULL)
	{
		printf("�Թ�Ϊ�գ�\n");
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

// ����Թ�������Ƿ���Ч 
int IsValidEnter(Maze* m, Position enter)
{
	assert(m);
	if (m->_map[enter._x][enter._y] == 1)
		return 1;
	else
		return 0;
}

// ���curλ���Ƿ�Ϊ�Թ��ĳ��� 
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

// �������·�� 
void SaveShortPath(Stack* path, Stack* shortPath)
{
	int i = 0;
	if (shortPath->_top != 0)
		shortPath->_top = 0;
	for (i = 0; i < path->_top; i++)
		StackPush(shortPath, path->_array[i]);
}

// ��⵱ǰλ�õ���һ���Ƿ��ܹ���ͨ 
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

// ���Թ� 
void PassMaze(Maze* m, Position enter, Stack* path,Stack* shortPath)
{
	assert(m);
	if (!IsValidEnter(m, enter))
	{
		printf("�����Ч��\n");
		return;
	}
	_PassMaze(m, enter, enter, path, shortPath);
}

// �������Թ���ʽ 
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

	//������
	next._x =cur._x - 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//������
	next = cur;
	next._y =cur._y - 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//������
	next = cur;
	next._y = cur._y + 1;
	if (IsNextPass(m, cur, next, entry))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}
	//������
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

// ��ӡ�Թ���ͼ���� 
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

// ��ӡ·�� 
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

