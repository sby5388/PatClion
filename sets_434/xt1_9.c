//
// Created by Administrator on 2020/6/19.
//
/**
 * 习题1.9 有序数组的插入 (20分)
 * 本题要求将任一给定元素插入从大到小排好序的数组中合适的位置，以保持结果依然有序。
 * 函数接口定义：
 * bool Insert(List L, ElementType X);
 * 其中List结构定义如下：
 * typedef int Position;
 * typedef struct LNode *List;
 * struct LNode {
 *   ElementType Data[MAXSIZE];
 *    Position Last; //保存线性表中最后一个元素的位置
 * };
 * L是用户传入的一个线性表，
 * 其中ElementType元素可以通过>、==、<进行比较，
 * 并且题目保证传入的数据是递减有序的。
 * 函数Insert要将X插入Data[]中合适的位置，
 * 以保持结果依然有序（注意：元素从下标0开始存储）。
 * 但如果X已经在Data[]中了，就不要插入，返回失败的标记false；
 * 如果插入成功，则返回true。
 * 另外，因为Data[]中最多只能存MAXSIZE个元素，所以如果插入新元素之前已经满了，也不要插入，
 * 而是返回失败的标记false。
 *
 *
 *
 */
/*
输入样例1：
5
35 12 8 7 3
10
输出样例1：
35 12 10 8 7 3
Last = 5
输入样例2：
6
35 12 10 8 7 3
8
输出样例2：
Insertion failed.
35 12 10 8 7 3
Last = 5
 */


#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef enum {
    false, true
} bool;

typedef int ElementType;
typedef int Position;
typedef struct LNode *List;

struct LNode {
    //元素
    ElementType Data[MAXSIZE];
    //最后一个元素的位置
    Position Last;
};

List ReadInput();

void PrintList(List L);

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

List ReadInput() {
    List L;
    int N;
    int X;
    Position index = 0;

    L = (List) malloc(sizeof(struct LNode));
    L->Last = 0;
    scanf("%d", &N);
    L->Last = N - 1;
    printf("N = %d\n", N);
    while (N > 0) {
        scanf("%d", &X);
        L->Data[index] = X;
        printf("X = %d,index = %d,N = %d\n", X, index, N);

        index++;
        N--;
    }

    printf("输入结束\n");
    printf("L->Last = %d\n", L->Last);
    for (int i = 0; i <= L->Last; i++) {
        printf("L->Data[%d] = %d\n", i, L->Data[i]);
    }

    return L;
}

void PrintList(List L) {
    if (L == NULL) {
        return;
    }
//    int index = 0;
    Position last = L->Last;
//    while (index < last) {
//        printf("%d ", L->Data[index]);
//        index++;
//    }
    for (int i = 0; i <= last; i++) {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
    printf("Last = %d", last);
}

//插入：从大到小
bool Insert(List L, ElementType X) {
    if (L == NULL) {
        return false;
    }
    if (L->Last >= (MAXSIZE - 1)) {
        return false;
    }
    Position last = L->Last;
    int insertIndex = -1;
    if (X > L->Data[0]) {
        insertIndex = 0;
    } else if (X < L->Data[last - 1]) {
        insertIndex = last + 1;
    } else {
        for (int i = 1; i < last; i++) {
            if ((L->Data[i] > X) && (L->Data[i + 1] < X)) {
                insertIndex = i + 1;
                break;
            }
        }
    }
    if (insertIndex == -1) {
        //printf("qqq33\n");
        return false;
    }
    //printf("indexInsert = %d\n", insertIndex);
    for (int j = last; j >= insertIndex; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[insertIndex] = X;
    L->Last++;

    return true;
}
/**
 * 往有序数组中插入数据
 * @param L
 * @param X
 * @return
 */
bool Insert2(List L, ElementType X) {
    if (L->Last >= MAXSIZE) {
        return false;
    }
    Position last = L->Last + 1;
    if (last >= MAXSIZE) {
        return false;
    }
    for (int i = 0; i < last; ++i) {
        if (X == L->Data[i]) {
            return false;
        }
    }
    /* 确定插入的位置*/
    Position insertIndex = 0;
    if (X >= L->Data[0]) {
        insertIndex = 0;
    } else if (X < L->Data[last - 1]) {
        insertIndex = last;
    } else {
        for (int i = 0; i < last; ++i) {
            if (X < L->Data[i] && X > L->Data[i + 1]) {
                insertIndex = i + 1;
                break;
            }
        }
    }
    //往后移动数据
    for (int j = last; j >= insertIndex; j--) {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[insertIndex] = X;
    L->Last = L->Last + 1;
    return true;
}
