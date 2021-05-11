%{
#include <string>
#include <iostream>
using namespace std;
extern int yylex();
void yyerror(string s);
extern int yydebug;
extern int yyparse();

#include "ass5_17CS10036_17CS30013_translator.h"

Quad_Array Q_arr;
symboltable GT;
symboltable *sym = &GT;
symboltable *curr_sym = sym;
type_inf *global_type;
int global_width;
%}

%union {
  int intval;
  float floatval;
  char charval;
  string *str;
  exp_attr *expr_attr;
  declaration *decclist;
  init_dec_list *init_dec_list_;
  type_inf *type_;
  func_def *func_def_;
  func_list *func_list_;
}


%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token FLOAT FOR GOTO_KEYWORD IF INLINE INT LONG REGISTER RESTRICT RETURN_KEYWORD SHORT SIGNED SIZEOF STATIC STRUCT SWITCH
%token TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY
%token POINTER INCREMENT DECREMENT LEFT_SHIFT RIGHT_SHIFT LESS_EQUALS GREATER_EQUALS EQUALS NOT_EQUALS
%token AND_OP OR_OP ELLIPSIS MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN
%token LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SCOMMENT MCOMMENT

%token <str> ID
%token <intval> CONST_INT
%token CONST_ENUM
%token <floatval> CONST_FLT
%token <str> STRING
%token <charval> CONST_CHAR

%type<expr_attr> primary_expression
%type<expr_attr> postfix_expression
%type<expr_attr> unary_expression
%type<charval> unary_operator
%type<expr_attr> cast_expression
%type<expr_attr> multiplicative_expression
%type<expr_attr> additive_expression
%type<expr_attr> shift_expression
%type<expr_attr> relational_expression
%type<expr_attr> equality_expression
%type<expr_attr> AND_expression
%type<expr_attr> exclusive_OR_expression
%type<expr_attr> inclusive_OR_expression
%type<expr_attr> logical_AND_expression
%type<expr_attr> logical_OR_expression
%type<expr_attr> conditional_expression
%type<expr_attr> assignment_expression
%type<expr_attr> assignment_expression_opt
%type<expr_attr> assignment_operator
%type<expr_attr> expression
%type<expr_attr> constant_expression
%type<expr_attr> declaration
%type<type_> declaration_specifiers
%type<init_dec_list_> init_declarator_list
%type<decclist> init_declarator
%type<decclist> direct_declarator
%type<type_> type_specifier
%type<type_> specifier_qualifier_list
%type<decclist> declarator
%type<expr_attr> initializer
%type<decclist> initializer_list
%type<type_> type_name
%type<type_> pointer
%type<func_list_> parameter_list
%type<func_list_> parameter_type_list
%type<func_def_> parameter_declaration
/* %type<func_list_> parameter_type_list_opt */
%type<expr_attr> jump_statement
%type<expr_attr> compound_statement
%type<expr_attr> block_item
%type<expr_attr> block_item_list
%type<expr_attr> selection_statement
%type<expr_attr> iteration_statement
%type<expr_attr> M
%type<expr_attr> N
%type<expr_attr> statement
%type<expr_attr> expression_statement
%type<func_list_> argument_expression_list
%type<expr_attr> expression_opt
%type<decclist> function_definition

%start translation_unit

%%

// Rules start here

M:   {
    $$ = new exp_attr;
    $$->instr = Q_arr.index;};

N:   {
    $$ = new exp_attr;
    $$->nextlist = makelist(Q_arr.index);};


primary_expression:             ID {
                                //printf("\nprimary expression rule 1\n");
                                    $$ = new exp_attr;
                                    string t = (*($1));     //done
                                    symtab *h = curr_sym->lookup(t);
                                    $$->loc = t;
                                    h -> nested_table = NULL;
                                } |
                                CONST_INT {
                                    //printf("\nprimary expression rule 2\n");
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type.type_name = "int";
                                    opcodeType op = COPY;
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,$$->loc, $1);
                                    init_value *init = new init_value;
                                    init->int_val = $1;
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    $$->is_pointer_type = 0;
                                } |
                                CONST_FLT {
                                    //printf("\nprimary expression rule 2\n");
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type.type_name = "double";
                                    opcodeType op = COPY;
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,$$->loc, $1);
                                    init_value *init = new init_value;
                                    init->int_val = $1;
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    $$->is_pointer_type = 0;
                                } |
                                CONST_CHAR {
                                    //printf("\nprimary expression rule 2\n");
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type.type_name = "char";
                                    opcodeType op = COPY;
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,$$->loc, $1);
                                    init_value *init = new init_value;
                                    init->int_val = $1;
                                    curr_sym->lookup($$->loc)->init_val = init;
                                    $$->is_pointer_type = 0;
                                } |
                                STRING {
                                    //printf("\nprimary expression rule 3\n");
                                } |
                                '(' expression ')' {
                                    //printf("\nprimary expression rule 4\n");
                                    $$ = $2;
                               };

enumeration_constant:           ID {};

