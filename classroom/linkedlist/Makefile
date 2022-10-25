all: linkedlist
linkedlist: linkedlist.c linkedlist.h main.c
	gcc linkedlist.c main.c -o main
clean:
	rm main
run: linkedlist.c linkedlist.h main.c
	gcc linkedlist.c main.c -o main
	./main
val: linkedlist.c linkedlist.h main.c
	valgrind --leak-check=yes ./main

