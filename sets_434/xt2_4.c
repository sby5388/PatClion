//
// Created by Administrator on 2020/6/21.
//
/**
 * 习题2.4 递增的整数序列链表的插入 (15分)
 * 本题要求实现一个函数，在递增的整数序列链表（带头结点）中插入一个新整数，并保持该序列的有序性。
 * 函数接口定义：
 * List Insert(List L, ElementType X);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct Node *PtrToNode;
 * typedef PtrToNode List;
 * struct Node {
 *  ElementType Data;
 *  PtrToNode Next;
 * };
 * L是给定的带头结点的单链表，其结点存储的数据是递增有序的；
 * 函数Insert要将X插入L，并保持该序列的有序性，返回插入后的链表头指针。
 *
 *
 * 输入样例：
 * 5
 * 1 2 4 5 6
 * 3
 * 输出样例：
 * 1 2 3 4 5 6
 *
 * TODO 带头结点
 * todo 带头结点
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node2 *PtrToNode;
typedef PtrToNode List;
struct Node2 {
    ElementType Data;
    PtrToNode Next;
};

List Read();

void Print(List L);

/**
 * 插入一个元素
 * @param L
 * @param X
 * @return
 */
List Insert(List L, ElementType X);

int main() {
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

List Read() {
    List L = (List) malloc(sizeof(struct Node2));
    L->Next = NULL;
    List tail = L;

    int N;
    scanf("%d", &N);
    while (N) {
        List node = (List) malloc(sizeof(struct Node2));
        node->Next = NULL;
        scanf("%d", &node->Data);
        tail->Next = node;
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
    while (next) {
        printf("%d ", next->Data);
        next = next->Next;
    }
}

/* 你的代码将被嵌在这里 */

List Insert(List L, ElementType X) {
    List pNode = (List) malloc(sizeof(struct Node2));
    pNode->Next = NULL;
    pNode->Data = X;
    //插在头部
    if (L->Next == NULL || L->Next->Data > X) {
        pNode->Next = L->Next;
        L->Next = pNode;
        return L;
    }
    List pHead = L->Next;
    //插在中间或者尾部
    while (pHead) {
        if (pHead->Data < X && (pHead->Next == NULL || pHead->Next->Data > X)) {
            pNode->Next = pHead->Next;
            pHead->Next = pNode;
            break;
        } else {
            pHead = pHead->Next;
        }
    }
    return L;
}