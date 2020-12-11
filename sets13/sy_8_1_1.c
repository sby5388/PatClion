//
// Created by Administrator on 2020/12/10.
//
//实验8-1-1 利用指针找最大值 (10分)
//https://pintia.cn/problem-sets/13/problems/539
#include <stdio.h>

/*
 * 其中px和py是用户传入的两个整数的指针。
 * 函数findmax应找出两个指针所指向的整数中的最大值，存放在pmax指向的位置。
 */
void findmax(int *px, int *py, int *pmax);

int main() {
    int max, x, y;

    scanf("%d %d", &x, &y);
    findmax(&x, &y, &max);
    printf("%d\n", max);

    return 0;
}

/* 你的代码将被嵌在这里 */

void findmax(int *px, int *py, int *pmax) {
    int x = *px;
    int y = *py;
    if (x >= y) {
        *pmax = *px;
    } else {
        *pmax = *py;
    }
}