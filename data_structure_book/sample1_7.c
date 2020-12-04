//
// Created by Administrator on 2020/6/14.
//

#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define MAXK 1e7

clock_t start;
clock_t stop;

double duration;

double MyFunction1(int n, double a[], double x);

double MyFunction2(int n, double a[], double x);

/**
 * 记录函数的运行时间的
 * @return
 */
int main() {
    start = clock();
    MyFunction1();
    stop = clock();
    duration = ((double) (stop - start)) / CLK_TCK;

    printf("MyFunction1 = %f", duration);
    start = clock();
    MyFunction2();
    stop = clock();
    duration = ((double) (stop - start)) / CLK_TCK;
    printf("MyFunction2 = %f", duration);


    return 0;
}

double MyFunction1(int n, double a[], double x) {
    int i;
    double p = 0.0;
    for (i = 0; i < n; ++i) {
        p += (a[i] * pow(x, i));
    }
    return p;

}

double MyFunction2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for (i = n; i > 0; i--) {
        p = a[i - 1] + x * p;
    }
    return p;

}