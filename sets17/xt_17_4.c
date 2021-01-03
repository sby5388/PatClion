//
// Created by Administrator on 2021/1/3.
//
//自测-4 Have Fun with Numbers (20分)
//https://pintia.cn/problem-sets/17/problems/263


#include<string.h>
#include<stdio.h>

#define MAXSIZE 100

int main() {
    int count[10];
    int count2[10];

    for (int i = 0; i < 10; ++i) {
        count[i] = 0;
        count2[i] = 0;
    }

    char input[MAXSIZE];
    scanf("%s", input);

    //printf("input = %s\n", input);
    if (0 && input[0] > '4') {
        printf("No");
    } else {
        int length = strlen(input);

        for (int j = 0; j < length; ++j) {
            count[input[j] - '0']++;
        }

        //进位
        int add = 0;
        for (int k = length - 1; k >= 0; k--) {
            int i = (input[k] - '0') * 2 + add;
            add = 0;
            printf("i = %d\n", i);

            while (i > 9) {
                add++;
                i -= 10;
            }
//            while (i > 9) {
//                i -= 10;
////                todo 这里出错了，只进了一位，进位后会影响前面的
//                if (k > 1) {
//                    input[k - 1] = input[k - 1] + 1;
//                }
//            }
            input[k] = '0' + i;
//            printf("\t input[%d]=%d\n", input[k] - '0', k);
        }

        //printf("input = %s\n", input);


        for (int j = 0; j < length; ++j) {
            count2[input[j] - '0']++;
        }
        int match = 1;

        for (int i = 0; i < 10; ++i) {
            if (count[i] != count2[i]) {
                printf("%d %d:%d\n", i, count[i], count2[i]);
                match = 0;
                break;
            }
        }
        if (match) {
            printf("Yes\n");
            printf("%s", input);
        } else {

            printf("No");
        }
    }


    return 0;
}