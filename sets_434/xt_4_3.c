//
// Created by Administrator on 2020/12/17.
//
//习题4.3 是否二叉搜索树 (25分)
//https://pintia.cn/problem-sets/434/problems/6178

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

bool IsBST(BinTree T);

/* 由裁判实现，细节不表 */
BinTree BuildTree();

int main() {
    BinTree T;
    T = BuildTree();
    if (IsBST(T)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}


BinTree BuildTree() {
//    todo 由系统实现
}

/* 你的代码将被嵌在这里 */
//TODO 这里出错了，仅仅判断了根节点与直接左右子树的值的关系，没有判断子孙子树的大小关系
//fixme
bool IsBST(BinTree T) {
    if (!T) {
        return true;
    }
    if (T->Left && T->Right) {
        return (T->Data > T->Left->Data) && (T->Data < T->Right->Data) && IsBST(T->Left) && IsBST(T->Right);
    } else if (T->Left) {
        return T->Data > T->Left->Data && IsBST(T->Left);
    } else if (T->Right) {
        return T->Data < T->Right->Data && IsBST(T->Right);
    }
    return true;
}