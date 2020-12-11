//
// Created by Administrator on 2020/12/10.
//
//实验11-2-1 建立学生信息链表 (20分)
//https://pintia.cn/problem-sets/13/problems/601


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
struct stud_node *head;
struct stud_node *tail;

void input();

int main() {
    struct stud_node *p;

    //头尾其实是同一个
    head = tail = NULL;

    input();
    for (p = head; p; p = p->next) {
        printf("%d %s %d\n", p->num, p->name, p->score);
    }

    return 0;
}


void input() {
    int N;
    char name[20];


    scanf("%d", &N);
    while (N != 0) {
        struct stud_node *pNode = (struct stud_node *) malloc(sizeof(struct stud_node));
        pNode->next = NULL;
        pNode->num = N;
        //使用这个方法时，需要多敲一行
        //gets(name);
        scanf("%s", name);
        strcpy(pNode->name, name);
        scanf("%d", &(pNode->score));
        if (head == NULL) {
            head = pNode;
        }

        if (tail == NULL) {
            tail = pNode;
        } else {
            tail->next = pNode;
            tail = tail->next;
        }
        scanf("%d", &N);
    }

}
