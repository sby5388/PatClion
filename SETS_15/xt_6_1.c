
/**
 * 6-1 单链表逆转 (20分)
 * 本题要求实现一个函数，将给定的单链表逆转。
 * 函数接口定义：
 * List Reverse(List L);
 * L是给定单链表，函数Reverse要返回被逆转后的链表。
 *
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef struct Node *PtrToNode;
 * struct Node {
 *      // 存储结点数据
 *      ElementType Data;
 *      //指向下一个结点的指针
 *      PtrToNode Next;
 *  };
 *  定义单链表类型
 *  typedef PtrToNode List;
 *
 *输入样例：
 * 5
 * 1 3 4 5 2
 * 输出样例：
 * 1
 * 2 5 4 3 1
 *
 */
#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;
typedef struct Node2 *PtrToNode;
struct Node2 {
    // 存储结点数据
    ElementType Data;
    PtrToNode Next;
};

typedef PtrToNode List;

//读取，由系统实现
List Read();

//打印，由系统实现
void Print(List L);

List Reverse(List L);

int main() {
    List L1;
    List L2;

    L1 = Read();
    //Print(L1);


    L2 = Reverse(L1);
    //printf("L1\n");
    Print(L1);
    //printf("L2\n");
    Print(L2);
    return 0;
}

List Read() {
    List list = NULL;
    List pTail = list;

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        if (list == NULL) {
            list = (struct Node2 *) malloc(sizeof(struct Node2));
            list->Next = NULL;
            scanf("%d", &list->Data);
            pTail = list;
        } else {
            List next = (struct Node2 *) malloc(sizeof(struct Node2));
            next->Next = NULL;
            scanf("%d", &next->Data);
            pTail->Next = next;
            pTail = pTail->Next;
        }

    }


    return list;

}

void Print(List L) {
    List show = L;
    while (show) {
        printf("%d ", show->Data);
        show = show->Next;
    }
    printf("\n");
}


List Reverse(List L) {
    List L2;
    List next;
    List last = L;
    while (L) {
        next = L->Next;
        List current = L;
        if (next) {
            last = next;
            //last->Next = NULL;
        }
        if (L2 == NULL) {
            //printf("空\n");
            L2 = current;
            L2->Next = NULL;
        } else {
            //printf("非空\n");
            current->Next = L2;
            L2 = current;
            //Print(L2);
        }
        L = next;
    }
    L = last;
    //L->Next = NULL;
    return L2;
}









