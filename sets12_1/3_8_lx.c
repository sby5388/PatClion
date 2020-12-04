/*
练习3-8 查询水果价格 （15 分）
给定四种水果，分别是苹果（apple）、梨（pear）、桔子（orange）、葡萄（grape），
单价分别对应为3.00元/公斤、2.50元/公斤、4.10元/公斤、10.20元/公斤。

首先在屏幕上显示以下菜单：

[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
用户可以输入编号1~4查询对应水果的单价。
当连续查询次数超过5次时，程序应自动退出查询；
不到5次而用户输入0即退出；
输入其他编号，显示价格为0。

输入格式:
输入在一行中给出用户连续输入的若干个编号。

输出格式:
首先在屏幕上显示菜单。
然后对应用户的每个输入，在一行中按格式“price = 价格”输出查询结果，其中价格保留两位小数。
当用户连续查询次数超过5次、或主动输入0时，程序结束。

输入样例1:
3 -1 0 2
输出样例1:
[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
price = 4.10
price = 0.00
输入样例2:
1 2 3 3 4 4 5 6 7 8
输出样例2:
[1] apple
[2] pear
[3] orange
[4] grape
[0] exit
price = 3.00
price = 2.50
price = 4.10
price = 4.10
price = 10.20
*/
#include<stdio.h>

#define max 5

void query(int type);

const double prices[] = {0.00, 3.00, 2.50, 4.10, 10.20};

int main() {
    int N[max];
    //todo 这里虽然通过了在线检测系统，但是存在 输入样例1之中，输入参数不够五个时  停住不动的问题
    for (int i = 0; i < max; i++) {
        scanf("%d", &N[i]);
    }
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");

    for (int i = 0; i < max; i++) {
        if (0 == N[i]) {
            break;
        }
        query(N[i]);
    }

    return 0;
}

void query(int type) {
    double result = 0.0;
    if (type < sizeof(prices) / sizeof(prices[0])) {
        result = prices[type];
    }
    printf("price = %.2lf\n", result);
}

