#include<stdio.h>
#include<stdlib.h>
int g_unval;//未初始化
int g_val = 100;//初始化
int main(int argc,char *argv[],char *env[])
{
    printf("code addr:           %p\n",main);//代码区起始地址
    const char* p = "hello bit";//p是指针变量(栈区)，p指向字符常量h(字符常量区)
    printf("read only :          %p\n",p);
    printf("global val:          %p\n",&g_val);
    printf("global uninit val:   %p\n",&g_unval);
    char *q = (char *)malloc(10);
    printf("heap addr:           %p\n",q);
    
    printf("stack addr:          %p\n",&p);//p先定义，先入栈
    printf("stack addr:          %p\n",&q);
    
    printf("args addr            %p\n",argv[0]);//命令行参数
    printf("args addr            %p\n",argv[argc-1]);
    
    printf("env addr:            %p\n",env[0]);//环境变量
    return 0;
}
