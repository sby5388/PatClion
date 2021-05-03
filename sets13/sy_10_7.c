//
// Created by Administrator on 2021/5/3.
//

//实验10-7 递归求Fabonacci数列 (10 分)
//https://pintia.cn/problem-sets/13/problems/579

#include <stdio.h>

int f(int n);

int main() {

    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));


    return 0;
}


int f(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return f(n - 1) + f(n - 2);
}