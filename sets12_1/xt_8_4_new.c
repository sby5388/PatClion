//
// Created by Administrator on 2020/12/21.
//
//习题8-4 报数 (20分)
//https://pintia.cn/problem-sets/12/problems/337

#include <stdio.h>

#define MAXN 20

void CountOff(int n, int m, int out[]);

int main() {
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff(n, m, out);
    for (i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

void CountOff(int n, int m, int out[]) {
    for (int i = 0; i < n; ++i) {
        out[i] = 0;
    }
    int index = 0;
    int count = 0;
    while (index < n) {
        for (int i = 0; i < n; ++i) {
            if (out[i] == 0) {
                count++;
                if (count == m) {
                    index++;
                    out[i] = index;
                    count = 0;
                }
            }
        }
    }
}