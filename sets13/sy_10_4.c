//
// Created by Administrator on 2020/12/10.
//实验10-4 递归实现指数函数 (15分)
//https://pintia.cn/problem-sets/13/problems/576

#include <stdio.h>

/**
 * 本题要求实现一个计算x^n​​ （n≥1）的函数。
 * @param x
 * @param n
 * @return
 */
double calc_pow(double x, int n);

int main() {
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.0f\n", calc_pow(x, n));

    return 0;
}

/* 你的代码将被嵌在这里 */

double calc_pow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    return x * calc_pow(x, n - 1);
}