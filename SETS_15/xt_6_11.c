//
// Created by Administrator on 2020/12/7.
//
//6-11 先序输出叶结点 (15分)
//https://pintia.cn/problem-sets/15/problems/925
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/**
 * 实现细节忽略
 * @return
 */
BinTree CreateBinTree();

/**
 * 先序输出叶结点
 * @param BT
 */
void PreorderPrintLeaves(BinTree BT);

int main() {
    BinTree BT = CreateBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    return 0;
}

BinTree CreateBinTree() {
//    todo 未实现
}

void PreorderPrintLeaves(BinTree BT) {
    if (!BT) {
        return;
    }
    if (BT->Left || BT->Right) {
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    } else {
        printf(" %c", BT->Data);
    }
}