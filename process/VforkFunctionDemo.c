//
// Created by hwddhome on 2020/4/30.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/*
 * vforx 函数也是系统调用函数，但是和 forx 函数不同的是，vforx 函数在创建子进程时不会复制父进程的所有资源，父子进程共享地址空间．
 *
 * 在使用vforx函数时，父进程会被阻塞，需要在子进程中调用_exit()函数退出子进程，不能使用 exit()函数推出
 */
int gvar = 2;

int main(void) {
    pid_t pid;
    int var = 5;
    printf("process id:%ld\n", (long) getpid());
    printf("gvar=%d var=%d\n", gvar, var);


    if ((pid = vfork()) < 0) { /*创建一个新进程*/
        perror("error!");
        return 1;
    } else if (pid == 0) {
        /*子进程*/
        gvar--;
        var++;
        printf("the child process id:%ld\n gvar=%d var=%d\n", (long) getpid(), gvar, var);
        _exit(0);
    } else {
        /*父进程*/
        printf("the parent process id:%ld\n gvar=%d var=%d\n", (long) getpid(), gvar, var);
        return 0;
    }


    return 0;
}



