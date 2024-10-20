#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int  argc, char *argv[])
{
    int fd;
    int nb = 90;

    fd = fork();
    if(fd == 0)
    {
        nb  = 100;
        printf("nb in the child is  %d\n", nb);
        printf("child  pid is %d\n", getpid());
        printf("parent pid is %d\n", getppid());
        //execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        wait(NULL);
        printf("fd in the child is  %d\n", fd);
        printf("parent pid is %d\n", getpid());
        printf("child pid is %d\n", getppid());
        printf("in the parent nb is  %d\n", nb);
        printf("Hello, World!\n");
    }
    return 0;
}