//
// Created by Administrator on 2021/1/2.
//
//7-3 A除以B (10分)
//https://pintia.cn/problem-sets/1146682252642181120/problems/1146696172069150722


#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int A;
    int B;
    scanf("%d %d", &A, &B);

    printf("%d/", A);
    if (B == 0) {
        printf("%d=Error", B);
    } else if (B < 0) {
        printf("(%d)=%.2f", B, (A * 1.0) / B);
    } else {
        printf("%d=%.2f", B, (A * 1.0) / B);
    }

    return 0;
}