#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    umask(0); // 防止0666权限设置失败(变成0664)

    // O_WRONLY:以只读的方式打开 |O_CREAT:若不存在,则创建文件 |O_TRUNC 在此打开清空内容 ->相当于'w';0666:权限
    // int fd=open("log.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
    int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666); // O_APPEND:追加(不覆盖,向后追加内容)->相当于'a'

    if (fd < 0)
    {
        perror("error");
        return 1;
    }
    const char *massage = "Hello Linux file !\n";
    write(fd, massage, strlen(massage));

    close(fd);

    return 0;
}

// #include<stdio.h>
// #include<sys/types.h>
// #include<sys/stat.h>
// #include<fcntl.h>
// int main()
// {
//     umask(0);//防止0666权限设置失败(变成0664)

//     //O_WRONLY:以只读的方式打开 |O_CREAT:若不存在,则创建文件;0666:权限
//     int fd=open("log.txt",O_WRONLY | O_CREAT,0666);

//     if(fd<0)
//     {
//         perror("error");
//         return 1;
//     }

//     return 0;
// }