//
// Created by Administrator on 2020/12/4.
//

/*
 * 6-9 二叉树的遍历 (25分)
 * https://pintia.cn/problem-sets/15/problems/732
 * 要求给定二叉树的四种遍历
 */

#include <stdlib.h>
#include <stdio.h>

typedef char ElementData;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementData Data;
    BinTree Left;
    BinTree Right;
};

/**
 * 创建二叉树(实现细节忽略)
 */
BinTree CreateBinTree();

/**
 * 中序遍历
 */
void InorderTraversal(BinTree BT);

/**
 * 前序遍历
 */
void PreorderTraversal(BinTree BT);

/**
 * 后序遍历
 */
void PostorderTraversal(BinTree BT);

/**
 * 层次遍历
 */
void LevelorderTraversal(BinTree BT);


int main() {
    BinTree BT = CreateBinTree();

    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");

    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");

    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");

    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

/**
 * 创建二叉树(实现细节忽略)
 */
BinTree CreateBinTree() {
//    TODO 如何创建一个二叉树
}

/**
 * 中序遍历
 */
void InorderTraversal(BinTree BT) {
    if (BT == NULL) {
        return;
    }
    BinTree pNode = BT;
    if (pNode->Left) {
        InorderTraversal(pNode->Left);
    }
    printf("%c ", pNode->Data);
    if (pNode->Right) {
        InorderTraversal(pNode->Right);
    }
}

/**
 * 前序遍历
 */
void PreorderTraversal(BinTree BT) {
    if (BT == NULL) {
        return;
    }
    BinTree pNode = BT;
    printf("%c ", pNode->Data);
    if (pNode->Left) {
        PreorderTraversal(pNode->Left);
    }
    if (pNode->Right) {
        PreorderTraversal(pNode->Right);
    }
}

/**
 * 后序遍历
 */
void PostorderTraversal(BinTree BT) {
    if (BT == NULL) {
        return;
    }

    BinTree pNode = BT;
    if (pNode->Left) {
        PostorderTraversal(pNode->Left);
    }
    if (pNode->Right) {
        PostorderTraversal(pNode->Right);
    }
    printf("%c ", pNode->Data);


}
//对BinTree的引用
typedef struct Node *Item;

struct Node {
    Item Next;
    BinTree Data;
};

//队列
typedef struct QNode *Queue;
struct QNode {
    Item Front;
    Item Rear;
};

Queue CreateQueue();

Queue AddQ(Item item);


/**
 * 层次遍历
 */
void LevelorderTraversal(BinTree BT) {
//    TODO 中序遍历真的有点无从下手
    if (BT == NULL) {
        return;
    }
    BinTree bt = BT;


    Queue Q = CreateQueue();


    while (bt) {

    }


}

Queue CreateQueue() {
    Queue Q = (Queue) malloc(sizeof(struct QNode));
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}
