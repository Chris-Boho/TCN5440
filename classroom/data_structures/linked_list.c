#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//migtht be Node *createNode(int num);
Node* createNode(int num){
	Node *myNode = malloc(sizeof(Node));
	myNode->data = num;
	myNode->next = NULL;

	return myNode;
}

List* createList() {
	List *newList = malloc(sizeof(List));
	newList->first = NULL;
	return newList;
}

void printList(List* myList){
	if (myList == NULL){
		printf("List is empty.\n");
		return;
	}

	Node* current = myList-> first;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void listInsert(List* myList, int num){
	return;
}


int main(){

	return 0;
}
