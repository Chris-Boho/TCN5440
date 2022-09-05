#include <stdio.h>

int main() {
	int first;
	int second;

	first = 1;
	second =2;

	printf("First: %d\n", first);
	printf("Second: %d\n", second);

	int result = first - second;

	printf("Result: %d\n", result);
	
	printf("----------------------\n");

	char lowercase = 'a';
	char uppercase = 'A';

	if(lowercase > uppercase){
		printf("%c \n", lowercase);
	} else {
		printf("%c \n", uppercase);
	}
	
	printf("----------------------\n");

	for(int i = 0; i < 10; i++){
		printf("FOR Value: %d\n", i);
	}
	
	printf("----------------------\n");

	int x = 0;
	while(x < 10){
		printf("WHILE Value: %d\n", x);
		x++;
	}

	return 0;
}
