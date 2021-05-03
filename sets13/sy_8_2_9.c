//
// Created by Administrator on 2021/5/3.
//
//实验8-2-9 长整数转化成16进制字符串 (15 分)
//https://pintia.cn/problem-sets/13/problems/542


#include <stdio.h>

#define MAXN 10

void f(long int x, char *p);

int main() {
    long int x;
    char s[MAXN] = "";

    scanf("%ld", &x);
    f(x, s);
    printf("%s\n", s);

    return 0;
}

void f(long int x, char *p) {
    if (x == 0) {
        p[0] = '0';
        p[1] = '\0';
        return;
    }
    int negative = 0;

    if (x < 0) {
        x = 0 - x;
        negative = 1;
    }
    //起始位置
    int startIndex = 0;
    if (negative) {
        p[0] = '-';
        startIndex = 1;
    }
    int index = startIndex;

    while (x > 0) {
        long i1 = x % 16;
        int count = index;
        p[count + 1] = '\0';
        while (count > startIndex) {
            p[count] = p[count - 1];
            count--;
        }

        if (i1 >= 0 && i1 <= 9) {
            p[startIndex] = '0' + i1;
        } else {
            p[startIndex] = 'A' + (i1 - 10);
        }

        x = x / 16;
        index++;
    }
}