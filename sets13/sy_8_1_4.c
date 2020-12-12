//
// Created by Administrator on 2020/12/12.
//
//实验8-1-4 使用函数的选择法排序 (25分)
//https://pintia.cn/problem-sets/13/problems/540

#include <stdio.h>

#define MAXN 10

void sort(int a[], int n);

int main() {
    int i, n;
    int a[MAXN];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, n);

    printf("After sorted the array is:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
/**
 * 选择排序，每次选择最大或者最小的，放大开头
 * @param a
 * @param n
 */
void sort(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = a[i];
        int minIndex = i;
        //找到值
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        }
        //交换值
        if (min < a[i]) {
            int temp = a[i];
            a[i] = min;
            a[minIndex] = temp;
        }
    }
}