/*
习题4-7 最大公约数和最小公倍数 （15 分）
本题要求两个给定正整数的最大公约数和最小公倍数。

输入格式:
输入在一行中给出两个正整数M和N（≤1000）。

输出格式:
在一行中顺序输出M和N的最大公约数和最小公倍数，两数字间以1空格分隔。

输入样例:
511 292
输出样例:
73 2044
*/
#include<stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int min = N > M ? M : N;
    int max = N < M ? M : N;
    if (max % min == 0) {
        printf("%d %d", min, max);
    } else {
        int result = 1;
        int maxValue = min;
        for (int i = 1; i < maxValue; i++) {
            if (min % i == 0 && max % i == 0) {
                result = i;
            }
        }

        printf("%d %d", result, min * max / result);
    }


    return 0;
}


