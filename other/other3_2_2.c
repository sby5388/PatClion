//
// Created by Administrator on 2020/12/10.
//
//基础实验3-2.2 单链表分段逆转 (25分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988038293285015552
//带头结点

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

List ReadInput();

void PrintList(List L);

void K_Reverse(List L, int K);

int main() {
    List L;
    int K;
    L = ReadInput();
    scanf("%d", &K);
    K_Reverse(L, K);
    PrintList(L);
    return 0;
}

List ReadInput() {
    List L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;

    List head = L;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        List pNode = (List) malloc(sizeof(struct Node));
        pNode->Next = NULL;
        scanf("%d", &pNode->Data);
        head->Next = pNode;
        head = head->Next;
    }
    return L;
}

void PrintList(List L) {
    List pNode = L->Next;
    while (pNode) {
        printf("%d ", pNode->Data);
        pNode = pNode->Next;
    }
}

void K_Reverse(List L, const int K) {
    if (K <= 1) {
        //无需操作
        return;
    }
    List Head = (List) malloc(sizeof(struct Node));
    Head->Next = NULL;
    List pNode = Head;
    int count = 0;

    List Temp = (List) malloc(sizeof(struct Node));
    Temp->Next = NULL;
    List hTemp = Temp;
    while (L->Next) {
        PtrToNode next = L->Next;
        L->Next = next->Next;
        if (count == 0) {
            //放在头部
            hTemp->Next = next;
            next->Next = NULL;
            count++;
        } else {
            next->Next = NULL;
            next->Next = hTemp->Next;
            hTemp->Next = next;
            count++;
        }

        if (count == K) {
            pNode->Next = hTemp->Next;
            hTemp->Next = NULL;
            count = 0;
            while (pNode->Next) {
                pNode = pNode->Next;
            }
        }
    }

    //不满足K长度的部分，要恢复
    //剩余部分不需要逆转,其实已经被逆序一次了，所以需要再次逆转回去
    if (hTemp->Next) {
        List last = (List) malloc(sizeof(struct Node));
        last->Next = NULL;
        List pLastHead = last;
        while (hTemp->Next) {
            List next = hTemp->Next;
            hTemp->Next = next->Next;
            next->Next = NULL;
            if (pLastHead->Next) {
                next->Next = pLastHead->Next;
                pLastHead->Next = next;
            } else {
                pLastHead->Next = next;
            }
        }
        pNode->Next = last->Next;
        last->Next = NULL;
        free(last);
    }

    free(Temp);
    L->Next = Head->Next;
    Head->Next = NULL;
    free(Head);
}


