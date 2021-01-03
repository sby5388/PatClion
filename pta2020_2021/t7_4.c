//
// Created by Administrator on 2021/1/1.
//
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    //zisheng,0
    //akeb,1
    //bkea,2
    //ashengb,3
    //bshenga,4
    int result[5][5] = {
            0, 1, 3, 2, 4,
            2, 0, 4, 3, 1,
            4, 3, 0, 1, 2,
            1, 4, 2, 0, 3,
            3, 2, 1, 4, 0

    };


    while (N) {
        int a, b;
        scanf("%d %d", &a, &b);
        int i = result[a - 1][b - 1];
        if (i == 1) {
            printf("%d ke %d\n", a, b);
        } else if (i == 2) {
            printf("%d ke %d\n", b, a);
        } else if (i == 3) {
            printf("%d sheng %d\n", a, b);
        }else if(i==4){
            printf("%d sheng %d\n", b, a);
        }
        N--;
    }


    return 0;
}
