//
// Created by Administrator on 2020/12/22.
//
//1002 写出这个数 (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384


#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 200

char *number[10] = {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu",
};

int main() {
    char a[MAX_LENGTH];
    scanf("%s", &a);
    int length = strlen(a);
    int sum = 0;
    int result[200];
    for (int i = 0; i < length; ++i) {
        char c = a[i];
        if (c > '0' && c <= '9') {
            sum += (c - '0');
        }
    }
    int sum2 = sum;
    int i = -1;
    while (sum2 > 0) {
        i++;
        result[i] = sum2 % 10;
        sum2 = sum2 / 10;
    }
    printf("%s", number[result[i]]);
    for (int j = i - 1; j >= 0; j--) {
        printf(" %s", number[result[j]]);
    }
    return 0;
}
