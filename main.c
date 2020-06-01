#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void shuihuashu(void) {
    int start = 100;
    int end = 999;
    int g, s, b;
    for (int i = start; i <= end; ++i) {
        g = i % 10;
        s = i / 10 % 10;
        b = i / 100;
        if (g * g * g + s * s * s + b * b * b == i) {
            printf("%d ", i);
        }
    }
}

void feiboqiena(void) {
    int f1, f2;
    f1 = f2 = 1;
    printf("%10d %10d ", f1, f2);
    int n = 2;
    for (int i = 3; i <= 20; ++i) {
        int f = f1 + f2;
        printf("%10d ", f);
        n++;
        if (n % 5 == 0) {
            printf("\n");
        }
        f1= f2;
        f2 = f;
    }
}

int main() {
    feiboqiena();
    return 0;
}
