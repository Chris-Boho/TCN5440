#include <stdio.h>

#define STRSIZE 4

struct Data {
    int num;
    char str[STRSIZE];
};

int main() {
    struct Data data;
    printf("Data's size: %lu\n", sizeof(data));
    return 0;
}
