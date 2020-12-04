/*
习题10-1 判断满足条件的三位数 （15 分）
本题要求实现一个函数，统计给定区间内的三位数中有两位数字相同的完全平方数（如144、676）的个数。

函数接口定义：
int search( int n );
其中传入的参数int n是一个三位数的正整数（最高位数字非0）。
函数search返回[101, n]区间内所有满足条件的数的个数。

裁判测试程序样例：

输入样例：
500
输出样例：
count=6
*/
#include <stdio.h>
#include <math.h>

int search(int n);

int main() {
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}


/* 你的代码将被嵌在这里 */
int search(int n) {
    int count = 0;
    for (int i = 11;; i++) {
        int temp = i * i;
        if (temp > 101 && temp <= n) {
            int a = temp / 100;
            int b = temp / 10 % 10;
            int c = temp % 10;
            if (a == b || b == c || a == c) {
                count++;
            }

        } else {
            break;
        }
    }
    return count;


}

/*
101
110
011



*/
