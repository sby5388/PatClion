//
// Created by Administrator on 2020/12/12.
//
//实验8-1-5 在数组中查找指定元素 (15分)
//https://pintia.cn/problem-sets/13/problems/548

#include <stdio.h>

#define MAXN 10

int search(int list[], int n, int x);

int main() {
    int i, index, n, x;
    int a[MAXN];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    index = search(a, n, x);
    if (index != -1) {
        printf("index = %d\n", index);
    } else {
        printf("Not found\n");
    }

    return 0;
}

/* 你的代码将被嵌在这里 */
int search(int list[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (list[i] == x) {
            return i;
        }
    }
    return -1;
}