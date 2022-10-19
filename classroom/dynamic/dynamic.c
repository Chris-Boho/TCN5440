#include <stdio.h>
#include <stdlib.h>

size_t mySizeof(void *p) {
   	//printf("%d\n",*(int*)p);
	 return sizeof(p);
}

int main() {
    int a = 580;
    printf("%lu %lu\n", mySizeof(&a), sizeof(&a));
    return 0;
}
