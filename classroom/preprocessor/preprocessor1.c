#include <stdio.h>

#define INC(x) x+1
#define SQUARE(x) (x)*(x)

int main(){

	int x = 4;
	printf("%d\n", INC(x));
	printf("%d\n", SQUARE(4+4));
	return 0;
}
