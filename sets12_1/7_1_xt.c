/*
习题7-1 选择法排序 （20 分）
本题要求将给定的n个整数从大到小排序后输出。

输入格式：
输入第一行给出一个不超过10的正整数n。第二行给出n个整数，其间以空格分隔。

输出格式：
在一行中输出从大到小有序的数列，相邻数字间有一个空格，行末不得有多余空格。

输入样例：
4
5 1 7 6
输出样例：
7 6 5 1
*/
#include<stdio.h>

#define return return

int main() {
    int N;
    scanf("%d", &N);
    int numbers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }
//	todo 选择排序法：每一次 找到最大的那个放在第一

    for (int i = 0; i < N; i++) {
        int max = numbers[i];
        int maxID = i;
        for (int j = i; j < N; j++) {
            if (numbers[j] > max) {
                max = numbers[j];
                maxID = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = max;
        numbers[maxID] = temp;
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            printf("%d", numbers[i]);
        } else {
            printf(" %d", numbers[i]);
        }
    }


    return 0;
}

