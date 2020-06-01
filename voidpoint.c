//
// Created by hwddhome on 2020/3/17.
// void 指针是万能指针,一般用于形参,这样方法就可以接收多种类型的参数

#include <stdio.h>
#include <string.h>
int main(void) {
    void *p;
    int a = 6;
    p = &a;
    printf("%d", *(int *) p);
    printf("\n");
    int arr[2];
    for (int i = 0; i < 2; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    memset(arr, 0, 2* sizeof(int));
    for (int i = 0; i < 2; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}

