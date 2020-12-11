//
// Created by Administrator on 2020/12/10.
//
//实验11-2-6 奇数值结点链表 (20分)
//https://pintia.cn/problem-sets/13/problems/608

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();

struct ListNode *getodd(struct ListNode **L);

void printlist(struct ListNode *L) {
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
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
//TODO  有点投机取巧，并不是
struct ListNode *getodd(struct ListNode **L) {
    struct ListNode *pHeadOdd = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHeadOdd->next = NULL;
    struct ListNode *pTailOdd = pHeadOdd;

    struct ListNode *pNode = *L;

    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode *pTail = pHead;


    while (pNode) {
        struct ListNode *current = pNode;
        struct ListNode *next = pNode->next;
        pNode = next;
        current->next = NULL;
        if (current->data % 2 == 0) {
            pTail->next = current;
            pTail = pTail->next;
        } else {
            pTailOdd->next = current;
            pTailOdd = pTailOdd->next;
        }
    }

    *L = pHead->next;
    return pHeadOdd->next;
}