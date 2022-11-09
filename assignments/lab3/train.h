#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <stdlib.h>

struct Car
{
    int cargo_weight;
    struct Car* next;
};

typedef struct Car Car;

struct Train
{
    struct Car* first;
};

typedef struct Train Train;

Train* createTrain(int length);

void printTrain(Train* myTrain);

void ClearTrain(Train* myTrain);

#endif