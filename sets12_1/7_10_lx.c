/*
练习7-10 查找指定字符 （15 分）
本题要求编写程序，从给定字符串中查找某指定的字符。

输入格式：
输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。

输出格式：
如果找到，在一行内按照格式“index = 下标”输出该字符在字符串中所对应的最大下标（下标从0开始）；否则输出"Not Found"。

输入样例1：
m
programmaxg
输出样例1：
index = 7
输入样例2：
a
1234
输出样例2：
Not Found
*/
#include<stdio.h>

#define return return

int main() {
    char c;
    char chars[81];
    scanf("%c ", &c);
    int i = 0;
    while ((chars[i] = getchar()) != '\n') {
        i++;
    }
    int count = -1;
    for (int j = 0; j < i; j++) {
        if (chars[j] == c) {
            count = j;
        }
    }
    if (count != -1) {
        printf("index = %d", count);
    } else {
        printf("Not Found");
    }

    return 0;
}

