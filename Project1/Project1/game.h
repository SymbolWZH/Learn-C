#pragma once
#include <stdio.h>

#define ROW 3
#define COL 3


/*��ӡ����*/
void PrintfBoard(char board[ROW][COL], int row, int col);
/*�������*/
void PlayerMove(char board[ROW][COL], int row, int col);
/*�ж���Ϸ״̬*/
char isWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);
/*��ʼ������ ����������Ϊ��*/
void InitBoard(char board[ROW][COL], int row, int col);
/*������*/
void ComputerMove(char board[ROW][COL], int row, int col);