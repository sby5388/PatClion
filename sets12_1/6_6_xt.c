/*
习题6-6 使用函数输出一个整数的逆序数 （20 分）
本题要求实现一个求整数的逆序数的简单函数。

函数接口定义：
int reverse( int number );
其中函数reverse须返回用户传入的整型number的逆序数。

裁判测试程序样例：

输入样例：
-12340
输出样例：
-4321
*/
#include <stdio.h>

int reverse(int number);

int main() {
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int reverse(int number) {
    int fushu = 0;
    if (number < 0) {
        fushu = 1;
        number = 0 - number;
    }
    int result = 0;
    while (number > 0) {
        result = result * 10 + number % 10;
        number = number / 10;
    }
    if (fushu == 1) {
        result = 0 - result;
    }
    return result;
}

