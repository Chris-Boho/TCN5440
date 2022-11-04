#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createNode(int data){
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

List* createList(){
	List* temp = malloc(sizeof(List));
	temp->first = NULL;
	return temp;
}

void clearList(List* list){
	free(list);
	list = NULL; //idk if this is necessary... check later
}

void printList(List* list){
	if(list == NULL){
		printf("List is empty\n");
		return;
	}

	Node* current = list->first;
}

int main(){

	return 0;
}
