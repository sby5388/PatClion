/**
 * 6-8 求二叉树的高度
 * https://pintia.cn/problem-sets/15/problems/731
 */
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
 * 返回给定二叉树BT的高度值。
 * @param BT
 * @return
 */
int GetHeight(BinTree BT);

/**
 * 创建一棵二叉树
 * @return 
 */
BinTree CreateBinTree();

int main() {
    BinTree BT = CreateBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

BinTree CreateBinTree() {
//    todo 如何创建一个树，要根据输入来确定

}

int GetHeight(BinTree BT) {
    if (BT == NULL) {
        return 0;
    }
    int heightLeft = GetHeight(BT->Left);
    int heightRight = GetHeight(BT->Right);
    return heightLeft >= heightRight ? heightLeft + 1 : heightRight + 1;
}