postfix_expression :            primary_expression {
                                    //printf("\n<postfix-expression rule 1>\n");
                                    $$ = $1;
                                } |
                                postfix_expression '[' expression ']'
                                {
                                    //printf("\n<postfix-expression rule 2>\n");
                                    type_inf t = curr_sym->lookup($1->loc)->type;
                                    if($1->dim == 0)
                                    {
                                        string f = curr_sym->gentemp(t);
                                        Q_arr.emit(COPY, f, 0);
                                        $1 -> inner = new string(f);
                                    }
                                    string f = *($1->inner);
                                } |
                                postfix_expression '(' ')' {
                                    /* printf("\n<postfix-expression rule 3>\n"); */
                                } |
                                postfix_expression '(' argument_expression_list ')' {
                                    /* printf("\n<postfix-expression rule 3>\n"); */
                                    string f = $1->loc;
                                    symboltable *fsym = GT.lookup(f)->nested_table;
                                    func_list *flist = ($3);
                                    list<func_def*>::iterator it;
                                    int c = 0;
                                    for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++)
                                    {
                                        func_def *f = *it;
                                        c++;
                                        Q_arr.emit(PARAM, f->param_name,"","");
                                    }
                                    string s = to_string(c);
                                    Q_arr.emit(CALL,f,s,"");
                                } |
                                postfix_expression '.' ID {
                                    /* printf("\n<postfix-expression rule 4>\n"); */
                                }|
                                postfix_expression POINTER ID {
                                    /* printf("\n<postfix-expression rule 5>\n"); */
                                } |
                                postfix_expression INCREMENT {
                                    /* printf("\n<postfix-expression rule 6>\n"); */
                                    $$ = new exp_attr;
                                    string s = $1->loc;
                                    symtab * f = curr_sym->lookup($1->loc);
                                    $$->loc = curr_sym->gentemp(f->type);
                                    /* //cout<<$$->loc<<"\n"; */
                                    Q_arr.emit(COPY, $$->loc, $1->loc, "");
                                    Q_arr.emit(PLUS, $1->loc, $1->loc, "1");
                                } |
                                postfix_expression DECREMENT {
                                    /* printf("\n<postfix-expression rule 7>\n"); */
                                    $$ = new exp_attr;
                                    string s = $1->loc;
                                    symtab * f = curr_sym->lookup($1->loc);
                                    $$->loc = curr_sym->gentemp(f->type);
                                    //cout<<$$->loc<<"\n";
                                    Q_arr.emit(COPY, $$->loc, $1->loc, "");
                                    Q_arr.emit(MINUS, $1->loc, $1->loc, "1");
                                } |
                                '(' type_name ')' '{' initializer_list '}' {
                                    /* printf("\n<postfix-expression rule 8>\n"); */
                                }|
                                '(' type_name ')' '{' initializer_list ',' '}' {
                                    /* printf("\n<postfix-expression rule 1>\n"); */
                                };

argument_expression_list:       assignment_expression {
                                    /* printf("\n<argument-expression-list rule 1>\n"); */
                                    func_def *f = new func_def;
                                    f->param_name = $1->loc;
                                    $$ = new func_list;
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    $$->func_def_list.push_back(f);
                                }|
                                argument_expression_list ',' assignment_expression {
                                    /* printf("\n<argument-expression-list rule 1>\n"); */
                                    func_def *f = new func_def;
                                    f->param_name = $3->loc;
                                    $$ = new func_list;
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    $$->func_def_list.push_back(f);
                                };

unary_expression:               postfix_expression {
                                    /* printf("\n<unary-expression rule 1>\n"); */
                                }|
                                INCREMENT unary_expression {
                                    /* printf("\n<unary-expression rule 2>\n"); */
                                    opcodeType op;
                                    op = PLUS;
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup($2->loc)->type;
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op, $$->loc, $2->loc, "1");
                                    op = COPY;
                                    Q_arr.emit(op, $2->loc, $$->loc, "");
                                }|
                                DECREMENT unary_expression {
                                    /* printf("\n<unary-expression rule 3>\n"); */
                                    opcodeType op;
                                    op = MINUS;
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup($2->loc)->type;
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op, $$->loc, $2->loc, "1");
                                    op = COPY;
                                    Q_arr.emit(op, $2->loc, $$->loc, "");
                                }|
                                unary_operator cast_expression {
                                    /* printf("\n<unary-expression rule 4>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type;
                                    type.type_name = string("int");
                                    if($1 == '-')
                                    {
                                        $$ = new exp_attr;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(UNARY_MINUS,$$->loc,$2->loc,"");
                                    }
                                    else if($1 == '&')
                                    {
                                        $$ = new exp_attr;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(REFERENCE,$$->loc,$2->loc,"");
                                    }
                                    else if($1 == '*')
                                    {
                                        $$ = new exp_attr;
                                        $$->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(DEREFERENCE,$$->loc,$2->loc,"");
                                    }
                                    else
                                    {
                                        $$ = $2;
                                    }
                                }|
                                SIZEOF unary_expression {
                                    /* printf("\n<unary-expression rule 5>\n"); */
                                }|
                                SIZEOF '(' type_name ')' {
                                    /* printf("\n<unary-expression rule 6>\n"); */
                                };

unary_operator  :               '&' {
                                    /* printf("\nUnary operator - AND\n"); */
                                    $$ = '&';
                                }|
                                '*' {
                                    /* printf("\nUnary operator - STAR\n"); */
                                    $$ = '*';
                                }|
                                '+' {
                                    /* printf("\nUnary operator - PLUS\n"); */
                                    $$ = '+';
                                }|
                                '-' {
                                    /* printf("\nUnary operator - MINUS\n"); */
                                    $$ = '-';
                                }|
                                '~' {
                                    /* printf("\nUnary operator - TILDE\n"); */
                                    $$ = '~';
                                }|
                                '!' {
                                    /* printf("\nUnary operator - NOT\n"); */
                                    $$ = '!';
                                };

cast_expression :               unary_expression {
                                    /* printf("\n<cast-expression rule 1>\n"); */
                                }|
                                '(' type_name ')' cast_expression {
                                    /* printf("\n<cast-expression rule 2>\n"); */
                                };

