#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    printf("*p = %d, address = 0x%x\n", *p, p);
    printf("*(p + 1) = %d, address = 0x%x\n", *(p + 1), p + 1);
    *p = 2019;
    *(p + 1) = 2020;
    printf("*p = %d, address = 0x%x\n", *p, p);
    printf("*(p + 1) = %d, address = 0x%x\n", *(p + 1), p + 1);
    free(p);
    return 0;
}
