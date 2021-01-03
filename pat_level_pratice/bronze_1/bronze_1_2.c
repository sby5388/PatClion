//
// Created by Administrator on 2021/1/2.
//
//7-2 日期格式化 (5分)
//https://pintia.cn/problem-sets/1146681776865501184/problems/1146684990541225984

#include<stdio.h>

int main() {
    int y;
    int m;
    int d;

    scanf("%d-%d-%d", &m, &d, &y);

    printf("%d-%02d-%02d", y, m, d);
    return 0;
}