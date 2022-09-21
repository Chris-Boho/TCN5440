#include <stdio.h>

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

int main() {
    Data d1;
    d1.dataType = DOUBLE;
    d1.data.doub = 2019.2;

    //Print the Data.data according to its type.
    switch (d1.dataType) {
        case INTEGER : { printf("d1.dataType is INTEGER, it's value is %d\n", d1.data.inte); break; }
        case DOUBLE : { printf("d1.dataType is DOUBLE, it's value is %lf\n", d1.data.doub); break; }
        case CHAR : { printf("d1.dataType is CHAR, it's value is %c\n", d1.data.c); break; }
        default: {}
    }
    return 0;
}