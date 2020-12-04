//
// Created by Administrator on 2020/6/14.
//
/**
 * 6-5 链式表操作集 (20分)
 * 本题要求实现链式表的操作集。
 * 函数接口定义：
 * Position Find( List L, ElementType X );
 *  返回线性表中首次出现X的位置。若找不到则返回ERROR；
 * List Insert( List L, ElementType X, Position P );
 *  将X插入在位置P指向的结点之前，返回链表的表头。
 *  如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR；
 * List Delete( List L, Position P );
 *  将位置P的元素删除并返回链表的表头。若参数P指向非法位置，
 *  则打印“Wrong Position for Deletion”并返回ERROR。
 *  其中List结构定义如下：
 *  typedef struct LNode *PtrToLNode;
 *  struct LNode {
 *      ElementType Data;
 *      PtrToLNode Next;
 * };
 * typedef PtrToLNode Position;
 * typedef PtrToLNode List;
 *
 * 输入样例：
 * 6
 * 12 2 4 87 10 2
 * 4
 * 2 12 87 5
 *
 * 输出样例：
 * 2 is found and deleted.
 * 12 is found and deleted.
 * 87 is found and deleted.
 * Finding Error: 5 is not in.
 * 5 is inserted as the last element.
 * Wrong Position for Insertion
 * Wrong Position for Deletion
 * 10 4 2 5
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};

/**
 * 返回线性表中首次出现X的位置,若找不到则返回ERROR
 * @param L
 * @param X
 * @return
 */
Position Find(List L, ElementType X);

/**
 * 将X插入在位置P指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印 ”Wrong Position for Insertion“，返回 ERROR
 * @param L
 * @param X
 * @param P
 * @return
 */
List Insert(List L, ElementType X, Position P);

/**
 * 将位置P的元素删除并返回链表的表头。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR。
 * @param L
 * @param P
 * @return
 */
List Delete(List L, Position P);

int main() {
    int debug = 0;
    List L;
    ElementType X;
    Position P, temp;
    int N;

    L = NULL;
    //insert
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) {
            printf("Wrong Answer\n");
        }
    }

    if (debug) {
        printf("\n录入成功\n");
        printf("L = ");
        List temp = L;
        while (temp) {
            printf("%d ", temp->Data);
            temp = temp->Next;
        }
        printf("\n");
    }



    //find && delete
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR) {
            printf("Finding Error: %d is not in.\n", X);
        } else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR) {
                printf("Wrong Answer or Empty List.\n");
            }
        }
    }

    L = Insert(L, X, NULL);
    if (L == ERROR) {
        printf("Wrong Answer 000 \n");
    } else {
        printf("%d is inserted as the last element.\n", X);
    }

    if (debug) {
        printf("\n插入后的数据：\n");
        printf("L = ");
        List temp = L;
        while (temp) {
            printf("%d ", temp->Data);
            temp = temp->Next;
        }
        printf("\n");
    }


    P = (Position) malloc(sizeof(struct LNode));
    temp = Insert(L, X, P);
    if (temp != ERROR) {
        printf("Wrong Answer\n");
    }

    temp = Delete(L, P);
    if (temp != ERROR) {
        printf("Wrong Answer\n");
    }

    for (P = L; P; P = P->Next) {
        printf("%d ", P->Data);
    }

    return 0;
}


List Insert(List L, ElementType X, Position P) {
    List head = L;
    List insert = (List) malloc(sizeof(struct LNode));
    insert->Next = NULL;
    insert->Data = X;

    if (L == NULL) {
        L = insert;
        return insert;

    } else {
        if (P == NULL) {
            //TODO 插在末尾
            while (head->Next) {
                head = head->Next;
            }
            head->Next = insert;
            return L;
        } else {
            if (head == P) {
                //TODO 插在最前面
                insert->Next = L;
                L = insert;
                return insert;
            } else {
                //TODO 插在中间
                while (head->Next) {
                    if (head->Next == P) {
                        head->Next = insert;
                        insert->Next = P;
                        return L;
                    }
                    head = head->Next;
                }
            }
        }
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

Position Find(List L, ElementType X) {
    List pNode = L;
    if (L == NULL) {
        return ERROR;
    }
    while (pNode) {
        if (pNode->Data == X) {
            return pNode;
        }
        pNode = pNode->Next;
    }
    return ERROR;
}


List Delete(List L, Position P) {
    if (P == NULL) {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    List pNode = L;
    //判断首部
    if (pNode->Data == P->Data) {
        PtrToLNode next = pNode->Next;
        free(pNode);
        L = next;
        return L;
    }
    //不是第一个
    while (pNode->Next) {
        if (pNode->Next->Data == P->Data) {
            PtrToLNode delete = pNode->Next;
            pNode->Next = delete->Next;
            free(delete);
            return L;
        }
        pNode = pNode->Next;
    }

    printf("Wrong Position for Deletion\n");
    return ERROR;
}