//
// Created by Administrator on 2021/5/3.
//

//实验10-10 递归实现顺序输出整数 (15 分)
//https://pintia.cn/problem-sets/13/problems/581

#include <stdio.h>

void printdigits(int n);

int main() {

    int n;
    scanf("%d", &n);
    printdigits(n);
    return 0;
}

void printdigits(int n) {
    if (n > 10) {
        printdigits(n / 10);
        printf("%d\n", n % 10);
    } else {
        printf("%d\n", n);
    }
}