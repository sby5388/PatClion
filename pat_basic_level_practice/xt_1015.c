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
#include<string.h>

#define Max 9
#define A 1
#define B 2
#define C 3
#define D 4
#define E 0


//运行超时
typedef struct MAN {
    int id;
    int de;
    int cai;
    int all;
    int type;
} Man;
int low, high;

int showClass(int de, int cai);

int compareMan(Man a, Man b);

int main() {
    //get inputs
    int N;
    scanf("%d %d %d", &N, &low, &high);
    Man mans[N];
    int countPass = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &mans[i].id, &mans[i].de, &mans[i].cai);
        mans[i].all = mans[i].de + mans[i].cai;
        mans[i].type = showClass(mans[i].de, mans[i].cai);
        if (mans[i].type != 0) {
            countPass++;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            Man man1 = mans[i];
            Man man2 = mans[j];
            int result = compareMan(man1, man2);
            if (result > 0) {
                int all = man1.all;
                int cai = man1.cai;
                int de = man1.de;
                int type = man1.type;
                int id = man1.id;

                mans[i].all = man2.all;
                mans[i].id = man2.id;
                mans[i].de = man2.de;
                mans[i].cai = man2.cai;
                mans[i].type = man2.type;

                mans[j].all = all;
                mans[j].id = id;
                mans[j].de = de;
                mans[j].cai = cai;
                mans[j].type = type;
            }
        }
    }

    printf("%d\n", countPass);
    for (int i = 0; i < N; i++) {
        Man man = mans[i];
        if (man.type != 0) {
            printf("%d %d %d\n", mans[i].id, mans[i].de, mans[i].cai);
        }
    }
    return 0;

}

int showClass(int de, int cai) {
    if (de >= low && cai >= low) {
        if (de >= high) {
            return cai >= high ? A : B;
        } else {
            return de >= cai ? C : D;
        }
    } else {
        return E;
    }
}

int compareMan(Man a, Man b) {
    if (a.type != b.type) {
        return a.type - b.type;
    }
    if (a.all != b.all) {
        return b.all - a.all;
    }
    if (a.de != b.de) {
        return b.de - a.de;
    }
    return a.id - b.id;
}
