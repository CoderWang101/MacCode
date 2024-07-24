#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0) {
        perror("open");
        return 1;
    }

    // 将标准输出重定向到文件
    if (dup2(file, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(file);
        return 1;
    }

    close(file);  // 关闭原文件描述符

    // 此后的 printf 输出会写入到 output.txt 文件
    printf("This will go to the file 'output.txt'\n");
    printf("Hello\n");

    return 0;
}