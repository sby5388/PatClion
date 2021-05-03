//
// Created by Administrator on 2020/12/10.
//
//实验8-1-3 拆分实数的整数与小数部分 (15分)
//https://pintia.cn/problem-sets/13/problems/547


#include <stdio.h>

/*
 * 其中x是被拆分的实数（0≤x<10000），*intpart和*fracpart分别是将实数x拆分出来的整数部分与小数部分。
 */
void splitfloat(float x, int *intpart, float *fracpart);

int main() {
    float x, fracpart;
    int intpart;

    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);

    return 0;
}

/* 你的代码将被嵌在这里 */

void splitfloat(float x, int *intpart, float *fracpart) {
    (*intpart) = 0;
    (*fracpart) = 0.0f;

    if (x > 0) {
        while (x >= 1) {
            x--;
            (*intpart)++;
        }
        (*fracpart) = x;
    }

    if (x < 0) {
        while (x <= -1) {
            x++;
            (*intpart)--;
        }
        (*fracpart) = x;
    }

}