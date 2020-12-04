/**
 * 习题1.8 二分查找 (20分)
 * 本题要求二分查找算法
 * 函数接口定义：
 * Position BinarySearch(List L, ElementType X);
 * L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，
 * 并且题目保证传入的数据是递增有序的。
 * 函数BinarySearch要查找X在Data中的位置，
 * 即数组下标（注意：元素从下标1开始存储）。
 * 找到则返回下标，否则返回一个特殊的失败标记NotFound。
 *
 *
 * typedef int Position;
 * typedef int ElementType;
 * typedef struct LNode *List;
 * struct LNode {
 *  ElementType Data[MAXSIZE];
 *  //保存线性表中最后一个元素的位置
 *  Position Last;
 *  };
 *
 * 输入样例1：
 * 5
 * 12 31 55 89 101
 * 31
 * 输出样例1：
 * 2
 * 输入样例2：
 * 3
 * 26 78 233
 * 31
 * 输出样例2：
 * 0
 *
 */
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 10
#define NotFound 0
typedef int Position;
typedef int ElementType;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    //保存线性表中最后一个元素的位置
    Position Last;
};

List ReadInput();

Position BinarySearch(List L, ElementType X);

int main() {
    List L;
//    List L1;
    ElementType X;
    Position P;
    L = ReadInput();
//    L1 = L;
//    for (int i = 1; i <= L->Last; ++i) {
//        printf("%d : %d\n", i, L1->Data[i]);
//
//    }

    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);
    return 0;
}

List ReadInput() {
    int N;
    List L;
    L = (List) malloc(sizeof(struct LNode));
    L->Last = 0;
    scanf("%d", &N);
    while (N--) {
        L->Last++;
        scanf("%d", &L->Data[L->Last]);
    }
    return L;
}

/**
 * 使用二分法查找元素的位置
 * @param L 传入的数据时有序递增的
 * @param X
 * @return
 */
Position BinarySearch0(List L, ElementType X) {
    if (!L) {
        return NotFound;
    }
    Position left = 1;
    Position right = L->Last;
    Position middle = (left + right) / 2;

    if (X == L->Data[left]) {
        return left;
    }

    if (X == L->Data[right]) {
        return right;
    }

    while (middle != right) {
        ElementType value = L->Data[middle];

        if (X == value) {
            return middle;
        } else {
            if (X > middle) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }
    }

    return NotFound;
}

Position BinarySearch(List L, ElementType X) {
    if (L == NULL) {
        return NotFound;
    }
//    if (L->Data[0] == X) {
//        return 1;
//    }
    //printf("last = %d\n", last);
//    if (L->Data[last - 1] == X) {
//        return last;
//    }

    Position right = L->Last;
    Position left = 1;
    Position middle = (right + left) / 2;
    if (X == L->Data[left]) {
        return left;
    }

    if (X == L->Data[right]) {
        return right;
    }

    while (middle != right) {
        ElementType value = L->Data[middle];
        //printf("value = %d \n", value);
        if (value == X) {
            return middle;
        } else {
            if (value > X) {
                right = middle - 1;
                middle = (left + right) / 2;
            } else {
                left = middle + 1;
                middle = (left + right) / 2;
            }
        }
    }
    return NotFound;
}