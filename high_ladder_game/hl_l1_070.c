//
// Created by Administrator on 2020/12/29.
//
//L1-070 吃火锅 (15分)
//https://pintia.cn/problem-sets/994805046380707840/problems/1336215880692482053

#include <stdio.h>
#include <string.h>

#define END "."
#define KEY_WORD "chi1 huo3 guo1"
#define MAX 81

int main() {
    int first = 0;
    int count = 0;
    int line = 0;
    char input[MAX];

    gets(input);
    //相等返回0
    while (strcmp(input, END) != 0) {
        //printf("%s\n", input);
        line++;
        // TODO  后面是子字符串，如果匹配了返回Str开始匹配的指针
        //  strstr(*_Str,*_SubStr)
        char *string = strstr(input, KEY_WORD);
        //printf("----%s\n", string);
        if (string != NULL) {
            if (first == 0) {
                first = line;
            }
            count++;
        }
        gets(input);
    }

    printf("%d\n", line);
    if (count != 0) {
        printf("%d %d", first, count);
    } else {
        printf("-_-#");
    }
    return 0;
}

