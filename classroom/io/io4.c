#include <stdio.h>

int main(){

	char buffer[10];

	FILE * fptr = fopen("data.txt", "r");

	fclose(fptr);

	return 0;
}
