//
// Created by hwddhome on 2020/4/24.
//
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void realloc_test();

void memset_test();

void calloc_test();

int main(void) {
    // realloc_test();
    // memset_test();
    calloc_test();
    return 0;
}

void calloc_test() {
    long *buffer;
    buffer = calloc(20, sizeof(long));
    free(buffer);
}

void memset_test() {
    char s[] = "welcome to mrsoft\n";
    printf("s before memset: %s\n", s);
    memset(s, '*', strlen(s) - 1);
    printf("s after memset %s\n", s);
}

void realloc_test() {
    char *p;
    p = (char *) malloc(10);
    if (p) {
        printf("Memory Allocated at %x", p);
    } else {
        printf("Not Enough memory\n");
    }
    getchar();
    p = (char *) realloc(p, 256);
    if (p) {
        printf("Memory Reallocated at %x", p);
    } else {
        printf("Not Enough Memory\n");
    }
    free(p);
    getchar();
}
