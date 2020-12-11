//
// Created by Administrator on 2020/12/10.
//
//实验11-2-3 逆序数据建立链表 (20分)
//https://pintia.cn/problem-sets/13/problems/603
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main() {
    struct ListNode *p, *head = NULL;

    head = createlist();
    for (p = head; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist() {
    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    int N;
    scanf("%d", &N);

    while (N != -1) {
        struct ListNode *pNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        pNode->next = NULL;
        pNode->data = N;

        if (pHead->next == NULL) {
            pHead->next = pNode;
        } else {
            pNode->next = pHead->next;
            pHead->next = pNode;
        }
        scanf("%d", &N);
    }

    return pHead->next;
}