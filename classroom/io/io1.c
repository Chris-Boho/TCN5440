#include <stdio.h>
#include <stdlib.h>

int main(){

	char name[20];
	int age;
	char letter;

	printf("Please Enter your Name: ");
	scanf("%20s", name);


	printf("Please Enter you Age: ");
	scanf("%d", &age);

	printf("Please Enter your Favorite Letter: ");
	scanf("%1s", &letter);

	fprintf(stdout, "Name: %s\n", &name);
	fprintf(stdout, "Age: %d\n", &age);
	fprintf(stdout, "Letter: %s\n", &letter);

	return 0;
}
