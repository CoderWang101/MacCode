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
    /*系统调用*/
    close(1); // 关闭标准输出
    int fd = open(filename, O_CREAT | O_WRONLY | O_WRONLY, O_TRUNC, 0666);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    /*库函数*/
    printf("printf ,fd: %d\n", fd);
    fprintf(stdout, "fprints, fd: %d\n", fd);
    fflush(stdout);

    /*系统调用*/
    close(fd); 

    return 0;
}

// const char *filename = "log.txt";

// int main()
// {
//     struct stat st;
//     int n = stat(filename, &st);
//     if (n < 0)
//         return 1;

//     printf("file size: %llu\n", st.st_size); // st_size:无符号整数

//     int fd = open(filename, O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 2;
//     }
//     printf("fd: %d\n", fd);

//     char *file_buffer = (char *)malloc(st.st_size + 1);
//     n=read(fd,file_buffer,st.st_size);// 超过字符串长度,返回值是字符串的末尾,而不是定义的长度

//     if(n>0)
//     {
//         file_buffer[n]='\0';
//         printf("%s",file_buffer);
//     }

//     free(file_buffer);

//     close(fd);

//     return 0;
// }
