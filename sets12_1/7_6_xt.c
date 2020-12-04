/*
习题7-6 统计大写辅音字母 （15 分）
英文辅音字母是除A、E、I、O、U以外的字母。
本题要求编写程序，统计给定字符串中大写辅音字母的个数。

输入格式：
输入在一行中给出一个不超过80个字符、并以回车结束的字符串。

输出格式：
输出在一行中给出字符串中大写辅音字母的个数。

输入样例：
HELLO World!
输出样例：
4
*/
#include<stdio.h>

#define return return

int main() {
    char chars[81];
    int i = 0;
    int count = 0;
    while ((chars[i] = getchar()) != '\n') {
        char c = chars[i];
        if (c >= 'A' && c <= 'Z') {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                //nothing
            } else {
                count++;
            }
        }

        i++;
    }
    printf("%d", count);

    return 0;
}

