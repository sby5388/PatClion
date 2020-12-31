//
// Created by Administrator on 2020/12/30.
//
//L1-034 点赞 (20分)
//https://pintia.cn/problem-sets/994805046380707840/problems/994805098188750848
#include <stdio.h>
#include <stdlib.h>

#define SORT 0

typedef struct Label *List;
typedef int ElementType;

struct Label {
    int Id;
    int Count;
    List Next;
};

List FindMax(List L);

List CreateList(int N);

void AddLabel(List L);

List Find(List L, int Id);

void InsertItem(List L, int Id);

void PrintList(List L);

int main() {
    int N;
    scanf("%d", &N);
    List L = CreateList(N);
//    PrintList(L);
    List max = FindMax(L);
    printf("%d %d", max->Id, max->Count);

    return 0;
}

List FindMax(List L) {
    List next = L->Next;

    List result = next;
    int max = result->Count;

    next = next->Next;

    while (next) {
        if (next->Count > max) {
            max = next->Count;
            result = next;
        } else if (next->Count == max) {
            if (next->Id > result->Id) {
                result = next;
            }
        }
        next = next->Next;
    }

    return result;
}

List CreateList(int N) {
    List L = (List) malloc(sizeof(struct Label));
    L->Next = NULL;
    while (N) {
        AddLabel(L);
        //PrintList(L);
        N--;
    }
    return L;
}

void AddLabel(List L) {
    int Id;
    int N;
    scanf("%d", &N);
    while (N) {
        scanf("%d", &Id);
        List find = Find(L, Id);
        if (find != NULL) {
            find->Count++;
        } else {
            InsertItem(L, Id);
        }
        N--;
    }
}

/**
 * 从小到大排序
 * @param L
 * @param Id
 * @return
 */
List Find(List L, int Id) {
    List next = L->Next;
    while (next) {
        if (next->Id == Id) {
            return next;
        } else {
            next = next->Next;
        }

    }
    return NULL;
}

void InsertItem(List L, int Id) {
    List pNode = (List) malloc(sizeof(struct Label));
    pNode->Next = NULL;
    pNode->Id = Id;
    pNode->Count = 1;

    if (!SORT) {
        List next2 = L->Next;

        pNode->Next = next2;
        L->Next = pNode;


        return;
    }


    List next = L->Next;

    if (next == NULL) {
        L->Next = pNode;
        return;
    }

    if (Id < next->Id) {
        pNode->Next = next->Next;
        L->Next = pNode;
        return;
    }


    while (next) {
        if (next->Next) {
            List next1 = next->Next;
            if (next->Id < Id && next1->Id > Id) {
                pNode->Next = next1;
                next->Next = pNode;
                break;
            } else {
                next = next->Next;
            }
        } else {
            next->Next = pNode;
            break;
        }
    }
}

void PrintList(List L) {
    List pLabel = L->Next;
    while (pLabel) {
        printf("%d:%d\n", pLabel->Id, pLabel->Count);
        pLabel = pLabel->Next;
    }
}