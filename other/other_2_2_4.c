//
// Created by Administrator on 2020/12/29.
//
//基础实验2-2.4 装箱问题 (20分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988036689915572224
//使用数组实现，有点浪费空间
#include <stdio.h>

#define MAX 100
//TODO 使用数组貌似有点浪费空间，试试线性链表

int main() {
    int N;
    int number;
    int count = 0;

    scanf("%d", &N);
    int box[N];
    int i;
    for (i = 0; i < N; ++i) {
        box[i] = MAX;
    }

    for (i = 0; i < N; ++i) {
        scanf("%d", &number);
        for (int j = 0; j < N; ++j) {
            if (box[j] >= number) {
                box[j] -= number;
                printf("%d %d\n", number, j + 1);
                break;
            }
        }
    }
    for (i = 0; i < N; ++i) {
        if (box[i] < MAX) {
            count++;
        } else {
            break;
        }
    }

    printf("%d", count);
    return 0;
}
