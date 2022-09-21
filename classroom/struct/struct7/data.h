#include <stdio.h>

#ifndef DATA_H
#define DATA_H

enum DataType { INTEGER, DOUBLE, CHAR };

typedef struct Data {
    int num;
    char str[5];
    enum DataType dataType;

    union {
        int inte;
        double doub;
        char c;
    } data;
} Data;

#endif