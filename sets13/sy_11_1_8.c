//
// Created by Administrator on 2020/12/11.
//
//实验11-1-8 查找子串 (20分)
//https://pintia.cn/problem-sets/13/problems/593
#include <stdio.h>

#define MAXS 30

#define TEST_LOCAL 0

char *search(char *s, char *t);

void ReadString(char s[]); /* 裁判提供，细节不表 */

int main() {
#if TEST_LOCAL
    char *pos;
    char s[MAXS] = "The C Programming Language";
    char t[MAXS] = "bored";
//    char s[MAXS] = "The C Programming Language";
//    char t[MAXS] = "ram";

#else
    char s[MAXS], t[MAXS], *pos;
    ReadString(s);
    ReadString(t);
#endif

//    printf("s = %s\n", s);
//    printf("t = %s\n", t);

    pos = search(s, t);
    if (pos != NULL) {
        printf("%d\n", pos - s);
    } else {
        printf("-1\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
#if !TEST_LOCAL

void ReadString(char s[]) {
    char c;
    int index = 0;
    scanf("%c", &c);
    while (c != '\0' && c != '\n') {
        //printf("c = %c\n", c);
        s[index] = c;
        index++;
        scanf("%c", &c);
    }
    s[index] = '\0';
    //printf("s = %s\n", s);
}

#endif

char *search(char *s, char *t) {
    char *sHead0 = s;
    char *sHead = sHead0;
    char *tHead = t;
    int found = 0;

//    printf("s = %c,t = %c\n", *s, *t);
//    printf("s = %s\n", s);
//    printf("t = %s\n", t);

    while (sHead0 && tHead) {
        if (*sHead == *tHead) {
//            printf("%c==%c\n", *sHead, *tHead);
            sHead++;
            tHead++;
        } else {
//            printf("%c!=%c\n", *sHead, *tHead);
            sHead0++;
            sHead = sHead0;
            tHead = t;
        }
        if (*tHead == '\0') {
            found = 1;
            break;
        }
        if (*sHead == '\0') {
            break;
        }
    }
    if (found) {
        return sHead0;
    } else {
        return NULL;
    }
}