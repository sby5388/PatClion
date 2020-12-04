/*
 * 习题9-5 通讯录排序 (20分)
 * 输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。
 *
 * 输入格式:
 * 输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，
 * 其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。
 *
 * 输出格式:
 * 按照年龄从大到小输出朋友的信息，格式同输出。
 *
 *
 * 输入样例:
 * 3
 * zhang 19850403 13912345678
 * wang 19821020 +86-0571-88018448
 * qian 19840619 13609876543
 *
 * 输出样例:
 * wang 19821020 +86-0571-88018448
 * qian 19840619 13609876543
 * zhang 19850403 13912345678
 *
 *
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 10

struct Friend {
    char name[10];
    int birthday;
    char number[18];
    int index;
    int print;
};


int main() {
    int n;
    struct Friend friend[MAX];
    int max = 0;
    int position = -1;


    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", friend[i].name, &friend[i].birthday, friend[i].number);
        friend[i].index = i;
        friend[i].print = 0;
    }

    for (int j = 0; j < n; j++) {
        position = -1;
        max = 99999999;
        for (int i = 0; i < n; i++) {
            if (friend[i].print == 0) {
                if (friend[i].birthday <= max) {
                    max = friend[i].birthday;
                    position = i;
                    //printf("position = %d\n", position);
                }
            }
        }
        if (position != -1) {
            printf("%s %d %s\n", friend[position].name, friend[position].birthday,
                   friend[position].number);
            friend[position].print = 1;
        }
    }

    return 0;
}