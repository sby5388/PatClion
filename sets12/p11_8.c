//
// Created by Administrator on 2020/7/4.
//

/**
 * 习题11-8 单链表结点删除 (20分)
 * 本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中所有存储了某给定值的结点删除。
 * 链表结点定义如下：
 * struct ListNode {
 *  int data;
 *  ListNode *next;
 * };
 *
 * 函数接口定义：
 * struct ListNode *readlist();
 * struct ListNode *deletem( struct ListNode *L, int m );
 * 函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。
 * 当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
 * 函数deletem将单链表L中所有存储了m的结点删除。
 * 返回指向结果链表头结点的指针。
 *
 * 输入样例：
 * 10 11 10 12 10 -1
 * 10
 * 输出样例：
 * 11 12
 *
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();

struct ListNode *deletem(struct ListNode *L, int m);

struct ListNode *deletem0(struct ListNode *L, int m);

void printlist(struct ListNode *L) {
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);
    return 0;
}

struct ListNode *readlist() {
    struct ListNode *L = (struct ListNode *) malloc(sizeof(struct ListNode));
    L->next = NULL;
    struct ListNode *tail = L;
    int N = -1;
    while (scanf("%d", &N) == 1 && N != -1) {
        struct ListNode *pNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        pNode->next = NULL;
        pNode->data = N;
        tail->next = pNode;
        tail = tail->next;
    }
    return L->next;
}

struct ListNode *deletem(struct ListNode *L, int m) {
    if (1) {
        return deletem0(L, m);
    }
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode *tail = result;
    while (L) {
        struct ListNode *next = L->next;
        if (L->data != m) {
            L->next = NULL;

            tail->next = L;
            tail = tail->next;
        }
        L = next;
    }
    return result->next;
}
/**
 * https://blog.csdn.net/weixin_44376134/article/details/85646127
 * @param L
 * @param m
 * @return
 */
struct ListNode *deletem0(struct ListNode *L, int m) {
    struct ListNode *head = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *q = NULL;

    head = L;
    //去掉最前面的
    while (head && head->data == m && head->next) {
        pre = head->next;
        free(head);
        head = pre;
    }

    if (head->data == m) {
        return NULL;
    }
    pre = head;
    q = head->next;
    while (q) {
        if (q->data == m) {
            pre->next = q->next;
            free(q);
            q = pre->next;
        } else {
            pre = q;
            q = pre->next;
        }

    }
    return head;

}