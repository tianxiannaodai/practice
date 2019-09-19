#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h" 

//��ӡ�˵�
void menu()
{
	printf("**********************\n");
	printf("********0.exit********\n");
	printf("********1.play********\n");
	printf("**********************\n");
}

//��Ϸ
void game()
{
	int ret = 0;
	char board[3][3] = { 0 };//����������Ϊ����
	InitBoard(board, ROW, COL);//��ʼ������ 
	ShowBoard(board, ROW, COL);//��ӡ���� 
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		ShowBoard(board, ROW, COL); //��ӡ����
		ret = IsWin(board, ROW, COL);//ÿ�ζ�Ҫ�ж��Ƿ�Ӯ�˱��� 
		if (ret != 1)//ƽ�֣�������Ϸ
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		ShowBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//ÿ�ζ�Ҫ�ж��Ƿ�Ӯ�˱���
		if (ret != 1)//ƽ�֣�������Ϸ
		{
			break;
		}
	}
	if (ret == 'X')//��һ�ʤ����Ϸ����
	{
		printf("��һ�ʤ\n");
	}
	if (ret == 'Y')//���Ի�ʤ����Ϸ����
	{
		printf("���Ի�ʤ\n");
	}
	if (ret == 0)//ƽ�֣���Ϸ����
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{
		menu();//��ӡ�˵�
		printf("\n��ѡ����Ĳ�����\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n��Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("��Ϸ�˳���\n\n");
			break;
		default:
			printf("��������ȷ�����֣�\n");
			break;
		}
	} while (input);
	return 0;
}
