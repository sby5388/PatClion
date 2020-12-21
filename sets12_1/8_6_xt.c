/*
习题8-6 删除字符 （20 分）
本题要求实现一个删除字符串中的指定字符的简单函数。

函数接口定义：
void delchar( char *str, char c );
其中char *str是传入的字符串，c是待删除的字符。函数delchar的功能是将字符串str中出现的所有c字符删除。
输入样例：
a
happy new year
输出样例：
hppy new yer
*/
#include <stdio.h>

#define MAXN 20

void delchar(char *str, char c);

void ReadString(char s[]); /* 由裁判实现，略去不表 */

int main() {
    char str[MAXN] = "aahappy new yearaaa";
    char c = 'a';

//	scanf("%c\n", &c);
//	ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

/* 你的代码将被嵌在这里 */


/* 由裁判实现，略去不表 */
void ReadString(char s[]) {

}

void delchar(char *t, char c) {
    int length = 0;
    while (t[length] != '\0') {
        length++;
    }
    int count = length;
    for (int i = count - 1; i > -1; i--) {
        char temp = t[i];
        //printf("%c\n",temp);
        if (temp == '\0') {
            break;
        }
        if (c == temp) {
            //printf("i = %d,count = %d\n",i,count);
            for (int k = i; k < count + 1; k++) {
                t[k] = t[k + 1];
            }
        }
    }

}
