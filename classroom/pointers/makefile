all: pointer1 pointer2

pointer1: pointer1.c
	gcc pointer1.c -o pointer1.o

pointer2: pointer2
	gcc pointer2.c -o pointer2.o

clean:
	rm *.o

run:
	gcc pointer1.c -o pointer1.o
	gcc pointer2.c -o pointer2.o
	./pointer1.o
	./pointer2.o