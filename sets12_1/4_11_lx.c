/*
练习4-11 统计素数并求和 （20 分）
本题要求统计给定整数M和N区间内素数的个数并对它们求和。

输入格式:
输入在一行中给出两个正整数M和N（1≤M≤N≤500）。

输出格式:
在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

输入样例:
10 31
输出样例:
7 143
*/
#include<stdio.h>
#include<math.h>

int prime(int p);

void PrimeAction(int m, int n);

int main() {
    int m, n, p;
    scanf("%d %d", &m, &n);
    PrimeAction(m, n);
    return 0;
}

int prime(int p) {
    if (p < 2) {
        return 0;
    }
    if (p > 3 && 0 == (p % 2)) {
        return 0;
    }
    int count = 0;
    int min = 1;
    int max = sqrt(p);
    for (int i = min; i <= max; i++) {
        if (0 == p % i) {
            count++;
        }
        if (count > 1) {
            return 0;
        }
    }
    return 1;
}

void PrimeAction(int m, int n) {
    int count = 0;
    int sum = 0;
    for (int i = m; i <= n; i++) {
        if (1 == prime(i)) {
            sum += i;
            count++;
        }
    }
    printf("%d %d", count, sum);
}