multiplicative_expression:      cast_expression {
                                    /* printf("\n<multiplicative-expression rule 1>\n"); */
                                    $$ = $1;
                                }|
                                multiplicative_expression '*' cast_expression {
                                    /* printf("\n<multiplicative-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convI2D(e,$3);
                                        type.type_name = type1.type_name;
                                        //$3->loc
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convI2D(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MULT, $$->loc, $1->loc, $3->loc);
                                }|
                                multiplicative_expression '/' cast_expression {
                                    /* printf("\n<multiplicative-expression rule 3>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convI2D(e,$3);
                                        type.type_name = type1.type_name;
                                        //$3->loc
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convI2D(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(DIVIDE, $$->loc, $1->loc, $3->loc);
                                }|
                                multiplicative_expression '%' cast_expression {
                                    /* printf("\n<multiplicative-expression rule 4>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convI2D(e,$3);
                                        type.type_name = type1.type_name;
                                        //$3->loc
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convI2D(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MODULO, $$->loc, $1->loc, $3->loc);
                                };

additive_expression :           multiplicative_expression {
                                    /* printf("\n<additive-expression rule 1>\n"); */
                                    $$ = $1;
                                }|
                                additive_expression '+' multiplicative_expression {
                                    /* printf("\n<additive-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convI2D(e,$3);
                                        type.type_name = type1.type_name;
                                        //$3->loc
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convI2D(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(PLUS, $$->loc, $1->loc, $3->loc);
                                }|
                                additive_expression '-' multiplicative_expression {
                                    /* printf("\n<additive-expression rule 3>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup($1->loc)->type;
                                    type2 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        type.type_name = type1.type_name;
                                        flag = 1;
                                    }
                                    // if flag equals 1, none of the conditions will executed.
                                    // could optimise here, if necessary
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convI2D(e,$3);
                                        type.type_name = type1.type_name;
                                        //$3->loc
                                    }
                                    else if(type1.type_name.compare("int")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convI2D(e,$1);
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$1);
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,$3);
                                        type.type_name = type1.type_name;

                                    }
                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MINUS, $$->loc, $1->loc, $3->loc);
                                };

shift_expression:               additive_expression {
                                    /* printf("\n<shift-expression rule 1>\n"); */
                                    $$ = $1;
                                }|
                                shift_expression LEFT_SHIFT additive_expression {
                                    /* printf("\n<shift-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1;
                                    type1 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {

                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("double") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            Q_arr.convD2I(e,$3);
                                            //type.type_name = type1.type_name;
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,$3);
                                            //type.type_name = type1.type_name;
                                        }
                                    }
                                    type1.type_name = "int";
                                    $$->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_LEFT, $$->loc, $1->loc, $3->loc);
                                }|
                                shift_expression RIGHT_SHIFT additive_expression {
                                    /* printf("\n<shift-expression rule 3>\n"); */
                                    $$ = new exp_attr;
                                    type_inf type1;
                                    type1 = curr_sym->lookup($3->loc)->type;
                                    int flag = 0;
                                    // the amount to be shifted should be an integer
                                    if(type1.type_name.compare("int") == 0)
                                    {

                                    }
                                    else
                                    {
                                        if(type1.type_name.compare("double") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            Q_arr.convD2I(e,$3);
                                            //type.type_name = type1.type_name;
                                        }
                                        else if(type1.type_name.compare("char") == 0)
                                        {
                                            type1.type_name = "int";
                                            string t = curr_sym->gentemp(type1);
                                            symtab *s = curr_sym->lookup(t, "int");
                                            exp_attr *e = new exp_attr;
                                            e->loc = t;
                                            e->type.type_name = "int";
                                            Q_arr.convC2I(e,$3);
                                            //type.type_name = type1.type_name;
                                        }
                                    }
                                    type1.type_name = "int";
                                    $$->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_RIGHT, $$->loc, $1->loc, $3->loc);
                                };

relational_expression:          shift_expression {
                                    /* printf("\n<relational-expression rule 1>\n"); */
                                    /* $$ = $1; */
                                }|
                                relational_expression '<' shift_expression {
                                    /* printf("\n<relational-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression '>' shift_expression {
                                    /* printf("\n<relational-expression rule 3>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression LESS_EQUALS shift_expression {
                                    /* printf("\n<relational-expression rule 4>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                relational_expression GREATER_EQUALS shift_expression {
                                    /* printf("\n<relational-expression rule 5>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                };

equality_expression:            relational_expression {
                                    /* printf("\n<equality-expression rule 1>\n"); */
                                    $$ = $1;
                                }|
                                equality_expression EQUALS relational_expression {
                                    /* printf("\n<equality-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_IS_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }|
                                equality_expression NOT_EQUALS relational_expression {
                                    /* printf("\n<equality-expression rule 3>\n"); */
                                    $$ = new exp_attr;
                                    $$->type.type_name = "bool";
                                    $$->loc = curr_sym->gentemp($$->type);
                                    $$->truelist = makelist(Q_arr.index);
                                    $$->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_NOT_EQUAL, "", $1->loc, $3->loc);
                                    Q_arr.emit(GOTO,"","","");
                                };

