
final: parser

parser: ass4_17CS10036_parser.c  y.tab.h lex.yy.c y.tab.c
	gcc ass4_17CS10036_parser.c lex.yy.c y.tab.c

lex.yy.c: ass4_17CS10036.l y.tab.h
	flex ass4_17CS10036.l y.tab.h

y.tab.h: ass4_17CS10036.y
	yacc -dtv ass4_17CS10036.y

clean:
	rm a.out lex.yy.c y.tab.c y.tab.h y.output
