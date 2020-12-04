/*
习题2-5 求平方根序列前N项和 （15 分）
本题要求编写程序，计算平方根序列
√1  + √2 + √3 + ...
的前N项之和。可包含头文件math.h，并调用sqrt函数求平方根。

输入格式:
输入在一行中给出一个正整数N。

输出格式:
在一行中按照“sum = S”的格式输出部分和的值S，精确到小数点后两位。题目保证计算结果不超过双精度范围。

输入样例:
10
输出样例:
sum = 22.47
*/
#include<stdio.h>
#include<math.h>

int main() {
    int N;
    scanf("%d", &N);
    double sum = 0.0;
    while (N > 0) {
        sum += sqrt(N);
        N--;
    }
    printf("sum = %.2lf", sum);

    return 0;
}

