/*
练习5-2 找两个数中最大者 （10 分）
本题要求对两个整数a和b，输出其中较大的数。

函数接口定义：
int max( int a, int b );
其中a和b是用户传入的参数，函数返回的是两者中较大的数。
输入样例：
-5 8
输出样例：
max = 8
*/
#include <stdio.h>

int max(int a, int b);

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("max = %d\n", max(a, b));

    return 0;
}

/* 你的代码将被嵌在这里 */
int max(int a, int b) {
    int max = a;
    if (b > a) {
        max = b;
    }
    return max;
}
