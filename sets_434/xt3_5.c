//
// Created by Administrator on 2020/6/27.
//
/**
 * 习题3.5 求链表的倒数第m个元素 (20分)
 * 请设计时间和空间上都尽可能高效地算法，
 * 在不改变链表的前提下，求链式存储的线性表的倒数第m(m>0)个元素。
 * 函数接口定义：
 * ElementType Find(List L, int m);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct Node *PtrToNode;
 * typedef PtrToNode List;
 *
 * struct Node {
 *  ElementType Data;
 *  PtrToNode Next;
 * };
 * L是给定的带头结点的单链表；
 * 函数Find要将L的倒数第m个元素返回，并不改变原链表。
 * 如果这样的元素不存在，则返回一个错误标志ERROR。
 *
 * 输入样例：
 * 5
 * 1 2 4 5 6
 * 3
 * 输出样例：
 * 4
 * 1 2 4 5 6
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct Node2 *PtrToNode;
typedef PtrToNode List;

struct Node2 {
    ElementType Data;
    PtrToNode Next;
};


List Read();

void Print(List L);

ElementType Find(List L, int m);

int main() {
    List L;
    int m;

    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

//todo 带头结点
List Read() {
    List L = (List) malloc(sizeof(struct Node2));
    L->Next = NULL;
    List tail = L;
    int N;
    scanf("%d", &N);
    while (N > 0) {
        List pNode = (List) malloc(sizeof(struct Node2));
        pNode->Next = NULL;
        scanf("%d", &pNode->Data);

        tail->Next = pNode;
        tail = tail->Next;
        N--;
    }
    return L;
}

void Print(List L) {
    if (L == NULL) {
        return;
    }
    List next = L->Next;
    while (next != NULL) {
        printf("%d ", next->Data);
        next = next->Next;
    }
}

//todo 倒数第m个，也就是正序的第(总长度-m)个
ElementType Find(List L, int m) {
    if (L == NULL) {
        return ERROR;
    }
    //all length
    int count = 0;
    int index = 0;
    List pNode = L;
    while (pNode->Next) {
        pNode = pNode->Next;
        count++;
    }
    //printf("count  = %d\n", count);
    if (count >= m) {
        m = count - m;
        PtrToNode next = L->Next;
        while (next) {
            if (index == m) {
                return next->Data;
            } else {
                index++;
                next = next->Next;
            }
        }
    }
    return ERROR;
}