#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// #include <stdio.h>
// #include <stdlib.h>

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

struct Stack
{
    Node* top;
};

typedef struct Stack Stack;

struct Queue
{
    Node* front;
    Node* back;
};

typedef struct Queue Queue;



Node* createNode(int data);

Node* front(List* list);



List* createList();

void clearList(List* list);

void printList(List* list);

Node* indexInsert(List* list, int index, int data);

void listInsert(List* list, int data);

void listRandInsert(List* list, int amount);

int myRemove(List* list, int index);

void searchForward(List* list, int value);

void searchBackward(List* list, int value);



Stack* createStack();

void printStack(Stack* stack);

void push(Stack* stack, int value);

int pop(Stack* stack);



Queue* createQueue();

void printQueue(Queue* queue);

void enqueue(Queue* queue, int vlaue);

int dequeue(Queue* queue);

#endif // !LINKEDLIST_H

