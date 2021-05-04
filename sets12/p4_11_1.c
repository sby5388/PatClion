/*
 * 习题4-11 兔子繁衍问题 (15分)斐波那契数列问题
 * 一对兔子，从出生后第3个月起每个月都生一对兔子。小兔子长到第3个月后每个月又生一对兔子。
 * 假如兔子都不死，请问第1个月出生的一对兔子，至少需要繁衍到第几个月时兔子总数才可以达到N对？
 *输入格式:
 * 输入在一行中给出一个不超过10000的正整数N。
 * 输出格式:
 * 在一行中输出兔子总数达到N最少需要的月数。
 *
 * 输入样例:
 * 30
 * 输出样例:
 * 9
 *
 */
#include <stdio.h>

int getCount(int N);

int main() {
    int N;
    scanf("%d", &N);

    int m = 0;
    int count = 0;
    while (count < N) {
        m++;
        count = getCount(m);
    }

    printf("%d", m);

    return 0;

}

int getCount(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1 || N == 2) {
        return 1;
    }
    return getCount(N - 1) + getCount(N - 2);
}