/*
习题7-3 判断上三角矩阵 （15 分）
上三角矩阵指主对角线以下的元素都为0的矩阵；主对角线为从矩阵的左上角至右下角的连线。

本题要求编写程序，判断一个给定的方阵是否上三角矩阵。

输入格式：
输入第一行给出一个正整数T，为待测矩阵的个数。
接下来给出T个矩阵的信息：每个矩阵信息的第一行给出一个不超过10的正整数n。
随后n行，每行给出n个整数，其间以空格分隔。

输出格式：
每个矩阵的判断结果占一行。如果输入的矩阵是上三角矩阵，输出“YES”，否则输出“NO”。

输入样例：
2
3
1 2 3
0 4 5
0 0 6
2
1 0
-8 2
输出样例：
YES
NO
*/
#include<stdio.h>

#define return return

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        int numbers[M][M];
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                scanf("%d", &numbers[j][k]);
            }
        }
        int yes = 1;
        for (int j = 1; j < M; j++) {
            for (int k = 0; k < j; k++) {
                if (numbers[j][k] != 0) {
                    yes = 0;
                    break;
                }
            }
        }
        if (yes == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}

