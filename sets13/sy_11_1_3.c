//
// Created by Administrator on 2021/5/3.
//

//实验11-1-3 查找星期 (15 分)
//https://pintia.cn/problem-sets/13/problems/590

#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex(char *s);

int main() {
    int n;
    char s[MAXS];
    scanf("%s", s);


    n = getindex(s);

    if (n == -1) {
        printf("wrong input!\n");
    } else {
        printf("%d\n", n);
    }

}

int getindex(char *s) {

    char *week[] = {
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
    };
    int i = 0;
    while (i < 7) {
        if (strcmp(week[i], s) == 0) {
            return i;
        } else {
            i++;
        }
    }
    return -1;
}

