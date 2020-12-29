//
// Created by Administrator on 2020/12/29.
//
//基础实验2-2.3 组合数的和 (15分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988036618285490176
#include <stdio.h>

int main() {
    int N;
    int sum = 0;
    int number = 0;

    scanf("%d", &N);
    int i = 0;
    while (i < N) {
        scanf("%d", &number);
        sum += number;
        i++;
    }

    printf("%d", sum * 11 * (N - 1));
    return 0;
}
