//
// Created by Administrator on 2020/12/12.
//
//习题9-4 查找书籍 (20分)
//https://pintia.cn/problem-sets/12/problems/346
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
typedef struct Node *PtrToNode;
typedef PtrToNode Book;
struct Node {
    char *name;
    double price;
    Book next;
};

Book CreateBooks();

Book FindMinPrice(Book B);

Book FindMaxPrice(Book B);

void PrintBook(Book B);

int main() {
    Book books;
    Book min;
    Book max;
    books = CreateBooks();
    min = FindMinPrice(books);
    max = FindMaxPrice(books);
    PrintBook(max);
    PrintBook(min);

    return 0;
}

Book CreateBooks() {
    Book b = (Book) malloc(sizeof(struct Node));
    b->name = (char *) malloc(sizeof(char) * MAX);
    b->next = NULL;
    Book pTail = b;
    int N;
    scanf("%d", &N);

    while (N > 0) {
        Book pNode = (Book) malloc(sizeof(struct Node));
        pNode->name = (char *) malloc(sizeof(char) * MAX);
        pNode->next = NULL;
//        todo 这是什么鬼：等到回车键时，才结束
        getchar();
        gets(pNode->name);
        scanf("%lf", &pNode->price);

        pTail->next = pNode;
        pTail = pTail->next;
        N--;
    }
    return b;

}

Book FindMinPrice(Book B) {
    Book pNode = B;
    Book pTail = pNode->next;
    Book min = pNode->next;
    while (pTail) {
        if (pTail->price < min->price) {
            min = pTail;
        }
        pTail = pTail->next;
    }
    return min;
}

Book FindMaxPrice(Book B) {
    Book pNode = B;
    Book pTail = pNode->next;
    Book max = pNode->next;
    while (pTail) {
        if (pTail->price > max->price) {
            max = pTail;
        }
        pTail = pTail->next;
    }
    return max;
}

void PrintBook(Book B) {
    if (B) {
        printf("%.2f, %s\n", B->price, B->name);
    }
}
