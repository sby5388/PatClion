/*
习题2-6 求阶乘序列前N项和 （15 分）
本题要求编写程序，计算序列 1!+2!+3!+... 的前N项之和。

输入格式:
输入在一行中给出一个不超过12的正整数N。

输出格式:
在一行中输出整数结果。

输入样例:
5
输出样例:
153
*/
#include<stdio.h>

int factorial(int a);

int main() {
    int N;
    scanf("%d", &N);
    int start = 1;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        start *= i;
        sum += start;
    }
    printf("%d", sum);

    return 0;
}

int factorial(int a) {
    return a;
}

