//
// Created by Administrator on 2021/1/3.
//
//7-6 福到了 (15分)
//https://pintia.cn/problem-sets/1146682947520913408/problems/1192046624089870336

#include<stdio.h>


int main() {
    char c;
    int N;

    scanf("%c", &c);
    scanf("%d", &N);
    //TODO 这一行很关键啊
    getchar();
    char input[N][N + 1];

    for (int i = 0; i < N; ++i) {
        gets(input[i]);
    }

    //相同
    int match = 1;

    int middle = (N + 1) / 2;
    for (int j = 0; j < middle; ++j) {
        for (int i = 0; i < N; ++i) {
            if (input[j][i] != input[N - j - 1][N - i - 1]) {
                match = 0;
                break;
            }
        }
    }

    if (match) {
        printf("bu yong dao le\n");
    }

    for (int k = N - 1; k >= 0; k--) {
        for (int i = N - 1; i >= 0; i--) {
            if (input[k][i] == ' ') {
                printf(" ");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");

    }


    return 0;
}