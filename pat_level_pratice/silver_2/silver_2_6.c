//
// Created by Administrator on 2021/1/2.
//
//7-6 寻找250 (10分)
//https://pintia.cn/problem-sets/1146682475225505792/problems/1192036017034801152

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int count = 1;

    int N;
    scanf("%d", &N);
    while (N != 250) {
        count++;
        scanf("%d", &N);
    }
    printf("%d",count);
    return 0;
}