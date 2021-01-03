//
// Created by Administrator on 2021/1/2.
//
//7-4 到底有多二 (15分)
//https://pintia.cn/problem-sets/1146682720562929664/problems/1146696911889850368


#include<string.h>
#include<stdio.h>

#define MAXSIZE 51

int main() {

    char number[MAXSIZE];
    scanf("%s", number);

    int length = strlen(number);

    int count2 = 0;
    int negative = 0;
    //偶数
    int even = 0;

    for (int i = 0; i < length; ++i) {
        char c = number[i];
        switch (c) {
            case '2':
                count2++;
                break;
            case '-':
                negative = 1;
                break;
            default:
                continue;
        }
    }

    switch (number[length - 1]) {
        case '0':
        case '2':
        case '4':
        case '6':
        case '8':
            even = 1;
        default:
            break;
    }
    if (negative) {
        length--;
    }

    double result = count2 * 1.0 / length * 100;
    if (negative) {
        result *= 1.5;
    }
    if (even) {
        result *= 2;
    }

    printf("%.2f%%", result);

    return 0;
}