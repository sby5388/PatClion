//
// Created by Administrator on 2021/1/2.
//
//7-1 装睡 (10分)
//https://pintia.cn/problem-sets/1146682720562929664/problems/1146696806617014272



#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 14
#define MAX_BREATH 20
#define MIN_BREATH 15
#define MAX_PULSE 70
#define MIN_PULSE 50

typedef enum {
    false, true
} bool;

typedef struct LNode *Man;

struct LNode {
    char Name[MAX_LENGTH];
    /*呼吸频率*/
    int Breath;
    /*脉搏频率*/
    int Pulse;
    Man Next;
};

Man CreateList(int N);

bool IsSleep(Man man);

int main() {
    int N;
    scanf("%d", &N);
    Man List = CreateList(N);
    Man next = List->Next;
    while (next) {
        if (!IsSleep(next)) {
            printf("%s\n", next->Name);
        }
        next = next->Next;
    }
    return 0;
}

Man CreateList(int N) {
    Man List = (Man) malloc(sizeof(struct LNode));
    List->Next = NULL;
    Man pTail = List;
    while (N > 0) {
        Man pNode = (Man) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        scanf("%s %d %d", pNode->Name, &pNode->Breath, &pNode->Pulse);

        pTail->Next = pNode;
        pTail = pTail->Next;

        N--;
    }
    return List;
}

bool IsSleep(Man man) {
    if (man->Breath <= MAX_BREATH && man->Breath >= MIN_BREATH
        && man->Pulse <= MAX_PULSE && man->Pulse >= MIN_PULSE) {
        return true;
    }
    return false;
}