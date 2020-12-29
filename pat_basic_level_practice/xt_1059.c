//
// Created by Administrator on 2020/12/28.
//
//1059 C语言竞赛 (20分)
//https://pintia.cn/problem-sets/994805260223102976/problems/994805269828059136

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ERROR NULL
#define FIRST 1
#define CHECK_ID -1


typedef struct LNode *Student;
struct LNode {
    int index;
    int id;
    Student Next;
};
typedef enum {
    false, true
} bool;

bool isPrime(int number);

Student CreateList(int N);

Student Find(Student List, int id);

int zhishu(int zs);


int main() {
    int N;
    int M;
    int Id;
    scanf("%d", &N);
    if (N <= 0 || N >= 10000) {
        return 0;
    }

    Student List = CreateList(N);
    scanf("%d", &M);


    for (int k = 0; k < M; ++k) {
        scanf("%d", &Id);
        Student pNode = Find(List, Id);
        if (pNode == ERROR) {
            printf("%d: Are you kidding?\n", Id);
        } else {
            if (pNode->index == CHECK_ID) {
                //已经领过奖
                printf("%04d: Checked\n", Id);
            } else {
                if (pNode->index == FIRST) {
                    printf("%04d: Mystery Award\n", Id);
                } else if (isPrime(pNode->index)) {
                    printf("%04d: Minion\n", Id);
                } else {
                    printf("%04d: Chocolate\n", Id);
                }
                pNode->index = CHECK_ID;
            }
        }

    }
    return 0;

}

int main2() {
    int N;
    scanf("%d", &N);

    int s1[N];
    int chaxun[N];
    char c1[N][5];
    for (int i = 0; i < N; i++) {
        s1[i] = 0;
        chaxun[i] = 0;//是否查询：0未查询，1已查询
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", c1[i]);
    }
    //转化成十进制的逆序数
    for (int i = 0; i < N; i++) {
        int sum = 0;
        int l = strlen(c1[i]);
        for (int j = 0; j < l; j++) {
            sum = sum * 10 + (c1[i][j] - '0');
        }
        s1[i] = sum;
    }

    ///查询部分
    int m = 0;
    scanf("%d", &m);
    int s2[m];
    char c2[m][5];
    for (int i = 0; i < m; i++) {
        s2[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", &c2[i]);
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        int l = strlen(c2[i]);
        for (int j = 0; j < l; j++) {
            sum = sum * 10 + (c2[i][j] - '0');
        }
        s2[i] = sum;
    }
    //开始判断

    for (int i = 0; i < m; i++) {
        int zzz = 0;
        for (int j = 0; j < N; j++) {
            if (s2[i] == s1[j]) {
                zzz = 1;
                if (chaxun[j] == 0) {
                    if (j == 0) {
                        printf("%s: Mystery Award\n", c2[i]);
                    } else {
                        if (zhishu(j) == 1) {
                            printf("%s: Minion\n", c2[i]);
                        } else {
                            printf("%s: Chocolate\n", c2[i]);
                        }
                    }
                    chaxun[j] = 1;
                } else {
                    printf("%s: Checked\n", c2[i]);
                }
            }
        }
        if (zzz == 0) {
            printf("%s: Are you kidding?\n", c2[i]);
        }
    }

    return 0;
}

int zhishu(int zs) {
    int r = 1;
    if (zs == 1) {
        r = 0;
    } else {
        for (int i = 2; i < zs; i++) {
            if (zs % i == 0) {
                r = 0;
                break;
            }
        }
    }
    return r;
}

Student CreateList(int N) {
    int i = FIRST;
    Student List = (Student) malloc(sizeof(struct LNode));
    List->Next = NULL;
    Student pTail = List;
    while (i <= N) {
        Student pNode = (Student) malloc(sizeof(struct LNode));
        pNode->Next = NULL;
        pNode->index = i;
        scanf("%d", &(pNode->id));
        pTail->Next = pNode;
        pTail = pTail->Next;
        i++;
    }
    return List;
}

Student Find(Student List, int id) {
    if (List == NULL) {
        return ERROR;
    }
    Student next = List->Next;
    while (next) {
        if (next->id == id) {
            return next;
        }
        next = next->Next;
    }
    return ERROR;
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number > 2) {
        if (number % 2 == 0) {
            return false;
        }
    }
    int max = (int) sqrt(number);
    for (int i = 3; i <= max; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;


}