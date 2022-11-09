#include <stdio.h>
#include <stdlib.h>
#include "train.h"

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

        do
        {
            printf("Input the weight of car #%d: ", i + 1);
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

    printf("NULL\n");
}

void printTrain(Train* myTrain){
    if (myTrain == NULL){
        printf("This train is empty!\n");
        return;
    }

    Car* current = myTrain->first;
    while (current != NULL)
    {
        printf("%d -> \n", current->cargo_weight);
        printf("mem: %d\n", &current);
        current = current->next;
    }

    printf("NULL\n");
}


int main(){
    Train* test_train = createTrain(3);
    printTrain(test_train);
    clearTrain(test_train);
    free(test_train);
    return 0;
}