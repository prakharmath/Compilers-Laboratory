a.out: lex.yy.c y.tab.c y.tab.h ass5_17CS10036_17CS30013_translator.h ass5_17CS10036_17CS30013_translator.cxx
	g++ -std=c++14 lex.yy.c y.tab.c ass5_17CS10036_17CS30013_translator.cxx -lfl
	echo "Type \"make run to output all test files\" "

y.tab.h: ass5_17CS10036_17CS30013.y
	yacc -dtv ass5_17CS10036_17CS30013.y
y.tab.c: ass5_17CS10036_17CS30013.y
	yacc -dtv ass5_17CS10036_17CS30013.y
lex.yy.c: ass5_17CS10036_17CS30013.l y.tab.h
	flex ass5_17CS10036_17CS30013.l

clean:
	rm a.out y.tab.h y.tab.c lex.yy.c y.output
run:
	./a.out < ass5_17CS10036_17CS30013_test1.c > ass5_17CS10036_17CS30013_quad1.txt
	./a.out < ass5_17CS10036_17CS30013_test2.c > ass5_17CS10036_17CS30013_quad2.txt
	./a.out < ass5_17CS10036_17CS30013_test3.c > ass5_17CS10036_17CS30013_quad3.txt
	./a.out < ass5_17CS10036_17CS30013_test4.c > ass5_17CS10036_17CS30013_quad4.txt
	./a.out < ass5_17CS10036_17CS30013_test5.c > ass5_17CS10036_17CS30013_quad5.txt
