// c 语言,在内存分配中,堆和栈的区别
// Created by hwddhome on 2020/4/24.
//
#include <stdio.h>
#include <malloc.h>

int main(void) {
    //在栈上分配
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    printf("栈: 向下\n");
    printf("i1=0x%08x\n", &i1);
    printf("i2=0x%08x\n", &i2);
    printf("i3=0x%08x\n", &i3);
    printf("i4=0x%08x\n\n", &i4);
    printf("----------------\n\n");
    //在堆上分配
    char *p1 = (char *) malloc(4);
    char *p2 = (char *) malloc(4);
    char *p3 = (char *) malloc(4);
    char *p4 = (char *) malloc(4);
    printf("p1=0x%08x\n", p1);
    printf("p2=0x%08x\n", p2);
    printf("p3=0x%08x\n", p3);
    printf("p4=0x%08x\n\n", p4);

    //释放内存
    free(p1);
    p1 = NULL;
    free(p2);
    p2 = NULL;
    free(p3);
    p3 = NULL;
    free(p4);
    p4 = NULL;
    return 0;
}
