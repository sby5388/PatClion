//
// Created by Administrator on 2021/1/2.
//
//7-2 心理阴影面积 (5分)
//https://pintia.cn/problem-sets/1146682475225505792/problems/1192035628319289344

#include<stdio.h>

int main() {
    int x;
    int y;
    scanf("%d %d", &x, &y);


    int all = 100 * 100 / 2;
    int size1 = y * (100 - x);
    int size2 = (100 - x) * (100 - y) / 2;
    int size3 = x * y / 2;

    printf("%d", all - size1 - size2 - size3);
    return 0;
}