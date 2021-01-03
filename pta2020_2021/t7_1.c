//
// Created by Administrator on 2021/1/1.
//
//7-1 压岁钱 (5分)
//https://pintia.cn/problem-sets/1342389883092344832/problems/1343932697323728896

#include <stdio.h>

int main() {
    int N = 4;
    int sum = 0;
    int number;
    while (N > 0) {
        scanf("%d", &number);
        sum += number;
        N--;
    }
    printf("%d", sum);
    return 0;
}