//
// Created by Administrator on 2020/12/8.
//
//习题3.13 双端队列 (25分)
//https://pintia.cn/problem-sets/434/problems/6096

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR -1
typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrToQNode;
typedef PtrToQNode Deque;
/**
 * 双端队列（deque，即double-ended queue的缩写）是一种具有队列和栈性质的数据结构，
 * 即可以（也只能）在线性表的两端进行插入和删除。
 * 若以顺序存储方式实现双端队列，
 * TODO 顺序存储
 */
struct QNode {
    /* 存储元素的素组 */
    ElementType *Data;
    /* 队列的头指针 */
    Position Front;
    /* 队列的尾指针 */
    Position Rear;
    /* 最大容量 */
    int MaxSize;
};

typedef enum {
    push,
    pop,
    inject,
    eject,
    end
} Operation;

typedef enum {
    false, true
} bool;


/* 创建双端队列 */
Deque CreateDeque(int MaxSize);

/**
 * 将元素X插入到双端队列D的头
 * @param X
 * @param D
 * @return
 */
bool Push(ElementType X, Deque D);

/**
 * 删除双端队列D的头元素，并返回
 * @param D
 * @return
 */
ElementType Pop(Deque D);

/**
 * 将元素插入到双端队列D的尾部
 * @param X
 * @param D
 * @return
 */
bool Inject(ElementType X, Deque D);

/**
 * 删除双端队列D的尾部元素，并返回
 * @param D
 * @return
 */
ElementType Eject(Deque D);

Operation getOp();

void PrintDeque(Deque D);

int main() {
    ElementType X;
    Deque D;
    int N;
    int done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done) {
        switch (getOp()) {
            case push:
                scanf("%d", &X);
                if (!Push(X, D)) {
                    printf("Deque is Full!\n");
                }
                break;
            case pop:
                X = Pop(D);
                if (X == ERROR) {
                    printf("Deque is Empty!\n");
                } else {
                    printf("%d is out\n", X);
                }

                break;
            case inject:
                scanf("%d", &X);
                if (!Inject(X, D)) {
                    printf("Deque is Full!\n");
                }
                break;
            case eject:
                X = Eject(D);
                if (X == ERROR) {
                    printf("Deque is Empty!\n");
                } else {
                    printf("%d is out\n", X);
                }
                break;
            case end:
                PrintDeque(D);
                done = 1;
                break;
        }
    }

    return 0;
}


/* 注意：为区分空队列和满队列，需要多开辟一个空间 */
//TODO 这里是题目给定的，不能修改
Deque CreateDeque(int MaxSize) {
    Deque D = (Deque) malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *) malloc(sizeof(ElementType) * MaxSize);
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

Operation getOp() {
    char Push[] = "Push";
    char Pop[] = "Pop";
    char Inject[] = "Inject";
    char Eject[] = "Eject";
    char End[] = "End";
    char s[100];
    scanf("%s", s);
    if (strcmp(Push, s) == 0) {
        return push;
    }
    if (strcmp(Pop, s) == 0) {
        return pop;
    }
    if (strcmp(Inject, s) == 0) {
        return inject;
    }
    if (strcmp(Eject, s) == 0) {
        return eject;
    }
    if (strcmp(End, s) == 0) {
        return end;
    }
    return end;
}

void PrintDeque(Deque D) {
    printf("Inside Deque:");
    ElementType X = Pop(D);
    while (X != ERROR) {
        printf("%d ", X);
        X = Pop(D);
    }

}

/* 你的代码将被嵌在这里 */

bool IsFull(Deque D);

bool IsEmpty(Deque D);

bool Push(ElementType X, Deque D) {
    printf("Front = %d,Rear = %d\n", D->Front, D->Rear);
    if (IsFull(D)) {
        return false;
    }
    D->Data[D->Front] = X;
    D->Front = (D->Front - 1) % D->MaxSize;
    return true;
}

ElementType Pop(Deque D) {
    printf("Front = %d,Rear = %d\n", D->Front, D->Rear);
    if (IsEmpty(D)) {
        return ERROR;
    }
    D->Front = (D->Front + 1) % D->MaxSize;
    return D->Data[D->Front];

}

bool Inject(ElementType X, Deque D) {
    printf("Front = %d,Rear = %d\n", D->Front, D->Rear);
    if (IsFull(D)) {
        return false;
    }
    D->Rear = (D->Rear + 1) % D->MaxSize;
    D->Data[D->Rear] = X;
    return true;
}

ElementType Eject(Deque D) {
    printf("Front = %d,Rear = %d\n", D->Front, D->Rear);
    if (IsEmpty(D)) {
        return ERROR;
    }
    ElementType X = D->Data[D->Rear];
    D->Rear = (D->Rear - 1) % D->MaxSize;
    return X;
}

bool IsFull(Deque D) {
    return (D->Rear + 1) % D->MaxSize == D->Front;
}

bool IsEmpty(Deque D) {
    return D->Front == D->Rear;
}