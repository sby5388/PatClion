/*
练习4-6 猜数字游戏 （15 分）
猜数字游戏是令游戏机随机产生一个100以内的正整数，
用户输入一个数对其进行猜测，需要你编写程序自动对其与随机产生的被猜数进行比较，
并提示大了（“Too big”），还是小了（“Too small”），相等表示猜到了。
如果猜到，则结束程序。
程序还要求统计猜的次数，如果1次猜出该数，提示“Bingo!”；
如果3次以内猜到该数，则提示“Lucky You!”；
如果超过3次但是在N（>3）次以内（包括第N次）猜到该数，则提示“Good Guess!”；
如果超过N次都没有猜到，则提示“Game Over”，并结束程序。
如果在到达N次之前，用户输入了一个负数，也输出“Game Over”，并结束程序。

输入格式:
输入第一行中给出两个不超过100的正整数，
分别是游戏机产生的随机数、以及猜测的最大次数N。
最后每行给出一个用户的输入，直到出现负数为止。

输出格式:
在一行中输出每次猜测相应的结果，直到输出猜对的结果或“Game Over”则结束。

输入样例:
58 4
70
50
56
58
60
-2
输出样例:
Too big
Too small
Too small
Good Guess!
*/

#include <stdio.h>

int main() {
    int count = -1, N = -1;
    int number = -1, guess = -1;
    count = 0;
    scanf("%d%d", &number, &N);
    while (count < N) {
        scanf("%d", &guess);
        count++;
        if (guess < 0) {
            break;
        }
        if (guess == number) {
            if (count == 1) {
                printf("Bingo!\n");
                break;
            } else if (count <= 3) {
                printf("Lucky You!\n");
                break;
            } else {
                printf("Good Guess!\n");
                break;
            }
        } else if (guess < number) {
            printf("Too small\n");
        } else {
            printf("Too big\n");
        }
    }
    if (guess < 0 || count == N && guess != number) {
        printf("Game Over\n");
    }

    return 0;
}
//---------------------
//作者：云上明月
//来源：CSDN
//原文：https://blog.csdn.net/qq_36913610/article/details/81117435
//版权声明：本文为博主原创文章，转载请附上博文链接！
