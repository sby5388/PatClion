/*
练习8-8 移动字母 （10 分）
本题要求编写函数，将输入字符串的前3个字符移到最后。

函数接口定义：
void Shift( char s[] );
其中char s[]是用户传入的字符串，题目保证其长度不小于3；函数Shift须将按照要求变换后的字符串仍然存在s[]里。

裁判测试程序样例：

输入样例：
abcdef
输出样例：
defabc
*/
#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift(char s[]);

void GetString(char s[]); /* 实现细节在此不表 */

int main() {
    char s[MAXS];

    GetString(s);
//	char s[] = "abcdef";
    Shift(s);
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */
void Shift(char s[]) {
    int length = strlen(s);
    int n = 3;
    char temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = s[i];
    }
    for (int i = n; i < length; i++) {
        s[i - n] = s[i];
    }
    for (int i = 0; i < n; i++) {
        s[length - n + i] = temp[i];
    }


}
