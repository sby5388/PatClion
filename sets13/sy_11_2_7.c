//
// Created by Administrator on 2020/12/11.
//
//实验11-2-7 统计专业人数 (15分)
//https://pintia.cn/problem-sets/13/problems/606
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char code[8];
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
int countcs(struct ListNode *head);

int main() {
    struct ListNode *head;

    head = createlist();
    printf("%d\n", countcs(head));

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist() {
    struct ListNode *pNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    pNode->next = NULL;
    struct ListNode *pTail = pNode;
    char code[8];
    scanf("%s", code);
    while (strlen(code) == 7 && code[0] != '#') {
        //printf("%s length = %ld\n", code, strlen(code));

        struct ListNode *pListNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        pListNode->next = NULL;
        strcpy(pListNode->code, code);

        pTail->next = pListNode;
        pTail = pTail->next;

        scanf("%s", code);
    }


    return pNode->next;
}

int countcs(struct ListNode *head) {
    int count = 0;
    while (head && strlen(head->code) == 7) {
        if (head->code[1] == '0' && head->code[2] == '2') {
            count++;
        }
        head = head->next;
    }
    return count;
}
