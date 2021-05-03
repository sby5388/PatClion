//
// Created by Administrator on 2021/5/3.
//
//实验8-2-6 分类统计各类字符个数 (15 分)
//https://pintia.cn/problem-sets/13/problems/555

#include <stdio.h>

#define MAXS 15

void StringCount(char *s);

//由pat系统实现
void ReadString(char *s);

int main() {
    char s[MAXS];
    ReadString(s);
//    s = "aaahshs ";

    StringCount(s);

    return 0;
}

//由pat系统实现,这里做测试使用
void ReadString(char *s) {
    char c;
    int index = 0;
    scanf("%c", &c);
    while (c != '\0' && index < MAXS - 1) {
        //printf("c = %c\n", c);
        s[index] = c;
        index++;
        scanf("%c", &c);
    }
    s[index] = '\0';
}

void StringCount(char *s) {
    int letterLower = 0;
    int letterUpper = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    for (int i = 0; i < MAXS; i++) {
        //读取一个字符串，而输出一个字符串是 putchar(c);
        char c = s[i];
        if (c == '\0') {
            break;
        }
        if (c >= 'A' && c <= 'Z') {
            letterUpper++;
        } else if (c >= 'a' && c <= 'z') {
            letterLower++;
        } else if (c == ' ') {
            blank++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else {
            other++;
        }
    }
    //printf("letterLower = %d, blank = %d, digit = %d, other = %d", letterLower, blank, digit, other);
    printf("%d %d %d %d %d", letterUpper, letterLower, blank, digit, other);
}