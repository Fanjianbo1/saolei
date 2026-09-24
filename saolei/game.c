#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set_char)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set_char;
		}

	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
 }
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = EASY1;;
	while (count)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}
void UpdateBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	show[x][y]=mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]-'0'*7;
}

void FIND(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int win = 0;
	while (win < row * col - EASY1)

	{
		int x = 0;
		int y = 0;
		//DisplayBoard(show, row, col);
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你踩到雷了！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				UpdateBoard(mine, show, x, y);
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");
		}

		if (win == row * col - EASY1)
		{
			printf("恭喜你，扫雷成功！\n");
			DisplayBoard(mine, row, col);
			break;
		}
	}
}
