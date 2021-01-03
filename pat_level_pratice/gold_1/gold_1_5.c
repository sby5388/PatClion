//
// Created by Administrator on 2021/1/2.
//
//7-5 一帮一 (15分)
//https://pintia.cn/problem-sets/1146682720562929664/problems/1146697022086799360


#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 9


typedef struct LNode *Student;
struct LNode {
    //0:girl,1:boy
    int Sex;

    char Name[MAXSIZE];

    int Match;
};

int main() {
    int N;
    scanf("%d", &N);
    Student List[N];
    for (int i = 0; i < N; ++i) {
        Student pNode = (Student) malloc(sizeof(struct LNode));
        scanf("%d %s", &pNode->Sex, pNode->Name);
        pNode->Match = 0;

        List[i] = pNode;
    }

    int middle = N / 2;
    for (int j = 0; j < middle; ++j) {
        Student first = List[j];
        int k;
        for (k = N - 1; k > middle; k--) {
            Student last = List[k];
            if (!last->Match && last->Sex != first->Sex) {
                break;
            }
        }
        first->Match = 1;
        Student last = List[k];
        last->Match = 1;
        printf("%s %s\n", first->Name, last->Name);

    }


    return 0;
}
