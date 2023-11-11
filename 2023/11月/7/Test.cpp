// // 贪吃蛇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// #include <stdio.h>
// #include <graphics.h>
// #include <conio.h>
// #include <time.h>
// #define BLOCK_SIZE 20
// #define HEIGHT 30
// #define WIDTH 40
// int blocks[HEIGHT][WIDTH] = {0}, cs = 0; // 储存地图信息和记录吃的食物数量，来控制速度；
// char moveDirection;                      // 控制舍身运动方向；
// int food_i, food_j;                      // 食物的坐标
// int isfailure = 0;                       // 是否失败的标识符

// void startup()
// { // 初始化函数
//     int i;
//     blocks[HEIGHT / 2][WIDTH / 2] = 1; // 1代表蛇头，给蛇头位置
//     for (i = 1; i < 5; i++)
//     {
//         blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;
//     }                    // 初始化一个长度为5的蛇身；
//     moveDirection = 'd'; // 初始化蛇身方向为"d"；
//     // srand(time(0));//给srand()时间种子，防止随机有规律有寻；
//     food_i = rand() % (HEIGHT - 5) + 2; // 初始化食物坐标
//     food_j = rand() % (WIDTH - 5) + 2;
//     initgraph(WIDTH * BLOCK_SIZE, HEIGHT * BLOCK_SIZE); // 初始化窗体
//     setlinecolor(RGB(200, 200, 200));                   // 设置地图中每个方块的边界颜色
//     BeginBatchDraw();                                   // 开始批量绘制，防止闪屏，必须与FlushBatchDraw()一起使用；
// }
// void show()
// {                  // 绘制函数
//     cleardevice(); // 清屏与绘画搭配使用，做到动画的效果；
//     int i, j;
//     for (i = 0; i < HEIGHT; i++)
//     {
//         for (j = 0; j < WIDTH; j++)
//         { // 整个地图遍历
//             if (blocks[i][j] > 0)
//             {
//                 setfillcolor(HSVtoRGB(blocks[i][j] * 10, 0.9, 0.7)); // 蛇身的绘制，并用到HSVTORBG(),使蛇身颜色不一样；
//             }
//             else
//             {
//                 setfillcolor(RGB(150, 150, 150)); // 绘制非蛇身的场景；
//             }
//             fillrectangle(j * BLOCK_SIZE, i * BLOCK_SIZE, (j + 1) * BLOCK_SIZE, (i + 1) * BLOCK_SIZE); // 真正的绘制函数；
//         }
//     }
//     setfillcolor(RGB(0, 255, 0));                                                                                  // 设置食物颜色
//     fillrectangle(food_j * BLOCK_SIZE, food_i * BLOCK_SIZE, (food_j + 1) * BLOCK_SIZE, (food_i + 1) * BLOCK_SIZE); // 在食物地址绘制食物；
//     if (isfailure)
//     { // 如果游戏失败，绘制游戏失败标题；
//         setbkmode(TRANSPARENT);
//         settextcolor(RGB(255, 0, 0));
//         settextstyle(80, 0, _T("宋体"));
//         outtextxy(240, 220, _T("游戏失败"));
//     }
//     FlushBatchDraw(); // 按从BeginBatchDraw()开始的绘制要求绘制
// }
// void moveSnake()
// { // 控制蛇身动作反应的内在函数
//     int i, j;
//     for (i = 0; i < HEIGHT; i++)
//     { // 给所有的蛇身的数组加一
//         for (j = 0; j < WIDTH; j++)
//         {
//             if (blocks[i][j] > 0)
//             {
//                 blocks[i][j]++;
//             }
//         }
//     }
//     int oldtial_i, oldtial_j, oldHead_i, oldHead_j;
//     int max = 0;
//     for (i = 0; i < HEIGHT; i++)
//     {
//         for (j = 0; j < WIDTH; j++)
//         {
//             if (max < blocks[i][j])
//             { // 数组中最大的一定是蛇尾，把旧蛇尾的坐标存起来；
//                 max = blocks[i][j];
//                 oldtial_i = i;
//                 oldtial_j = j;
//             }
//             if (blocks[i][j] == 2)
//             { // 因为蛇头1加了1，所以为2，借此得到蛇头的位置
//                 oldHead_i = i;
//                 oldHead_j = j;
//             }
//         }
//     }
//     int newHead_i = oldHead_i; //  设定变量存储新蛇头的位置
//     int newHead_j = oldHead_j;
//     if (moveDirection == 'w')
//     {
//         newHead_i = oldHead_i - 1; // 向上新蛇头的位置应该是逻辑上老蛇头的Y坐标减1；
//     }
//     else if (moveDirection == 's')
//     {
//         newHead_i = oldHead_i + 1; // 向下新蛇头的位置应该是逻辑上老蛇头的Y坐标加1；
//     }
//     else if (moveDirection == 'a')
//     {
//         newHead_j = oldHead_j - 1; // 向左新蛇头的位置应该是逻辑上老蛇头的X坐标减1；
//     }
//     else if (moveDirection == 'd')
//     {
//         newHead_j = oldHead_j + 1; // 向右新蛇头的位置应该是逻辑上老蛇头的X坐标加1；
//     }
//     if (newHead_i >= HEIGHT || newHead_i <= 0 || newHead_j >= WIDTH || newHead_j <= 0 || blocks[newHead_i][newHead_j] > 0)
//     { // 蛇头蛇尾出界，以及检查到新蛇头在蛇身上，也就是蛇咬到自己为游戏失败；
//         isfailure = 1;
//         return;
//     }
//     blocks[newHead_i][newHead_j] = 1; // 给新蛇头的位置赋值1；
//     if (newHead_i == food_i && newHead_j == food_j)
//     { // 如果新蛇头位置在食物的地方，也就是蛇吃到了食物，并给食物重新给一个位置；
//         food_i = rand() % (HEIGHT - 5) + 2;
//         food_j = rand() % (WIDTH - 5) + 2;
//         cs++; // 吃的次数加一；
//     }
//     else
//         blocks[oldtial_i][oldtial_j] = 0; // 如果没迟到食物，把旧蛇尾赋值为
// }
// void updateWithoutInput()
// {
//     if (isfailure)
//     { // 游戏未失败继续
//         return;
//     }
//     if (cs > 7)
//     {
//         cs = 7; // 防止cs过大而过快
//     }
//     int sx = 10 - cs;         // 通过cs来控制刷新率，从而控制速度。
//     static int waitIndex = 1; // 设置静态变量，防止调用完该函数调用完后此变量内存空间被舍弃（效果和全局一样）。
//     waitIndex++;

//     if (waitIndex == sx)
//     { // sx帧显示一次；
//         moveSnake();
//         waitIndex = 1; // 循环重新开始
//     }
// }
// void updateWithInput()
// {
//     if (kbhit() && isfailure == 0)
//     { // 如果有输入，且未失败
//         char input = _getch();
//         if (input == 'a' || input == 's' || input == 'w' || input == 'd')
//         {
//             moveDirection = input;
//             moveSnake();
//         }
//     }
// }
// int main()
// {
//     startup(); // 初始化；
//     while (1)
//     { // 不断调用；
//         show();
//         updateWithoutInput(); // 更新与输入无关的参数；
//         updateWithInput();    // 更新与输入有关的参数；
//     }
//     return 0;
// }