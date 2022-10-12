#include <stdio.h>

int main(){
//slide 28
// stack frames: 2
// stack frames: 3
// stack frames: infinite; itll overflow

	int* my_pointer = 5;
	printf("Int Pointer: %d\n", my_pointer);
	my_pointer += 1;
	printf("Int Pointer: %d\n", my_pointer);

	char* char_p = 5;
	printf("Char Pointer: %d\n", char_p);
	char_p +=1;
	printf("Char Pointer: %d\n", char_p);

	double* doub_p = 5;
	printf("Double Pointer: %d\n", doub_p);
	doub_p += 1;
	printf("Double Pointer: %d\n", doub_p);


	return 0;
}