AND_expression :                equality_expression {
                                    /* printf("\n<AND-expression rule 1>\n"); */
                                }|
                                AND_expression '&' equality_expression {
                                    /* printf("\n<AND-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(LOGICAL_AND, $$->loc, $1->loc, $3->loc);
                                };

exclusive_OR_expression:        AND_expression {
                                    /* printf("\n<exclusive-OR-expression rule 1>\n"); */
                                }|
                                exclusive_OR_expression '^' AND_expression {
                                    /* printf("\n<exclusive-OR-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(XOR, $$->loc, $1->loc, $3->loc);
                                };

inclusive_OR_expression:        exclusive_OR_expression {
                                    /* printf("\n<inclusive-OR-expression rule 1>\n"); */
                                }|
                                inclusive_OR_expression '|' exclusive_OR_expression {
                                    /* printf("\n<inclusive-OR-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    symtab *f = curr_sym->lookup($1->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    $$->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(OR, $$->loc, $1->loc, $3->loc);
                                };

logical_AND_expression:         inclusive_OR_expression {
                                    /* printf("\n<logical-AND-expression rule 1>\n"); */
                                };|
                                logical_AND_expression N AND_OP M inclusive_OR_expression N {
                                    /* printf("\n<logical-AND-expression rule 2>\n"); */
                                    type_inf type;
                                    type.type_name = "bool";
                                    $$ = new exp_attr;
                                    $$->type = type;

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($1);

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($5);

                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch($1->truelist, $4->instr);
                                    $$->truelist = $5->truelist;
                                    $$->falselist = merge($1->falselist, $5->falselist);
                                };

logical_OR_expression:          logical_AND_expression {
                                    /* printf("\n<logical-OR-expression rule 1>\n"); */
                                };|
                                logical_OR_expression N OR_OP M logical_AND_expression N {
                                    /* printf("\n<logical-expression rule 2>\n"); */
                                    type_inf type;
                                    type.type_name = "bool";
                                    $$ = new exp_attr;
                                    $$->type = type;

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($1);

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($5);

                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch($1->falselist, $4->instr);
                                    $$->falselist = $5->falselist;
                                    $$->truelist = merge($1->truelist, $5->truelist);
                                };

/*It is assumed that type of expression and conditional expression are same*/
conditional_expression:         logical_OR_expression {
                                    /* printf("\n<conditional-expression rule 1>\n"); */
                                };|
                                logical_OR_expression N '?' M expression N ':' M conditional_expression {
                                    /* printf("\n<conditional-expression rule 2>\n"); */
                                    $$ = new exp_attr;
                                    list<int> I;
                                    type_inf type;
                                    type = curr_sym->lookup($5->loc)->type;

                                    $$->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(COPY, $$->loc, $9->loc,"");
                                    I = makelist(Q_arr.index);
                                    Q_arr.emit(GOTO,"","","");

                                    // for the second N
                                    Q_arr.backpatch($6->nextlist, Q_arr.index);

                                    Q_arr.emit(COPY, $$->loc, $5->loc, "");
                                    I = merge(I, makelist(Q_arr.index));
                                    Q_arr.emit(GOTO,"", "", "");

                                    // for the first N
                                    Q_arr.backpatch($2->nextlist, Q_arr.index);

                                    Q_arr.convInt2Bool($1);

                                    // the standard stuff from the slides
                                    Q_arr.backpatch($1->truelist, $4->instr);
                                    Q_arr.backpatch($1->falselist, $8->instr);
                                    Q_arr.backpatch(I, Q_arr.index);
                                };

assignment_operator:            '=' {
                                    /* printf("\nAssignment operator :: =\n");  */
                                }|
                                MULTIPLY_ASSIGN {
                                    /* printf("\nAssignment operator :: *=\n"); */
                                }|
                                DIVIDE_ASSIGN {
                                    /* printf("\nAssignment operator :: /=\n"); */
                                }|
                                MODULO_ASSIGN {
                                    /* printf("\nAssignment operator :: =\n"); */
                                }|
                                ADD_ASSIGN  {
                                    /* printf("\nAssignment operator :: +=\n"); */
                                }|
                                SUBTRACT_ASSIGN {
                                    /* printf("\nAssignment operator :: -=\n"); */
                                }|
                                LEFT_SHIFT_ASSIGN {
                                    /* printf("\nAssignment operator :: <<=\n"); */
                                }|
                                RIGHT_SHIFT_ASSIGN {
                                    /* printf("\nAssignment operator :: >>=\n"); */
                                }|
                                AND_ASSIGN {
                                    /* printf("\nAssignment operator :: &=\n"); */
                                }|
                                XOR_ASSIGN {
                                    /* printf("\nAssignment operator :: ^=\n"); */
                                }|
                                OR_ASSIGN {
                                    /* printf("\nAssignment operator :: |=\n"); */
                                };

assignment_expression:          conditional_expression {
                                    /* printf("\n<assignment-expression rule 1>\n"); */
                                }|
                                unary_expression assignment_operator assignment_expression {
                                    /* printf("\n<assignment-expression rule 2>\n"); */
                                    Q_arr.emit(COPY, $1->loc, $3->loc, "");
                                    $$ = $1;
                                };

/*A constant value of this expression exists*/
constant_expression:            conditional_expression {
                                    /* printf("\n<constant-expression rule 1>\n"); */
                                };

expression :                    assignment_expression {
                                    /* printf("\n<expression rule 1>\n"); */
                                }|
                                expression ',' assignment_expression {
                                    /* printf("\n<expression rule 2>\n"); */
                                };

