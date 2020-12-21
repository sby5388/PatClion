//
// Created by Administrator on 2020/12/21.
//
//实验6-7 使用函数输出一个整数的逆序数 (20分)
//https://pintia.cn/problem-sets/13/problems/479

#include <stdio.h>

int reverse(int number);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
//好像也可以用一个数组来实现
int reverse(int number) {
    //负数
    int negative = 0;
    if (number < 0) {
        negative = 1;
        number = 0 - number;
    }
    int sum = 0;
    while (number > 0) {
        int i = number % 10;
        sum = sum * 10 + i;
        number = number / 10;
    }
    if (negative) {
        sum *= -1;
    }
    return sum;
}