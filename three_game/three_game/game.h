#pragma once
#define    GAME_H 	
#include<stdlib.h>
#include<time.h>
#include<String.h>
#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char board[][ROW], int row, int col);

//��ӡ����
void ShowBoard(char board[][ROW], int row, int col);

//����ƶ�
void PlayerMove(char board[][ROW], int row, int col);

//�Ƿ�Ӯ����ʤ��
int IsWin(char board[][ROW], int row, int col);

//�����ƶ�
void ComputerMove(char board[][ROW], int row, int col);

//�ж���Ӯ
int IsWin(char board[][ROW], int row, int col);

//�ж������Ƿ����
int IsFull(char board[][ROW], int row, int col);