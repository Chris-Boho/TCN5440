#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

struct List
{
    struct Node* first;
    struct Node* last;
};

typedef struct List List;

Node* createNode(int data);

List* createList();

Node* front(List* list);

// void clearList(List* list);

void printList(List* list);

Node* indexInsert(List* list, int index, int data);

void listInsert(List* list, int data);

void listRandInsert(List* list, int amount);

int myRemove(List* list, int index);

void searchForward(List* list, int value);

void searchBackward(List* list, int value);

#endif // !LINKEDLIST_H

