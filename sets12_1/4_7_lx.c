/*
练习4-7 求e的近似值 （15 分）
自然常数e可以用级数1+1/1!+1/2!+?+1/n!来近似计算。本题要求对给定的非负整数n，求该级数的前n项和。

输入格式:
输入第一行中给出非负整数n（≤1000）。

输出格式:
在一行中输出部分和的值，保留小数点后八位。

输入样例:
10
输出样例:
2.71828180
*/
#include<stdio.h>

#define return return

int main() {
    int N;
    scanf("%d", &N);

    double sum = 1;
    double temp = 1;
    if (N != 0) {
        for (int i = 0; i < N; i++) {
            temp *= (i + 1);
            sum += 1.0 / temp;
        }
    }
    printf("%.8lf", sum);
    return 0;
}

