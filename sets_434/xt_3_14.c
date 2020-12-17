//
// Created by Administrator on 2020/12/16.
//
//习题3.14 另类堆栈 (15分)
//https://pintia.cn/problem-sets/434/problems/6098

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR -1


typedef int ElementType;
typedef enum {
    push, pop, end
} Operation;
typedef enum {
    false, true
} bool;
typedef int Position;
typedef struct SNode *PtrToSNode;
typedef PtrToSNode Stack;
struct SNode {
    /* 存储元素的素组 */
    ElementType *Data;
    /* 栈顶指针 */
    Position Top;
    /* 堆栈的最大容量 */
    int MaxSize;
};

Stack CreateStack(int MaxSize);

bool Push(Stack S, ElementType X);

ElementType Pop(Stack S);

Operation GetOp();

void PrintStack(Stack S);

int main() {
    ElementType X;
    Stack S;
    int N;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d", &X);
                Push(S, X);
                break;
            case pop:
                X = Pop(S);
                if (X != ERROR) {
                    printf("%d is out\n", X);
                }
                break;
            case end:
                PrintStack(S);
                done = 1;
                break;
        }
    }
    return 0;
}

Stack CreateStack(int MaxSize) {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    S->Top = 0;
    S->MaxSize = MaxSize;
    return S;
}

Operation GetOp() {
    char Push[] = "Push";
    char Pop[] = "Pop";
    char End[] = "End";
    char s[100];
    scanf("%s", s);
    if (strcmp(Push, s) == 0) {
        return push;
    }
    if (strcmp(Pop, s) == 0) {
        return pop;
    }
    if (strcmp(End, s) == 0) {
        return end;
    }
    return end;
}

void PrintStack(Stack S) {
    Stack pNode = S;
    Position top = S->Top;
    while (top > 0) {
        top--;
        printf("%d ", pNode->Data[top]);
    }
}


/* 你的代码将被嵌在这里 */

bool Push(Stack S, ElementType X) {
    if (S->Top == S->MaxSize) {
        printf("Stack Full\n");
        return false;
    }
    S->Data[S->Top] = X;
    S->Top++;
    return true;
}

ElementType Pop(Stack S) {
    if (S->Top == 0) {
        printf("Stack Empty\n");
        return ERROR;
    }
    S->Top--;
    return S->Data[S->Top];
}