#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct List
{
    struct Node *first;
};

typedef struct List List;

Node* createNode(int data);

List* createList();

void clearList(List* list);

void printList(List* list);

void listInsert(List* list, int data);

void listRandInsert(List* list, int amount);

#endif // !LINKEDLIST_H

