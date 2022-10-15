#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
void menu()
{
	printf("**********************\n");
	printf("***1.paly    2.exit***\n");
	printf("**********************\n");
}
void game()
{
	int ret;
	char board[ROW][COL] = {0};
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayMove1(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
		PlayMove2(board, ROW, COL);
		//ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		break;
	}
	if (ret == '*')
		printf("玩家1赢\n");
	else if (ret == '#')
		printf("玩家2赢\n");
    //else if (ret == '#')
	//	printf("电脑赢\n");
	else if (ret == 'Q')
		printf("平局\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input=0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
