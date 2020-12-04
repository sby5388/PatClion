/*
习题6-2 使用函数求特殊a串数列和 （20 分）
给定两个均不超过9的正整数a和n，要求编写函数求a+aa+aaa++…+aa…a（n个a）之和。

函数接口定义：
int fn( int a, int n );
int SumA( int a, int n );
其中函数fn须返回的是n个a组成的数字；SumA返回要求的和。

裁判测试程序样例：

输入样例：
2 3
输出样例：
fn(2, 3) = 222
s = 246
*/
#include <stdio.h>

int fn(int a, int n);

int SumA(int a, int n);

int main() {
    int a, n;

    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a, n));
    printf("s = %d\n", SumA(a, n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int fn(int a, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result * 10 + a;
    }
    return result;
}

int SumA(int a, int n) {
    int sum = 0;
    int count = 1;
    for (int i = 0; i <= n; i++) {
        sum = sum * 10 + count * i;
    }
    return sum * a;

}
