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

    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");

    MinP = FindMin(BST);
    MaxP = FindMax(BST);


    scanf("%d", &N);

    for (i = 0; i < N; ++i) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) {
            printf("%d is not found\n", X);
        } else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP) {
                printf("%d is the smallest key\n", Tmp->Data);
            }
            if (Tmp == MaxP) {
                printf("%d is the largest key\n", Tmp->Data);
            }
        }
    }

    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }

    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}


void PreorderTraversal(BinTree BT) {
    if (BT) {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal(BinTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}

/* 你的代码将被嵌在这里 */

BinTree Insert(BinTree BST, ElementType X) {
    BinTree binTree = (BinTree) malloc(sizeof(struct TNode));
    binTree->Right = NULL;
    binTree->Left = NULL;
    binTree->Data = X;
    if (BST) {
        BinTree B = BST;
        while (B) {
            if (X > B->Data) {
                if (B->Right) {
                    B = B->Right;
                } else {
                    B->Right = binTree;
                    break;
                }
            } else if (X < B->Data) {
                if (B->Left) {
                    B = B->Left;
                } else {
                    B->Left = binTree;
                }
            } else {
                //理论上这种事不允许存在二叉树里面的
                break;
            }
        }

    } else {
        BST = binTree;
    }
    return BST;


}

//todo 删除之后，树的形状要发生改变
//fixme 我还不会
//四种情况，1,找不到，无法删除，
//2找到了，且没有左右孩子树
//3.找到了只有一个孩子树
//4.找到了，左右孩子树都有
BinTree Delete(BinTree BST, ElementType X) {

    BinTree deleteNode = Find(BST, X);
    if (deleteNode == NULL) {
        printf("Not Found\n");
        return BST;
    }
    BinTree pNode = BST;



    //删除之后，并不会
    return BST;

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
        return Find(pNode->Right, X);
    }
    if (X < pNode->Data) {
        return Find(pNode->Left, X);
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

