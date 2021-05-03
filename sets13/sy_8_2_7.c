//
// Created by Administrator on 2021/5/3.
//

//实验8-2-7 字符串的连接 (15 分)
//https://pintia.cn/problem-sets/13/problems/556

#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat(char *s, char *t);

int main() {
    char *p;
    char str1[MAXS + MAXS] = {'\0'};
    char str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);

    p = str_cat(str1, str2);

    printf("%s\n%s\n", p, str1);


    return 0;
}

/**
 * 将字符串t复制到字符串s的末端，并且返回字符串s的首地址。
 * @param s
 * @param t
 * @return
 */
char *str_cat(char *s, char *t) {
    int lengthS = strlen(s);
    int lengthT = strlen(t);

    //printf("%d:%d\n", lengthS, lengthT);

    int length = lengthS + lengthT;

    for (int i = 0; i < lengthT; ++i) {
        s[i + lengthS] = t[i];
    }
    s[length] = '\0';


    return s;
}



