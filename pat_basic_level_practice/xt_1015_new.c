//
// Created by Administrator on 2020/12/25.
//

/*
输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；
L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，
考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，
按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Test 0

static int Min;
static int Max;


typedef enum {
    A, B, C, D, E
} SType;

typedef enum {
    false, true
} bool;

typedef struct Node *Student;
struct Node {
    int Id;
    int De;
    int Cai;
    int All;
    long Total;
    SType type;

    Student Next;
};

Student CreateStudentList(int N);

//a是否大于b,靠得前
bool compareStudent(Student a, Student b);


SType getType(int de, int cai);

void InsertStudent(Student List, Student student);

void PrintStudent(Student student);


int main() {
    //printf("%d %d %d %d %d\n", A, B, C, D, E);
    int N;
    scanf("%d %d %d", &N, &Min, &Max);
    Student student = CreateStudentList(N);
    Student pHead = student;
    int count = 0;
    while (pHead->Next) {
        count++;
        pHead = pHead->Next;
    }

    printf("%d\n", count);

    PrintStudent(student);

    return 0;

}

void PrintStudent(Student student) {
    if (student == NULL) {
        return;
    }
    Student next = student->Next;
    while (next) {
        printf("%d %d %d\n", next->Id, next->De, next->Cai);
        next = next->Next;
    }
}

Student CreateStudentList(int N) {
    Student pHead = (Student) malloc(sizeof(struct Node));
    pHead->Next = NULL;
    Student pTail = pHead;
    while (N) {
        Student pNode = (Student) malloc(sizeof(struct Node));
        pNode->Next = NULL;
        scanf("%d %d %d", &pNode->Id, &pNode->De, &pNode->Cai);
        pNode->All = pNode->Cai + pNode->De;
        pNode->type = getType(pNode->De, pNode->Cai);
//        pNode->Total = pNode->Cai * 1
//                       + pNode->De * 1000
//                       + pNode->All * 1000 * 1000
//                       + pNode->type * 1000 * 1000 * 1000;


        //不合格的过滤掉
        if (pNode->type > A) {
            InsertStudent(pTail, pNode);
        }
        N--;
    }
    return pHead;
}

SType getType(int de, int cai) {
    if (de < Min || cai < Min) {
        //不及格
        return A;
    }

    if (de >= Max) {
        if (cai >= Max) {
            //才德全尽
            return E;
        } else {
            //德胜才
            return D;
        }
    }
    //de<Max && de >= Min
    if (cai > de) {
        //才德兼亡
        return C;
    }
    //及格
    return B;
}


//a是否大于b，靠得前
bool compareStudent0(Student a, Student b) {
    if (a->Total != b->Total) {
        return a->Total > b->Total;
    }
    return a->Id < b->Id;
}

bool compareStudent(Student a, Student b) {
    //


    if (a != NULL && b != NULL) {
        //printf("%d %d %d %d %d\n", a->type, a->All, a->De, a->Cai, a->Id);
        //printf("%d %d %d %d %d\n", b->type, b->All, b->De, b->Cai, b->Id);

        if (a->type != b->type) {
            return a->type > b->type;
        }
        if (a->All != b->All) {
            //printf("%d %d All\n", a->Id, b->Id);
            return a->All > b->All;
        }
        if (a->De != b->De) {
            //printf("%d %d De\n", a->Id, b->Id);
            return a->De > b->De;
        }
        //printf("%d %d id\n", a->Id, b->Id);
        return a->Id < b->Id;

    }


    return true;
}


/**
 * 带头结点
 * @param List
 * @param student
 */
void InsertStudent(Student List, Student student) {
    if (List == NULL || student == NULL) {
        return;
    }
    if (List->Next == NULL) {
        List->Next = student;
        return;
    }
    Student pHead = List;
    //头部
    if (compareStudent(student, pHead->Next)) {
        student->Next = pHead->Next->Next;
        pHead->Next = student;
        return;
    }
    while (pHead->Next && compareStudent(pHead->Next, student)) {
        if (pHead->Next->Next) {
            if (compareStudent(student, pHead->Next->Next)) {
                student->Next = pHead->Next->Next;
                pHead->Next->Next = student;
                break;
            } else {
                pHead = pHead->Next;
            }
        }
    }


}


void InsertStudent0(Student List, Student student) {
//    printf("insert**\n");
    if (List == NULL || student == NULL) {
        return;
    }
    if (List->Next == NULL) {
        List->Next = student;
    } else {
        if (Test) {
            Student pNode = List;
            while (pNode->Next) {
                pNode = pNode->Next;
            }
            pNode->Next = student;
        } else {


            Student pHead = List;

            while (pHead->Next) {
                bool insert = compareStudent(pHead->Next, student);
                printf("insert = %d\n", insert);
                if (insert) {
                    bool insert2 = compareStudent(student, pHead->Next->Next);
                    printf("insert2 = %d\n", insert2);
                    if (insert2) {
                        student->Next = pHead->Next->Next;
                        pHead->Next = student;
                        break;
                    } else {
                        pHead = pHead->Next;
                    }
                } else {
                    student->Next = pHead->Next;
                    pHead->Next = student;
                    break;
                }
            }
        }
    }
    printf("after insert\n");
    PrintStudent(List);
}