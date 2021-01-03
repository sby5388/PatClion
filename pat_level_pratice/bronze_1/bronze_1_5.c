//
// Created by Administrator on 2021/1/2.
//
//7-5 A除以B (10分)
//https://pintia.cn/problem-sets/1146681776865501184/problems/1146685377797120000

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