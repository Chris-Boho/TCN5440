#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createNode(int data){
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

Stack* createStack(){
	Stack* temp = malloc(sizeof(Stack));
	temp->top = NULL;
	return temp;
}


//Creates a node and adds it to the top of the stack
void push(Stack* stack, int value){
	Node* current = stack->top;
	Node* new = createNode(value);

	new->next = current;
	stack->top = new;
}

//Removes node at the top of the stack and prints it out
int pop(Stack* stack){

	if (stack->top == NULL)
	{
		printf("Stack is Empty!\n");
		return 0;
	}

	Node* current = stack->top;
	printf("pop: %d\n", current->data);

	stack->top = current->next;
	free(current);
	current = NULL;

}

//prints stack, used to see if everything was connected properly
void printStack(Stack* stack){
	Node* current = stack->top;

	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}

	printf("NULL\n");
}

Queue* createQueue(){
	Queue* temp = malloc(sizeof(Queue));
	temp->front = NULL;
	temp->back = NULL;
	return temp;
}

//creates node and add its to the back of the line
void enqueue(Queue* queue, int value){
	Node* new = createNode(value);

	if (queue->back == NULL)
	{
		queue->back = new;
		queue->front = new;
		return;
	} else {
		queue->back->next = new;
		queue->back = new;
	}
}

//removes node from the front of the line and prints it
int dequeue(Queue* queue){

	if (queue->front == NULL)
	{
		printf("Queue is Empty!\n");
		return 0;
	}
	
	Node* temp = queue->front;

	printf("dq: %d\n", queue->front->data);

	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
		queue->back = NULL;
	}

	free(temp);
	
}

int main(){

	int input_val = 0;
	Stack* test_stack = createStack();
	for (int i = 0; i < 5; i++)
	{
		printf("Push # to the Stack: \n");
		scanf("%d", &input_val);
		push(test_stack, input_val);
	}

	printf("---------\n");

	//Poping one extra to test what happens when stack is empty
	for (int i = 0; i < 6; i++)
	{
		pop(test_stack);
	}

	free(test_stack);
	test_stack = NULL;

	printf("---------\n");

	Queue* test_queue = createQueue();
	for (int i = 0; i < 5; i++)
	{
		printf("Enqueue # into Queue: \n");
		scanf("%d", &input_val);
		enqueue(test_queue, input_val);
	}

	printf("---------\n");

	//Dequeueing one extra to test what happens when queue is empty
	for (int i = 0; i < 6; i++)
	{
		dequeue(test_queue);
	}

	free(test_queue);
	test_queue = NULL;

	return 0;
}