/*Declarations*/
declaration:                    declaration_specifiers';' {
                                    /* printf("\n<declaration rule 1>\n"); */
                                }|
                                declaration_specifiers init_declarator_list {
                                    /* printf("\n<init-declarator-list-opt rule 1>\n"); */
                                    init_dec_list *new_dec = new init_dec_list;
                                    new_dec = $2;
                                    int size = 0;
                                    type_inf *type = $1;
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("double")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;

                                    list<declaration*>::iterator it;
                                    for(it = $2->dec_list.begin(); it != $2->dec_list.end(); it++)
                                    {
                                        declaration *new_dec = *it;
                                        //check this
                                        if(type->type_name.compare("function"))
                                        {
                                            string name = new_dec->dec_name;
                                            curr_sym = &GT;
                                            //Q_arr.emit(_FUNCTION_END,name,"","");
                                            //write an emit
                                        }

                                        symtab *ret, *f;
                                        symboltable *nest;
                                        if(type->type_name.compare("function"))
                                        {
                                            f = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            f->nested_table = new symboltable;
                                            nest = f->nested_table;
                                            ret = nest->lookup("retVal", type->type_name, new_dec->pc);
                                            f->offset = curr_sym->offset;
                                            f->size = size;
                                            //curr_sym = nest;
                                            //f->init_val = NULL;
                                            //continue;
                                        }

                                        //cout<<type->type_name;
                                        f = curr_sym->lookup(new_dec->dec_name, type->type_name);

                                        f->nested_table = NULL;
                                          

                                        //condition for id
                                        if(new_dec->alist == vector<int>() && new_dec->pc == 0)
                                        {
                                            f->offset = curr_sym->offset;
                                            f->offset = f->offset + size;
                                            f->type = *type;
                                            f = curr_sym->lookup(new_dec->dec_name, type->type_name);
                                            //cout<<type->type_name<<"\n";
                                            if(new_dec->init != NULL)
                                            {
                                              //  cout<<curr_sym->sym_table[0].id<<"\n";

                                                string x = new_dec->init->loc;
                                                Q_arr.emit(COPY, new_dec->dec_name, x, "");
                                                f->init_val = curr_sym->lookup(x,f->type.type_name)->init_val;
                                            }
                                            else
                                                new_dec->init = NULL;
                                        }
                                        else if(new_dec->alist!=vector<int>())
                                        {
                                            f->array_type = *type;
                                            f->type.type_name = "array";
                                        }
                                    }
                                    //incomplete
                                };

declaration_specifiers:         storage_class_specifier declaration_specifiers_opt {
                                    /* printf("\n<declaration-specifiers rule 1>\n"); */
                                }|
                                type_specifier declaration_specifiers_opt {
                                    /* printf("\n<declaration-specifiers rule 2>\n"); */
                                }|
                                type_qualifier declaration_specifiers_opt {
                                    /* printf("\n<declaration-specifiers rule 3>\n"); */
                                }|
                                function_specifier declaration_specifiers_opt {
                                    /* printf("\n<declaration-specifiers rule 4>\n"); */
                                };
/*  I have made a change here .. please note if not working */
declaration_specifiers_opt:     declaration_specifiers {
                                    /* printf("\n<declaration-specifiers-opt rule 1>\n"); */
                                }|
                                /*epsilon*/ {} ;

init_declarator_list:           init_declarator {
                                    /* printf("\n<init-declarator-list rule 1>\n"); */
                                    $$ = new init_dec_list;
                                    $$->dec_list.push_back($1);
                                }|
                                init_declarator_list ',' init_declarator {
                                    /* printf("\n<init-declarator-list rule 2>\n"); */
                                    $1->dec_list.push_back($3);
                                    $$ = $1;
                                };

init_declarator:                declarator {
                                    /* printf("\n<init-declarator rule 1>\n"); */
                                    $$ = $1;
                                    $$->init = NULL;
                                }|
                                declarator '=' initializer {
                                    /* printf("\n<init-declarator rule 2>\n"); */
                                    $$ = $1;
                                    $$->init = $3;
                                };

storage_class_specifier:        EXTERN {
                                    /* printf("\n<storage-class-specifier :: extern>\n"); */
                                }|
                                STATIC {
                                    /* printf("\n<storage-class-specifier :: static>\n"); */
                                }|
                                AUTO {
                                    /* printf("\n<storage-class-specifier :: auto>\n"); */
                                }|
                                REGISTER {
                                    /* printf("\n<storage-class-specifier :: register>\n"); */
                                };

type_specifier:                 VOID {
                                    /* printf("\n<type-specifier :: void>\n"); */
                                    $$ = new type_inf;
                                    $$->type_name = string("void");
                                    $$->next = NULL;
                                }|
                                CHAR {
                                    /* printf("\n<type-specifier :: char>\n"); */
                                    $$ = new type_inf;
                                    $$->type_name = string("char");
                                    $$->next = NULL;
                                }|
                                SHORT {
                                    /* printf("\n<type-specifier :: short>\n"); */
                                }|
                                INT {
                                    /* printf("\n<type-specifier :: int>\n"); */
                                    $$ = new type_inf;
                                    $$->type_name = string("int");
                                    $$->next = NULL;
                                }|
                                LONG {
                                    /* printf("\n<type-specifier :: long>\n"); */
                                }|
                                FLOAT {
                                    /* printf("\n<type-specifier :: float>\n"); */
                                }|
                                DOUBLE {
                                    /* printf("\n<type-specifier :: double>\n"); */
                                    $$ = new type_inf;
                                    $$->type_name = string("double");
                                    $$->next = NULL;
                                }|
                                SIGNED {
                                    /* printf("\n<type-specifier :: signed>\n"); */
                                }|
                                UNSIGNED {
                                    /* printf("\n<type-specifier :: unsigned>\n"); */
                                }|
                                BOOL {
                                    /* printf("\n<type-specifier :: _Bool>\n"); */
                                }|
                                COMPLEX {
                                    /* printf("\n<type-specifier :: _Complex>\n"); */
                                }|
                                IMAGINARY {
                                    /* printf("\n<type-specifier :: _Imaginary>\n"); */
                                }|
                                enum_specifier {
                                    /* printf("\n<type-specifier :: enum>\n"); */
                                };

