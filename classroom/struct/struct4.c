#include <stdio.h>

struct Data {
   int num;
   char str[5];

    union {
        int inte;
        double doub;
        char c;
    } data;
};

int main() {
    struct Data data;
    printf("Data's size: %lu\n", sizeof(data));
    return 0;
}
