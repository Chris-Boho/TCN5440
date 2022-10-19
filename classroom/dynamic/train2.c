#include <stdio.h>
#include <stdlib.h>

struct Train {
    struct Car *first;
};

struct Car {
    int weight;
    struct Car *next;
};

typedef struct Train Train;
typedef struct Car Car;

//structs should be in a .h file

Train *createTrain(int trainSize){
    Train *myTrain = NULL;
    Car *last = NULL;
    for(int i = 0; i < trainSize; i++){
        printf("Input the weight of car #%d: ", i + 1);
        int weight;
        scanf("%d", &weight);
        if(myTrain == NULL){
            //dont need to type cast, since OS does it automatically,
            //but it can be done
            myTrain = (Train*) malloc(sizeof(Train));
            last = myTrain->first;
        } else {
            last->next = (Car*) malloc(sizeof(Car));
            last = last->next;
        }
    }


    return myTrain;
}


//MAKE SURE TO FREE MEMORY AND NULL POINTERS
//add comments to assignment
int main(){
    int size = 0;
    Train *bestTrain = NULL;
    printf("Input the train size: ");
    scanf("%d", &size);
    bestTrain = createTrain(size);

    return 0;
}