//
// Created by Administrator on 2020/12/3.
//

//单链表逆转
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef int ElementType;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

/**
 * L是给定单链表，函数Reverse要返回被逆转后的链表
 * @param L
 * @return
 */
List Reverse(List L);

/**
 * 细节在此不表
 * @return
 */
List Read();

/**
 * 细节在此不表
 * @param L
 */
void Print(List L);

int main() {
    List L1;
    List L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int N;
    scanf("%d", &N);
    //带头节点的
    List pHead;
    pHead = (List) malloc(sizeof(struct Node));
    pHead->Next = NULL;
    List pNext = pHead;
    while (N > 0) {
        List pNode = (List) malloc(sizeof(struct Node));
        pNode->Next = NULL;
        scanf("%d", &pNode->Data);
        pNext->Next = pNode;
        pNext = pNext->Next;
        N--;
    }
    PtrToNode next = pHead->Next;
    pHead->Next = NULL;
    free(pHead);
    return next;
}

void Print(List L) {
    List show = L;
    while (show) {
        printf("%d ", show->Data);
        show = show->Next;
    }
    printf("\n");
}

List Reverse(List L) {
    List pResult;
    pResult = (List) malloc(sizeof(struct Node));
    pResult->Next = NULL;
    while (L != NULL) {
        List pCurrent = L;
        L = L->Next;
        pCurrent->Next = NULL;
        if (pResult->Next == NULL) {
            pResult->Next = pCurrent;
        } else {
            pCurrent->Next = pResult->Next;
            pResult->Next = pCurrent;
        }
    }

    PtrToNode pNode = pResult->Next;
    pResult->Next = NULL;
    free(pResult);
    return pNode;
}

