/*
练习2-18 求组合数 （15 分）
本题要求编写程序，根据公式
C(m,n) = n!/(m!*(n-m)!)
 算出从n个不同元素中取出m个元素（m≤n）的组合数。

建议定义和调用函数fact(n)计算n!，其中n的类型是int，函数类型是double。

输入格式:
输入在一行中给出两个正整数m和n（m≤n），以空格分隔。

输出格式:
按照格式“result = 组合数计算结果”输出。题目保证结果在double类型范围内。

输入样例:
2 7
输出样例:
result = 21
*/
#include<stdio.h>

double fact(int N);

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    double result = fact(n) / (fact(m) * fact(n - m));
    printf("result = %.0lf", result);

    return 0;
}

double fact(int n) {
    double result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

