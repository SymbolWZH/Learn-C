#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//五子棋游戏
int menu()
{
	printf("*******    ��������Ϸ  ******\n");
	printf("*******      1.play    ******\n");
	printf("*******      0.exit    ******\n");
	printf("*****************************\n");
}
void game()
{
	char board[ROW][COL];
	InitBoard(board,ROW,COL);//��ʼ������
	PrintfBoard(board, ROW, COL);//��ӡ����
	char  result = 0;//��ʾ��Ϸ״̬
	while (1)
	{
		PlayerMove(board, ROW, COL);
		PrintfBoard(board, ROW, COL);//��ӡ����
		result = isWin(board, ROW, COL);//�ж��Ƿ�ʤ��
		if (result != 'C')
			break;
		ComputerMove(board, ROW, COL);//������
		PrintfBoard(board, ROW, COL);//��ӡ����
		result = isWin(board, ROW, COL);//�ж��Ƿ�ʤ��
		if (result != 'C')
			break;
	}
	if (result == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (result == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	PrintfBoard(board, ROW, COL);//��ӡ����
}
int main()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ���������ѡ��\n");
				break;
		}
	} while (input);
	
	return 0;
}