//
// Created by Administrator on 2020/6/23.
//
/**
 * 习题2.7 弹球距离 (15分)
 * 设有一个球从高度h米的地方落下，碰到地面后又弹到高度为原来P倍的位置，
 * 然后又落下，再弹起，在落下……。
 * 请编写函数求初始高度为h的求下落后到基本定下来（高度小于给定的阀值TOl）时
 * 在空中所经过的路程综合。
 * 函数接口定义：
 * double dist(double h, double p);
 * 其中h是球的初始高度，p是球弹起高度与弹起前落下高度的比值；
 * 函数dist要返回球下落后到基本停下来时在空中所经过的路程总和。
 * todo 注意：当弹起的高度小于裁判程序定义的常数TOL时，弹起的距离不计算在内。
 *
 * 输入样例：
 * 1.0 0.4
 * 输出样例：
 * 2.319680
 */
#define TOL 1E-2

#include <stdio.h>

double dist(double h, double p);

int main() {
    double h;
    double p;
    double d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);

    return 0;
}

double dist(double h, double p) {
    double d = h;
    double current = h * p;
    while (current > TOL) {
        d += current * 2;
        current = current * p;
    }
    return d;
}
