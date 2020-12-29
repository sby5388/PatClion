//
// Created by Administrator on 2020/12/29.
//
//基础实验2-2.4 装箱问题 (20分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988036689915572224
//链表实现，按需申请空间
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct LNode *Box;
struct LNode {
    /*序号，从1开始*/
    int Id;
    /* 剩余空间*/
    int Space;
    Box Next;
};

Box CreateBox(int Id);

int main() {
    int N;
    int number;
    int count = 1;
    Box pHead = CreateBox(1);
    Box pTail = pHead;

    scanf("%d", &N);
    if (N == 0) {
        count = 0;
    }

    int i;

    for (i = 0; i < N; ++i) {
        scanf("%d", &number);
        pTail = pHead;
        while (1) {
            if (pTail->Space >= number) {
                pTail->Space -= number;
                printf("%d %d\n", number, pTail->Id);
                break;
            } else {
                if (pTail->Next) {
                    pTail = pTail->Next;
                } else {
                    Box next = CreateBox(pTail->Id + 1);
                    count++;
                    pTail->Next = next;
                    pTail = pTail->Next;
                }
            }
        }
    }

    printf("%d", count);
    return 0;
}

Box CreateBox(int Id) {
    Box box = (Box) malloc(sizeof(struct LNode));
    box->Next = NULL;
    box->Id = Id;
    box->Space = MAX;
    return box;
}
