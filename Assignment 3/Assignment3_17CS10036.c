#define	KEYWORD		10
#define	ID		11
#define PUNC		12
#define	INTCONST	13
#define	FLTCONST	14
#define STRING		15
#define MCOMNT		16
#define SCOMNT		17
#define CHARCONST	18
#define WS		19
#include <stdio.h>
extern int yylex(void);
extern char *yytext;

int main(int argc,char *argv[]) {
	int token;
	while (token = yylex()) {
		switch (token) 
		{
			case _KEYWORD:
						printf("<KEYWORD, %d, %s>\n", token, yytext);
						break;
			case _ID:
						printf("<IDENTIFIER, %d, %s>\n", token, yytext);
						break;
			case _CONST_INT:
						printf("<INTEGER_CONSTANT, %d, %s>\n", token, yytext);
						break;
			case _PUNC:
						printf("<PUNCTUATOR, %d, %s>\n", token, yytext);
						break;
			case _CONST_FLT:
						printf("<FLOATING_CONSTANT, %d, %s>\n", token, yytext);
						break;
			case _CONST_ENUM :
						printf("<ENUMERATION_CONSTANT, %d, %s>\n", token, yytext);
						break;
			case _CONST_CHAR:
						printf("<CHARACTER_CONSTANT, %d, %s>\n", token, yytext);
						break;
			case _ESCAPE_SEQUENCE:
						printf("<ESCAPE_SEQUENCE, %d, %s>\n", token, yytext);
						break;
			case _STRING:
						printf("<STRING, %d, %s>\n", token, yytext);
						break;			
			case _MCOMMENT:
						printf("<MULTILINE_COMMENT, %d, %s>\n", token, yytext);
						break;
			case _SCOMMENT:
						printf("<SINGLELINE_COMMENT, %d, %s>\n", token, yytext);
						break;
			case _WS:	printf("%s",yytext);
		}
	}
	return 0;
}
