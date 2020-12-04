//
// Created by Administrator on 2020/6/27.
//

/**
 * 习题3.3 线性表元素的区间删除 (20分)
 * 给定一个顺序存储的的线性表，请设计一个函数删除所有值大于min
 * 而且小于max的元素。
 * 删除后表中剩余元素保持顺序存储，且相对位置不能改变。
 * 函数接口定义：
 * List Delete(List L, ElementType minD, ElementType maxD);
 * 其中List结构定义如下：
 * typedef int ElementType;
 * typedef int Position;
 * typedef struct LNode *List;
 *
 * struct LNode {
 *  ElementType Data[MAXSIZE];
 *  Position Last;
 * };
 *
 * L是用户传入的一个线性表，
 * 其中ElementType元素可以通过>、==、<进行比较；
 * minD和maxD分别为待删除元素的值域的下、上界。
 * 函数Delete应将Data[]中所有值大于minD而且小于maxD的元素删除，
 * 同时保证表中剩余元素保持顺序存储，
 * 并且相对位置不变，最后返回删除后的表。
 *
 * 输入样例：
 * 10
 * 4 -8 2 12 1 5 9 3 3 10
 * 0 4
 * 输出样例：
 * 4 -8 12 5 9 10
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;

struct LNode {
    ElementType Data[MAXSIZE];
    //保存线性表中最后一个元素的位置
    Position Last;
};

/**
 * 获取输入
 * @return
 */
List ReadInput();

/**
 * 打印
 * @param L
 */
void PrintList(List L);

/**
 * 删除指定大小范围内的元素，且删除后的元素依然保持有序
 * @param L 线性表
 * @param minD  下边界，不包括
 * @param maxD  上边界，不包括
 * @return L
 */
List Delete(List L, ElementType minD, ElementType maxD);

int main() {
    List L;
    ElementType min;
    ElementType max;
    //int i;

    L = ReadInput();
    PrintList(L);

    scanf("%d %d", &min, &max);
    L = Delete(L, min, max);
    PrintList(L);

    return 0;
}


List ReadInput() {
    int N;
    List L = (List) malloc(sizeof(struct LNode));
    L->Last = 0;
    int index = 0;

    scanf("%d", &N);
    if (N < MAXSIZE) {
        L->Last = N;
    }
    while (index < N) {
        scanf("%d", &L->Data[index]);
        index++;
    }
    return L;
}

void PrintList(List L) {
    if (L == NULL) {
        return;
    }
    int index = 0;
    while (index < L->Last) {
        printf("%d ", L->Data[index]);
        index++;
    }
    printf("\n");
}

// 最笨的办法
//todo 测试用例4 失败了：运行超时
//  大规模数据，隔位删除，卡n平方算法
List Delete3(List L, ElementType minD, ElementType maxD) {
    if (L == NULL) {
        return L;
    }
    if (L->Last > MAXSIZE) {
//        return L;
        L->Last = MAXSIZE;
    }
    int index = 0;
    while (index <= L->Last && index <= MAXSIZE) {
        ElementType X = L->Data[index];
        if (X > minD && X < maxD) {
            //满足条件时：删除X，并移动后面的元素，Last--
            for (int i = index; i < L->Last; i++) {
                L->Data[i] = L->Data[i + 1];
            }
            L->Last--;
        } else {
            //不满足时 进入下一个
            index++;
        }

    }
    return L;
}

//别人的实现，参考
List Delete2(List L, ElementType minD, ElementType maxD) {
    int num = 0;
    for (int j = 0; j <= (L->Last); j++) {
        if (L->Data[j] <= minD || L->Data[j] >= maxD) {
            L->Data[num++] = L->Data[j];
        }
    }
    L->Last = num - 1;
    return L;
}
//————————————————
//版权声明：本文为CSDN博主「你好我叫椰子」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/c13868303523/article/details/104216991

//todo 优点是只循环一次
List Delete(List L, ElementType minD, ElementType maxD) {
    if (L == NULL) {
        return L;
    }
    int m = 0;
//    todo 注意是 <=
    for (int i = 0; i <= L->Last; i++) {
        ElementType X = L->Data[i];
        if (X <= minD || X >= maxD) {
            L->Data[m] = X;
            m++;
        }
    }
    //todo 长度+1
    L->Last = m + 1;
    return L;
}

