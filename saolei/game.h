#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define EASY1 10
#define ROW 9
#define COL 9
#define ROWS  ROW+2
#define COLS  COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set_char);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FIND(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);