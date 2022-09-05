#include <stdio.h>

int main(){
	for(int x = 0; x < 5; x++){
		if((x & 1) == 0){
			printf("%d Is Even!\n", x);
		} else {
			printf("%d Is Odd!\n", x);
		}
	}

	printf("--------------------------\n");

	int a = 4;
	int b = 6;

	printf("Initial Values: \n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	a = a ^ b;
	b = b ^ a;
	a = a ^ b;

	printf("Swapped Values:\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	printf("--------------------------\n");
}