specifier_qualifier_list:       type_specifier specifier_qualifier_list_opt {
                                    $$ = $1;
                                    /* printf("\n<specifier-qualifier-list rule 1>\n"); */
                                }|
                                type_qualifier specifier_qualifier_list_opt {
                                    /* printf("\n<specifier-qualifier-list rule 2>\n"); */
                                };

specifier_qualifier_list_opt:   specifier_qualifier_list {
                                    /* printf("\n<specifier-qualifier-list-opt rule 1>\n"); */
                                }|
                                /*epsilon*/ {};

enum_specifier:                 ENUM ID_opt '{' enumerator_list '}' {
                                    /* printf("\n<enum-specifier rule 1>\n"); */
                                }|
                                ENUM ID_opt '{' enumerator_list ',' '}' {
                                    /* printf("\n<enum-specifier rule 2>\n"); */
                                }|
                                ENUM ID {
                                    /* printf("\n<enum-specifier rule 3>\n"); */
                                };

ID_opt:                         ID {
                                    /* printf("\n<identifier rule 1>\n"); */
                                }|
                                /*epsilon*/ {};

enumerator_list:                enumerator {
                                    /* printf("\n<enumerator-list rule 1>\n"); */
                                }|
                                enumerator_list ',' enumerator {
                                    /* printf("\n<enumerator-list rule 2>\n"); */
                                };

enumerator:                     CONST_ENUM {
                                    /* printf("\n<enumerator rule 1>\n"); */
                                }|
                                CONST_ENUM '=' constant_expression {
                                    /* printf("\n<enumerator rule 2>\n"); */
                                };

type_qualifier:                 CONST {
                                    /* printf("\n<type-qualifier :: const>\n"); */
                                }|
                                RESTRICT {
                                    /* printf("\n<type-qualifier :: inline>\n"); */
                                }|
                                VOLATILE {
                                    /* printf("\n<type-qualifier :: volatile>\n"); */
                                };

function_specifier:             INLINE {
                                    /* printf("\n<function-specifier :: inline>\n"); */
                                };

declarator :                    pointer_opt direct_declarator {
                                    /* printf("\n<declarator rule 1>\n"); */
                                    $$ = $2;
                                };

pointer_opt:                    pointer {
                                    /* printf("\n<pointer-opt rule 1>\n"); */
                                }|
                                /*epsilon*/{};

direct_declarator:              ID {
                                    /* printf("\n<direct-declarator rule 1>\n"); */
                                    $$ = new declaration;
                                    $$->dec_name = *($1);
                                }|
                                '(' declarator ')' {
                                    /* printf("\n<direct-declarator rule 2>\n"); */
                                    $$ = $2;
                                }|
                                direct_declarator '[' type_qualifier_list_opt assignment_expression_opt ']' {
                                    /* printf("\n<direct-declarator rule 3>\n"); */
                                    $$ = $1;
                                    int idx = curr_sym->lookup($4->loc)->init_val->int_val;
                                    $$->alist.push_back(idx);
                                }|
                                direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']' {
                                    /* printf("\n<direct-declarator rule 4>\n"); */
                                }|
                                direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' {
                                    /* printf("\n<direct-declarator rule 5>\n"); */
                                }|
                                direct_declarator '[' type_qualifier_list_opt '*' ']' {
                                    /* printf("\n<direct-declarator rule 6>\n"); */
                                }|
                                direct_declarator '(' parameter_type_list ')' {
                                    /* printf("\n<direct-declarator rule 7>\n"); */
                                    //name of function is now available
                                    symboltable *new_sym = new symboltable;
                                    $$ = $1;
                                    string name = $$->dec_name;
                                    $$->type = new type_inf;
                                    $$->type->type_name = string("function");
                                    symtab *func_lookup = curr_sym->lookup($$->dec_name, $$->type->type_name);
                                    func_lookup -> nested_table = new_sym;

                                    list<func_def*> l = $3->func_def_list;
                                    list<func_def*>::iterator it;
                                    for(it = l.begin(); it != l.end(); it++)
                                    {
                                        func_def *temp = *it;
                                        new_sym -> lookup(temp->param_name, temp->type->type_name);
                                    }
                                    curr_sym = new_sym;
                                    Q_arr.emit(_FUNCTION_START, name,"","");
                                    //printf("direct_declarator -> direct_declarator (parameter_type_list)\n");
                                }|
                                direct_declarator '(' ID_list_opt ')' {
                                    /* printf("\n<direct-declarator rule 8>\n"); */
                                };

type_qualifier_list_opt:        type_qualifier_list {
                                    /* printf("\n<type-qualifier-list-opt rule 1>\n"); */
                                }|
                                /*epsilon*/ {};

assignment_expression_opt:      assignment_expression {
                                    /* printf("\n<assignment-expression-opt rule 1>\n"); */
                                }|
                                /*epsilon*/ {};

ID_list_opt:                    ID_list {
                                    /* printf("\n<identifier-list-opt rule 1>\n"); */
                                }|
                                /*epsilon*/ {};

pointer:                        '*' type_qualifier_list_opt {
                                    /* printf("\n<pointer rule 1>\n"); */
                                    $$ = new type_inf;
                                    $$->type_name = string("ptr");
                                    $$->next = NULL;
                                }|
                                '*' type_qualifier_list_opt pointer {
                                    /* printf("\n<pointer rule 2>\n"); */
                                    $$ = $3;
                                    type_inf *t = new type_inf;
                                    t->type_name = string("ptr");
                                    t->size = 4;
                                    t->next = $3;
                                };

type_qualifier_list:            type_qualifier {
                                    /* printf("\n<type-qualifier-list rule 1>\n"); */
                                }|
                                type_qualifier_list type_qualifier {
                                    /* printf("\n<type-qualifier-list rule 2>\n"); */
                                };

