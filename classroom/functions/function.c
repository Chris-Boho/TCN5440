#include <stdio.h>

void inc(){
	static int num = 1;
	printf("inc'd num: %d\n", num);
	num++;
}

int foo(){
	printf("I am a function\n");
	return 4;
}

void bar(int x){
	x++;
	printf("Value: %d\n", x);
}

int main() {
	int num = 1;
	foo();
	bar(foo());
	bar(num);

	printf("num: %d\n", num);
	printf("=================================\n");

	inc();
	inc();
	inc();
	return 0;
}
