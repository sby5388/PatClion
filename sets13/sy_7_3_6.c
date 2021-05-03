//
// Created by Administrator on 2021/5/3.
//

//实验7-3-6 字符串转换成十进制整数 (15 分)
//https://pintia.cn/problem-sets/13/problems/527

#include <stdio.h>

#define END '#'

int main() {

    char input[80];
    int index = 0;
    int digits = 0;
    int negative = 0;

    char c = getchar();
    while (c != END) {
        if (c == '-' && digits == 0) {
            negative = 1;
        } else if ((c >= '0' && c <= '9')
                   || (c >= 'a' && c <= 'f')
                   || (c >= 'A' && c <= 'F')) {
            digits = 1;
            input[index] = c;
            index++;
        }
        c = getchar();
    }
    input[index] = '\0';

    if (0) {
        if (negative) {
            printf("-");
        }
        printf("input = %s\n", input);
    }

    long result = 0;
    for (int i = 0; i < index; ++i) {
        char cTemp = input[i];
        int temp;
        if (cTemp >= 'A' && cTemp <= 'F') {
            temp = cTemp - 'A' + 10;
        } else if (cTemp >= 'a' && cTemp <= 'f') {
            temp = cTemp - 'a' + 10;
        } else {
            temp = cTemp - '0';
        }
        //printf("cTemp = %c,temp = %d\n", cTemp, temp);
        result = result * 16 + temp;

    }

    if (negative && result != 0) {
        printf("-");
    }
    printf("%ld", result);

    return 0;
}

