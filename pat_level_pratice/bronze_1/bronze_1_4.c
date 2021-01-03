//
// Created by Administrator on 2021/1/2.
//
//7-4 是不是太胖了 (5分)
//https://pintia.cn/problem-sets/1146681776865501184/problems/1146685226957365248


#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    float weight = (N - 100) * 0.9 * 2;
    printf("%.1f", weight);
    return 0;
}