parameter_type_list:            parameter_list {
                                    /* printf("\n<parameter-type-list rule 1>\n"); */
                                    $$ = new func_list;
                                }|
                                parameter_list ',' ELLIPSIS {
                                    /* printf("\n<parameter-type-list rule 2>\n"); */
                                };

parameter_list:                 parameter_declaration {
                                    /* printf("\n<parameter-list rule 1>\n"); */
                                    $$ = new func_list;
                                    $$->func_def_list.push_back($1);
                                }|
                                parameter_list ',' parameter_declaration {
                                    /* printf("\n<parameter-list rule 2>\n"); */
                                    $1->func_def_list.push_back($3);
                                    $$ = $1;
                                };

parameter_declaration:          declaration_specifiers declarator {
                                    /* printf("\n<parameter-declaration rule 1>\n"); */
                                    $$ = new func_def;
                                    $$->type = $1;
                                    $$->param_name = $2->dec_name;
                                }|
                                declaration_specifiers {
                                    /* printf("\n<parameter-declaration rule 2>\n"); */
                                };

ID_list :                       ID {
                                    /* printf("\n<identifier-list rule 1>\n"); */
                                }|
                                ID_list ',' ID {
                                    /* printf("\n<identifier-list rule 2>\n"); */
                                };

type_name:                      specifier_qualifier_list {
                                    /* printf("\n<type-name rule 1>\n"); */
                                };

initializer:                    assignment_expression {
                                    /* printf("\n<initializer rule 1>\n"); */
                                    $$ = $1;
                                }|
                                '{' initializer_list '}' {
                                    /* printf("\n<initializer rule 2>\n"); */
                                }|
                                '{' initializer_list ',' '}' {
                                    /* printf("\n<initializer rule 3>\n"); */
                                };

initializer_list:               designation_opt initializer {
                                    /* printf("\n<initializer-list rule 1>\n"); */
                                }|
                                initializer_list ',' designation_opt initializer {
                                    /* printf("\n<initializer-list rule 2>\n"); */
                                };

designation_opt:                designation {
                                    /* printf("\n<designation-opt rule 1>\n"); */
                                }|
                                /*Epslion*/                                             ;

designation:                    designator_list '=' {
                                    /* printf("\n<designation rule 1>\n"); */
                                };

designator_list:                designator {
                                    /* printf("\ndesignator-list rule 1>\n"); */
                                }|
                                designator_list designator {
                                    /* printf("\ndesignator-list rule 2>\n"); */
                                };

designator:                     '[' constant_expression ']' {
                                    /* printf("\ndesignator rule 1>\n"); */
                                }|
                                '.' ID {
                                    /* printf("\ndesignator rule 2>\n"); */
                                };

/*Statements*/
statement:                      labeled_statement {
                                    /* printf("\nstatement rule 1>\n"); */
                                }|
                                compound_statement {
                                    /* printf("\nstatement rule 2>\n"); */
                                }|
                                expression_statement {
                                    /* printf("\nstatement rule 3>\n"); */
                                }|
                                selection_statement {
                                    /* printf("\nstatement rule 4>\n"); */
                                }|
                                iteration_statement {
                                    /* printf("\nstatement rule 5>\n"); */
                                }|
                                jump_statement {
                                    /* printf("\nstatement rule 6>\n"); */
                                };

labeled_statement:              ID ':' statement {
                                    /* printf("\nlabeled-statement rule 1>\n"); */
                                }|
                                CASE constant_expression ':' statement {
                                    /* printf("\nlabeled-statement rule 2>\n"); */
                                }|
                                DEFAULT ':' statement {
                                    /* printf("\nlabeled-statement rule 3>\n"); */
                                };

compound_statement:             '{' '}' {
                                    /* printf("\ncompound-statement rule 1>\n"); */
                                }|
                                '{' block_item_list '}' {
                                    $$ = $2;
                                };

block_item_list:                block_item {
                                    /* printf("\nblock-item-list rule 1>\n"); */
                                    $$ = $1;
                                    Q_arr.backpatch($1->nextlist, Q_arr.index);
                                }|
                                block_item_list M block_item {
                                    /* printf("\nblock-item-list rule 2>\n"); */
                                    $$ = new exp_attr;
                                    $$->nextlist = $3->nextlist;
                                    Q_arr.backpatch($1->nextlist, $2->instr);
                                };

block_item:                     declaration {
                                    /* printf("\nblock-item rule 1>\n"); */
                                    $$ = new exp_attr;
                                }|
                                statement {
                                    /* printf("\nblock-item rule 2>\n"); */
                                };

expression_statement:           expression_opt ';'{
                                    /* printf("\nexpression-statement rule 1>\n"); */
                                    $$ = $1;
                                };

expression_opt:                 expression {
                                    /* printf("\nexpression-opt rule 1>\n"); */
                                    $$ = $1;
                                }|
                                /*Epslion*/ {
                                    $$ = new exp_attr;
                                };

