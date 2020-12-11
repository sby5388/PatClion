//
// Created by Administrator on 2020/12/9.
//
//自测-1 打印沙漏 (20分)
//https://pintia.cn/problem-sets/17/problems/260
#include <stdio.h>

void println(char c, int max, int line);

int main() {
    char c;
    int count;
    scanf("%d %c", &count, &c);
//    printf("%d %c\n", count, c);

    int max = 1;
    count = count - 1;
    while (count > 0) {
        int current = (max + 2) * 2;
        if (count >= current) {
            count -= current;
            max += 2;
        } else {
            break;
        }
    }
//    printf("max = %d\n", max);

    int line = max;
    while (line > 1) {
        println(c,max,line);
        line -= 2;
    }
    line = 1;
    while (line <= max) {
        println(c, max, line);
        line += 2;
    }
    printf("%d",count);
    return 0;
}

void println(char c, int max, int line) {
    int empty = (max - line) / 2;
    for (int j = 0; j < empty; ++j) {
        printf(" ");
    }
    for (int i = 0; i < line; ++i) {
        printf("%c", c);
    }
    printf("\n");
}
