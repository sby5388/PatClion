//
// Created by Administrator on 2020/12/29.
//
//基础实验2-2.1 整数的分类处理 (20分)
//https://pintia.cn/problem-sets/988034414048743424/problems/988036281675845632

#include <stdio.h>
#include <stdlib.h>

struct LNode {
    int value;
    int count;
};
typedef struct LNode *Data;

Data CreateData();

int main() {
    int N;
    int number;
    Data A1 = CreateData();
    Data A2 = CreateData();
    Data A3 = CreateData();
    scanf("%d", &N);
    while (N > 0) {
        scanf("%d", &number);
        int i = number % 3;
        if (i == 0) {
            if (A1->count == 0) {
                A1->value = number;
                A1->count = 1;
            } else {
                if (number > A1->value) {
                    A1->value = number;
                }
            }
        } else if (i == 1) {
            A2->count++;
        } else {
            A3->count++;
            A3->value += number;
        }
        N--;
    }

    if (A1->count == 0) {
        printf("NONE");
    } else {
        printf("%d", A1->value);
    }

    printf(" ");

    if (A2->count == 0) {
        printf("NONE");
    } else {
        printf("%d", A2->count);
    }
    printf(" ");

    if (A3->count == 0) {
        printf("NONE");
    } else {
        printf("%.1f", (A3->value * 1.0f) / A3->count);
    }

    free(A1);
    free(A2);
    free(A3);

    return 0;
}

Data CreateData() {
    Data data = (Data) malloc(sizeof(struct LNode));
    data->count = 0;
    data->value = 0;
    return data;
}