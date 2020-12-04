/*
练习7-3 将数组中的数逆序存放 （20 分）
本题要求编写程序，将给定的n个整数存入数组中，将数组中的这n个数逆序存放，再按顺序输出数组中的元素。

输入格式:
输入在第一行中给出一个正整数n（1≤n≤10）。第二行输入n个整数，用空格分开。

输出格式:
在一行中输出这n个整数的处理结果，相邻数字中间用一个空格分开，行末不得有多余空格。

输入样例:
4
10 8 1 2
输出样例:
2 1 8 10
*/
#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N > 0) {
        int count[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &count[i]);
        }
        int temp;
        for (int i = 0; i < N / 2; i++) {
            temp = count[i];
            count[i] = count[N - 1 - i];
            count[N - 1 - i] = temp;
        }
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                printf("%d", count[i]);
            } else {
                printf(" %d", count[i]);
            }
        }
    }

    return 0;
}

