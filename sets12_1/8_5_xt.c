/*
习题8-5 使用函数实现字符串部分复制 （20 分）
本题要求编写函数，将输入字符串t中从第m个字符开始的全部字符复制到字符串s中。

函数接口定义：
void strmcpy( char *t, int m, char *s );
函数strmcpy将输入字符串char *t中从第m个字符开始的全部字符复制到字符串char *s中。
若m超过输入字符串的长度，则结果字符串应为空串。

裁判测试程序样例：

输入样例：
7
happy new year
输出样例：
new year
*/
#include <stdio.h>

#define MAXN 20

void strmcpy(char *t, int m, char *s);

void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main() {
    {
        //原始的数据

        char t[MAXN], s[MAXN];
        int m;

        scanf("%d\n", &m);
        ReadString(t);
        strmcpy(t, m, s);
        printf("%s\n", s);

        return 0;
    }
    {
        //调试使用
        char t[MAXN] = "a";
//	char t[MAXN] =  "abc";
        char s[MAXN];
        int m;

        //printf("sizeof(t) = %d\n",sizeof(t));

        //scanf("%d\n", &m);
        m = 1;
        //ReadString(t);
//	*t  = "happy new year";
        strmcpy(t, m, s);
        printf("%s\n", s);

        return 0;
    }
}

/* 你的代码将被嵌在这里 */
void strmcpy(char *t, int m, char *s) {
    int length = 0;
    while (t[length] != '\0') {
        length++;
    }
    if (m < MAXN && m <= length) {
        for (int i = 0; i < length - m + 1; i++) {
            s[i] = t[m + i - 1];
        }
        s[length - m + 1] = '\0';
    } else {
        s[0] = '\0';
    }
}
