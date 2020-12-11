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

    if (M == 0) {
        printf("%d", number[0]);
        for (int j = 1; j < N; ++j) {
            printf(" %d", number[j]);
        }
    } else {
        //第一个不带空格
        printf("%d", number[N - M]);
        //后半部分，相当于移动后的前面
        for (int j = N - M + 1; j < N; ++j) {
            printf(" %d", number[j]);
        }
        //前面部分，相当于移动后的后面
        for (int j = 0; j < N - M; ++j) {
            printf(" %d", number[j]);
        }
    }

    return 0;
}

