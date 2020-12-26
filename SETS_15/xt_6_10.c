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
typedef struct LNode2 *List;
struct LNode2 {
    ElementType Data[MAXSIZE];
    //最后一个元素的位置
    Position Last;
};


/**
 * 细节不表,
 */
List ReadInput();

Position BinarySearch(List L, ElementType X);

void PrintList(List L);

int main() {
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    //PrintList(L);

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
    List L = (List) malloc(sizeof(struct LNode2));
    L->Last = 0;
    scanf("%d", &N);
    while (L->Last < N) {
        L->Last++;
        scanf("%d", &(L->Data[L->Last]));
    }
    return L;
}

Position BinarySearch(List L, ElementType X) {
    if (!L || !L->Last) {
        return NotFound;
    }
    if (L->Data[L->Last] < X || L->Data[1] > X) {
        return NotFound;
    }

    //原来的左右值初始化 错误
    int left = 1;
    int right = L->Last;
    int middle = (right + left) / 2 + 1;
    int result = NotFound;

    while (middle > left) {
        if (L->Data[right] == X) {
            result = right;
            break;
        }
        if (L->Data[left] == X) {
            result = left;
            break;
        }
        if (L->Data[middle] == X) {
            result = middle;
            break;
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

    return result;
}

void PrintList(List L) {
    List pNode = L;
    if (!pNode || !pNode->Last) {
        printf("L is null or empty!\n");
        return;
    }
    int i = 1;
    for (; i <= pNode->Last; ++i) {
        printf("%d ,", pNode->Data[i]);
    }
    printf("\n");

}
/* 你的代码将被嵌在这里 */
Position BinarySearch0(List L, ElementType X) {
//	todo
    if (!L) {
        return NotFound;
    }

    //TODO 题目要求从1开始的
    Position left = 1;
    Position right = L->Last;

    Position mid = (left + right) / 2;

    if (X == L->Data[left]) {
        return left;
    }
    if (X == L->Data[right]) {
        return right;
    }


    while (mid != right) {

        if (X == L->Data[mid]) {
            return mid;
        } else {
            if (X > L->Data[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
//          todo 忘记了更改mid的值
            mid = (left + right) / 2;

        }
    }
    return NotFound;
}