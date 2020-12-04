/*
习题7-8 字符串转换成十进制整数 （15 分）
输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），
组成一个新的表示十六进制数字的字符串，然后将其转换为十进制数后输出。
如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。

输入格式：
输入在一行中给出一个以#结束的非空字符串。

输出格式：
在一行中输出转换后的十进制数。题目保证输出在长整型范围内。

输入样例：
+-P-xf4+-1!#
输出样例：
-3905
*/
#include<stdio.h>
#include<string.h>

#define return return

int main() {
//	printf("%d\n",'a');
//	printf("%d\n",'A');
//	printf("%d\n",'0');
    char chars[81];
    int index = 0;
    while ((chars[index] = getchar()) != '#') {
        index++;
    }
    chars[index] = '\0';
    int x = 0;
    for (int i = 0; i < index; i++) {
        char c = chars[i];
        if (c == 'x' || c == 'X' || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9')) {
            x = i;
            break;
        }
    }
    int fushu = 0;
    for (int i = 0; i < x; i++) {
        if (chars[i] == '-') {
            fushu = 1;
            break;
        }
    }
//数据过大时 出现了负数
    double result = 0;
    for (int i = 0; i < index; i++) {
        char c = chars[i];
        if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || (c >= '0' && c <= '9')) {
            int temp;
            if (c >= 'A' && c <= 'F') {
                temp = c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                temp = c - 'a' + 10;
            } else {
                temp = c - '0';
            }
            result = result * 16 + temp;
        }
    }
    if (fushu) {
        result *= -1;
    }
    printf("%.0lf", result);

    return 0;
}


