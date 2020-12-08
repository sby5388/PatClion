//
// Created by Administrator on 2020/12/7.
//
//6-12 二叉搜索树的操作集 (30分)
//https://pintia.cn/problem-sets/15/problems/927
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/**
 * 先序遍历，由裁判实现，细节不表
 * @param BT
 */
void PreorderTraversal(BinTree BT);

/**
 * 中序遍历，由裁判实现，细节不表
 * @param BT
 */
void InorderTraversal(BinTree BT);

/*
 * 函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
 */
BinTree Insert(BinTree BST, ElementType X);

/*
 * 函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；
 * 如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
 */
BinTree Delete(BinTree BST, ElementType X);

/*
 * 函数Find在二叉搜索树BST中找到X，返回该结点的指针；
 * 如果找不到则返回空指针；
 */
BinTree Find(BinTree BST, ElementType X);

/*
 * 返回二叉搜索树BST中最小元结点的指针；
 */
BinTree FindMin(BinTree BST);

/*
 * 返回二叉搜索树BST中最大元结点的指针。
 */
BinTree FindMax(BinTree BST);


int main() {
    BinTree BST;
    BinTree MinP;
    BinTree MaxP;
    BinTree Tmp;
    ElementType X;
    int N;
    int i;


    BST = NULL;
    scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }


    return 0;
}


BinTree Insert(BinTree BST, ElementType X) {
    BinTree binTree = (BinTree) malloc(sizeof(struct TNode));
    binTree->Right = NULL;
    binTree->Left = NULL;
    binTree->Data = X;
    if (BST) {


    } else {
        BST = binTree;
    }
    return BST;


}

//todo 删除之后，树的形状要发生改变
BinTree Delete(BinTree BST, ElementType X) {
    BinTree pNode = BST;
//    if (!pNode) {
//        printf("Not Found\n");
//
//    }
    while (pNode) {

    }

}

BinTree Find(BinTree BST, ElementType X) {

    BinTree pNode = BST;
    if (!pNode) {
        return NULL;
    }

    if (pNode->Data == X) {
        return pNode;
    }
    if (X > pNode->Data) {
        return Find(BST->Right, X);
    }
    if (X < pNode->Data) {
        return Find(BST->Left, X);
    }
    return NULL;
}

BinTree FindMin(BinTree BST) {
    //最左边的
    BinTree pNode = BST;
    while (pNode->Left) {
        pNode = pNode->Left;
    }
    return pNode;

}

BinTree FindMax(BinTree BST) {
    //最右边的
    BinTree pNode = BST;
    while (pNode->Right) {
        pNode = pNode->Right;
    }
    return pNode;

}