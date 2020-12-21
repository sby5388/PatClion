//
// Created by Administrator on 2020/12/21.
//
//实验11-1-6 指定位置输出字符串 (20分)
//https://pintia.cn/problem-sets/13/problems/592


#include <stdio.h>

#define MAXS 10

char *match(char *s, char ch1, char ch2);

int main() {
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */

char *match(char *s, char ch1, char ch2) {
    char *result = "";
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    int start = -1;
    int stop = 0;
    for (int i = 0; i < length; ++i) {
        if (s[i] == ch1) {
            if (start == -1) {
                result = s + i;
                start = i;
            }
        }
        stop = i;
        if (s[i] == ch2) {
            break;
        }
    }
    if (start != -1) {
        for (int j = start; j <= stop; ++j) {
            printf("%c", s[j]);
        }
    }
    printf("\n");
    return result;
}