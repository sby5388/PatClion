//
// Created by Administrator on 2021/1/2.
//
//7-5 求整数段和 (10分)
//https://pintia.cn/problem-sets/1146682475225505792/problems/1192035949498109952

#include<stdio.h>

int main() {
    int A;
    int B;
    scanf("%d %d", &A, &B);

    int count = 0;
    int sum = 0;


    for (int i = A; i <= B; ++i) {
        printf("%5d", i);
        sum += i;
        count++;
        if (count % 5 == 0) {
            printf("\n");
        }

    }
    if (count % 5 != 0) {
        printf("\n");
    }
    printf("Sum = %d", sum);


    return 0;
}