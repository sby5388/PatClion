//
// Created by Administrator on 2020/12/8.
//习题1.9 有序数组的插入 (20分)
//本题要求将任一给定元素插入从大到小排好序的数组中合适的位置，以保持结果依然有序。
//https://pintia.cn/problem-sets/434/problems/965573204499779584

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {
    false, true
} bool;
typedef int ElementType;

typedef int Position;
typedef struct LNode2 *List;
struct LNode2 {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList(List L); /* 裁判实现，细节不表 */
bool Insert(List L, ElementType X);

int main() {
    List L;
    ElementType X;

    L = ReadInput();
    PrintList(L);

    scanf("%d", &X);
    if (Insert(L, X) == false) {
        printf("Insertion failed.\n");
    }
    PrintList(L);

    return 0;
}


/* 你的代码将被嵌在这里 */

List ReadInput() {
    List L = (List) malloc(sizeof(struct LNode2));
    L->Last = 0;
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &L->Data[i]);
    }
//    while (L->Last < N - 1) {
//
////        L->Last++;
//    }
    L->Last = N - 1;
    return L;

}

bool Insert(List L, ElementType X) {
    int insertIndex = -1;
    if (L && L->Last < MAXSIZE - 1) {
        if (X > L->Data[0]) {
            insertIndex = 0;
        } else if (X < L->Data[L->Last - 1]) {
            insertIndex = L->Last;
        } else {
            for (int i = 0; i < L->Last - 1; ++i) {
                if (X == L->Data[i]) {
                    insertIndex = -1;
                    break;
                }
                if (X < L->Data[i] && X > L->Data[i + 1]) {
                    insertIndex = i + 1;
                    break;
                }
            }
        }
    }
    printf("insertIndex = %d\n", insertIndex);

    if (insertIndex == -1) {
//        printf("Insertion failed.\n");
        return false;
    }

    for (int j = L->Last; j >= insertIndex; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[insertIndex] = X;
    L->Last++;
    return true;
}

void PrintList(List L) {
    if (L) {
        for (int i = 0; i < L->Last; ++i) {
            printf("%d ", L->Data[i]);
        }
        printf("\n");
        printf("Last = %d\n", L->Last);
    }

}