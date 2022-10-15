#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//棋盘初始化
{
	int i = 0;
	int j = 0;
	for (i = 0;i <row;i++)
	{
		for (j = 0;j <col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int  col)//棋盘显示
{
	int i;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
					printf("---");
					if (j < col - 1)
						printf("|");

			}
			printf("\n");
		}
		
	}
}
void PlayMove1(char board[ROW][COL], int row, int  col)//玩家1下棋
{
	int x, y;
	printf("请玩家1走:>\n");
	while (1)
	{
		printf("输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该字被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}
}
void PlayMove2(char board[ROW][COL], int row, int  col)//玩家2下棋
{
	int x, y;
	printf("请玩家2走:>\n");
	while (1)
	{
		printf("输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该字被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}
}
//void ComputerMove(char board[ROW][COL], int row, int  col)//电脑下棋
//{
//	int x, y;
//	printf("请电脑走:>\n");
//	x = rand() % ROW;
//	y = rand() % COL;
//	while (1)
//	{
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
char IsWin(char board[ROW][COL], int row, int  col)//判断是否胜利
{
	int i;
	for (i = 0;i < row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
			return board[i][0];
	}
	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[1][1];
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}
int IsFull(char board[ROW][COL], int row, int  col)//判断棋盘是否满，判断平局
{
	int i, j;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
