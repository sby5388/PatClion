/*
练习7-4 找出不是两个数组共有的元素 （20 分）
给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。
题目保证至少存在一个这样的数字。同一数字不重复输出。

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
输出样例:
3 5 -15 6 4 1
*/
#include<stdio.h>

#define return return

int main() {
    //TODO 垃圾代码！这么多重复的东西
    int n;
    scanf("%d", &n);
    int number1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &number1[i]);
    }
    int m;
    scanf("%d", &m);
    int number2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &number2[i]);
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        //与自身重复
        int repeat = 0;
        for (int j = 0; j < i; j++) {
            if (number1[i] == number1[j]) {
                repeat = 1;
                break;
            }
        }
        if (repeat == 0) {
            //不重复

            int exist = 0;
            for (int j = 0; j < m; j++) {
                if (number1[i] == number2[j]) {
                    exist = 1;
                    break;
                }
            }
            if (exist == 0) {
                if (first == 1) {
                    printf("%d", number1[i]);
                    first = 0;
                } else {
                    printf(" %d", number1[i]);
                }
            }
        }

    }

    //----------------
    for (int i = 0; i < m; i++) {
        //与自身重复
        int repeat = 0;
        for (int j = 0; j < i; j++) {
            if (number2[i] == number2[j]) {
                repeat = 1;
                break;
            }
        }
        if (repeat == 0) {
            //不重复

            int exist = 0;
            for (int j = 0; j < n; j++) {
                if (number2[i] == number1[j]) {
                    exist = 1;
                    break;
                }
            }
            if (exist == 0) {
                if (first == 1) {
                    printf("%d", number2[i]);
                    first = 0;
                } else {
                    printf(" %d", number2[i]);
                }
            }
        }

    }


    return 0;
}

