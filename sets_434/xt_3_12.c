//
// Created by Administrator on 2020/12/8.
//
//习题3.12 另类循环队列 (20分)
//https://pintia.cn/problem-sets/434/problems/6085

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

typedef int ElementType;
typedef int Position;
struct QNode {
    //TODO 相当于一个 ElementType Data[];
    /* 存储元素的数组   */
    ElementType *Data;
    /* 队列的头指针     */
    Position Front;
    /* 队列中元素个数   */
    int Count;
    /* 队列最大容量     */
    int MaxSize;
};
typedef struct QNode *PtrToQNode;
typedef PtrToQNode Queue;

typedef enum {
    addq, delq, end
} Operation;

typedef enum {
    false, true
} bool;

//队列的入队操作
bool AddQ(Queue Q, ElementType X);

//队列的出队操作
ElementType DeleteQ(Queue Q);

Queue CreateQueue(int MaxSize);

Operation getOp();

int main() {
    ElementType X;
    Queue Q;
    int N;
    int done = 0;

    scanf("%d", &N);
    Q = CreateQueue(N);
    while (!done) {
        switch (getOp()) {
            case addq:
                scanf("%d", &X);
                AddQ(Q, X);
                break;
            case delq:
                X = DeleteQ(Q);
                if (X != ERROR) {
                    printf("%d is out\n", X);
                }
                break;
            case end:
                while (Q->Count) {
                    printf("%d ", DeleteQ(Q));
                }
                done = 1;
                break;
        }
    }
    return 0;
}

Queue CreateQueue(int MaxSize) {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    //数组部分也要申请空间
    Q->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    Q->Count = 0;
    Q->Front = 0;
    Q->MaxSize = MaxSize;
    return Q;
}


Operation getOp(){
    char Del[] = "Del";
    char Add[] = "Add";
    char End[] = "End";
    char s[100];
    scanf("%s", s);
    if (strcmp(Del, s) == 0) {
        return delq;
    }
    if (strcmp(Add, s) == 0) {
        return addq;
    }
    if (strcmp(End, s) == 0) {
        return end;
    }
    return end;
}


bool AddQ(Queue Q, ElementType X) {
    if (Q->Count == Q->MaxSize) {
        printf("Queue Full\n");
        return false;
    }
    Position i = Q->Front + Q->Count;
    if (i >= Q->MaxSize) {
        i = i - Q->MaxSize;
    }
    Q->Data[i] = X;
    Q->Count++;
    return true;

}

ElementType DeleteQ(Queue Q) {
    if (Q->Count == 0) {
        printf("Queue Empty\n");
        return ERROR;
    }

    ElementType X = Q->Data[Q->Front];
    Q->Front++;
    if (Q->Front == Q->MaxSize) {
        Q->Front = 0;
    }
    Q->Count--;
    return X;

}