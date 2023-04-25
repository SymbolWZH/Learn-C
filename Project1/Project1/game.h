#pragma once
#include <stdio.h>

#define ROW 3
#define COL 3


/*打印棋盘*/
void PrintfBoard(char board[ROW][COL], int row, int col);
/*玩家下棋*/
void PlayerMove(char board[ROW][COL], int row, int col);
/*判断游戏状态*/
char isWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);
/*初始化棋盘 让数组内容为空*/
void InitBoard(char board[ROW][COL], int row, int col);
/*电脑走*/
void ComputerMove(char board[ROW][COL], int row, int col);