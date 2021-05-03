//
// Created by Administrator on 2021/5/3.
//

//实验10-5 递归求简单交错幂级数的部分和 (15 分)
//https://pintia.cn/problem-sets/13/problems/577
//递归
//https://pintia.cn/problem-sets/12/problems/354

#include <stdio.h>

double fn(double x, int n);

int main() {
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x, n));

    return 0;
}

double fn(double x, int n) {
    if (n == 1) {
        return x;
    }

    return x * (1 - fn(x, n - 1));
}