#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int sum = 0;

	if( argc < 3){
		printf("Enter at least two numbers...\n");
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}
	
	printf("Sum: %d\n", sum);

	return 0;
}
