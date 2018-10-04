#define _CRT_SECURE_NO_WARNINGS 1

#include"SimpleMaze.h"
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
//// ��ʼ���Թ���ͼ���� 
//void InitMap(Maze* m, int map[MAX_ROW][MAX_COL])
//{
//	if (m == NULL)
//	{
//		printf("�Թ�����\n");
//		return;
//	}
//	int i = 0, j = 0;
//	for (i = 0; i < MAX_ROW; i++)
//	{
//		for (j = 0; j < MAX_COL; j++)
//		{
//			m->_map[i][j] = map[i][j];
//		}
//	}
//}
//
//// ����Թ�������Ƿ���Ч 
//int IsValidEnter(Maze* m, Position enter)
//{
//	if (1 == m->_map[enter._x][enter._y])
//	{
//		printf("�����Ч��\n");
//		return 1;
//	}
//	else
//	{
//		printf("�����Ч��\n");
//		return 0;
//	}
//}
//
//// ���curλ���Ƿ�Ϊ�Թ��ĳ��� 
//int IsMazeExit(Maze* m, Position cur, Position enter)
//{
//	if (cur._x != enter._x && cur._y != enter._y)
//	{
//		if (0 == cur._x || MAX_ROW - 1 == cur._x ||
//			0 == cur._y || MAX_COL - 1 == cur._y)
//			return 1;
//		else
//			return 0;
//	}
//	return 0;
//}
//
//// ��⵱ǰλ���Ƿ�Ϊͨ· 
//int IsPass(Maze* m, Position cur)
//{
//	if (m->_map[(cur._x)+1][cur._y] == 1 || m->_map[cur._x][(cur._y)+1] == 1 ||
//		m->_map[(cur._x)-1][cur._y] == 1 || m->_map[cur._x][(cur._y)-1] == 1)
//		return 1;
//	else
//		return 0;
//}
//
//// ���Թ� 
//void PassMazeNor(Maze* m, Position enter, Stack* s)
//{
//	if (m == NULL)
//	{
//		printf("�Թ���Ч��\n");
//		return;
//	}
//	if (IsValidEnter(m, enter))
//	{
//		StackPush(s, enter);
//		m->_map[enter._x][enter._y] = 2;
//		Position cur = enter;
//		Position node = enter;
//		while (!IsMazeExit(m,enter,node))
//		{
//			if (1 == m->_map[enter._x - 1][enter._y])
//			{
//				cur = enter;
//				enter._x = enter._x - 1;
//				m->_map[enter._x][enter._y] = 2;
//				StackPush(s, enter);
//				
//			}
//			else if (1 == m->_map[enter._x][enter._y-1])
//			{
//				cur = enter;
//				enter._y = enter._y - 1;
//				m->_map[enter._x][enter._y] = 2;
//				StackPush(s, enter);
//		
//			}
//			else if (1 == m->_map[enter._x][enter._y + 1])
//			{
//				cur = enter;
//				enter._y = enter._y + 1;
//				m->_map[enter._x][enter._y] = 2;
//				StackPush(s, enter);
//				
//			}
//			else if(1 == m->_map[enter._x + 1][enter._y])
//			{
//				cur = enter;
//				enter._x = enter._x + 1;
//				m->_map[enter._x][enter._y] = 2;
//				StackPush(s, enter);
//				
//			}
//			else
//			{
//				StackPop(s);
//				enter = StackTop(s);
//
//			}
//
//		}
//	}
//
//}

//// ��ӡ�Թ���ͼ���� 
//void PrintMap(Maze* m)
//{
//	if (m == NULL)
//	{
//		printf("�Թ�����\n");
//		return;
//	}
//	int i = 0, j = 0;
//	for (i = 0; i < MAX_ROW; i++)
//	{
//		for (j = 0; j < MAX_COL; j++)
//		{
//			printf("%d ",m->_map[i][j]);
//		}
//		printf("\n");
//	}
//}

//// ��ӡ·�� 
//void PrintPath(Stack* s)
//{
//	while(s->_top-1)
//	{
//		printf("(%d,%d) <-- ", s->_array[s->_top-1]._x,s->_array[s->_top-1]._y);
//		StackPop(s);
//	}
//	printf("(%d,%d)", s->_array[s->_top - 1]._x, s->_array[s->_top - 1]._y);
//	printf("\n");
//}

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

//>> �õݹ�ķ�ʽ�����Թ�����
//#define MAX_ROW 10 
//#define MAX_COL 10 

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
		|| cur._y == 0 || cur._y == MAX_COL-1)
		&& cur._x != enter._x && cur._y != enter._y)
		return 1;
	else
		return 0;
}

// ��⵱ǰλ���Ƿ���ͨ· 
int IsPass(Maze* m, Position cur)
{
	assert(m);
	return 1 == m->_map[cur._x][cur._y];
}

// ���Թ� 
void PassMaze(Maze* m, Position enter,Stack* s)
{
	assert(m);
	if (!IsValidEnter(m, enter))
	{
		printf("�����Ч��\n");
		return;
	}
	_PassMaze(m, enter, enter,s);

}

// �������Թ��Ĳ��� 
int _PassMaze(Maze* m, Position entry, Position cur,Stack* s)
{
	if (IsPass(m, cur))
	{
		Position next;
		m->_map[cur._x][cur._y] = 2;
		StackPush(s, cur);
		if (IsMazeExit(m, cur, entry))
			return 1;

		//������
		next = cur;
		next._x -= 1;
		if (_PassMaze(m, entry, next,s))
			return 1;
		//������
		next = cur;
		next._y -= 1;
		if (_PassMaze(m, entry, next,s))
			return 1;
		//������
		next = cur;
		next._y += 1;
		if (_PassMaze(m, entry, next,s))
			return 1;
		//������
		next = cur;
		next._x += 1;
		if (_PassMaze(m, entry, next,s))
			return 1;
		m->_map[cur._x][cur._y] = 3;
		StackPop(s);

	}
	return 0;
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

// ��ӡ�߹���·�� 
void PrintPath(Stack* s)
{
	while (s->_top-1)
	{
		printf("(%d,%d)<--", s->_array[s->_top-1]._x, s->_array[s->_top-1]._y);
		StackPop(s);
	}
	printf("(%d,%d)", s->_array[s->_top-1]._x, s->_array[s->_top-1]._y);
	StackPop(s);
	printf("\n");
	return;
}
