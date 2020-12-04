/**
 * 习题11-7 奇数值结点链表 (20分)
 * 本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：
 * struct ListNode {
 *  int data;
 *  ListNode *next;
 * };
 *
 * 函数接口定义：
 * struct ListNode *readlist();
 * struct ListNode *getodd( struct ListNode **L );
 * 函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。
 *
 * 函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，
 * 同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。
 *
 * 输入样例：
 * 1 2 2 3 4 5 6 7 -1
 * 输出样例：
 * 1 3 5 7
 * 2 2 4 6
 *
 */

#include "stdio.h"
#include "stdlib.h"

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
    struct ListNode *L;
    struct ListNode *Odd;

    L = readlist();
    //struct ListNode *pNode = L;
    //printlist(pNode);

    Odd = getodd(&L);

    printlist(Odd);
    printlist(L);

    return 0;
}

//todo 带头结点
struct ListNode *readlist() {
    int N;
    struct ListNode *L = (struct ListNode *) malloc(sizeof(struct ListNode));
    L->next = NULL;
    struct ListNode *tail = L;

    scanf("%d", &N);

    while (N != -1) {
        struct ListNode *p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->data = N;
        //printf("n = %d\n", p->data);

        tail->next = p;
        tail = tail->next;

        scanf("%d", &N);
    }

    return L->next;
}

struct ListNode *getodd(struct ListNode **L) {
    struct ListNode *odd = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *even = (struct ListNode *) malloc(sizeof(struct ListNode));
    odd->next = NULL;
    even->next = NULL;

    struct ListNode *tail = odd;
    struct ListNode *tailEven = even;
    struct ListNode *pNode = *L;
    //todo 还要修改**L指向的数据


    while (pNode) {
        struct ListNode *temp = pNode;
        struct ListNode *next = pNode->next;

        //printf("data = %d\n", temp->data);
        if (temp->data % 2 == 1) {
            //todo 奇数
            tail->next = temp;
            temp->next = NULL;
            tail = tail->next;

        } else {
            tailEven->next = temp;
            temp->next = NULL;
            tailEven = tailEven->next;
        }
        pNode = next;

    }
    //修改*L指向的位置
    *L = even->next;
    return odd->next;
}

