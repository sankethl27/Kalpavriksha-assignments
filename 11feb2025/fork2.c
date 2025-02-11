#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    printf("Hello\n");
    fork();
    wait(NULL);
    return 0;
}