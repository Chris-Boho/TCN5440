all: structs
structs: structs.c data.h
	gcc structs.c -o structs
clean:
	rm structs
run: structs.c data.h
	gcc structs.c -o structs
	./structs
