#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("******************\n");
	printf("****  1.play  ****\n");
	printf("****  0.exit  ****\n");
	printf("******************\n");
}

void game()
{
	char board[ROW][COL];
	//初始化棋盘
	initboard(board,ROW,COL);
	//打印棋盘
	displayborad(board, ROW, COL);
	char ret = 0;
	while (1)
	{
	//玩家下棋
		playermove(board, ROW, COL);
		displayborad(board, ROW, COL);
	//判断输赢
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
		break;
		}
			
	//电脑下棋
		computermove(board, ROW, COL);
		displayborad(board, ROW, COL);
	//判断输赢
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}  
	if (ret == '*')
		printf("玩家胜利\n");
	if (ret == '#')
		printf("电脑胜利\n");
	if (ret == 'q')
		printf("平局\n");
	displayborad(board, ROW, COL);
}
int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (i);
			return 0;
}