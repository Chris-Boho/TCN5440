#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

Node* front(List* list){
	return list->first;
}

Node* indexInsert(List* list, int index, int data){

	if (list == NULL)
	{
		printf("List is empty!\n");
		return NULL;
	}
	
	int count = 0;
	Node* new = createNode(data);
	Node* current = list->first;
	Node* prev = NULL; 
			
	if (current == NULL && index == 0)
	{
		list->first = createNode(data);
	} else {
		while (current->next != NULL && count != index) {
			prev = current;
            current = current->next;
			count++;
        }
		if (count == index){
			prev->next = new;
			new->next = current;
		}else{
			printf("Out of bounds!\n");
			return NULL;
		}
			
		
	}
	
	return new;
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

void listRandInsert(List* list, int amount){

	if (list == NULL)
	{
		printf("List is empty!\n");
		return;
	}

	for (int i = 0; i < amount; i++)
	{
		int rand_num = rand() % 50 + 1;
		listInsert(list, rand_num);
	}
	
}

// void clearList(List* list){
// 	free(list);
// 	list = NULL; //idk if this is necessary... check later
// }

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

int main(){
	srand(time(NULL));

	List* derp = createList();
	listRandInsert(derp, 5);
	indexInsert(derp, 8, 124);

	printList(derp);

	return 0;
}
