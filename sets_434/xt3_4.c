//
// Created by Administrator on 2020/12/18.
//
//习题3.4 最长连续递增子序列 (20分)
//https://pintia.cn/problem-sets/434/problems/5860

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct LNode2 *List;
struct LNode2 {
    ElementType *Data;
    int MaxSize;
};

List CreateList(int MaxSize);

int main() {
    int N;
    List L;

    scanf("%d", &N);
    L = CreateList(N);

//    for (int k = 0; k < L->MaxSize; ++k) {
//        printf("%d ",L->Data[k]);
//    }
//    printf("\n");
    int start = 0;
    int countMax = 1;
    int max = L->Data[0];

    int tempStart = 0;
    int countTemp = 1;
    int tempMax = max;

    for (int i = 1; i < L->MaxSize; ++i) {
//        printf("%d : %d \n", L->Data[i], tempMax);
        if (L->Data[i] > tempMax) {
            tempMax = L->Data[i];
            countTemp++;
        } else {
            tempStart = i;
            tempMax = L->Data[i];
            countTemp = 1;
        }
//        printf("countTemp = %d\n", countTemp);

        if (countTemp > countMax) {
            countMax = countTemp;
            start = tempStart;
            max = tempMax;
        }

    }
    printf("%d", L->Data[start]);
    for (int j = start + 1; j < start + countMax; ++j) {
        printf(" %d", L->Data[j]);
    }
    return 0;
}

List CreateList(int MaxSize) {
    List L = (List) malloc(sizeof(struct LNode2));
    L->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    L->MaxSize = MaxSize;

    for (int i = 0; i < MaxSize; ++i) {
        scanf("%d", &L->Data[i]);
    }
    return L;
}
