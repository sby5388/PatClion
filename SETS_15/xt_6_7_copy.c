//
// Created by Administrator on 2020/12/3.
//
/*
本题要求在一个数组中实现两个堆栈。

函数接口定义：
Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );
其中Tag是堆栈编号，取1或2；MaxSize堆栈数组的规模；Stack结构定义如下：

typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;
注意：如果堆栈已满，Push函数必须输出“Stack Full”并且返回false；如果某堆栈是空的，则Pop函数必须输出“Stack Tag Empty”（其中Tag是该堆栈的编号），并且返回ERROR。
*/
/*
输入样例：
5
Push 1 1
Pop 2
Push 2 11
Push 1 2
Push 2 12
Pop 1
Push 2 13
Push 2 14
Push 1 3
Pop 2
End
输出样例：
Stack 2 Empty
Stack 2 is Empty!
Stack Full
Stack 1 is Full!
Pop from Stack 1: 1
Pop from Stack 2: 13 12 11
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR 1e8

typedef int ElementType;
typedef enum {
    push, pop, end
} Operation;

typedef enum {
    false, true
} bool;

typedef int Position;
struct SNode {
    //一系列的，相当于ElementType Data[MaxSize]
    ElementType *Data;
    Position Top1;
    Position Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);

bool Push(Stack S, ElementType X, int Tag);

ElementType Pop(Stack S, int Tag);

/**
 * 细节不表
 * @return
 */
Operation GetOp();

/**
 * 细节不表
 * @param S
 * @param Tag
 */
void PrintStack(Stack S, int Tag);

int main() {
    int N;
    int Tag;
    int X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) {
                    printf("Stack %d is Full!\n", Tag);
                }
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if (X == ERROR) {
                    printf("Stack %d is Empty!\n", Tag);
                }
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

Stack CreateStack(int MaxSize) {
    Stack S = (Stack) malloc(sizeof(struct SNode));
    S->MaxSize = MaxSize;
    //TODO 这是一个数组
    S->Data = (int *) malloc(sizeof(ElementType) * MaxSize);
    S->Top1 = 0;
    S->Top2 = 0;

    return S;
}

bool Push(Stack S, ElementType X, int Tag) {
    if (!S) {
        return false;
    }
    if (S->Top1 + S->Top2 >= S->MaxSize) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) {
        S->Data[S->Top1] = X;
        S->Top1++;
    }
    if (Tag == 2) {
        S->Data[S->MaxSize - S->Top2 - 1] = X;
        S->Top2++;
    }
    return true;
}

ElementType Pop(Stack S, int Tag) {
    if (!S) {
        return ERROR;
    }
    if (Tag != 1 && Tag != 2) {
        return ERROR;
    }
    if (Tag == 1) {
        if (S->Top1 == 0) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
//        S->Data[S->Top1] = (int) NULL;
        Position top1 = S->Top1;
        S->Top1--;
        return S->Data[top1];
    }
    if (Tag == 2) {
        if (S->Top2 == 0) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
//        S->Data[S->MaxSize - S->Top2 - 1] = (int) NULL;
        int top2 = S->MaxSize - S->Top2 - 1;
//        printf("---------top2 = %d\n", top2);
//        fixme 这里发生严重错误了，造成超时
        S->Top2--;
        return S->Data[top2];
    }
    return false;
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

void PrintStack(Stack S, int Tag) {
    if (!S) {
        return;
    }
    if (Tag != 1 && Tag != 2) {
        return;
    }
    if (S->Top1 >= 0 || S->Top2 >= 0) {
        printf("Pop from Stack%d:", Tag);
    }

    if (Tag == 1) {
        while (S->Top1 > 0) {
            printf(" %d", S->Data[S->Top1 - 1]);
            S->Top1--;
        }
        printf("\n");
    } else if (Tag == 2) {
        while (S->Top2 > 0) {
            printf(" %d", S->Data[S->MaxSize - S->Top2]);
            S->Top2--;
        }
        printf("\n");
    }
}
