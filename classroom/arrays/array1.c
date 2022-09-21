#include <stdio.h>

int main(){
	int arr[5] = {0};
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 1;
	}
	
	printf("arr[1]: %d\n", arr[1]);
	printf("arr[5]: %d\n", arr[5]);
	printf("arr[10]: %d\n", arr[10]);
	printf("arr[-1]: %d\n", arr[-1]);

	return 0;
}
