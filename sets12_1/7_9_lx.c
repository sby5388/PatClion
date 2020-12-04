/*
练习7-9 计算天数 （15 分）
本题要求编写程序计算某年某月某日是该年中的第几天。

输入格式:
输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。
注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。

输出格式:
在一行输出日期是该年中的第几天。

输入样例1:
2009/03/02
输出样例1:
61
输入样例2:
2000/03/02
输出样例2:
62
鸣谢湖北汽车工业学院袁科老师补充数据
*/
#include<stdio.h>

int isLoopYear(int year);

int day_of_year(int year, int month, int day);

int main() {
    int yyyy, mm, dd;
    scanf("%d/%d/%d", &yyyy, &mm, &dd);

    printf("%d", day_of_year(yyyy, mm, dd));

    return 0;
}

int day_of_year(int year, int month, int day) {
    int sum = 0;
    int days[12] = {31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31
    };
    if (isLoopYear(year) == 1) {
        days[1] = 29;
    }
    for (int i = 0; i < month - 1; i++) {
        sum += days[i];
    }
    sum += day;
    return sum;

}

int isLoopYear(int year) {
    if (year % 4 != 0) {
        return 0;
    }
    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}

