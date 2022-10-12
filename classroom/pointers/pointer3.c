#include <stdio.h>

struct MyStruct{
	int num;
	int (*fp) = foo;
};

int foo(){

}

int main(){

	return 0;
}
