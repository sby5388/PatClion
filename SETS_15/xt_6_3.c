/**
 * 6-3 求链式表的表长 (10分)
 * 本题要求实现一个函数，求链式表的表长。
 * 函数接口定义：
 * int Length(List L);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct LNode *PtrNode;
 * typedef PtrNode List;
 * struct LNode {
 *  ElementType Data;
 *  PtrNode Next;
 * };
 * L是给定单链表，函数Length要返回链式表的长度。
 *
 *
 * 输入样例：
 * 1 3 4 5 2 -1
 * 输出样例：
 * 5
 */
#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;
typedef struct LNode *PtrNode;
typedef PtrNode List;
struct LNode {
    ElementType Data;
    PtrNode Next;

};

int Length(List L);

List Read();

int main() {
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

List Read() {
    List L;
    int N;
    scanf("%d", &N);
    while (N != -1) {
        List pNode = (List) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        pNode->Data = N;
        if (L == NULL) {
            L = pNode;
        } else {
            L->Next = pNode;
        }
    }

    return L;

}

int Length(List L) {
    List pNode = L;
    int count = 0;
    while (pNode) {
        count++;
        pNode = pNode->Next;
    }
    return count;
}