//
// Created by Administrator on 2020/12/21.
//
//实验8-2-4 使用函数实现字符串部分复制 (20分)
//https://pintia.cn/problem-sets/13/problems/552

#include <stdio.h>

#define MAXN 20
#define LOCAL_TEST 1

void strmcpy(char *t, int m, char *s);

void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main() {
    char s[MAXN];

#if LOCAL_TEST
    char t[MAXN] = "happy new year";
    int m = 7;
#else
    int m;
    char t[MAXN];
    scanf("%d\n", &m);
    ReadString(t);
#endif


    strmcpy(t, m, s);
    printf("%s\n", s);

    return 0;
}

#if !LOCAL_TEST

void ReadString(char s[]) {
    char c;
    int i = 0;
    scanf("%c", &c);

    //最后一位放'\0'
    while (1) {
        if (c == '\0') {
            break;
        }
        if (i >= MAXN) {
            break;
        }
        s[i] = c;
        i++;
        scanf("%c", &c);
    }
    s[i] = '\0';
}

#endif

/* 你的代码将被嵌在这里 */

void strmcpy(char *t, int m, char *s) {
    int length = 0;
    while (t[length] != '\0') {
        length++;
    }
    if (m > length) {
        s[0] = '\0';
        return;
    }

    //TODO m是从1开始的，所以要减去1
    int k = 0;
    for (int i = m - 1; i < length; ++i) {
        s[k] = t[i];
        k++;
    }
    s[k] = '\0';
}