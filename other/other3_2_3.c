//
// Created by Administrator on 2020/12/10.
//
//基础实验3-2.3 共享后缀的链表 (25分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988038562512924672

#include <stdlib.h>
#include <stdio.h>

typedef char ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node {
    ElementType Data;
    PtrToNode Next;
};

void ReadInput(List L1, List L2);

void PrintSublist(PtrToNode StartP);

PtrToNode Suffix(List L1, List L2);

int main() {
    List L1;
    List L2;

    PtrToNode P;

    L1 = (List) malloc(sizeof(struct Node));
    L1->Next = NULL;

    L2 = (List) malloc(sizeof(struct Node));
    L2->Next = NULL;

    ReadInput(L1, L2);
    P = Suffix(L1, L2);
    PrintSublist(P);

    return 0;
}

PtrToNode Suffix(List L1, List L2){
    EOF;
}