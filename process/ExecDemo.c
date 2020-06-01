//
// Created by hwddhome on 2020/4/30.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

extern char **environ;

/*int main(int argc, char *argv[]) {

    execve("New2", argv, environ);
    puts("正常情况下无法输出此信息!");
}*/

/*int main(void){
    execve("New2", NULL, environ);
    puts("正常情况下无法输出此信息!");
}*/

/**
 * 带l的exec函数 <br/>
 * 这类函数有：execl，execlp，execle <br/>
 *具体说明：表示后边的参数以可变参数的形式给出且都以一个空指针结束。这里特别要说明的是，程序名也是参数，所以第一个参数就是程序名。
 */
void l_function_test() {
    printf("process begin...pid is : %d\n", getpid());
    execl("/bin/ls", "ls", NULL);
    printf("process end...pid is : %d\n", getpid());
}

/**
 * 带p的exec函数
 *
 * 这类函数有：execlp，execvp
 *
 * 具体说明：表示第一个参数无需给出具体的路径，只需给出函数名即可，系统会在PATH环境变量中寻找所对应的程序，如果没找到的话返回－1。
 */
void p_function_test() {
    printf("process begin...pid is : %d\n", getpid());
    execlp("ls", "ls","-l", NULL);
    printf("process end...pid is : %d\n", getpid());
}

/**
 * 带v的exec函数
 *
 * 这类函数有：execv，execvp
 *
 * 具体说明：表示命令所需的参数以char *arg[]形式给出且arg最后一个元素必须是NULL
 */
void v_function_test() {
    printf("process begin...pid is : %d\n", getpid());
    char *arr[] = {"ls","-l","-a",NULL};
    execvp("ls", arr);
    printf("process end...pid is : %d\n", getpid());
}

/**
 * 带e的exec函数
 *
 * 这类函数有：execle
 *
 * 具体说明：将环境变量传递给需要替换的进程，原来的环境变量不再起作用。
 */
void e_function_test() {
    printf("process begin...pid is : %d\n", getpid());
    char *envp[] = {"AA=11","BB=22",NULL};
    execle("./env", "env",NULL,envp);
}

/*int main(int argc, char *argv[]) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        puts("create a child process failed");
    }
    if (pid == 0) {
        execve("New2", argv, environ); *//*在子进程中调用 execve() 函数*//*
    } else {
        puts("此信息正常输出!"); *//*在父进程中输出此消息*//*
    }
}*/
extern char **environ;
int main() {

    // p_function_test();
    // v_function_test();
    e_function_test();
    for (int i = 0; environ[i] != NULL; ++i) {
        printf("%s\n", environ[i]);
    }
    return 0;

}


