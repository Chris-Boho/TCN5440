all: lab3_part1 lab3_part2 lab3_part3

lab3_part1: lab3_part1.c
	gcc lab3_part1.c -o lab3_part1.o

lab3_part2: lab3_part2.c
	gcc lab3_part2.c -o lab3_part2.o

lab3_part3:
	gcc lab3_part3.c -o lab3_part3.o

clean:
	rm *.o

debug:
	gcc -g3 lab3_part1.c -o lab3_part1.o
	gcc -g3 lab3_part2.c -o lab3_part2.o
	gcc -g3 lab3_part3.c -o lab3_part3.o