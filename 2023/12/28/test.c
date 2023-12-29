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
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i, j;
    for (i = 0;i < rows;i++)
    {
        for( j = 0;j < cols;j++)
        {
            board[i][j] = set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int j, i;
    printf("------扫雷-------\n");
    for (i = 0;i <= col;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for (i = 1;i <= row;i++)
    {
        printf("%d ", i);
        for (j = 1;j <= col;j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("------扫雷-------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
    int count = EAZY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}
int GetmyCount(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y] +
           mine[x - 1][y - 1] +
           mine[x][y - 1] +
           mine[x + 1][y - 1] +
           mine[x + 1][y] +
           mine[x + 1][y + 1] +
           mine[x][y + 1] +
           mine[x - 1][y + 1]-8*'0';
}
//递归展开

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)
{

    if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //限制在棋盘内展开，防止越界
    {
        int count = GetmyCount(mine, x, y);//获取雷数

        if (count == 0) //四周没雷，进入递归展开
        {
            show[x][y] = ' ';//四周没雷的改为 空格  ' '


            int i = 0;
            //向四周共8个位置递归
            for (i = x - 1; i <= x + 1; i++)
            {
                int j = 0;
                for (j = y - 1; j <= y + 1; j++)
                {

                    //只对 '*' 进行展开，防止死循环
                    if (show[i][j] == '*')
                    {
                        expand(mine, show, i, j, win);
                    }

                }
            }
        }
        else   //四周有雷显示雷数
        {
            show[x][y] = count + '0';
        }

        //记录展开的数量
        (*win)++;
    }
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0, y = 0,z=0;
    int win = 0;
    int s = EAZY_COUNT;
    while (win < (row * col) - s)
    {
        system("cls");
        if (z == 0)
        {
            printf("游戏开始\n");
        }
        if (z > 0)
        {
            printf("\n");
        }
        DisplayBoard(show, ROW, COL);
        printf("请输入要排查的坐标:>");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y>=1 && y <= col)
        {
            if (mine[x][y] == '1')
            {

                system("cls");
                printf("很遗憾，被炸死了!!1\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            {
                expand(mine, show, x, y, &win);

                //统计周围雷数
                int c = GetmyCount(mine, x, y);
                show[x][y]=c + '0';// 字符0ascll为48 1为49 加字符即可打印出周围集合的相关的字符
                //每排查一次打印一次棋盘
                DisplayBoard(mine, ROW, COL);
                win++;
            }
        }
        else
        {
            printf("坐标非法请重新输入\n");
        }
        z++;
    }
    if (win == (row * col) - s)
    {
        printf("恭喜你，排雷成功\n");
        DisplayBoard(mine, ROW, COL);

    }
}
void menu()
{
    printf("******************\n");
    printf("***** 1.play *****\n");
    printf("***** 0.exit *****\n");
    printf("******************\n");
}
void game()
{
    char mine[ROWS][COLS] = { 0 };
    char show[ROWS][COLS] = { 0 };
    //初始化数组
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //打印棋盘
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    //排查雷
    FindMine(mine, show,ROW,COL);
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择\n");
                break;
        }
    } while (input);

    return 0;
}