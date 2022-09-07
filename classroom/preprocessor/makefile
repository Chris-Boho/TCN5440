all: preprocessor0 preprocessor1 preprocessor2

preprocessor0: preprocessor0.c
	gcc preprocessor0.c -o preprocessor0.o

preprocessor1:
	gcc preprocessor1.c -o preprocessor1.o

preprocessor2:
	gcc preprocessor2.c -o preprocessor2.o

clean:
	rm *.o

run:
	gcc preprocessor0.c -o preprocessor0.o
	gcc preprocessor1.c -o preprocessor1.o
	gcc preprocessor2.c -o preprocessor2.o
	./preprocessor0.o
	./preprocessor1.o
	./preprocessor2.o
