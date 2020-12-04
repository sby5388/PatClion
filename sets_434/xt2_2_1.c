//
// Created by Administrator on 2020/6/28.
//

/**
 * 习题2.2 数组循环左移 (20分)
 * 本题要求实现一个对数组进行循环左移的简单函数：
 * 一个数组a中存有n（>0）个整数，todo 在不允许使用另外数组的前提下，
 * 将每个整数循环向左移m（≥0）个位置，
 * 即将a中的数据由(a0a1...an)
 * 变换为（am...an-1a0a1 ...am-1）
 * （最前面的m个数循环移至最后面的m个位置）。
 * 如果还需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
 *
 * 输入格式:
 * 输入第1行给出正整数n（≤100）和整数m（≥0）；第2行给出n个整数，其间以空格分隔。
 * 输出格式:
 * 在一行中输出循环左移m位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
 *
 * 输入样例：
 * 8 3
 * 1 2 3 4 5 6 7 8
 * 输出样例：
 * 4 5 6 7 8 1 2 3
 *
 */
#include <stdio.h>

void moveArray(int array[], int length, int n);

int main() {
    int m = 11;
    int n = -6;

    int array[] = {
            1, 2, 3, 4, 5, 6, 7, 8,9,10,11
    };

    moveArray(array, m, n);


    int first = 1;
    for (int j = 0; j < m; ++j) {
        if (first) {
            printf("%d", array[j]);
            first = 0;
        } else {
            printf(" %d", array[j]);
        }

    }

    return 0;
}

void moveArray(int array[], int m, int n) {
    if (n == m || n == 0) {
        return;
    }
    if (n < 0) {
        n += m;
    }
    while (n >= m) {
        n -= m;
    }
//    todo 还是只是交换地址
//    int new;
//    int old;
//    for (int i = 0; i < m; i++) {
//        old = array[i];
//        array[i] = array[i + n];
//
//    }
    for (int i = 0; i < n; i++) {
        int temp = array[0];
        for (int j = 1; j < m; j++) {
            array[j - 1] = array[j];
        }
        array[m-1] = temp;
    }


}