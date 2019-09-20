#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void ShowBoard(char board[][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("===================\n");
	for (i = 0; i < rows - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("===================\n");
}

void SetMine(char mine[][COLS], int row, int col, int x, int y)//9  9
{
	int count = MINENUM;
	int x1 = 0;
	int y1 = 0;
	while (count != 0)
	{
		x1 = rand() % row + 1;//[0-9)  [1,10)
		y1 = rand() % col + 1;

		while (1)
		{
			x1 = rand() % row + 1;//[0-9)  [1,10)
			y1 = rand() % col + 1;
			if (x != x1 || y != y1)
			{
				break;
			}
		}

		if (mine[x1][y1] == '0')
		{
			mine[x1][y1] = '1';
			count--;
		}
	}
}


static int GetMine(char mine[][COLS], int x, int y)
{
	//'1' - '0'  = 1
	// 1 + '0' = '1'

	//return mine[x-1][y-1]-'0'+
	//mine[x-1][y]-'0'+
	//mine[x-1][y+1]-'0'+
	//mine[x][y+1]-'0'+
	//mine[x+1][y+1]-'0'+
	//mine[x+1][y]-'0'+
	//mine[x+1][y-1]-'0'+
	//mine[x][y-1]-'0';
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] - 8 * '0';
}

void FindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	//                    
	while (count < row * col - MINENUM)
	{
		printf("请输入你的坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				break;
			}
			else
			{
				int mineNum = GetMine(mine, x, y);//  
				if (mineNum == 0)
				{
					int i, j;
					int m, n;
					if (x > 1 && x < 9 && y>1 && y < 9)
					{
						for (i = x - 1; i <= x + 1; i++)
						{
							for (j = y - 1; j <= y + 1; j++)
							{
								int mineNum = GetMine(mine, i, j);
								if (mineNum == 0)
								{
									for (m = i - 1; m <= i + 1; m++)
									{
										for (n = j - 1; n <= i + j; n++)
										{
											if (mineInfo[i][j] == '*')
											{
												mineInfo[i][j] = '0';
											}
										}

									}
								}
							}
						}
					}
					count += 9;
				}
				else
				{
					mineInfo[x][y] = mineNum + '0';
					count++;

				}
				ShowBoard(mineInfo, ROWS, COLS);
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}

	if (count == row * col - MINENUM)
	{
		printf("扫雷成功\n");
	}
}
void FirstFindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入你的坐标：\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			SetMine(mine, ROW, COL, x, y);
			int mineNum = GetMine(mine, x, y);//  
			if (mineNum == 0)
			{
				int i, j;
				int m, n;
				if (x > 1 && x < 9 && y>1 && y < 9)
				{
					for (i = x - 1; i <= x + 1; i++)
					{
						for (j = y - 1; j <= y + 1; j++)
						{
							int mineNum = GetMine(mine, i, j);
							if (mineNum == 0)
							{
								for (m = i - 1; m <= i + 1; m++)
								{
									for (n = j - 1; n <= i + j; n++)
									{
										if (mineInfo[i][j] == '*')
										{
											mineInfo[i][j] = '0';
										}
									}

								}
							}
						}
					}
				}
			}
			else
			{
				mineInfo[x][y] = mineNum + '0';
			}
			break;
		}
	}
}