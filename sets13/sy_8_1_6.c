//
// Created by Administrator on 2020/12/12.
//
//实验8-1-6 函数实现字符串逆序 (15分)
//https://pintia.cn/problem-sets/13/problems/541

#include <stdio.h>

#define MAXS 20

void f(char *p);

void ReadString(char *s); /* 由裁判实现，略去不表 */

int main() {
    char s[MAXS];

    ReadString(s);
    f(s);
    printf("%s\n", s);
    return 0;
}

void ReadString(char *s) {
    char c;
    int index = 0;
    scanf("%c", &c);
    while (c != '\0' && c != '\n' && index < MAXS - 1) {
        //printf("c = %c\n", c);
        s[index] = c;
        index++;
        scanf("%c", &c);
    }
    s[index] = '\0';
}

/* 你的代码将被嵌在这里 */
/**
 * 函数f对p指向的字符串进行逆序操作。
 * 要求函数f中不能定义任何数组，不能调用任何字符串处理函数。
 * TODO 这里好像使用了数组
 * @param p
 */
void f(char *p) {
    char *string = p;
    char *string0 = p;
    int length = 0;
    while (string && *string != '\0') {
        string++;
        length++;
    }
//    printf("\nlength= %d\n", length);
    // printf("%s\n", p);
    for (int i = 0; i < (length + 1) / 2; ++i) {
        char c = string0[i];
        char c2 = string0[length - i - 1];
//        printf("c = %c\n", c);
//        printf("c2= %c\n", c2);
        string0[i] = c2;
        string0[length - i - 1] = c;
    }
}