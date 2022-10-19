all: io1 io2 io3 io4

io1: io1.c
	gcc io1.c -o io1.o

io2: io2.c 
	gcc io2.c -o io2.o

io3: io3.c
	gcc io3.c -o io3.o

io4: io4.c
	gcc io4.c -o io4.o
	
clean:
	rm *.o

run:
	gcc io1.c -o io1.o
	gcc io2.c -o io2.o
	./io1.o