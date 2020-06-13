/**
 *
 * 6-4 链式表的按序号查找 (10分)
 * 本题要求实现一个函数，找到并返回链式表的第K个元素。
 * 函数接口定义：
 * ElementType FindKth(List L, int K);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct LNode *PtrToNode;
 * typedef PtrToNode List;
 * struct LNode {
 *  ElementType Data;
 *  PtrToNode Next;
 *  };
 *  L是给定单链表，函数FindKth要返回链式表的第K个元素。如果该元素不存在，则返回ERROR。
 *
 *  输入样例：
 *  1 3 4 5 2 -1
 *  6
 *  3 6 1 5 4 2
 *  输出样例：
 *  4 NA 1 2 5 3
 *
 */
#include "stdlib.h"
#include "stdio.h"

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToNode;
typedef PtrToNode List;

struct LNode {
    ElementType Data;
    PtrToNode Next;
};

List Read();

ElementType FindKth(List L, int K);

int main() {
    int N;
    int K;
    ElementType X;
    List L;
    L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR) {
            printf("%d ", X);
        } else {
            printf("NA ");
        }
    }
    return 0;
}

List Read() {
    //下标从1开始
    List L;
    List tail;
    int N;
    List pNode;
    scanf("%d", &N);
    while (N != -1) {
        pNode = (List) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        pNode->Data = 20;
        printf("input = %d\n", N);
        if (tail == NULL) {
            L = pNode;
            tail = pNode;
        } else {
            tail->Next = pNode;
            tail = tail->Next;
        }
        scanf("%d", &N);

    }
    return L;
}

ElementType FindKth(List L, int K) {
    if (!L) {
        return ERROR;
    }
    List p = L;
    int i = 1;
    while (p) {
        if (p->Data == K) {
            return i;
        }
        i++;
        p = p->Next;
    }
    return ERROR;

}
