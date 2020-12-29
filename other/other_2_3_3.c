//
// Created by Administrator on 2020/12/29.
//
//进阶实验2-3.3 两个有序链表序列的交集 (20分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988036947642970112
//已知两个非降序链表序列S1与S2，设计函数构造出S1与S2的交集新链表S3。
//带头结点的
#include <stdlib.h>
#include <stdio.h>

#define END -1

typedef int ElementType;
typedef struct LNode *List;
struct LNode {
    ElementType X;
    List Next;
};

List CreateList();

/**
 * 获取交集（相同元素的）
 * @param L1
 * @param L2
 * @return
 */
List GetIntersection(List L1, List L2);

void PrintList(List L);

void FreeList(List L);

int main() {
    List L1;
    List L2;
    List L3;

    L1 = CreateList();
    L2 = CreateList();
    L3 = GetIntersection(L1, L2);
    PrintList(L3);
    //TODO 需要释放空间
    FreeList(L3);
    FreeList(L2);
    FreeList(L1);
    return 0;
}

List CreateList() {
    List L = (List) malloc(sizeof(struct LNode));
    L->Next = NULL;
    List pTail = L;
    int number;
    scanf("%d", &number);
    while (number != END) {
        List pNode = (List) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        pNode->X = number;

        pTail->Next = pNode;
        pTail = pTail->Next;

        scanf("%d", &number);
    }

    return L;
}

void PrintList(List L) {
    int first = 1;
    List pHead = L->Next;
    if (pHead == NULL) {
        printf("NULL");
        return;
    }
    while (pHead) {
        if (first) {
            printf("%d", pHead->X);
            first = 0;
        } else {
            printf(" %d", pHead->X);
        }
        pHead = pHead->Next;
    }
}

List GetIntersection(List L1, List L2) {
    List L3 = (List) malloc(sizeof(struct LNode));
    L3->Next = NULL;
    List pTail = L3;

    List pHead1 = L1->Next;
    List pHead2 = L2->Next;

    while (pHead1 && pHead2) {
        if (pHead1->X == pHead2->X) {
            List pNode = (List) malloc(sizeof(struct LNode));
            pNode->Next = NULL;
            pNode->X = pHead1->X;

            pTail->Next = pNode;
            pTail = pTail->Next;

            pHead1 = pHead1->Next;
            pHead2 = pHead2->Next;
        } else {
            if (pHead2->X > pHead1->X) {
                pHead1 = pHead1->Next;
            } else {
                pHead2 = pHead2->Next;
            }
        }
    }
    return L3;
}

void FreeList(List L) {
    while (L->Next) {
        List next = L->Next;
        L->Next = next->Next;
        next->Next = NULL;
        free(next);
    }
    free(L);
}
