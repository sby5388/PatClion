//
// Created by Administrator on 2020/12/30.
//
//L1-056 猜数字 (20分)
//https://pintia.cn/problem-sets/994805046380707840/problems/994805074646122496
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_LENGTH 9
typedef int ElementType;
typedef struct LNode *List;
struct LNode {
    ElementType Data;
    char Name[MAX_LENGTH];
    List Next;
};

List CreateList(int N);

double getAvg(List L, int N);

List FindClosest(List L, double avg);


int main() {
    int N;
    scanf("%d", &N);
    List L = CreateList(N);
    double avg = getAvg(L, N);
    double hal = avg / 2;
    List closest = FindClosest(L, hal);

    printf("%.0f %s", hal, closest->Name);

    return 0;

}

List CreateList(int N) {
    List L = (List) malloc(sizeof(struct LNode));
    L->Next = NULL;
    List pTail = L;

    while (N) {
        List pNode = (List) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        scanf("%s %d", pNode->Name, &pNode->Data);

        pTail->Next = pNode;
        pTail = pTail->Next;

        N--;
    }

    return L;
}

double getAvg(List L, int N) {
    double sum = 0.0;
    List next = L->Next;
    while (next) {
        sum += next->Data;
        next = next->Next;
    }

    return sum / N;
}

List FindClosest(List L, double hal) {
    List next = L->Next;
    List result = next;
    double close = fabs(result->Data - hal);
    next = next->Next;
    while (next) {
        double fab = fabs(next->Data - hal);
        if (fab < close) {
            close = fab;
            result = next;
        }
        next = next->Next;
    }
    return result;
}