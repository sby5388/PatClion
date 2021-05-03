//
// Created by Administrator on 2021/5/3.
//

//实验10-9 十进制转换二进制 (15 分)
//https://pintia.cn/problem-sets/13/problems/580

#include <stdio.h>

void dectobin(int n);

int main() {
    int n;
    scanf("%d", &n);
    dectobin(n);

    return 0;
}

void dectobin(int n) {
    if (n < 0) {
        return;
    }
    if (n >= 0) {
        //todo 一开下面2句顺序反了，变成 10 -> 0101
        int i = n / 2;
        if (i != 0) {
            dectobin(i);
        }
        printf("%d", n % 2);
    }
}