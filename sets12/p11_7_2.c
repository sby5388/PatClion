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

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();

struct ListNode *getodd(struct ListNode **L);

struct ListNode *getodd3(struct ListNode **L);


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
    struct ListNode *pNode = L;
    printlist(pNode);

    Odd = getodd(&L);

    printlist(Odd);
    printlist(L);

    return 0;
}


struct ListNode *getodd2(struct ListNode **L) {
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode *tail = result;


    struct ListNode *head = *L;
    struct ListNode *p = head->next;
    struct ListNode *temp;
    struct ListNode *pre = head;
    int m = 0;

    while (p) {
        m++;
        if ((p->data) % 2 == 1) {
            //奇数
            printf("奇数 %d \n", p->data);
            temp = p;
            if (p == head->next) {
                head->next = p->next;
                pre = p;
                p = p->next;

                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            } else {
                //TODO 修改的是P 前一个的Next
//                todo

                pre->next = p->next;
                pre = p;
                p = p->next;

                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }

        } else {
            printf("偶数 %d \n", p->data);
            pre = p;
            p = p->next;
        }
    }
    *L = head->next;
    printf("m = %d\n", m);
    return result->next;

}


struct ListNode *readlist() {
    int n = -1;
    scanf("%d", &n);
    struct ListNode *List = (struct ListNode *) malloc(sizeof(struct ListNode));
    List->next = NULL;
    struct ListNode *tail = List;

    while (n != -1) {
        struct ListNode *p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->data = n;

        tail->next = p;
        tail = tail->next;
        scanf("%d", &n);
    }
//    todo 为何要指向下一个
    return List->next;
}

struct ListNode *getodd(struct ListNode **L) {
    if (0) {
        return getodd2(L);
    }
    if (0) {
        return getodd3(L);
    }
    struct ListNode *Odd = (struct ListNode *) malloc(sizeof(struct ListNode));
    Odd->next = NULL;
    struct ListNode *tail = Odd;
    //原来的指针：也是现在偶数的指针
    struct ListNode *pNode = *L;

    int count = 0;
    while (pNode) {
        count++;
        struct ListNode *p = pNode;
        if (p->data % 2 == 1) {
            printf("奇数 %d \n", p->data);
            pNode->next = p->next;

            tail->next = p;
            tail->next = NULL;
            tail = tail->next;

            pNode = pNode->next;

            //tail->next = p;
            //pNode->next = p->next;
            //pNode = pNode->next;
            //p->next = NULL;
            //tail = tail->next;

        } else {
            printf("偶数 %d \n", p->data);
            pNode = pNode->next;
        }
        //printlist(Odd->next);
        //printlist(pNode);

    }
    printf("count = %d\n", count);
    return Odd->next;

}

/**
 * 这里应该是带头结点的
 * @param L
 * @return
 */
struct ListNode *getodd3(struct ListNode **L) {
    struct ListNode *Odd = (struct ListNode *) malloc(sizeof(struct ListNode));
    Odd->next = NULL;
    struct ListNode *tail = Odd;

    //L当前的位置
    struct ListNode *head = *L;
    //真正的第一个
    struct ListNode *p = head->next;

    struct ListNode *temp;

    struct ListNode *pre = head;

//    while (p) {
//        if (p->data%2)
//
//    }


    return Odd->next;
}