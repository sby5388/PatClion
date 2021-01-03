//
// Created by Administrator on 2021/1/3.
//
//7-3 谁是赢家 (10分)
//https://pintia.cn/problem-sets/1146682947520913408/problems/1192046288608473088


#include<stdio.h>

int main() {
    int Pa;
    int Pb;
    int N = 3;
    int countA = 0;
    int countB = 0;
    int point;

    scanf("%d %d", &Pa, &Pb);
    while (N) {
        scanf("%d", &point);
        if (point == 0) {
            countA++;
        } else if (point == 1) {
            countB++;
        }
        N--;
    }


    if ((Pa > Pb && countA > 0) || (Pa < Pb && countA == 3)) {
        printf("The winner is a: %d + %d", Pa, countA);
    } else if ((Pb > Pa && countB > 0) || (Pb < Pa && countB == 3)) {
        printf("The winner is b: %d + %d", Pb, countB);
    }

    return 0;
}