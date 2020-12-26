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
#include <stdlib.h>
#include <stdio.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode2 *PtrToNode;
typedef PtrToNode List;

struct LNode2 {
    ElementType Data;
    PtrToNode Next;
};

List Read();

List Read2();

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
    if (0) {
        return Read2();
    }
    //下标从1开始
    List L = NULL;
    List tail;
    int N = -1;
    scanf("%d", &N);
    while (N != -1) {
        List pNode = (List) malloc(sizeof(struct LNode2));
        pNode->Next = NULL;
        pNode->Data = N;
        if (L == NULL) {
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


List Read2() {
    List L;
    List pTail;
    int N = -1;
    while ((scanf("%d", &N) == 1) && N != -1) {
        List pNode = (List) malloc(sizeof(struct LNode2));
        pNode->Next = NULL;
        pNode->Data = N;
        if (L == NULL) {
            L = pNode;
            pTail = L;
        } else {
            pTail->Next = pNode;
            pTail = pTail->Next;
        }
    }
    return L;
}

ElementType FindKth2(List L, int K) {
    int p = 1;
    while (p != K && L != NULL) {
        L = L->Next;
        p++;
    }
    if (L == NULL) {
        return ERROR;
    }
    return L->Data;

}

/**
 * 根据位置找值，而不是根据值找位置
 * @param L
 * @param K K是下标
 * @return  值
 */
ElementType FindKth(List L, int K) {
    if (L == NULL) {
        return ERROR;
    }
    List p = L;
    int i = 1;
    while (p) {
        if (K == i) {
            return p->Data;
        }
        i++;
        p = p->Next;
    }
    return ERROR;
}
