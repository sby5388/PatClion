//
// Created by Administrator on 2020/12/10.
//
//实验11-2-4 删除单链表偶数节点 (20分)
//https://pintia.cn/problem-sets/13/problems/604
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

struct ListNode *deleteeven(struct ListNode *head);

void printlist(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

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

struct ListNode *deleteeven(struct ListNode *head) {
    //删除首部的偶数节点
    while (head && head->data % 2 == 0) {
        struct ListNode *pNode = head;
        head = head->next;
        free(pNode);
    }

    struct ListNode *pListNode = head;
    while (pListNode && pListNode->next) {
        struct ListNode *next = pListNode->next;
        if (next->data % 2 == 0) {
            pListNode->next = next->next;
            free(next);
        }else{
            //printf("--%d--\n", next->data);
            pListNode = pListNode->next;
        }
    }
    return head;
}