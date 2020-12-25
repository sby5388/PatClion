//
// Created by Administrator on 2020/12/24.
//
//1009 说反话 (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960

#include <stdio.h>
#include <string.h>

#define MAX 81
#define TEST 0

int main() {
    char word[MAX];
    //获取一整行
    gets(word);
    int length = strlen(word);

#if TEST
    printf("%d\n", length);
#endif

    int last = length;
    int i;
    for (i = length - 1; i > 0;) {
        if (word[i] == ' ') {
#if TEST
            printf("i= %d,last = %d\n", i, last);
#endif
            for (int j = i + 1; j < last; ++j) {
                printf("%c", word[j]);
            }
            printf(" ");
            last = i;
            i--;
        } else {

#if TEST
            printf("%c\n", word[i]);
#endif
            i--;
        }
    }

#if TEST
    printf("i= %d,last = %d\n", i, last);
#endif

    if (last > i) {
        for (int j = i; j < last; ++j) {
            printf("%c", word[j]);
        }
    }

    return 0;
}