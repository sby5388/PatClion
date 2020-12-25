//
// Created by Administrator on 2020/12/24.
//

#include <stdio.h>
#include <string.h>

int main() {
    char work[80];
//    scanf("%s",work);
    gets(work);
    strlen(work);
    printf("work = %s\n", work);

    return 0;
}