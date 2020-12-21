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
struct QNode {
    //存储元素的素组
    ElementType *Data;
    //队列的头指针
    Position Front;
    //队列的尾指针
    Position Rear;
    //最大容量
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

bool IsEmpty(Deque D);

bool IsFull(Deque D);

bool PushBack(ElementType X, Deque D);

ElementType PopBack(Deque D);

//满了，返回false
//插入到头部，不是尾部
bool Push(ElementType X, Deque D) {
    if (IsFull(D)) {
        return false;
    }
    //TODO 要确保下标是非负数
    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    return true;
}

//DeleteD
ElementType Pop(Deque D) {
    if (IsEmpty(D)) {
        return ERROR;
    }
//    todo
    ElementType X = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;
    return X;
}

/**
 * 将元素插入到双端队列D的尾部（其实就是正常的Push操作）
 * @param X
 * @param D
 * @return
 */
//AddD
bool Inject(ElementType X, Deque D) {
    return PushBack(X, D);
}

/**
 * 删除双端队列D的尾部元素，并返回
 * @param D
 * @return
 */
ElementType Eject(Deque D) {
    return PopBack(D);
}

//fixme 20201213 这道题经过 push 3 之后，调用End,打印的确实空的
//todo

bool IsEmpty(Deque D) {
    return D->Front == D->Rear;
}

bool IsFull(Deque D) {
    //TODO P85 判断满了的条件
    return (D->Rear + 1) % D->MaxSize == D->Front;
}

/*
 * 将元素插入到双端队列D的尾部
 */
bool PushBack(ElementType X, Deque D) {
    //TODO P85 判断满了的条件
    if (IsFull(D)) {
        return false;
    }
    //TODO
    D->Data[D->Rear] = X;
    D->Rear = (D->Rear + 1) % D->MaxSize;
    return true;

}

ElementType PopBack(Deque D) {
    if (IsEmpty(D)) {
        return ERROR;
    }
    //TODO 要确保下标是非负数
    D->Rear = (D->Rear - 1 + D->MaxSize) % D->MaxSize;
    ElementType X = D->Data[D->Rear];
    return X;

}