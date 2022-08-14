#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define ROW 4
#define COL 4

//初始化棋盘
void initboard(char board[ROW][COL],int row ,int col);
//打印棋盘
void displayborad(char board[ROW][COL], int row, int col);
//玩家下棋
void playermove(char board[ROW][COL], int row, int col);
//电脑下棋
void computermove(char board[ROW][COL], int row, int col);
//判断输赢
char iswin(char board[ROW][COL], int row, int col);