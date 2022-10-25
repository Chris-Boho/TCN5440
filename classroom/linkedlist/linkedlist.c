#include "linkedlist.h"

Node *createNode(int data) {
    Node *ret = (Node*) malloc(sizeof(Node));
    ret->data = data;
    ret->next = NULL;
    return ret;
}

List *createList() {
    List *newList = (List*) malloc(sizeof(List));
    newList->first = NULL;
    return newList;
}

void printList(List *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = list->first;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void listInsert(List *list, int data) {
    if (list == NULL) {
        printf("listInsert: List is empty.\n");
        return;
    }
    Node *current = list->first;
    if (current == NULL) 
        list->first = createNode(data);
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(data);
    }
}


