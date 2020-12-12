//
// Created by Administrator on 2020/12/12.
//
//实验8-1-7 数组循环右移 (20分)
//https://pintia.cn/problem-sets/13/problems/551

#include <stdio.h>

#define MAXN 10

int ArrayShift(int a[], int n, int m);

int main() {
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ArrayShift(a, n, m);

    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int ArrayShift(int a[], int n, int m) {
    while (m > n) {
        m -= n;
    }

    int i = 0;



    int next = i + m;
    if (next >= n) {
        next = next - n;
    }
    int temp = a[next];
    int value = a[next];
    while (1) {
        a[next] = a[i];



        if (i < 0) {
            i += n;
        }
        if (i >= n) {
            i -= n;
        }


        if (i == 0) {
            break;
        }
    }

}