//
// Created by Administrator on 2020/7/6.
//
/**
 * todo 带头结点
 * 6-6 带头结点的链式表操作集 (20分)
 * 函数接口定义：
 * List MakeEmpty();
 * Position Find(List L,ElementType X);
 * bool Insert(List L,ElementType X,Position P);
 * bool Delete(List L,Position P);
 * 其中List的结构定义如下：
 * typedef int ElementType;
 * typedef struct LNode *PtrToLNode;
 *
 * struct LNode {
 *  ElementType Data;
 *  PtrToLNode Next;
 * };
 *
 * typedef PtrToLNode Position;
 * typedef PtrToLNode List;
 *
 * 各个操作函数的定义为：
 * List MakeEmpty()：创建并返回一个空的线性表；
 * Position Find(List L,ElementType X)：返回线性表中X的位置。若找不到则返回ERROR;
 * bool Insert(List L,ElementType X,Position P):将X插入到位置P指向的节点之前，返回true;
 *  如果参数P指向非法位置，则打印 "Wrong Position for Insertion",返回false;
 * bool Delete(List L,Position P):将位置P的元素删除并返回true;
 *  如果参数P指向非法位置，则打印 "Wrong Position for Deletion",返回false;
 *
 * 输入样例：
 * 6
 * 12 2 4 87 10 2
 * 4
 * 2 12 87 5
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
 *
 *
 * @return
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
#define DEBUG 0


typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef struct LNode2 *PtrToLNode;

struct LNode2 {
    ElementType Data;
    PtrToLNode Next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();

Position Find(List L, ElementType X);

bool Insert(List L, ElementType X, Position P);

bool Delete(List L, Position P);


int main() {
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false) {
            printf("Wrong Answer\n");
        }
    }
    if (DEBUG) {
        List pNode = L->Next;
        printf("Current Input ");
        while (pNode) {
            printf("%d ", pNode->Data);
            pNode = pNode->Next;
        }
        printf("\n");

    }


    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR) {
            //找不到
            printf("Finding Error: %d is not in.\n", X);
        } else {
            //找到了，删除
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false) {
                printf("Wrong Answer.\n");
            }
        }
    }

    //插到末尾
    flag = Insert(L, X, NULL);
    if (false == flag) {
        printf("Wrong Answer\n");
    } else {
        printf("%d is inserted as the last element.\n", X);
    }

    P = (Position) malloc(sizeof(struct LNode2));
    flag = Insert(L, X, P);
    //肯定是false
    if (flag == true) {
        printf("Wrong Answer\n");
    }
    flag = Delete(L, P);
    //肯定是false
    if (flag == true) {
        printf("Wrong Answer\n");
    }

    for (P = L->Next; P; P = P->Next) {
        printf("%d ", P->Data);

    }

    return 0;
}
#undef DEBUG
List MakeEmpty() {
    List L;
    L = (List) malloc(sizeof(struct LNode2));
    L->Next = NULL;
    return L;
}

bool Insert(List L, ElementType X, Position P) {
    int DEBUG = 0;
    List head = L;

    List insert = (List) malloc(sizeof(struct LNode2));
    insert->Next = NULL;
    insert->Data = X;

    bool result = false;
    if (L == NULL) {
        if (DEBUG) {
            printf("Insert Fail L==NULL \n");
        }

        result = false;
    } else {
        if (P == NULL) {
            if (DEBUG) {
                printf("Insert tail \n");
            }
            //插在末尾
            while (head->Next) {
                head = head->Next;
            }
            head->Next = insert;
            result = true;
        } else {
            if (L == P) {
                if (DEBUG) {
                    printf("Insert Head \n");
                }
                //插在最前面
                insert->Next = L;
                L = insert;
                result = true;
            } else {
                //todo 20200708 插在中间
                while (head->Next) {
                    if (head->Next == P) {
                        if (DEBUG) {
                            printf("Insert Middle\n");
                        }
                        List next = head->Next;
                        head->Next = insert;
                        insert->Next = next;
                        result = true;
                        break;
                    }
                    head = head->Next;
                }

            }
        }

    }


    if (result == false) {
        printf("Wrong Position for Insertion\n");
    }
    return result;
}

Position Find(List L, ElementType X) {
    List pNode = L;
    if (!pNode) {
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

bool Delete(List L, Position P) {
    if (!L || !P) {
        printf("Wrong Position for Deletion\n");
        return false;
    }
    List head = L;
    //头部、中间、尾部
    if (head == P) {
        List next = head->Next;
        free(head);
        L = next;
        return true;
    }
    List pre = NULL;
    while (head->Next) {
        List next = head->Next;
        if (next == P) {
            head->Next = next->Next;
            free(next);
            return true;
        }
        pre = head;
        head = head->Next;
    }
    if (pre && head == P) {
        pre->Next = NULL;
        free(head);
        return true;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}