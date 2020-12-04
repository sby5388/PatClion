//
// Created by Administrator on 2020/6/29.
//

/**
 * 习题2.3 数列求和-加强版 (20分)
 * https://pintia.cn/problem-sets/434/problems/5654
 * 给定某数字A（1≤A≤9）以及非负整数N（0≤N≤100000），
 * 求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。
 *
 * 输入格式：
 * 输入数字A与非负整数N。
 *
 * 输出格式：
 * 输出其N项数列之和S的值。
 *
 * 输入样例：
 * 1 3
 * 输出样例：
 * 123
 *
 */
#include <stdio.h>

long getSum(int A, int N);

int main() {
    int A;
    int N;
    scanf("%d %d", &A, &N);
    printf("%ld", getSum(A, N));
    return 0;
}

long getSum(int A, int N) {
    long sum = 0;
    long init = 1;
    while (N) {
        sum += init;
        init = init * 10 + 1;
        N--;
    }
    return sum * A;
}