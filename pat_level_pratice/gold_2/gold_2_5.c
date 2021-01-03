//
// Created by Administrator on 2021/1/3.
//
//7-5 幸运彩票 (15分)
//https://pintia.cn/problem-sets/1146682947520913408/problems/1192046538702229504


#include<stdio.h>

#define MAXSIZE 7


int main() {
    int N;
    char numbers[MAXSIZE];
    int sumPre = 0;
    int sumPost = 0;
    scanf("%d", &N);

    while (N) {
        scanf("%s", numbers);
        sumPost = 0;
        sumPre = 0;
        for (int i = 0; i < 3; ++i) {
            sumPre += (numbers[i] - '0');
            sumPost += (numbers[i + 3] - '0');
        }

        if (sumPost == sumPre) {
            printf("You are lucky!\n");
        } else {
            printf("Wish you good luck.\n");
        }
        N--;
    }

    return 0;
}
