#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    printf("I am parent process : pid: %d\n\n" ,getpid() );

    pid_t ret=fork();

    printf("ret:%d, pid:%d ppid:%d\n",ret,getpid(),getppid());

    sleep(1);

    return 0;
}

