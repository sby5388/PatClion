//
// Created by Administrator on 2020/6/12.
//
/**
 * 类似于4_11_1的问题，只是根据月数求兔子对数
 */

#include "stdio.h"

int getCount(int N);

int main() {
    int N;
    scanf("%d", &N);

    int count = getCount(N);
    printf("%d", count);
    return 0;
}

int getCount(int N) {
    if (N == 1 || N == 2) {
        return 1;
    }
    return getCount(N - 1) + getCount(N - 2);
}
