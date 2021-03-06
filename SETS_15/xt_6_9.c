//
// Created by Administrator on 2020/12/4.
//

/*
 * 6-9 二叉树的遍历 (25分)
 * https://pintia.cn/problem-sets/15/problems/732
 * 要求给定二叉树的四种遍历
 * TODO 输出是一个空格跟着一个字符
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
    printf(" %c", pNode->Data);
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
    printf(" %c", pNode->Data);
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
    printf(" %c", pNode->Data);
}

//TODO 出现了段错误
//  您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
//对BinTree的引用
typedef struct Node2 *Item;
//todo 新定义的，都出现了编译错误，冲突了，可能需要放在文件开头
struct Node2 {
    Item Next;
    BinTree Data;
};

//队列
typedef struct QNode2 *Queue2;
struct QNode2 {
    Item Front;
    Item Rear;
};

Queue2 CreateQueue2();

void AddQ2(Queue2 queue, Item item);

Item CreateItem(BinTree Data);


/**
 * 层次遍历
 */
void LevelorderTraversal(BinTree BT) {
//    TODO 中序遍历真的有点无从下手
    if (BT == NULL) {
        return;
    }
    BinTree bt = BT;

    Queue2 Q = CreateQueue2();
    AddQ2(Q, CreateItem(bt));

    while (Q->Front) {
        BinTree pNode = Q->Front->Data;
        if (pNode) {
            printf("%c ", pNode->Data);
            if (pNode->Left) {
                AddQ2(Q, CreateItem(bt->Left));
            }
            if (pNode->Right) {
                AddQ2(Q, CreateItem(bt->Right));
            }
        } else {
            break;
        }
        Q->Front = Q->Front->Next;

    }


}

Item CreateItem(BinTree Data) {
    Item item = (Item) malloc(sizeof(struct Node2));
    item->Next = NULL;
    item->Data = Data;
    return item;
}

Queue2 CreateQueue2() {
    Queue2 Q = (Queue2) malloc(sizeof(struct QNode2));
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}

void AddQ2(Queue2 queue, Item item) {
    if (item == NULL) {
        return;
    }

    if (queue->Front == queue->Rear) {
        queue->Front = item;
        queue->Rear->Next = item;
        queue->Rear = queue->Rear->Next;
    } else {
        queue->Rear->Next = item;
        queue->Rear = queue->Rear->Next;
    }
}

//计算树的节点
int getCount(BinTree BT);

void LevelorderTraversal0(BinTree BT) {
    if (!BT) {
        return;
    }
    int count = getCount(BT);
    BinTree trees[count + 1];
    BinTree bt = BT;
    int head = 0;
    int tail = 0;
    trees[0] = bt;
    tail++;
    while (head < tail) {
        BinTree pNode = trees[head];
        if (pNode->Left) {
            trees[tail++] = pNode->Left;
        }
        if (pNode->Right) {
            trees[tail++] = pNode->Right;
        }
        printf(" %c", pNode->Data);
        head++;
    }


}

int getCount(BinTree BT) {
    if (!BT) {
        return 0;
    }
    return getCount(BT->Right) + getCount(BT->Left) + 1;
}
