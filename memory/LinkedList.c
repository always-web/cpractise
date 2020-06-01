//
// Created by hwddhome on 2020/4/24.
//
#include <malloc.h>
#include <stdio.h>
#include <pthread.h>

#define LEN sizeof(struct student)


typedef struct student {
    int num;
    int age;
    float score;
    struct student *next;
} stu;


int n;

stu *create(void) {

    stu *head, *p1, *p2;
    n = 0;
    p1 = p2 = (stu *) malloc(LEN);

    scanf("%d,%d,%f", &p1->num, &p1->age, &p1->score);  /*输入结构体类型的数据*/
    head = NULL; /*头指针置空*/
    while (p1->num != 0) {
        n = n + 1;
        if (n == 1) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (stu *) malloc(LEN);
        scanf("%d,%d,%f", &p1->num, &p1->age, &p1->score);
    }
    p2->next = NULL;
    return head;
}

int main(void){
    stu *p, *head;
    head = create();
    p = head;
    if (head != NULL) {
        do {

            printf("%d,%d,%f\n", p->num, p->age, p->score);
            p = p->next;
        } while (p != NULL);
    }
    return 0;
}