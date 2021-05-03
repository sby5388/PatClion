//
// Created by Administrator on 2021/5/3.
//

//实验6-5 使用函数输出指定范围内的Fibonacci数 (20 分)
//https://pintia.cn/problem-sets/13/problems/477
//递归函数

#include <stdio.h>

int fib(int n);

void PrintFN(int m, int n);

int main() {
    int m, n, t;
    scanf("%d %d %d", &m, &n, &t);


    printf("fib(%d) = %d\n", t, fib(t));

    PrintFN(m, n);

    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

void PrintFN(int m, int n) {
    int first = 1;
    int i = 1;
    int value = fib(i);
    while (value <= n) {
        //printf("fib(%d):: = %d\n", i, value);
        if (value >= m && value <= n) {
            if (first) {
                printf("%d", value);
                first = 0;
            } else {
                printf(" %d", value);
            }
        }
        i++;
        value = fib(i);
    }
    if (first) {
        printf("No Fibonacci number");
    }
}

