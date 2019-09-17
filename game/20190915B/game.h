#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "stdlib.h"

#define ROW  9
#define COL  9

#define ROWS  ROW+2
#define COLS  COL+2


#define MINENUM 10  //³õÊ¼10¸öÀ×

void InitBoard(char board[][COLS],int rows,int cols,char set );
void ShowBoard(char board[][COLS],int rows,int cols);

void SetMine(char mine[][COLS],int row,int col);

void FindMine(char mineInfo[][COLS],char mine[][COLS],int row,int col);