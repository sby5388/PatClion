//
// Created by Administrator on 2021/1/1.
//
#include <stdio.h>

typedef enum {
    false, true
} bool;

bool IsCassels(int a, int b, int c);

int main() {
    int N;
    scanf("%d", &N);
    while (N > 0) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (IsCassels(a, b, c)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
        N--;
    }

    return 0;
}

bool IsCassels(int a, int b, int c) {
    return (a * a + b * b + c * c) == (3 * a * b * c);
}