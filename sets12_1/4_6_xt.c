/*
习题4-6 水仙花数 （20 分）
水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身。
例如：153=1^3 + 5^3 + 3^3。
本题要求编写程序,计算所有N位水仙花数。

输入格式:
输入在一行中给出一个正整数N（3≤N≤7）。

输出格式:
按递增顺序输出所有N位水仙花数，每个数字占一行。

输入样例:
3
输出样例:
153
370
371
407
*/
#include<stdio.h>
#include<math.h>

#define return return

int narcissistic(int number);

int getResult(int number, int N);

int main() {
    int N;
    scanf("%d", &N);
    for (int i = pow(10, N - 1); i < pow(10, N); i++) {
        if (narcissistic(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

/**
1:是
0：不是
*/
int narcissistic(int number) {
    int number2 = number;
    int count = 0;
    int sum = 0;
    while (number2 > 0) {
        count++;
        number2 = number2 / 10;
    }
    number2 = number;
    while (number2 > 0) {
        int temp = number2 % 10;
        sum += getResult(temp, count);
        number2 = number2 / 10;
        if (sum > number) {
            break;
        }
    }
    if (sum == number) {
        return 1;
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
int getResult(int number, int N) {
    int result = 1;
    while (N > 0) {
        result *= number;
        N--;
    }
    return result;
}

