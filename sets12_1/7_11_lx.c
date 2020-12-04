/*
实验7-3-1 字符串逆序 （15 分）
输入一个字符串，对该字符串进行逆序，输出逆序后的字符串。

输入格式：
输入在一行中给出一个不超过80个字符长度的、以回车结束的非空字符串。

输出格式：
在一行中输出逆序后的字符串。

输入样例：
Hello World!
输出样例：
!dlroW olleH
*/
#include<stdio.h>
#include<string.h>

#define MAX 81

int main() {
    //单个字符：%c
    //字符串：%s

    char str[MAX];
    //TODO  这里要读取的是一整行，而不是使用空格来作为输入结束的标志
    //	scanf("%s",&str);
    gets(str);
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    return 0;
}



