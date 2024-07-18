#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> //错误码
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 512
#define ZERO '\0'
#define SEP " "
#define NUM 32
#define SkipPath(p)         \
    do                      \
    {                       \
        p += strlen(p) - 1; \
        while (*p != '/')   \
            p--;            \
    } while (0) // 宏函数

// 缓冲区
char *gArgv[NUM];
char cwd[SIZE * 2];

int lastcode=0;

// 退出码
void Die()
{
    exit(1);
}

const char *GetHome()
{
    const char *home = getenv("HOME");
    if (home == NULL)
        return "/r";

    return home;
}

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
    const char *hostname = getenv("HOSTNAME");
    if (hostname == NULL)
        return "None";
    return hostname;
}

// 获取当前所处路径
const char *Getcwd()
{
    const char *cwd = getenv("PWD");
    if (cwd == NULL)
        return "None";
    return cwd;
}

// 输出命令行提示符
void MakeCommandLinePrint()
{
    char line[SIZE];
    const char *username = GetUserName();
    const char *hostname = GetHostName();
    const char *cwd = Getcwd();

    SkipPath(cwd);
    snprintf(line, SIZE, "[%s@%s %s]>", username, hostname, strlen(cwd) == 1 ? "/" : cwd + 1); //+1不打印‘/’
    printf("%s", line);
    fflush(stdout);
}

// 获取用户输入命令
int GetUserCommand(char command[], size_t n)
{
    char *s = fgets(command, n, stdin);
    if (s == NULL)
        return 1;

    command[strlen(command) - 1] = ZERO; // 移除最后的换行符
    return strlen(command);
}

// 分割用户命令
void SplitCommand(char command[], size_t n)
{
    gArgv[0] = strtok(command, SEP); // 第一个参数
    int index = 1;
    while ((gArgv[index++] = strtok(NULL, SEP)))
        ;
}

void ExecuteCommand()
{
    pid_t id = fork();
    if (id < 0)
        Die();
    else if (id == 0)
    {
        // child
        execvp(gArgv[0], gArgv);
        exit(errno);
    }
    else
    {
        // father
        int status = 0;
        pid_t rid = waitpid(id, &status, 0);
        if (rid > 0)
        { 
            lastcode=WEXITSTATUS(status);//获取错误代码
            if(lastcode!=0)printf("%s:%s:%d\n",gArgv[0],strerror(lastcode),lastcode);//打印出对应的错误信息
        }
    }
}

void cd()
{
    const char *path = gArgv[1];
    if (path == NULL)
        path = GetHome();
    // path一定存在

    // chdir:更改当前工作路径
    chdir(path);

    // 刷新环境变量
    char temp[SIZE * 2];
    getcwd(temp, sizeof(temp)); // getcwd:获取当前工作目录的路径,返回当前工作目录的路径名
    // 更新当前环境变量(不更新导致命令行提示符path不更新)
    snprintf(cwd, sizeof(cwd), "PWD=%s", temp);
    putenv(cwd);
}

int CheckBuildin()
{
    int yes = 0;
    const char *enter_cmd = gArgv[0];
    // 判断是不是内建命令
    if (strcmp(enter_cmd, "cd") == 0)
    {
        yes = 1;
        cd();
    }
    else if(strcmp(enter_cmd,"echo")==0 && strcmp(gArgv[1],"$?")==0)
    {
        yes=1;
        printf("%d\n",lastcode);
        lastcode=0;
    }

    return yes;
}

int main()
{
    int quit = 0;
    while (!quit)
    {
        // 1. 输出命令行提示符
        MakeCommandLinePrint();

        // 2. 获取用户输入的命令
        char usercommand[SIZE];
        int n = GetUserCommand(usercommand, sizeof(usercommand));
        if (n <= 0)
            return 1; // 获取失败，重新获取

        // 3. 分割命令
        SplitCommand(usercommand, sizeof(usercommand));

        // 4.检查命令是否是内建命令
        n = CheckBuildin();
        if (n)
            continue;

        // n.执行命令
        ExecuteCommand();
    }

    return 0;
}
// ls -l --color