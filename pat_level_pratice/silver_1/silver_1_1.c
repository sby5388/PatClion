//
// Created by Administrator on 2021/1/2.
//
//7-1 日期格式化 (5分)
//https://pintia.cn/problem-sets/1146682252642181120/problems/1146696172069150720


#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    int y;
    int m;
    int d;

    scanf("%d-%d-%d", &m, &d, &y);

    printf("%d-%02d-%02d", y, m, d);
    return 0;
}