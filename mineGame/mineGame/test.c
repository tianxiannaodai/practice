#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*****************\n");
	printf("*****0.exit*******\n");
	printf("*****1.play******\n");
	printf("*****************\n");
}
void game()
{
	char mineInfo[ROWS][COLS];//*
	char mine[ROWS][COLS];//'0'

	InitBoard(mineInfo, ROWS, COLS, '*');
	InitBoard(mine, ROWS, COLS, '0');

	ShowBoard(mineInfo, ROWS, COLS);

	SetMine(mine, ROW, COL);

	//ShowBoard(mine,ROWS,COLS);

	FindMine(mineInfo, mine, ROW, COL);

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}
