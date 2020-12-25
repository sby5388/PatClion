//
// Created by Administrator on 2020/12/22.
//
//1003 我要通过！ (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192


#include <stdio.h>
#include "string.h"

#define MAX_LENGTH 100
#define TEST 1

void check(char *string, int length);

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    char string[N][MAX_LENGTH];
    for (int i = 0; i < N; ++i) {
        //可能包含了空格
        char c;
        scanf("%c", &c);

        int len = 0;
        while (!(c == '\0' || c == '\n')) {
            string[i][len] = c;
            len++;
            scanf("%c", &c);
        }
        string[i][len] = '\0';
        //scanf("%s", string[i]);
        int length = strlen(string[i]);
        check(string[i], length);
    }

    return 0;
}


//应该使用一个堆栈来实现它
void check(char *string, int length) {

#ifdef TEST
    printf("%d %s\n", length, string);
#endif

    int error = 0;
    int p = 0;
    int a = 0;
    int t = 0;
    int pCount = 0;
    int aCount = 0;
    int tCount = 0;

    char *temp = string;


    for (int i = 0; i < length; ++i) {
        char c = temp[i];
        switch (c) {
            case 'A':
            case ' ':
                aCount++;
                break;
            case 'P':
                pCount++;
                if (pCount == 1) {
                    p = i;
                } else {
                    error = 1;
                }
                break;
            case 'T':
                tCount++;
                if (tCount == 1) {
                    t = i;
                } else {
                    error = 1;
                }
                break;
            default:
                error = 1;
                break;
        }
        if (error) {
            break;
        }
    }
    if (t < p || t - p == 1 || t < 2) {
        error = 1;
    }
    if (error) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}





