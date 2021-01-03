//
// Created by Administrator on 2021/1/2.
//
//7-2 电子汪 (10分)
//https://pintia.cn/problem-sets/1146682720562929664/problems/1146696806617014273


#include<stdio.h>

int main() {
    int A;
    int B;
    scanf("%d %d", &A, &B);
    int sum = A + B;
    while (sum > 0) {
        printf("Wang!");
        sum--;
    }

    return 0;
}