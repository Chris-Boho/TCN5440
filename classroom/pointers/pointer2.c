#include <stdio.h>

int main(){

	int arr[5], *p, i;

	for(p = arr; p < arr + 5; p++){
		*p = p;
	}
	
	for ( i = 0; i < 5; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	

	return 0;
}
