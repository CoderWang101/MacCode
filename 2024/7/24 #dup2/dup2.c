#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

const char *filename = "log.txt";

int main()
{
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);

    fd = dup2(fd, 1); // 将fd内容保存到1中
    /*
        1被改为指向"log.txt"
        1不再指向显示器
    */

    printf("HelloWord\n");
    fprintf(stdout, "Hi~\n");

    fflush(stdout);

    return 0;
}
