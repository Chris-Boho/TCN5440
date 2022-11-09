#include <stdio.h>
#include <stdlib.h>
#include "train.h"

//Creates train based on user specified length
Train* createTrain(int length){
    Train* myTrain = NULL;
    Car* last = NULL;
    int weight;
    for(int i = 0; i < length; i++){
        if(myTrain == NULL){
            myTrain = malloc(sizeof(Train));
            myTrain->first = malloc(sizeof(Car));
            last = myTrain->first;
        } else {
            last->next = malloc(sizeof(Car));
            last = last->next;
        }

        //Repeat if user tries to enter a value other an 1 or 0
        do
        {
            printf("Input the Weight of Car #%d: ", i + 1);
            scanf("%d", &weight);

            if (weight == 1 || weight == 0)
                break;
            printf("Weight must be 0 or 1!\n");
            
        } while (1);
        
        last->cargo_weight = weight;
        last->next = NULL;
    }

    return myTrain;
}

//Goes through each node, one by one and free's them
void clearTrain(Train* myTrain){
    if (myTrain == NULL){
        printf("This train is empty!\n");
        return;
    }

    Car* current = myTrain->first;
    Car* temp; 
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

//Goes through nodes and prints weight and memory locations neatly
void printTrain(Train* myTrain){
    if (myTrain == NULL){
        printf("This train is empty!\n");
        return;
    }

    Car* current = myTrain->first;
    while (current != NULL)
    {
        printf("%d -> ", current->cargo_weight);
        current = current->next;
    }

    printf("NULL\n");

    current = myTrain->first;
    while (current != NULL)
    {
        printf("%p -> ", current);
        current = current->next;
    }

    printf("NULL\n");
}


int main(){
    int train_length = 0;
    printf("Input # of Cars in the Train: ");
    scanf("%d", &train_length);

    Train* test_train = createTrain(train_length);
    printTrain(test_train);
    clearTrain(test_train);
    free(test_train);
    return 0;
}