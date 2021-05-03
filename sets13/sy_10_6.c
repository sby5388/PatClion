//
// Created by Administrator on 2021/5/3.
//

//实验10-6 递归计算Ackermenn函数 (15 分)
//https://pintia.cn/problem-sets/13/problems/578

#include <stdio.h>

int Ack(int m, int n);

int main() {

    int m;
    int n;

    scanf("%d %d", &m, &n);
    printf("%d\n", Ack(m, n));

    return 0;
}

int Ack(int m, int n) {
    if (m < 0 || n < 0) {
        //todo rule add by me
        return 0;
    }
    if (m == 0) {
        return n + 1;
    }

    //n==0 && m>0
    if (n == 0) {
        return Ack(m - 1, 1);
    }
    //other:m>0 && n>0
    return Ack(m - 1, Ack(m, n - 1));
}