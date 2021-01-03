//
// Created by Administrator on 2021/1/1.
//

#include <stdio.h>

int main() {

    int number;
    scanf("%d", &number);
    int point;
    if (number <= 5750) {
        point = 10;
    } else if (number <= 13750) {
        point = 9;
    } else if (number <= 21750) {
        point = 8;
    } else if (number <= 29750 ) {
        point = 7;
    } else if (number <= 37750) {
        point = 6;
    } else if (number <= 45750) {
        point = 5;
    } else if (number <= 53750) {
        point = 4;
    } else if (number <= 61750) {
        point = 3;
    } else if (number <= 69750) {
        point = 2;
    } else if (number <= 77750) {
        point = 1;
    } else {
        point = 0;
    }
    printf("%d", point);

    return 0;
}