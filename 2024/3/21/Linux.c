#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t id = fork();
    if (id < 0)
    {
        /* 创建失败*/
        perror("fork");
        return 1;
    }
    else if (id == 0)
    {
        /* child process(task)*/
        while (1)
        {
            printf("I an child , pid:%d , ppid:%d\n ", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        /* parent process */
        while (1)
        {
            printf("I an parent , pid:%d , ppid:%d\n ", getpid(), getppid());
            sleep(1);
        }
    }

    printf("you can see me!\n");
 
    sleep(1);

    return 0;
}