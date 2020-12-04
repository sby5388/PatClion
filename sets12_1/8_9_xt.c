/*
习题8-9 分类统计各类字符个数 （15 分）
本题要求实现一个函数，统计给定字符串中的大写字母、小写字母、空格、数字以及其它字符各有多少。

函数接口定义：
void StringCount( char *s );
其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照

大写字母个数 小写字母个数 空格个数 数字个数 其它字符个数
的格式输出。

裁判测试程序样例：

输入样例：
aZ&*?
093 Az
输出样例：
2 2 1 3 4
*/
#include <stdio.h>

#define MAXS 15

void StringCount(char *s);

void ReadString(char *s); /* 由裁判实现，略去不表 */

int main() {
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */
/* 由裁判实现，略去不表 */
void ReadString(char *s) {

}

void StringCount(char *s) {
    int lettera = 0;
    int letterA = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    for (int i = 0; i < MAXS; i++) {
        //读取一个字符串，而输出一个字符串是 putchar(c);
        char c = s[i];
        if (c == NULL) {
            break;
        }
        if (c >= 'a' && c <= 'z') {
            lettera++;
        } else if (c >= 'A' && c <= 'Z') {
            letterA++;
        } else if (c == ' ') {
            blank++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else {
            other++;
        }
    }
    printf("%d %d %d %d %d", letterA, lettera, blank, digit, other);
}
