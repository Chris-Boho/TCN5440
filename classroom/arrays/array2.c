#include <stdio.h>
#include <string.h>

int main(){

	char myString[10] = "hello";

	printf("Length: %lu\n", strlen(myString));
	printf("String: %lu\n", sizeof(myString));

	return 0;
}
