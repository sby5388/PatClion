//
// Created by Administrator on 2020/12/4.
//
/**
 * 6-10 二分查找 (20分)
 * https://pintia.cn/problem-sets/15/problems/923
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0

typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    //最后一个元素的位置
    Position Last;
};


/**
 * 细节不表,
 */
List ReadInput();

Position BinarySearch(List L, ElementType X);

int main() {
    List L;
    ElementType X;
    Position P;


    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/**
 * 元素下标从1开始，元素有序递增
 * @return
 */
List ReadInput() {
    int N;
    List L = (List) malloc(sizeof(struct LNode));
    L->Last = 0;
    scanf("%d", &N);
    while (L->Last < N) {
        scanf("%d", &(L->Data[L->Last++]));
    }
    return L;
}

Position BinarySearch(List L, ElementType X) {
    if (!L || L->Last == 0) {
        return NotFound;
    }
    if (L->Data[L->Last] < X || L->Data[1] > X) {
        return NotFound;
    }

    int right = 0;
    int left = L->Last;
    int middle = (right + left) / 2;
    while (middle > left) {
        if (L->Data[middle] == X) {
            return middle;
        }
        if (L->Data[right] == X) {
            return right;
        }
        if (L->Data[left] == X) {
            return left;
        }
        if (L->Data[middle] > X) {
            right = middle - 1;
            left = left + 1;
            middle = (right + left) / 2 + 1;
        } else {
            left = middle + 1;
            right = right - 1;
            middle = (right + left) / 2 + 1;
        }
    }

    return NotFound;

}