//
// Created by Administrator on 2021/1/2.
//
//7-3 到底是不是太胖了 (10分)
//https://pintia.cn/problem-sets/1146682720562929664/problems/1146696806617014274



#include<stdlib.h>
#include<stdio.h>
#include <math.h>

typedef enum {
    WanMei, Pang, Shou
} WeightType;
typedef struct LNode *Man;
struct LNode {
    int High;
    int Weight;
    WeightType Type;
    Man Next;
};


Man CreateList(int N);


int main() {
    int N;
    scanf("%d", &N);
    Man list = CreateList(N);
    Man pNode = list;
    while (pNode) {
        switch (pNode->Type) {
            case Pang: {
                printf("You are tai pang le!\n");
                break;
            }
            case Shou: {
                printf("You are tai shou le!\n");
                break;
            }
            case WanMei: {
                printf("You are wan mei!\n");
                break;
            }
            default:
                break;
        }

        pNode = pNode->Next;
    }


    return 0;
}

Man CreateList(int N) {
    Man pHead = (Man) malloc(sizeof(struct LNode));
    pHead->Next = NULL;
    Man pTail = pHead;
    while (N) {
        Man pNode = (Man) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        scanf("%d %d", &pNode->High, &pNode->Weight);


        //标准体重(市斤)
        double d = (pNode->High - 100) * 0.9 * 2;
        if (fabs(pNode->Weight - d) < d * 0.1) {
            pNode->Type = WanMei;
        } else {
            if (pNode->Weight > d) {
                pNode->Type = Pang;
            } else {
                pNode->Type = Shou;
            }
        }

        pTail->Next = pNode;
        pTail = pTail->Next;

        N--;
    }
    return pHead->Next;
}