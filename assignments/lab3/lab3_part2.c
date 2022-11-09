#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

//Doubly linked list needs a node pointer to the next node and the previous node
Node* createNode(int data){
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

//List that has node pointers to the first and last nodes
List* createList(){
	List* temp = malloc(sizeof(List));
	temp->first = NULL;
	temp->last = NULL;
	return temp;
}

Node* front(List* list){
	return list->first;
}

//Insert data at a certain index in the list
Node* indexInsert(List* list, int index, int data){

	if (list == NULL)
	{
		printf("List is empty!\n");
		return NULL;
	}
	
	int count = 0;
	Node* new = createNode(data);
	Node* current = list->first;
	Node* previous; 
			
	//If the first NULL, create a node with data
	if (current == NULL)
	{
		list->first = createNode(data);
	} else {
		//Iterate till the end of the list or count reaches the desired index
		//Whichever comes first
		while (current->next != NULL && count != index) {
			previous = current;
            current = current->next;
			count++;
        }
		//insert at the first index
		if (index == 0 && count == 0)
		{
			list->first = new;
			new->next = current;
			new->prev = NULL;	
		}
		//insert at any index other than the first
		else if(count == index){
			previous->next = new;
			new->prev = previous;
			new->next = current;
			current->prev = new;
		}
		//Iteration reach the end of list before the desired index
		else{
			printf("Out of bounds!\n");
			return NULL;
		}	
	}
	
	return new;
}

//insert at the end of the list
void listInsert(List *list, int data) {
    if (list == NULL) {
        printf("listInsert: List is empty.\n");
        return;
    }
    Node* current = list->first;
	Node* new = createNode(data);
    if (current == NULL){ 
        list->first = createNode(data);
		list->last = list->first;
	}
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
		new->prev = current;
		list->last = current->next;
    }
}

//fill the list with random numbers till desired length
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

//remove specified index from list
int myRemove(List* list, int index){
	if (list == NULL)
	{
		printf("List is empty!\n");
		return 0;
	}
	
	int count = 0;
	Node* current = list->first;
	Node* previous; 
			
	if (current == NULL)
	{
		printf("Out of bounds!\n");
	} else {
		while (current->next != NULL && count != index) {
			previous = current;
            current = current->next;
			count++;
        }
		if (index == 0 && count == 0)
		{
			list->first = current->next;
		}else if(count == index){
			previous->next = current->next;
			current->next->prev = previous;
			free(current);
			current = NULL;

		}else{
			printf("Out of bounds!\n");
			return 0;
		}	
	}
	
	return 0;
}
	
//iterate forward through list while comparing data and counting steps
void searchForward(List* list, int value){
	if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = list->first;
	int steps = 1;

    while (current != NULL) {
        if (current->data == value)
		{
			printf("Value is found in %d forward steps!\n", steps);
			return;
		}
        current = current->next;
		steps++;
    }
    printf("The Value was not found!\n");
}

//iterate forward through list while comparing data and counting steps
void searchBackward(List* list, int value){
	if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = list->last;
	int steps = 1;

    while (current != NULL) {
        if (current->data == value)
		{
			printf("Value is found in %d backward steps!\n", steps);
			return;
		}
        current = current->prev;
		steps++;
    }
    printf("The Value was not found!\n");
}

//empties list nodes
//it doesnt not pass valgrind, but i couldn't fix it
void clearList(List* list){
	if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->first;
	Node* neighbor = current->next;
    while (neighbor != NULL) {
        neighbor = current->next;
		free(current);
		current = neighbor;
    }
	free(current);
	current = NULL;
	free(neighbor);
	neighbor = NULL;
	free(list);
	list->first = NULL;
	list = NULL;
    printf("List has been Emptied.\n");
}

void printList(List *list) {
    
    Node *current = list->first;
	if (list == NULL || current == NULL) {
        printf("List is empty.\n");
        return;
    }
	

    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//used to verift if the prev nodes were working
void printListBackwards(List *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *current = list->last;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main(){
	srand(time(NULL));
	int search_value = 0;

	List* test_list = createList();
	listRandInsert(test_list, 10);
	printList(test_list);
	printf("------------------------\n");

	printf("Enter a value to search: \n");
	scanf("%d", &search_value);
	
	searchForward(test_list, search_value);
	searchBackward(test_list, search_value);

	printf("------------------------\n");
	clearList(test_list);
	printList(test_list);

	return 0;
}
