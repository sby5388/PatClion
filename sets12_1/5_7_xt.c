/**
 * 习题5-7 使用函数求余弦函数的近似值 (15分)
 * 本题要求实现一个函数，用下列公式求cos(x)的近似值，精确到最后一项的绝对值小于e：
 * cos(x) = x^0/0! - x^2/2! + x^4/4! - x^6/6! + ……
 * 函数接口定义：
 * double funcos(double e,double x);
 * 其中用户传入的参数为误差上限e和自变量x；函数funcos应返回用给定公式计算出来、
 * 并且满足误差要求的cos(x)的近似值。输入输出均在双精度范围内。
 * 输入样例：
 * 0.01 -3.14
 * 输出样例：
 * cos(-3.14) = -0.999899
 *
 */

#include "stdio.h"
#include "math.h"

double funcos(double e, double x);

int main() {
    double e, x;

    scanf("%1f %1f", &e, &x);
    printf("%.6f %.6f \n", e, x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    return 0;
}

double funcos(double e, double x) {

    if (1) {
        double cos = 0;
        int count = 0;
        int temp = 1;
        int add = 1;
        double value = 1.0;
        while (fabs(value) >= e) {
            if (add) {
                cos += value;
                printf("-- %.6f\n", cos);
            } else {
                cos -= value;
                printf("++ %.6f\n", cos);
            }

            add = add ? 0 : 1;
            temp = temp * (count + 1) * (count + 2);
            value = value * pow(x, 2) / temp;
            printf("value = %.6f\n", value);
            count += 2;
        }
        return cos;

    }


    double result = 0.0;
    int true = 1;
    int n = 0;
    double q = 1.0;
    double temp = pow(x, n);
    double abs2 = temp / q;

    while (fabs(abs2) > e) {
        if (true) {
            result += abs2;
            true = 0;
        } else {
            result -= abs2;
            true = 1;
        }
        n += 2;
        temp = pow(x, n);
        q = q * (n + 1) * (n + 2);
        abs2 = temp / q;
        printf("result = %.6f\n", result);
    }

    return result;
}