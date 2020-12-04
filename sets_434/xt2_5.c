//
// Created by Administrator on 2020/6/21.
//
/**
 * 习题2.5 两个有序链表序列的合并 (15分)
 * 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
 * 函数接口定义：
 * List Merge(List L1, List L2);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct Node *PtrToNode;
 * typedef PtrToNode List;
 *
 * struct Node {
 *  ElementType Data;
 *  PtrToNode Next;
 * };
 *
 * todo L1和L2是给定的带头结点的单链表，
 * 其结点存储的数据是递增有序的；
 * 函数Merge要将L1和L2合并为一个非递减的整数序列。
 * 应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。
 *
 * 输入样例：
 * 3
 * 1 3 5
 * 5
 * 2 4 6 8 10
 * 输出样例：
 * 1 2 3 4 5 6 8 10
 * NULL
 * NULL
 *
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

/**
 * 读取
 * @return
 */
List Read();

/**
 * 打印
 * @param L
 */
void Print(List L);

/**
 * 合并2个链表
 * @param L1
 * @param L2
 * @return
 */
List Merge(List L1, List L2);

int main() {
    List L1;
    List L2;
    List L;

    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);

    return 0;
}

List Read() {
    int N;
    List L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;
    List tail = L;

    scanf("%d", &N);
    while (N) {
        List next = (List) malloc(sizeof(struct Node));
        next->Next = NULL;
        scanf("%d", &next->Data);
        tail->Next = next;
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
    if (!next) {
        printf("NULL");
//        return ;
    } else {
        while (next) {
            printf("%d ", next->Data);
            next = next->Next;
        }
    }
    printf("\n");

}

List Merge(List L1, List L2) {
    List L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;
    List next = L;

    while (L1->Next || L2->Next) {
        List next1 = L1->Next;
        List next2 = L2->Next;
        if (next1 != NULL && next2 != NULL) {
            //需要移动的结点
            List move;
            if (next1->Data <= next2->Data) {
                L1->Next = next1->Next;
                move = next1;
            } else {
                L2->Next = next2->Next;
                move = next2;
            }
            next->Next = move;
            move->Next = NULL;
            next = next->Next;

        } else if (L1->Next) {
            //L2->Next == NULL
            next->Next = L1->Next;
            L1->Next = NULL;

        } else {
            //L2->Next != NULL
            //L1->Next == NULL
            next->Next = L2->Next;
            L2->Next = NULL;
        }
    }
    return L;

}


List Merge2(List L1, List L2) {
    /**
     * TODO 合并时，不申请新的空间，而是利用原有的数据单元
     */

    List p1 = L1->Next;
    List p2 = L2->Next;

    List L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;
    List tail = L;

    while (p1 && p2) {
        List p = NULL;

        ElementType min = p1->Data;
        if (p2->Data < min) {
            //TODO 移动L2:每次处理的肯定是第一个数据
            p = p2;

            L2->Next = p2->Next;
            p2 = p2->Next;
        } else {
            //移动L1
            p = p1;

            L1->Next = p1->Next;
            p1 = p1->Next;
        }
        tail->Next = p;
        tail = p;
        tail->Next = NULL;
    }

    List p3;
    while (p1) {
        p3 = p1;

        L1->Next = p1->Next;
        p1 = p1->Next;

        tail->Next = p3;
        tail = p3;
        tail->Next = NULL;
    }
    while (p2) {
        p3 = p2;

        L2->Next = p2->Next;
        p2 = p2->Next;

        tail->Next = p3;
        tail = p3;
        tail->Next = NULL;
    }

    return L;
}