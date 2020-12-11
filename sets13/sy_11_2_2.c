//
// Created by Administrator on 2020/12/10.
//
//实验11-2-2 学生成绩链表处理 (20分)
//https://pintia.cn/problem-sets/13/problems/602
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};

struct stud_node *createlist();

struct stud_node *deletelist(struct stud_node *head, int min_score);

int main() {
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
//    for (p = head->next; p != NULL; p = p->next) {
//        printf("%d %s %d\n", p->num, p->name, p->score);
//    }

    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for (p = head; p != NULL; p = p->next) {
        printf("%d %s %d\n", p->num, p->name, p->score);
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
struct stud_node *createlist() {
    struct stud_node *head = (struct stud_node *) malloc(sizeof(struct stud_node));
    head->next = NULL;
    struct stud_node *pTail = head;

    int N;
    scanf("%d", &N);
    while (N != 0) {
        struct stud_node *pNode = (struct stud_node *) malloc(sizeof(struct stud_node));
        pNode->next = NULL;

        pNode->num = N;
        char name[20];
        int score;
        scanf("%s %d", name, &score);
        strcpy(pNode->name, name);
        pNode->score = score;
        pTail->next = pNode;
        pTail = pTail->next;

        scanf("%d", &N);

    }

    return head->next;

}


//不带头结点的 这种结果虽然正确，但不是按照题目的初衷来的
struct stud_node *deletelist_0(struct stud_node *head, int min_score) {
    struct stud_node *pHead = (struct stud_node *) malloc(sizeof(struct stud_node));
    pHead->next = NULL;
    struct stud_node *pTail = pHead;
    while (head) {
        struct stud_node *next = head->next;
        struct stud_node *pNode = head;
        pNode->next = NULL;

        if (pNode->score < min_score) {
            free(pNode);
        } else {
            pTail->next = pNode;
            pTail = pTail->next;
        }

        head = next;
    }
    return pHead->next;
}

struct stud_node *deletelist(struct stud_node *head, int min_score) {
    struct stud_node *pNode = head;
    while (pNode && pNode->score < min_score) {
        struct stud_node *node = pNode;
        struct stud_node *next = pNode->next;
        node->next = NULL;
        free(node);
        pNode = next;
    }
    head = pNode;

    while (pNode && pNode->next) {
        struct stud_node *next = pNode->next;
        if (next->score < min_score) {
            pNode->next = next->next;
            next->next = NULL;
            free(next);
        } else {
            pNode = pNode->next;
        }
    }
    return head;
}