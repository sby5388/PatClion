//
// Created by Administrator on 2020/12/9.
//
//自测-3 数组元素循环右移问题 (20分)
//https://pintia.cn/problem-sets/17/problems/262
#include <stdio.h>

int main() {
    int N;
    int M;
    int Temp;
    scanf("%d %d", &N, &M);
    int number[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(number[i]));
    }
    while (M > N) {
        M -= N;
    }


    for (int j = 0; j < M; ++j) {
        Temp = number[N - 1];
        for (int k = N - 1; k > 0; k--) {
            number[k] = number[k - 1];
        }
        number[0] = Temp;
    }

    printf("%d", number[0]);
    for (int q = 1; q < N; ++q) {
        printf(" %d", number[q]);
    }


    return 0;
}

