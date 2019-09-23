#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "stdlib.h"

#define ROW  9
#define COL  9

#define ROWS  ROW+2
#define COLS  COL+2


#define MINENUM 5 //����10����

void InitBoard(char board[][COLS], int rows, int cols, char set);//��ʼ������

void ShowBoard(char board[][COLS], int rows, int cols);//��ӡ����

void SetMine(char mine[][COLS], int row, int col,  int x, int y);//������

void FirstFindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col);//��һ������
void FindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col);//����

void openMine(char mineInfo[][COLS], char mine[][COLS],int x, int y);

