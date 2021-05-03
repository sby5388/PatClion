//
// Created by Administrator on 2021/5/3.
//

//实验10-8 递归计算P函数 (15 分)
//https://pintia.cn/problem-sets/13/problems/582

#include <stdio.h>

double P(int n, double x);

int main() {
    int n;
    double x;

    scanf("%d %lf", &n, &x);
    printf("%.2f\n", P(n, x));

    return 0;
}

double P(int n, double x) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }

    //n>1
    return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
}