selection_statement:            IF '(' expression N ')' M statement N ELSE M statement N {
                                    /* printf("\nselection-statement rule 2>\n"); */
                                    $$ = new exp_attr;
                                    Q_arr.backpatch($4->nextlist , Q_arr.index);
                                    Q_arr.convInt2Bool($3);

                                    $$->nextlist = merge($7->nextlist, $8->nextlist);
                                    Q_arr.backpatch($3->truelist, $6->instr);
                                    Q_arr.backpatch($3->falselist, $10->instr);
                                    $$->nextlist = merge($$->nextlist, $11->nextlist);
                                    $$->nextlist = merge($$->nextlist, $12->nextlist);
                                }|
                                IF '(' expression N ')' M statement N {
                                    /* printf("\nselection-statement rule 1>\n"); */
                                    $$ = new exp_attr;
                                    Q_arr.backpatch($4->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($3);

                                    Q_arr.backpatch($3->truelist, $6->instr);

                                    $$->nextlist = merge($8->nextlist, $7->nextlist);
                                    $$->nextlist = merge($$->nextlist, $3->falselist);
                                }|
                                SWITCH '(' expression ')' statement {
                                    /* printf("\nselection-statement rule 3>\n"); */
                                };

iteration_statement:            WHILE M '('  expression N ')' M statement {
                                    /* printf("\niteration-statement rule 1>\n"); */
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),$2->instr);

                                    Q_arr.backpatch($5->nextlist,Q_arr.index);
                                    Q_arr.convInt2Bool($4);

                                    $$ = new exp_attr;
                                    Q_arr.backpatch($8->nextlist, $2->instr);
                                    Q_arr.backpatch($4->truelist, $7->instr);
                                    $$->nextlist = $4->falselist;
                                }|
                                DO M statement M WHILE '(' expression ')' ';' {
                                    /* printf("\niteration-statement rule 2>\n"); */
                                    $$ = new exp_attr;
                                    Q_arr.convInt2Bool($7);
                                    Q_arr.backpatch($3->nextlist, $4->instr);
                                    Q_arr.backpatch($7->truelist, $2->instr);
                                    $$->nextlist = $7->falselist;
                                }|
                                FOR '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement {
                                    /* printf("\niteration-statement rule 3>\n"); */
                                    $$ = new exp_attr;

                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),$9->instr);
                                    Q_arr.backpatch($7->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool($6);

                                    Q_arr.backpatch($11->nextlist,$5->instr);
                                    Q_arr.backpatch($6->truelist,$13->instr);
                                    Q_arr.backpatch($14->nextlist,$9->instr);

                                    $$->nextlist = $6->falselist;
                                }|
                                FOR '(' declaration expression_opt ';' expression_opt ')' statement {
                                    /* printf("\niteration-statement rule 4>\n"); */
                                    // Not to be produced, as per assignment
                                };

jump_statement:                 GOTO_KEYWORD ID ';' {
                                    /* printf("\njump-statement rule 1>\n"); */
                                }|
                                CONTINUE ';' {
                                    /* printf("\njump-statement rule 2>\n"); */
                                }|
                                BREAK ';' {
                                    /* printf("\njump-statement rule 3>\n"); */
                                }|
                                RETURN_KEYWORD ';' {
                                    /* printf("\njump-statement rule 4>\n"); */
                                    $$ = new exp_attr;
                                    if(curr_sym->lookup("retVal")->type.type_name.compare("void")==0)
                                    {
                                        Q_arr.emit(RETURN_VOID,"","","");
                                    }
                                }|
                                RETURN_KEYWORD expression ';' {
                                    $$ = new exp_attr;
                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup("retVal")->type;
                                    type2 = curr_sym->lookup($2->loc)->type;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        Q_arr.emit(RETURN, $2->loc, "", "");
                                    }
                                    else{
                                        // mismatch of return type , maybe convert ?
                                    }
                                };

/*External Definitions*/
translation_unit:               external_declaration  {
                                        /* printf("\n<translation-unit rule 1>\nSuccessful\n"); */
                                }|
                                translation_unit external_declaration {
                                    /* printf("\n<translation-unit rule 2>\nSuccessful\n"); */
                                };

external_declaration:           function_definition {
                                    /* printf("\nexternal-declaration rule 1>\n"); */
                                }|
                                declaration {
                                    /* printf("\nexternal-statement rule 2>\n"); */
                                };

function_definition:            declaration_specifiers declarator compound_statement {
                                    /* printf("\nfunction-definition rule 1>\n"); */
                                    declaration *new_dec = $2;
                                    int size = 0;
                                    type_inf *type = $1;
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("double")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    //cout<<$2->type->type_name;
                                    symboltable *gt = &GT;
                                    symtab *func = gt->lookup($2->dec_name);
                                    func->nested_table = new symboltable;
                                    symtab *ret = func->nested_table->lookup("retVal", type->type_name, $2->pc);
                                    ret->offset = curr_sym->offset;
                                    ret->size = size;
                                    ret->init_val = NULL;
                                    //curr_sym = func->nested_table;
                                    $$ = $2;
                                }|
                                declaration_specifiers declarator declaration_list compound_statement {
                                    /* printf("\nfunction-definition rule 1>\n"); */
                                };

declaration_list:               declaration {
                                    /* printf("\ndeclaration-list rule 1>\n"); */
                                }|
                                declaration_list declaration {
                                    /* printf("\ndeclaration-list rule 2>\n"); */
                                };

%%

void yyerror(string s){
    printf("\nError occured\n");
}

int main()
{
    yydebug = 1;
    bool failure = yyparse();
    int arr_size = Q_arr.arr.size();
    cout<<"********************Printing Quads**********************\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"*********************Quads******************************\n";
    for(int i = 0; i<arr_size;i++)
    {
        cout<<i<<" : ";
        Q_arr.arr[i].print();
    }

    cout<<"----------------SYMBOL TABLE-----------------------\n";
    symboltable *g = &GT;
    g->print();
    cout<<"----------------------------------------------------\n";
    //cout<<g->no_of_entries<<endl;

    cout<<"----------------Compilation Result------------------\n";
    if(failure)
        printf("Compilation Failure\n");
    else
        printf("Compilation Success\n");
    cout<<"*****************************************************\n";

}
