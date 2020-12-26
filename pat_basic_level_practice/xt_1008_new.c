//
// Created by Administrator on 2020/12/24.
//
//1009 说反话 (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960

#include <stdio.h>
#include <string.h>

#include <stdlib.h>

#define MAX 81
#define TEST 0

typedef char *ElementType;

typedef struct LNode2 *Word;
struct LNode2 {
    ElementType X;
    Word Next;
};


int main() {
    Word pHead = (Word) malloc(sizeof(struct LNode2));
    pHead->X = NULL;
    pHead->Next = NULL;

    char word[80];
    scanf("%s", word);
    //TODO 如何判断输入的结束
    while (strlen(word) != 0) {
        Word node = (Word) malloc(sizeof(struct LNode2));
        node->X = NULL;
        node->Next = NULL;
        strcpy(node->X, word);

        if (pHead->Next != NULL) {
            node->Next = pHead->Next;
            pHead->Next = node;
        } else {
            pHead->Next = node;
        }
        scanf("%s", word);
    }


    while (pHead->Next) {
        Word pNode = pHead->Next;
        printf("%s", pNode->X);
        printf(" ");
        pHead->Next = pNode->Next;

        free(pNode->X);
        free(pNode);
    }


    return 0;

}