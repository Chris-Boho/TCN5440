all: lab3_part1 lab3_part2

lab3_part1: lab3_part1.c
	gcc lab3_part1.c -o lab3_part1.o

lab3_part2: lab3_part2.c
	gcc lab3_part2.c -o lab3_part2.o

clean:
	rm *.o

run: lab3_part1
	./lab3_part1.o