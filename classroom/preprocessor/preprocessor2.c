#include <stdio.h>

#define DEBUG 0

#define INC(x) x+1
#define SQUARE(x) (x)*(x)

int main(){

	int x = 4;
	printf("%d\n", INC(x));
#if DEBUG
	printf("%d\n", SQUARE(4+4));
#endif
	return 0;
}
