//
// Created by Administrator on 2020/12/10.
//
//实验11-2-5 链表拼接 (20分)
//https://pintia.cn/problem-sets/13/problems/605


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);

void printlist(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct ListNode *createlist() {
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

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2) {

    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode *pTail = pHead;

    struct ListNode *next;

    while (list1 || list2) {
        if (list1 && list2) {
            if (list1->data <= list2->data) {
                next = list1;
                list1 = list1->next;

            } else {
                next = list2;
                list2 = list2->next;

            }
        } else if (list1) {
            next = list1;
            list1 = list1->next;

        } else {
            //list2
            next = list2;
            list2 = list2->next;
        }
        next->next = NULL;
        pTail->next = next;
        pTail = next;
    }

    return pHead->next;

}