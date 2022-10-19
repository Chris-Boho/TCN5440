#include <stdio.h>
#include <stdlib.h>

struct Car {
    int weight;
    struct Car *next;
};

typedef struct Car Car;

/**
 * Create a train based on the number of cars. You need to input 
 * the weight of each car.
 * @param: The number of cars.
 * @return: The head of the train;
 * */
Car *createTrain(int carNum) {
    // We inserted every new car in the tail.
    Car *head = NULL, *tail = NULL;
    int i;	
    for (i = 0; i < carNum; i++) {
        printf("Input the weight of %dth car: ", i + 1);
        int weight;
        scanf("%d", &weight);
        if (head == NULL) {
            // If the train is now empty, create the head.
            head = (Car*) malloc(sizeof(Car));
            tail = head;
        } else {
            // Otherwise, create a new car on the tail of the train.
            tail->next = (Car*) malloc(sizeof(Car));
            tail = tail->next;
        }
        tail->weight = weight;
        tail->next = NULL;
    }
    return head;
}

/**
 * Print the train;
 * @param: The head of the train.
 * */
void printTrain(Car *head) {
    if (head == NULL) { 
        printf("This train is empty.\n");
        return;
    }
    Car *p = head;
    while (p != NULL) { 
        printf("%d -> ", p->weight); 
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int carNum = 0;
    Car *head = NULL;
    printf("Input the number of cars in your \"train\": ");
    scanf("%d", &carNum);
    head = createTrain(carNum);
    printTrain(head);
    return 0;
}