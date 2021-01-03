//
// Created by Administrator on 2021/1/2.
//
//7-3 后天 (5分)
//https://pintia.cn/problem-sets/1146681776865501184/problems/1146685104932478976


#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int newDay = N + 2;
    if (newDay > 7) {
        printf("%d", newDay % 7);
    } else {
        printf("%d", newDay);
    }



//    for (int i = 1; i <= 7; ++i) {
//        printf("%d:%d\n", i, (i + 2) % 7);
//    }

    return 0;
}