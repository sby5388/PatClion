//
// Created by Administrator on 2020/12/22.
//
//1001 害死人不偿命的(3n+1)猜想 (15分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528

#include <stdio.h>

int GetCount(int N);

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", GetCount(N));
    return 0;
}

int GetCount(int N) {
    int count = 0;
    if (N <= 1000 && N > 0) {
        while (N != 1) {
            if (N % 2) {
                N = (3 * N + 1) / 2;
            } else {
                N = N / 2;
            }
            count++;
        }
    }
    return count;
}