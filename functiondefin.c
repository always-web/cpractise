//
// Created by hwddhome on 2020/3/14.
//
#include <stdio.h>


int power(int, int);

int main(void) {
    int result = power(3, 3);
    printf("%d", result);
    return 0;
}


int power(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    return power(a, n / 2) * power(a, n - n / 2);
}