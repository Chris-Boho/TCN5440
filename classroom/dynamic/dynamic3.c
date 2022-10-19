#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    printf("ptr before free: %p\n", ptr);
    free(ptr);
    printf("ptr after free: %p\n", ptr);
    ptr = NULL;
    printf("ptr after set to NULL: %p\n", ptr);
    return 0;
}