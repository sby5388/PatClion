/*
习题6-1 分类统计字符个数 （15 分）
本题要求实现一个函数，统计给定字符串中英文字母、空格或回车、数字字符和其他字符的个数。

函数接口定义：
void StringCount( char s[] );
其中 char s[] 是用户传入的字符串。函数StringCount须在一行内按照

letter = 英文字母个数, blank = 空格或回车个数, digit = 数字字符个数, other = 其他字符个数
的格式输出。

裁判测试程序样例：

输入样例：
aZ &
09 Az
输出样例：
letter = 4, blank = 3, digit = 2, other = 1
*/
#include <stdio.h>

#define MAXS 15

void StringCount(char s[]);

void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main() {
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */
void StringCount(char s[]) {
    int letter = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    for (int i = 0; i < MAXS; i++) {
        //读取一个字符串，而输出一个字符串是 putchar(c);
        char c = s[i];
        if (c == NULL) {
            break;
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letter++;
        } else if (c == ' ' || c == '\n') {
            blank++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
}

