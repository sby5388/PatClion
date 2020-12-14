//
// Created by Administrator on 2020/12/14.
//
//7-34 通讯录的录入与显示 (10分)
//https://pintia.cn/problem-sets/14/problems/814
#include <stdio.h>
#include <stdlib.h>


struct Node {
    char name[11];
    int yyyy;
    int mm;
    int dd;
    char sex;
    char telephone[16];
    char mobilePhone[16];
};

typedef struct Node *PtrToNode;
typedef PtrToNode Contacts;





int main() {
    int N;
    scanf("%d", N);
    Contacts contacts[N];

    return 0;
}
