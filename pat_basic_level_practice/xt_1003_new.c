//
// Created by Administrator on 2020/12/22.
//
//1003 我要通过！ (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_SIZE 5

typedef char ElementType;
typedef int Position;

struct LNode2 {
    ElementType Data[MAX_SIZE];
    Position Front;


};

void check(char *string, int length);

int main() {
    int N;
    scanf("%d", &N);
    char string[N][MAX_LENGTH];
    for (int i = 0; i < N; ++i) {
        scanf("%s", string[i]);
        int length = strlen(string[i]);
        check(string[i], length);
    }

    return 0;
}

//应该使用一个堆栈来实现它
void check(char *string, int length) {
    if (0) {
        printf("%d %s\n", length, string);
        return;
    }
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





