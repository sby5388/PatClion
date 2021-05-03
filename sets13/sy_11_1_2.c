//
// Created by Administrator on 2021/5/3.
//

//实验11-1-2 输出月份英文名 (15 分)
//https://pintia.cn/problem-sets/13/problems/589

#include <stdio.h>

char *getmonth(int n);

int main() {
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if (s == NULL) {
        printf("wrong input!\n");
    } else {
        printf("%s\n", s);
    }

    return 0;
}

char *getmonth(int n) {

    char *month[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    if (n >= 1 && n <= 12) {
        return month[n - 1];
    }
    return NULL;
}