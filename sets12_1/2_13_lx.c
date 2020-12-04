/*
练习2-13 求N分之一序列前N项和 （15 分）
本题要求编写程序，计算序列 1 + 1/2 + 1/3 + ... 的前N项之和。

输入格式:
输入在一行中给出一个正整数N。

输出格式:
在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后6位。题目保证计算结果不超过双精度范围。

输入样例:
6
输出样例:
sum = 2.450000
*/
#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    double sum = 0.0;
    if (N > 0) {
        for (int i = 1; i <= N; i++) {
            sum += 1.0 / i;
        }
    }
    printf("sum = %.6lf", sum);
    return 0;
}

