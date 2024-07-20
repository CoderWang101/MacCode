//打开文件时,是进程打开文件(打开和关闭文件,cup在执行代码)
#include<stdio.h>

int main()
{
    FILE * fp=fopen("log.txt","a");//a:追加
    if(fp==NULL)
    {
        perror("error");
        return 1;
    }
    fclose(fp);

    return 0;
}