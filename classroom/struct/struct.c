#include <stdio.h>

struct Data {
    int num;
    char str[5];
};

int main() {
    struct Data data;
    printf("data.num: %d\n", data.num);
    printf("data.str: %s\n", data.str);
    return 0;
}