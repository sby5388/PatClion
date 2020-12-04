/*
习题3-4 统计学生成绩 （15 分）
本题要求编写程序读入N个学生的百分制成绩，统计五分制成绩的分布。百分制成绩到五分制成绩的转换规则：

大于等于90分为A；
小于90且大于等于80为B；
小于80且大于等于70为C；
小于70且大于等于60为D；
小于60为E。
输入格式:
输入在第一行中给出一个正整数N（≤1000），即学生人数；第二行中给出N个学生的百分制成绩，其间以空格分隔。

输出格式:
在一行中输出A、B、C、D、E对应的五分制成绩的人数分布，数字间以空格分隔，行末不得有多余空格。

输入样例:
7
77 54 92 73 60 65 69
输出样例:
1 0 2 3 1
*/
#include<stdio.h>

#define max 5

int main() {
    int count[max] = {0};
    int M;
    scanf("%d", &M);
    int N = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &N);
        if (N >= 90 && N < 101) {
            count[0]++;
        } else if (N >= 80) {
            count[1]++;
        } else if (N >= 70) {
            count[2]++;
        } else if (N >= 60) {
            count[3]++;
        } else {
            count[4]++;
        }
    }
    printf("%d", count[0]);
    for (int i = 1; i < max; i++) {
        printf(" %d", count[i]);
    }

    return 0;
}

