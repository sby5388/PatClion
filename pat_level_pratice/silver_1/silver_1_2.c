//
// Created by Administrator on 2021/1/2.
//
//7-2 是不是太胖了 (5分)
//https://pintia.cn/problem-sets/1146682252642181120/problems/1146696172069150721


#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    float weight = (N - 100) * 0.9 * 2;
    printf("%.1f", weight);
    return 0;
}