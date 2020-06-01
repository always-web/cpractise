//
// Created by hwddhome on 2020/4/30.
//
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
 * fork 函数会复制父进程的所有资源，包括进程环境，内存资源等.
 */
int gvar = 2;

int main(void) {
    pid_t pid;
    int var = 5;
    if ((pid = fork()) < 0) {
        printf("fork error\n");
        exit(1);
    } else if (pid == 0) {
        /*子进程*/
        gvar--;
        var++;
        printf("in the child process id:%ld\n gvar=%d\n var=%d\n", (long) getpid(), gvar, var);
    } else {
        /*父进程*/
        printf("in the parent process id:%ld\n gvar=%d\n var=%d\n", (long) getpid(), gvar, var);
    }
    exit(0);
}