/*
练习2-11 计算分段函数[2] （10 分）
本题目要求计算下列分段函数f(x)的值：
f(x) = x^0.5  ,x>=0时; ---相当于开根号？
f(x) = (x+1)^2 + 2*x + 1/x ,x<0时

注：可在头文件中包含math.h，并调用sqrt函数求平方根，调用pow函数求幂。

输入格式:
输入在一行中给出实数x。

输出格式:
在一行中按“f(x) = result”的格式输出，其中x与result都保留两位小数。

输入样例1:
10
输出样例1:
f(10.00) = 3.16
输入样例2:
-0.5
输出样例2:
f(-0.50) = -2.75
*/
#include<stdio.h>
#include<math.h>

int main() {
    double N;
    scanf("%lf", &N);
    double result = 0.0;
    if (N >= 0) {
        result = pow(N, 0.5);
        //result  = sqrt(N);
    } else {
        result = pow(N + 1, 2) + 2 * N + 1 / N;
    }
    printf("f(%.2lf) = %.2lf", N, result);
    return 0;
}

