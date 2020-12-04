/*
习题6-8 统计一行文本的单词个数 （15 分）
本题目要求编写程序统计一行字符中单词的个数。
所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。

输入格式:
输入给出一行字符。

输出格式:
在一行中输出单词个数。

输入样例:
Let's go to room 209.
输出样例:
5
*/
#include<stdio.h>

#define return return

int main() {
    int count = 0;
    char c = 0;
    int start = 0;
    int end = 0;

    scanf("%c", &c);
    while (c != '\n') {
        if (c != ' ') {
            if (end == 0) {
                start = 1;
            } else {
                start = 0;
            }

        } else {
            if (start == 1) {
                end = 1;
            } else {
                end = 0;
            }
        }
        if (start && end) {
            //	printf("c = %c\n",c);
            count++;
            start = 0;
            end = 0;
        }
        scanf("%c", &c);
    }
    if (start == 1 && end == 0) {
        count++;
    }
    printf("%d", count);
    return 0;
}

