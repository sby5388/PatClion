//
// Created by Administrator on 2020/12/21.
//
//实验8-2-5 判断回文字符串 (20分)
//https://pintia.cn/problem-sets/13/problems/554
#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {
    false, true
} bool;

bool palindrome(char *s);

int main() {
    char s[MAXN];

    scanf("%s", s);
    if (palindrome(s) == true) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
bool palindrome(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    bool result = true;
    int mid = length / 2;
    for (int i = 0; i < mid; i++) {
        //TODO 下标与实际长度有偏差
        if (s[i] != s[length - i - 1]) {
            result = false;
            break;
        }
    }
    return result;
}