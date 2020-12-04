//
// Created by Administrator on 2020/7/5.
//

/**
 * 习题10-7 十进制转换二进制 (15分)
 * 本题要求实现一个函数，将正整数n转换为二进制后输出。
 * 函数接口定义：
 * void dectobin(int n);
 * 函数dectobin应在一行中打印出二进制的n,建议采用递归实现。
 * 输入样例：
 * 10
 * 输出样例：
 * 1010
 *
 */
#include <stdio.h>

void dectobin(int n);

int main() {
    int n;
    scanf("%d", &n);
    dectobin(n);
    return 0;
}

void dectobin(int n) {
    if (n == 1) {
        printf("%d", 1);
        return;
    }
    if (n == 0) {
        printf("%d", 0);
        return;
    }
    dectobin(n / 2);
    int i = n % 2;
    printf("%d", i);
}