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
typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node {
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
    int N;
    List L;
    L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;
    List tail = L;
    scanf("%d", &N);
    while (N) {
        List node = (List) malloc(sizeof(struct Node));
        node->Next = NULL;
        scanf("%d", &node->Data);
        tail->Next = node;
        tail = tail->Next;
        N--;
    }
    return L;
}

void Print(List L) {
    List next;
    if (L == NULL) {
        return;
    }
    next = L->Next;
    while (next) {
        printf("%d ", next->Data);
        next = next->Next;
    }
}

List Insert(List L, ElementType X) {
    List next;
    List insert;
    if (L == NULL) {
        return L;
    }
    next = L->Next;
    insert = (List) malloc(sizeof(struct Node));
    insert->Next = NULL;
    insert->Data = X;
    if (next == NULL) {
        //既有队列为空
        L->Next = insert;
    } else {
        if (X <= next->Data) {
            //插在头部
            insert->Next = next;
            L->Next = insert;
        } else {
            //插在中间或者尾部
            List last = next->Next;
            while (next && X >= next->Data) {
                if (last == NULL || X <= last->Data) {
                    insert->Next = last;
                    next->Next = insert;
                    break;
                } else {
                    next = next->Next;
                    last = next->Next;
                }
            }
        }
    }
    return L;
}

List Insert2(List L, ElementType X) {
    List temp = (List) malloc(sizeof(struct Node));
    temp->Data = X;
    temp->Next = NULL;
    /* 在头部插入 */
    if (X > L->Data) {
        temp->Next = L;
        return temp;
    }
    List origin = L;


    /*在中间或者末尾插入*/
    int insert = 0;
    while (L->Next) {
        if (L->Data <= X && X < L->Next->Data) {
            List pNode = L->Next;
            L->Next = temp;
            temp->Next = pNode;
            insert = 1;
            break;
        }
        L = L->Next;
    }
    /*末尾插入*/
    if (!insert) {
        L->Next = temp;
    }

    return origin;
}