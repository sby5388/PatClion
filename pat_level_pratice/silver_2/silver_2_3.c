//
// Created by Administrator on 2021/1/2.
//
//7-3 新胖子公式 (10分)
//https://pintia.cn/problem-sets/1146682475225505792/problems/1192035687580610560


#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main() {
    double weight;
    double high;
    scanf("%lf %lf", &weight, &high);
    double d = weight / (high * high);
    printf("%.1f\n", d);
    if (d > 25) {
        printf("PANG");
    } else {
        printf("Hai Xing");
    }
    return 0;
}