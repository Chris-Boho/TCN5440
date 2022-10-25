#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct List {
    struct Node *first;
};

typedef struct List List;

Node *createNode(int data);

List* createList();

void printList(List *list);

void listInsert(List *list, int data);

#endif //LINKEDLIST_H
