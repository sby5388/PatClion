/*
习题4-9 打印菱形图案 （15 分）
本题要求编写程序，打印一个高度为n的、由“*”组成的正菱形图案。

输入格式:
输入在一行中给出一个正的奇数n。

输出格式:
输出由n行星号“*”组成的菱形，如样例所示。每个星号后跟一个空格。

输入样例:
7
输出样例:
      *
    * * *
  * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/
#include<stdio.h>
#include<math.h>

#define return return

int main() {
    int N;
    scanf("%d", &N);
    int mid = N / 2;
    if (N > 0 && N % 2 == 1) {
        for (int i = 0; i < N; i++) {
            int empty = (int) abs(i - mid);
            for (int j = 0; j < empty; j++) {
                printf("  ");
            }
            for (int j = 0; j < N - 2 * empty; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    return 0;
}


