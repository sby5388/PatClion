/*
习题3-5 三角形判断 （15 分）
给定平面上任意三个点的坐标(x1,y1)，(x2,y2),(x3,y3)检验它们能否构成三角形。

输入格式:
输入在一行中顺序给出六个[?100,100]范围内的数字，即三个点的坐标x
x1,y1，x2,y2,x3,y3

输出格式:
若这3个点不能构成三角形，则在一行中输出“Impossible”；若可以，则在一行中输出该三角形的周长和面积，格式为“L = 周长, A = 面积”，输出到小数点后2位。

输入样例1:
4 5 6 9 7 8
输出样例1:
L = 10.13, A = 3.00
输入样例2:
4 6 8 12 12 18
输出样例2:
Impossible
*/
#include<stdio.h>
#include<math.h>

double getLenth(double x, double y);

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    scanf("%lf", &x3);
    scanf("%lf", &y3);
    if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)) {
        printf("Impossible");
    } else if ((x1 - x2) * (y3 - y2) == (y1 - y2) * (x3 - x2)) {
        printf("Impossible");
    } else {
        //使用海伦公式
        double l1 = getLenth(x1 - x2, y1 - y2);
        double l2 = getLenth(x1 - x3, y1 - y3);
        double l3 = getLenth(x3 - x2, y3 - y2);
        double L = l1 + l2 + l3;
        double p = L / 2;
        double A = sqrt(p * (p - l1) * (p - l2) * (p - l3));
        printf("L = %.2lf, A = %.2lf", L, A);
    }

    return 0;
}

double getLenth(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

