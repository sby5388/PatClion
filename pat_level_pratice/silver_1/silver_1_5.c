//
// Created by Administrator on 2021/1/2.
//
//7-5 电子汪 (10分)
//https://pintia.cn/problem-sets/1146682252642181120/problems/1146696406425886720


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