// shell:可以一直执行不同的命令
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 512
#define ZERO '\0'
#define SEP " "
#define NUM 32

// 获取用户名字，失败返回空
const char *GetUserName()
{
    const char *name = getenv("USER");
    if (name == NULL)
        return "None";
    return name;
}

// 获取主机名
const char *GetHostName()
{
    const char *hostnam = getenv("HOSTNAME");
    if (hostnam == NULL)
        return "None";
    return hostnam;
}

// 获取当前所处路径
// 临时
const char *Getcwd()
{
    const char *cwd = getenv("PWD");
    if (cwd == NULL)
        return "None";
    return cwd;
}

// output
void MakeCommandLinePrint()
{
    char line[SIZE]; // 命令缓冲

    const char *username = GetUserName();
    const char *hostname = GetHostName();
    const char *cwd = Getcwd();

    snprintf(line, sizeof(line), "[%s@%s %s]>", username, hostname, cwd);
    printf("%s", line);
    fflush(stdout); // 刷新缓冲区
}

//获取用户输入命令
int GetUserCommand(char command[], size_t n)
{
    char *s = fgets(command, n, stdin); // stdin:从标准输入中获取
    if (s == NULL)
        return 1; // 暂时

    command[strlen(command - 1)] = ZERO; // 消除最后输入的\n(回车)F
    //printf("echo : %s", usercommand);//test
    return strlen(command);
}

char *gArgv[NUM];
void SplitCommand(char command[],size_t n)
{
    //“ls -a -l -n" -> "ls" "-a" "-l" "-n"
    gArgv[0]=strtok(command,SEP);//分割符号:SEP
    int index=1;
}

int main()
{
    // 1.输出命令行
    MakeCommandLinePrint();

    // 2.获取命令行
    char usercommand[SIZE];
    int n=GetUserCommand(usercommand,sizeof(usercommand));
    (void)n;

    //3.命令行字符串分割
    


    return 0;
}