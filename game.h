#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define ROW 4
#define COL 4

//��ʼ������
void initboard(char board[ROW][COL],int row ,int col);
//��ӡ����
void displayborad(char board[ROW][COL], int row, int col);
//�������
void playermove(char board[ROW][COL], int row, int col);
//��������
void computermove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char iswin(char board[ROW][COL], int row, int col);