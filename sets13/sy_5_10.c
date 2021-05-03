//
// Created by Administrator on 2021/5/3.
//
//实验5-10 使用函数求余弦函数的近似值 (15 分)
//https://pintia.cn/problem-sets/13/problems/468

#include "stdio.h"
#include "math.h"


double funcos(double e, double x);

int main() {
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("%.6f %.6f \n", e, x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    return 0;
}


double funcos(double e, double x) {
    double left = 1.0;
    double right = 1.0;
    double item = left / right;
    //first item
    double result = item;
    double saveData = x * x;

    int add = 1;
    int start = 0;

    while (1) {
        left = left * saveData;
        right = right * (start + 1) * (start + 2);
        start += 2;

        item = left / right;
        add = add ? 0 : 1;

        if (add) {
            result += item;
        } else {
            result -= item;
        }


        if (fabs(item) < e) {
            break;
        }
    }


    return result;
}