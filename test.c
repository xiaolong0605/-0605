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
	//��ʼ������
	initboard(board,ROW,COL);
	//��ӡ����
	displayborad(board, ROW, COL);
	char ret = 0;
	while (1)
	{
	//�������
		playermove(board, ROW, COL);
		displayborad(board, ROW, COL);
	//�ж���Ӯ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
		break;
		}
			
	//��������
		computermove(board, ROW, COL);
		displayborad(board, ROW, COL);
	//�ж���Ӯ
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}  
	if (ret == '*')
		printf("���ʤ��\n");
	if (ret == '#')
		printf("����ʤ��\n");
	if (ret == 'q')
		printf("ƽ��\n");
	displayborad(board, ROW, COL);
}
int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (i);
			return 0;
}