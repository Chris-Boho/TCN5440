all: struct struct2 struct3 struct4 struct5 struct6
struct: struct.c
	gcc struct.c -o struct
struct2: struct2.c
	gcc struct2.c -o struct2
struct3: struct3.c
	gcc struct3.c -o struct3
struct4: struct4.c
	gcc struct4.c -o struct4
struct5: struct5.c
	gcc struct5.c -o struct5
struct6: struct6.c
	gcc struct6.c -o struct6
clean:
	rm struct struct2 struct3 struct4 struct5 struct6
run: struct.c struct2.c struct3.c struct4.c struct5.c struct6.c
	gcc struct.c -o struct
	./struct
	gcc struct2.c -o struct2
	./struct2
	gcc struct3.c -o struct3
	./struct3
	gcc struct4.c -o struct4
	./struct4
	gcc struct5.c -o struct5
	./struct5
	gcc struct6.c -o struct6
	./struct6
