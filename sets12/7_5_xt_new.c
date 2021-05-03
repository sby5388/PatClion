/*
习题7-5 找鞍点 （20 分）
一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。

本题要求编写程序，求一个给定的n阶方阵的鞍点。

输入格式：
输入第一行给出一个正整数n（1≤n≤6）。随后n行，每行给出n个整数，其间以空格分隔。

输出格式：
输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。
如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。

输入样例1：
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9
输出样例1：
2 1
输入样例2：
2
1 7
4 1
输出样例2：
NONE
*/
#include<stdio.h>
#include <stdlib.h>

#define NONE "NONE"

int main() {
    int N;
    scanf("%d", &N);
    int count[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &count[i][j]);
        }
    }

    int isEmpty = 1;
    int max, min;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        max = count[i][0];

        for (int j = 1; j < N; j++) {
            if (count[i][j] > max) {
                max = count[i][j];
                x = i;
                y = j;
            }
        }

        min = count[0][y];
        for (int k = 0; k < N; k++) {
            if (count[k][y] <= min) {
                min = count[k][y];
            }
        }
        if (min == max) {
            printf("%d %d\n", x, y);
            isEmpty = 0;
        }

    }
    if (isEmpty) {
        printf(NONE);
    }

    return 0;
}



