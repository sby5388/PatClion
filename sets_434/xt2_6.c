//
// Created by Administrator on 2020/6/21.
//
/**
 * 习题2.6 递归求简单交错幂级数的部分和 (15分)
 * 本题要求实现一个函数，计算下列简单交错幂级数的部分和：
 * f(x,n) = x - x^2 + x^3 - x^4 + ... + (-1)^(n-1)*(x^n)
 * 函数接口定义：
 * double fn( double x, int n );
 * 其中题目保证传入的n是正整数，并且输入输出都在双精度范围内。
 *  函数fn应返回上述级数的部分和。todo 建议尝试用递归实现。
 *
 * 输入样例：
 * 0.5 12
 * 输出样例：
 * 0.33
 */
#include <stdio.h>

double fn(double x, int n);

int main() {
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    //printf("x= %.2f,n = %d\n", x, n);

    printf("%.2f\n", fn(x, n));

    return 0;
}

double fn(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        //printf("n = %d,x = %.2f,result = %.2f\n", n, x, x);
        return x;
    }

    double d = -x * (fn(x, n - 1) - 1);
    //printf("n = %d,x = %.2f,result = %.2f\n", n, x, d);
    return d;
}