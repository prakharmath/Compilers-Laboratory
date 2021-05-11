
all: lex.yy.c lex.yy.o ass3_17CS10036.o a.out test clean

lex.yy.c:    ass3_17CS10036.l
	flex ass3_17CS10036.l

lex.yy.o:	lex.yy.c
	gcc -c lex.yy.c -lfl

ass3_17CS10036.o: ass3_17CS10036.c
	gcc -c ass3_17CS10036.c 

a.out:
	gcc -o a.out ass3_17CS10036.o lex.yy.o -lfl

test:
	./a.out < ass3_17CS10036_test.c

clean:
	rm ass3_17CS10036.o lex.yy.o lex.yy.c a.out
