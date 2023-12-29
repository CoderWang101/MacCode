#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
 
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EAZY_COUNT 10;//雷的数量
 
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//打印
void DisplayBoard(char board[ROWS][COLS],int row,int col);
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
// 清除排查雷周围五雷处
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win);