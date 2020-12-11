//
// Created by Administrator on 2020/12/8.
//
//7-29 删除字符串中的子串 (20分)
//https://pintia.cn/problem-sets/14/problems/809
/*
输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

输入格式：
输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

输出格式：
在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Tomcat is a male ccatat
cat
输出样例：
Tom is a male
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 80
#define debug 1

int main() {
    char S1[MAXSIZE];
    char S2[MAXSIZE];

    gets(S1);
    gets(S2);
    if (debug) {
        printf("%s\n", S1);
        printf("%s\n", S2);
    }


    long length1 = strlen(S1);
    long length2 = strlen(S2);
    if (debug) {
        printf("length1 = %ld\n", length1);
        printf("length2 = %ld\n", length2);
    }


    for (int i = 0; i < length1;) {
        if (S1[i] != S2[0] || (length1 - i < length2)) {
            printf("%c", S1[i]);
            i++;
        } else {
            int match = 1;
            for (int j = 0; j < length2; ++j) {
                if (S1[i + j] != S2[j]) {
                    match = 0;
                }
            }
            if (match) {
                i += length2;
            } else {
                printf("%c", S1[i]);
                i++;
            }
        }

    }


    return 0;
}