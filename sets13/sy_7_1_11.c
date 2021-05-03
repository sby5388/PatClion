//
// Created by Administrator on 2021/5/3.
//

//实验7-1-11 求整数序列中出现次数最多的数 (15 分)
//https://pintia.cn/problem-sets/13/problems/508


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int value[n];
    int count[n];
    for (int i = 0; i < n; ++i) {
        value[i] = 0;
        count[i] = 0;

    }

    int temp;

    int maxIndex = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        for (int j = 0; j < n; j++) {
            //printf("value[%d] = %d\n", j, value[j]);
            //找到匹配的
            if (value[j] == temp) {
                //printf("i = %d,value[%d] = %d\n", i, j, temp);
                count[j]++;
                if (j >= maxIndex) {
                    maxIndex = j;
                }
                break;
            }
            //插入新的
            if (value[j] == 0 && count[j] == 0) {
                value[j] = temp;
                count[j] = 1;
                if (j >= maxIndex) {
                    maxIndex = j;
                }
                break;
            }

        }

    }
    //temp
    if (0) {
        for (int k = 0; k <= maxIndex; k++) {
            printf("%d : %d\n", value[k], count[k]);
        }

    }


    int maxCountIndex = 0;
    int maxCount = count[0];


    for (int k = 0; k <= maxIndex; k++) {
        if (count[k] >= maxCount) {
            maxCount = count[k];
            maxCountIndex = k;
        }
    }

    printf("%d %d", value[maxCountIndex], maxCount);

    return 0;
}