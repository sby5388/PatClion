//
// Created by Administrator on 2021/1/2.
//
//7-4 谁是赢家 (10分)
//https://pintia.cn/problem-sets/1146682475225505792/problems/1192035767767314432


#include<stdio.h>

int main() {
    int A;
    int B;
    int N = 3;
    int countA = 0;
    int countB = 0;
    int point;

    scanf("%d %d", &A, &B);
    while (N) {
        scanf("%d", &point);
        if (point == 0) {
            countA++;
        } else if (point == 1) {
            countB++;
        }
        N--;
    }


    if ((A > B && countA > 0) || (A < B && countA == 3)) {
        printf("The winner is a: %d + %d", A, countA);
    } else if ((B > A && countB > 0) || (B < A && countB == 3)) {
        printf("The winner is b: %d + %d", B, countB);
    }

    return 0;
}