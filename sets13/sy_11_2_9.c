//
// Created by Administrator on 2020/12/11.
//
//实验11-2-9 链表逆置 (20分)
//https://pintia.cn/problem-sets/13/problems/607
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
/**
 *函数reverse将链表head逆置
 * @param head 用户传入的链表的头指针
 * @return 结果链表的头指针
 */
struct ListNode *reverse(struct ListNode *head);

void printlist(struct ListNode *head);

int main() {
    struct ListNode *head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

void printlist(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
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

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *pHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    pHead->next = NULL;
    struct ListNode *pTail = pHead;

    while (head) {
        struct ListNode *next = head->next;

        struct ListNode *pNode = head;

        pNode->next = NULL;

        if (pTail->next != NULL) {
            pNode->next = pTail->next;
            pTail->next = pNode;
        } else {
            pTail->next = pNode;
        }

        head = next;
    }

    return pHead->next;

}
