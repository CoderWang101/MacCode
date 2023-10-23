#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define WIDTH 20
#define HEIGHT 10

// 定义贪吃蛇结构体
typedef struct {
    int x;
    int y;
} Snake;

// 定义游戏状态
enum GameState {
    RUNNING,
    GAME_OVER
};

int kbhit();
void initSnake(Snake *snake);
void drawSnake(Snake *snake);
void clearScreen();
void updateSnake(Snake *snake);
void gameLoop();

// 获取键盘输入的函数
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// 初始化蛇的位置
void initSnake(Snake *snake) {
    snake->x = WIDTH / 2;
    snake->y = HEIGHT / 2;
}

// 绘制蛇
void drawSnake(Snake *snake) {
    clearScreen();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == snake->y && j == snake->x) {
                printf("@");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// 清空屏幕
void clearScreen() {
    printf("\033[H\033[J");
}

// 更新蛇的位置
void updateSnake(Snake *snake) {
    if (kbhit()) {
        char key = getchar();
        switch (key) {
            case 'w':
                snake->y--;
                break;
            case 'a':
                snake->x--;
                break;
            case 's':
                snake->y++;
                break;
            case 'd':
                snake->x++;
                break;
            default:
                break;
        }
    }
}

// 游戏循环
void gameLoop() {
    Snake snake;
    initSnake(&snake);

    enum GameState state = RUNNING;

    while (state == RUNNING) {
        drawSnake(&snake);
        updateSnake(&snake);
        usleep(100000); // 控制游戏速度
    }
}

int main() {
    gameLoop();

    return 0;
}