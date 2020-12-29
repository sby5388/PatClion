//
// Created by Administrator on 2020/12/29.
//判断质数
#include <math.h>
#include <stdio.h>
#include "prime.h"

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number > 2) {
        if (number % 2 == 0) {
            return false;
        }
    }
    int max = (int) sqrt(number);
    for (int i = 3; i <= max; i += 2) {
        if (number % i == 0) {
            //printf("\t%d %d \n", number, i);
            return false;
        }
    }
    return true;
}

int main() {
    int max = 100000;
    int count = 0;
    for (int i = 0; i < max; ++i) {
        if (isPrime(i)) {
            count++;
            printf("%d \n", i);
        }
    }
    printf("count = %d\n", count);
    return 0;
}
