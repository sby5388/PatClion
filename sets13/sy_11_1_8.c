//
// Created by Administrator on 2020/12/11.
//
//实验11-1-8 查找子串 (20分)
//https://pintia.cn/problem-sets/13/problems/593
#include <stdio.h>

#define MAXS 30

char *search(char *s, char *t);

void ReadString(char s[]); /* 裁判提供，细节不表 */

int main() {
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);

    printf("s = %s\n", s);
    printf("t = %s\n", t);

    pos = search(s, t);
    if (pos != NULL) {
        printf("%d\n", pos - s);
    } else {
        printf("-1\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
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

char *search(char *s, char *t) {
    char *sHead0 = s;
    char *sHead = sHead0;
    char *tHead = t;

    while (sHead0 && tHead) {
        if (*sHead == *tHead) {
            sHead++;
            tHead++;
        } else {
            sHead0++;
            sHead = sHead0;
            tHead = t;
        }
    }
    if (sHead0 != NULL) {
        return sHead0;
    } else {
        return NULL;
    }

}