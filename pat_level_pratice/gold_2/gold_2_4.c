//
// Created by Administrator on 2021/1/3.
//
//7-4 大笨钟 (10分)
//https://pintia.cn/problem-sets/1146682947520913408/problems/1192046373970948096


#include<stdio.h>

int main() {
    int hh;
    int mm;
    scanf("%d:%d", &hh, &mm);
    if (hh < 11 || (hh == 12 && mm == 00)) {
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
    } else {
        int count = hh - 12;
        if (mm > 0) {
            count++;
        }
        for (int i = 0; i < count; ++i) {
            printf("Dang");
        }

    }


    return 0;
}