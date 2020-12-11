//
// Created by Administrator on 2020/12/11.
//
// 实验11-2-8 单链表结点删除 (20分)
//https://pintia.cn/problem-sets/13/problems/609
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();

struct ListNode *deletem(struct ListNode *L, int m);

void printlist(struct ListNode *L);

int main() {
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

void printlist(struct ListNode *L) {
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */

struct ListNode *readlist() {
    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode *pTail = pHead;
    int N;
    scanf("%d", &N);
    while (N != -1) {
        struct ListNode *pNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        pNode->next = NULL;
        pNode->data = N;
        pTail->next = pNode;
        pTail = pTail->next;

        scanf("%d", &N);
    }

    return pHead->next;
}

struct ListNode *deletem(struct ListNode *L, int m) {
    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode *pTail = pHead;
    while (L) {
        struct ListNode *pNode = L;
        if (L->data == m) {
            L = L->next;
            pNode->next = NULL;
            free(pNode);
        } else {
            L = L->next;
            pNode->next = NULL;
            pTail->next = pNode;
            pTail = pTail->next;
        }
    }

    return pHead->next;
}