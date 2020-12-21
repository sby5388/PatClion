//
// Created by Administrator on 2020/12/21.
//
//习题8-6 删除字符 (20分)
//https://pintia.cn/problem-sets/12/problems/339

//实验8-2-3 删除字符 (20分)
//https://pintia.cn/problem-sets/13/problems/553

#include <stdio.h>

#define MAXN 20
#define LOCAL_TEST 0

void delchar(char *str, char c);

void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main() {

#if LOCAL_TEST
    char str[MAXN] = "aahappy new yearaaa";
    char c = 'a';
#else
    char str[MAXN], c;
    scanf("%c\n", &c);
    ReadString(str);
#endif

    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

#if !LOCAL_TEST

void ReadString(char s[]) {
    char c;
    int i = 0;
    scanf("%c", &c);

    //最后一位放'\0'
    while (c != '\0' || i < MAXN - 1) {
        s[i] = c;
        i++;
        scanf("%c", &c);
    }
    s[i] = '\0';
}

#endif


/* 你的代码将被嵌在这里 */

void delchar(char *str, char c) {
    for (int i = 0; i < MAXN;) {
        if (str[i] == '\0')break;
        if (str[i] != c) {
            i++;
        } else {
            for (int j = i; j < MAXN; ++j) {
                if (str[j] == '\0')break;
                str[j] = str[j + 1];
            }
        }
    }
}