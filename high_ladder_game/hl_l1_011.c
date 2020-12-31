//
// Created by Administrator on 2020/12/30.
//
//L1-011 A-B (20分)
//https://pintia.cn/problem-sets/994805046380707840/problems/994805130426171392
#include<stdio.h>
#include<string.h>

#define MAX 10001

//投机取巧，只是替换，并没有删除
int main() {
    char A[MAX];
    char B[MAX];
    int lengthA = 0;
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        A[lengthA] = c;
        lengthA++;
        scanf("%c", &c);
    }
    int lengthB = 0;
    scanf("%c", &c);
    while (c != '\n') {
        B[lengthB] = c;
        lengthB++;
        scanf("%c", &c);
    }
    for (int i = 0; i < lengthB; i++) {
        char b = B[i];
        for (int j = 0; j < lengthA; j++) {
            if (b == A[j]) {
                A[j] = '\n';
            }
        }
    }
    for (int j = 0; j < lengthA; j++) {
        if ('\n' != A[j]) {
            printf("%c", A[j]);
        }
    }

    return 0;
}
int main0() {
    char A[MAX];
    char B[MAX];
    int lengthA = 0;
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        A[lengthA] = c;
        lengthA++;
        scanf("%c", &c);
    }
    int lengthB = 0;
    scanf("%c", &c);
    while (c != '\n') {
        B[lengthB] = c;
        lengthB++;
        scanf("%c", &c);
    }
    for (int i = 0; i < lengthB; i++) {
        char b = B[i];
        for (int j = 0; j < lengthA; j++) {
            if (b == A[j]) {
                A[j] = '\n';
            }
        }
    }
    for (int j = 0; j < lengthA; j++) {
        if ('\n' != A[j]) {
            printf("%c", A[j]);
        }
    }

    return 0;
}