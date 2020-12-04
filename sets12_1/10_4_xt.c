/*
习题10-4 递归求简单交错幂级数的部分和 （15 分）
本题要求实现一个函数，计算下列简单交错幂级数的部分和：

f(x,n)=x-x^2+x^3-x^4+...+(-1)^(n-1)*x^n
x
00
函数接口定义：
double fn( double x, int n );
其中题目保证传入的n是正整数，并且输入输出都在双精度范围内。
函数fn应返回上述级数的部分和。建议尝试用递归实现。

裁判测试程序样例：

输入样例：
0.5 12
输出样例：
0.33
*/
#include <stdio.h>

double fn(double x, int n);

int main() {
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    for (int i = 0; i <= n; i++) {
        printf("%d %.2f\n", i, fn(x, i));
//		printf("%.2f\n", fn(x,i));
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1 - x;
    }

    return x * (1 - fn(x, n - 1));
}

