//
// Created by Administrator on 2020/12/26.
//
//1028 人口普查 (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805293282607104

/*
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——
假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，
所以超过 200 岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数 N，取值在(0,10^5]；
随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、
以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20140906
#define MIN 18140906
#define MAX_LENGTH 6


typedef struct LNode2 *Man;

struct LNode2 {
    char Name[MAX_LENGTH];
    int year;
    int mm;
    int dd;
    long birthday;
    int Legal;
    Man Next;
};

Man CreateMan(int N);

Man FindMin(Man List);

Man FindMax(Man List);

int GetCount(Man List);

int main() {
    int N;
    scanf("%d", &N);
    Man List = CreateMan(N);

    Man max = FindMax(List);
    Man min = FindMin(List);
    int count = GetCount(List);

    printf("%d %s %s", count, max->Name, min->Name);
    return 0;
}


Man CreateMan(int N) {
    Man pHead = (Man) malloc(sizeof(struct LNode2));
    pHead->Next = NULL;
    Man pTail = pHead;


    while (N) {
        Man pNode = (Man) malloc(sizeof(struct LNode2));
        pNode->Next = NULL;
        char name[MAX_LENGTH];
        scanf("%s %d/%d/%d", name, &pNode->year, &pNode->mm, &pNode->dd);
        strcpy(pNode->Name, name);

        pNode->birthday = pNode->year * 10000 + pNode->mm * 100 + pNode->dd;
        pNode->Legal = pNode->birthday <= MAX && pNode->birthday >= MIN;
        if (pNode->Legal) {
            pTail->Next = pNode;
            pTail = pTail->Next;
        }
        N--;
    }
    return pHead;
}

Man FindMin(Man List) {
    if (List == NULL) {
        return NULL;
    }
    Man pNode = List->Next;
    Man min = pNode;
    Man next = pNode->Next;
    while (next) {
        if (next->birthday > min->birthday) {
            min = next;
        }
        next = next->Next;
    }
    return min;
}

Man FindMax(Man List) {
    if (List == NULL) {
        return NULL;
    }
    Man pNode = List->Next;
    Man max = pNode;
    Man next = pNode->Next;
    while (next) {
        if (next->birthday < max->birthday) {
            max = next;
        }
        next = next->Next;
    }
    return max;
}

int GetCount(Man List) {
    int Count = 0;
    Man pNode = List->Next;
    while (pNode) {
        Count++;
        pNode = pNode->Next;
    }
    return Count;
}