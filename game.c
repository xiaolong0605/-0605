#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i < row; i++)
	{
		for (j=0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void displayborad(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
		printf(" %c ",board[i][j]); 
			if (j < col - 1)
			{
			printf("|");
			}
		}
		printf("\n");
		if (i < col-1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//玩家下棋
void playermove(char board[ROW][COL], int row, int col)
{

	while (1)
	{
	int i = 0;
	int j = 0;
	printf("请下棋:\n");
	scanf("%d %d", &i, &j);
		if (i > 0 && i < row + 1 && j < col + 1 && j > 0)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("输入错误，请重新输入：\n");
			}
		}

		else
		{
			printf("输入错误，请重新输入：\n");
		}
	}

}
//电脑下棋
void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	while (1)
	{
		int i = rand()%row;
		int j = rand()%col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}
//判断输赢
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;
	for (i = 0; i < row; i++)//行是否相等
	{
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][0] != ' ')
				x++;
		}
		if (x == col - 1)
		{
			return board[i][0];
		}
		x = 0;	
	}
	x = 0;
	for (i = 0; i < row; i++)//列是否相等
	{
		for (j = 0; j < col - 1; j++)
		{
			if (board[j][i] == board[j+1][i] && board[0][i] != ' ')
				x++;			
		}
		if (x == row - 1)
		{
			return board[0][i];
		}
		x = 0;	
	}
	x = 0;
	for (i = 0; i < row - 1; i++)//对角线
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i][i] != ' ')
		{
			x++;
		}
	}
	if (x == row - 1)
		return board[1][1];
	x = 0;
	for (i = 0; i < row - 1; i++)
	{

		if (board[i][row-i-1] == board[i + 1][row- i-2] && board[0][row-1] != ' ')
		{
			x++;
		}
	}		
	if (x == row - 1)
		return board[0][row-1];
	x = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	}
	return 'q';

}