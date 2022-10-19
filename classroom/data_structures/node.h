#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#endif

struct Node {
	int data;
	struct Node *next;
};

typedef struct Node Node;

struct List {
	struct Node *first;
};

typedef struct List List;

Node* createNode(int num);

List* createList();

void printList(List* myList);

void listInsert(List* myList, int num);
