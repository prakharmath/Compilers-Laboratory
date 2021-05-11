%{
    #include <stdio.h>
    extern int yylex();
    void yyerror(const char *s);
%}

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH
%token TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY
%token POINTER INCREMENT DECREMENT LEFT_SHIFT RIGHT_SHIFT LESS_EQUALS GREATER_EQUALS EQUALS NOT_EQUALS
%token AND OR ELLIPSIS MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN ADD_ASSIGN SUBTRACT_ASSIGN
%token LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SCOMMENT MCOMMENT
%token ID
%token CONST_INT
%token CONST_ENUM
%token CONST_FLT
%token STRING
%token CONST_CHAR

%start translation_unit

%%

// Rules start here

primary_expression:             ID { printf("\nprimary expression rule 1\n");} |
                                CONST_INT {printf("\nprimary expression rule 2\n");} |
                                CONST_FLT {printf("\nprimary expression rule 2\n");} |
                                CONST_CHAR {printf("\nprimary expression rule 2\n");} |
                                STRING {printf("\nprimary expression rule 3\n");} |
                                '(' expression ')' {
                                printf("\nprimary expression rule 4\n");
                                                   };

enumeration_constant:            ID {};

postfix_expression :            primary_expression {printf("\n<postfix-expression rule 1>\n");} |
                                postfix_expression '[' expression ']' {printf("\n<postfix-expression rule 2>\n");} |
                                postfix_expression '(' argument_expression_list_opt ')' {printf("\n<postfix-expression rule 3>\n");} |
                                postfix_expression '.' ID {printf("\n<postfix-expression rule 4>\n");}|
                                postfix_expression POINTER ID {printf("\n<postfix-expression rule 5>\n");} |
                                postfix_expression INCREMENT {printf("\n<postfix-expression rule 6>\n");} |
                                postfix_expression DECREMENT {printf("\n<postfix-expression rule 7>\n");} |
                                '(' type_name ')' '{' initializer_list '}' {printf("\n<postfix-expression rule 8>\n");}|
                                '(' type_name ')' '{' initializer_list ',' '}' {printf("\n<postfix-expression rule 1>\n");};

argument_expression_list:       assignment_expression {printf("\n<argument-expression-list rule 1>\n");}|
                                argument_expression_list ',' assignment_expression {printf("\n<argument-expression-list rule 1>\n");};

argument_expression_list_opt:   argument_expression_list {printf("\n<argument-expression-list-opt rule 1>\n");}|
                                /*epsilon*/;

unary_expression:               postfix_expression {printf("\n<unary-expression rule 1>\n");}|
                                INCREMENT unary_expression {printf("\n<unary-expression rule 2>\n");}|
                                DECREMENT unary_expression {printf("\n<unary-expression rule 3>\n");}|
                                unary_operator cast_expression {printf("\n<unary-expression rule 4>\n");}|
                                SIZEOF unary_expression {printf("\n<unary-expression rule 5>\n");}|
                                SIZEOF '(' type_name ')' {printf("\n<unary-expression rule 6>\n");};

unary_operator  :               '&' {printf("\nUnary operator - AND\n");}|
                                '*' {printf("\nUnary operator - STAR\n");}|
                                '+' {printf("\nUnary operator - PLUS\n");}|
                                '-' {printf("\nUnary operator - MINUS\n");}|
                                '~' {printf("\nUnary operator - TILDE\n");}|
                                '!' {printf("\nUnary operator - NOT\n");};

cast_expression :               unary_expression {printf("\n<cast-expression rule 1>\n");}|
                                '(' type_name ')' cast_expression{printf("\n<cast-expression rule 2>\n");};

multiplicative_expression:      cast_expression {printf("\n<multiplicative-expression rule 1>\n");}|
                                multiplicative_expression '*' cast_expression {printf("\n<multiplicative-expression rule 2>\n");}|
                                multiplicative_expression '/' cast_expression {printf("\n<multiplicative-expression rule 3>\n");}|
                                multiplicative_expression '%' cast_expression {printf("\n<multiplicative-expression rule 4>\n");};

additive_expression :           multiplicative_expression {printf("\n<additive-expression rule 1>\n");}|
                                additive_expression '+' multiplicative_expression {printf("\n<additive-expression rule 2>\n");}|
                                additive_expression '-' multiplicative_expression {printf("\n<additive-expression rule 3>\n");};

shift_expression:               additive_expression {printf("\n<shift-expression rule 1>\n");}|
                                shift_expression LEFT_SHIFT additive_expression {printf("\n<shift-expression rule 2>\n");}|
                                shift_expression RIGHT_SHIFT additive_expression {printf("\n<shift-expression rule 3>\n");};

relational_expression:          shift_expression {printf("\n<relational-expression rule 1>\n");}|
                                relational_expression '<' shift_expression {printf("\n<relational-expression rule 2>\n");}|
                                relational_expression '>' shift_expression {printf("\n<relational-expression rule 3>\n");}|
                                relational_expression LESS_EQUALS shift_expression {printf("\n<relational-expression rule 4>\n");}|
                                relational_expression GREATER_EQUALS shift_expression {printf("\n<relational-expression rule 5>\n");};

equality_expression:            relational_expression {printf("\n<equality-expression rule 1>\n");}|
                                equality_expression EQUALS relational_expression {printf("\n<equality-expression rule 2>\n");}|
                                equality_expression NOT_EQUALS relational_expression {printf("\n<equality-expression rule 3>\n");};

AND_expression :                equality_expression {printf("\n<AND-expression rule 1>\n");}|
                                AND_expression '&' equality_expression {printf("\n<AND-expression rule 2>\n");};

exclusive_OR_expression:        AND_expression {printf("\n<exclusive-OR-expression rule 1>\n");}|
                                exclusive_OR_expression '^' AND_expression {printf("\n<exclusive-OR-expression rule 2>\n");};

inclusive_OR_expression:        exclusive_OR_expression {printf("\n<inclusive-OR-expression rule 1>\n");}|
                                inclusive_OR_expression '|' exclusive_OR_expression {printf("\n<inclusive-OR-expression rule 2>\n");};

logical_AND_expression:         inclusive_OR_expression {printf("\n<logical-AND-expression rule 1>\n");};|
                                logical_AND_expression AND inclusive_OR_expression {printf("\n<logical-AND-expression rule 2>\n");};

logical_OR_expression:          logical_AND_expression {printf("\n<logical-OR-expression rule 1>\n");};|
                                logical_OR_expression OR logical_AND_expression   {printf("\n<logical-expression rule 2>\n");};

/*It is assumed that type of expression and conditional expression are same*/
conditional_expression:         logical_OR_expression {printf("\n<conditional-expression rule 1>\n");};|
                                logical_OR_expression '?' expression ':' conditional_expression {printf("\n<conditional-expression rule 2>\n");};

assignment_operator:            '=' {printf("\nAssignment operator :: =\n"); }                      |
                                MULTIPLY_ASSIGN {printf("\nAssignment operator :: *=\n");}           |
                                DIVIDE_ASSIGN {printf("\nAssignment operator :: /=\n");}                                          |
                                MODULO_ASSIGN                                    {printf("\nAssignment operator :: =\n");}       |
                                ADD_ASSIGN                                       {printf("\nAssignment operator :: +=\n");}       |
                                SUBTRACT_ASSIGN                                  {printf("\nAssignment operator :: -=\n");}       |
                                LEFT_SHIFT_ASSIGN                                 {printf("\nAssignment operator :: <<=\n");}      |
                                RIGHT_SHIFT_ASSIGN                                {printf("\nAssignment operator :: >>=\n");}      |
                                AND_ASSIGN                                        {printf("\nAssignment operator :: &=\n");}      |
                                XOR_ASSIGN                                        {printf("\nAssignment operator :: ^=\n");}      |
                                OR_ASSIGN                                         {printf("\nAssignment operator :: |=\n");}      ;

assignment_expression:          conditional_expression {printf("\n<assignment-expression rule 1>\n");}|
                                unary_expression assignment_operator assignment_expression {printf("\n<assignment-expression rule 2>\n");};

/*A constant value of this expression exists*/
constant_expression:            conditional_expression {printf("\n<constant-expression rule 1>\n");};

expression :                    assignment_expression {printf("\n<expression rule 1>\n");}|
                                expression ',' assignment_expression {printf("\n<expression rule 2>\n");};

/*Declarations*/

declaration:                    declaration_specifiers init_declarator_list_opt ';' {printf("\n<declaration rule 1>\n");};

init_declarator_list_opt:       init_declarator_list {printf("\n<init-declarator-list-opt rule 1>\n");}|
                                /*epsilon*/ {};

declaration_specifiers:         storage_class_specifier declaration_specifiers_opt {printf("\n<declaration-specifiers rule 1>\n");}|
                                type_specifier declaration_specifiers_opt {printf("\n<declaration-specifiers rule 2>\n");}               |
                                type_qualifier declaration_specifiers_opt {printf("\n<declaration-specifiers rule 3>\n");}|
                                function_specifier declaration_specifiers_opt {printf("\n<declaration-specifiers rule 4>\n");};

declaration_specifiers_opt:     declaration_specifiers {printf("\n<declaration-specifiers-opt rule 1>\n");}                                  |
                                /*epsilon*/                                             ;

init_declarator_list:           init_declarator {printf("\n<init-declarator-list rule 1>\n");}|
                                init_declarator_list ',' init_declarator {printf("\n<init-declarator-list rule 2>\n");}                ;

init_declarator:                declarator {printf("\n<init-declarator rule 1>\n");}|
                                declarator '=' initializer {printf("\n<init-declarator rule 2>\n");};

storage_class_specifier:        EXTERN {printf("\n<storage-class-specifier :: extern>\n");}|
                                STATIC {printf("\n<storage-class-specifier :: static>\n");}|
                                AUTO {printf("\n<storage-class-specifier :: auto>\n");}|
                                REGISTER {printf("\n<storage-class-specifier :: register>\n");};

type_specifier:                 VOID {printf("\n<type-specifier :: void>\n");}|
                                CHAR {printf("\n<type-specifier :: char>\n");}|
                                SHORT {printf("\n<type-specifier :: short>\n");}|
                                INT {printf("\n<type-specifier :: int>\n");}|
                                LONG {printf("\n<type-specifier :: long>\n");}|
                                FLOAT {printf("\n<type-specifier :: float>\n");}|
                                DOUBLE {printf("\n<type-specifier :: double>\n");}|
                                SIGNED {printf("\n<type-specifier :: signed>\n");}|
                                UNSIGNED {printf("\n<type-specifier :: unsigned>\n");}|
                                BOOL {printf("\n<type-specifier :: _Bool>\n");}|
                                COMPLEX {printf("\n<type-specifier :: _Complex>\n");}|
                                IMAGINARY {printf("\n<type-specifier :: _Imaginary>\n");}|
                                enum_specifier {printf("\n<type-specifier :: enum>\n");};

specifier_qualifier_list:       type_specifier specifier_qualifier_list_opt {printf("\n<specifier-qualifier-list rule 1>\n");}|
                                type_qualifier specifier_qualifier_list_opt {printf("\n<specifier-qualifier-list rule 2>\n");};

specifier_qualifier_list_opt:   specifier_qualifier_list {printf("\n<specifier-qualifier-list-opt rule 1>\n");}|
                                /*epsilon*/ {};

enum_specifier:                 ENUM ID_opt '{' enumerator_list '}' {printf("\n<enum-specifier rule 1>\n");}|
                                ENUM ID_opt '{' enumerator_list ',' '}' {printf("\n<enum-specifier rule 2>\n");}|
                                ENUM ID {printf("\n<enum-specifier rule 3>\n");};

ID_opt:                         ID {printf("\n<identifier rule 1>\n");}|
                                /*epsilon*/ {};

enumerator_list:                enumerator {printf("\n<enumerator-list rule 1>\n");}|
                                enumerator_list ',' enumerator {printf("\n<enumerator-list rule 2>\n");};

enumerator:                     CONST_ENUM {printf("\n<enumerator rule 1>\n");}|
                                CONST_ENUM '=' constant_expression {printf("\n<enumerator rule 2>\n");};

type_qualifier:                 CONST {printf("\n<type-qualifier :: const>\n");}|
                                RESTRICT {printf("\n<type-qualifier :: inline>\n");}|
                                VOLATILE {printf("\n<type-qualifier :: volatile>\n");};

function_specifier:             INLINE {printf("\n<function-specifier :: inline>\n");};

declarator :                    pointer_opt direct_declarator {printf("\n<declarator rule 1>\n");};

pointer_opt:                    pointer {printf("\n<pointer-opt rule 1>\n");}|
                                /*epsilon*/{};

direct_declarator:              ID {printf("\n<direct-declarator rule 1>\n");}|
                                '(' declarator ')' {printf("\n<direct-declarator rule 2>\n");}|
                                direct_declarator '[' type_qualifier_list_opt assignment_expression_opt ']' {printf("\n<direct-declarator rule 3>\n");}|
                                direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']' {printf("\n<direct-declarator rule 4>\n");}|
                                direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' {printf("\n<direct-declarator rule 5>\n");}|
                                direct_declarator '[' type_qualifier_list_opt '*' ']' {printf("\n<direct-declarator rule 6>\n");}|
                                direct_declarator '(' parameter_type_list ')' {printf("\n<direct-declarator rule 7>\n");}|
                                direct_declarator '(' ID_list_opt ')' {printf("\n<direct-declarator rule 8>\n");};

type_qualifier_list_opt:        type_qualifier_list {printf("\n<type-qualifier-list-opt rule 1>\n");}|
                                /*epsilon*/ {};

assignment_expression_opt:      assignment_expression {printf("\n<assignment-expression-opt rule 1>\n");}|
                                /*epsilon*/ {};

ID_list_opt:                    ID_list {printf("\n<identifier-list-opt rule 1>\n");}                                         |
                                /*epsilon*/                                             ;

pointer:                        '*' type_qualifier_list_opt {printf("\n<pointer rule 1>\n");}|
                                '*' type_qualifier_list_opt pointer {printf("\n<pointer rule 2>\n");};

type_qualifier_list:            type_qualifier {printf("\n<type-qualifier-list rule 1>\n");}|
                                type_qualifier_list type_qualifier {printf("\n<type-qualifier-list rule 2>\n");};

parameter_type_list:            parameter_list {printf("\n<parameter-type-list rule 1>\n");}|
                                parameter_list ',' ELLIPSIS {printf("\n<parameter-type-list rule 2>\n");};

parameter_list:                 parameter_declaration {printf("\n<parameter-list rule 1>\n");}|
                                parameter_list ',' parameter_declaration {printf("\n<parameter-list rule 2>\n");};

parameter_declaration:          declaration_specifiers declarator {printf("\n<parameter-declaration rule 1>\n");}|
                                declaration_specifiers {printf("\n<parameter-declaration rule 2>\n");};

ID_list :                       ID {printf("\n<identifier-list rule 1>\n");}                                              |
                                ID_list ',' ID {printf("\n<identifier-list rule 2>\n");}                         ;

type_name:                      specifier_qualifier_list {printf("\n<type-name rule 1>\n");}                               ;

initializer:                    assignment_expression {printf("\n<initializer rule 1>\n");}|
                                '{' initializer_list '}' {printf("\n<initializer rule 2>\n");}|
                                '{' initializer_list ',' '}' {printf("\n<initializer rule 3>\n");};

initializer_list:               designation_opt initializer {printf("\n<initializer-list rule 1>\n");}                             |
                                initializer_list ',' designation_opt initializer {printf("\n<initializer-list rule 2>\n");}        ;

designation_opt:                designation  {printf("\n<designation-opt rule 1>\n");}                                           |
                                /*Epslion*/                                             ;

designation:                    designator_list '=' {printf("\n<designation rule 1>\n");}                                    ;

designator_list:                designator {printf("\ndesignator-list rule 1>\n");}                                              |
                                designator_list designator {printf("\ndesignator-list rule 2>\n");}                             ;

designator:                     '[' constant_expression ']' {printf("\ndesignator rule 1>\n");}                            |
                                '.' ID {printf("\ndesignator rule 2>\n");};

/*Statements*/
statement:                      labeled_statement {printf("\nstatement rule 1>\n");}|
                                compound_statement {printf("\nstatement rule 2>\n");}|
                                expression_statement {printf("\nstatement rule 3>\n");}|
                                selection_statement {printf("\nstatement rule 4>\n");}|
                                iteration_statement {printf("\nstatement rule 5>\n");}|
                                jump_statement {printf("\nstatement rule 6>\n");};

labeled_statement:              ID ':' statement {printf("\nlabeled-statement rule 1>\n");}|
                                CASE constant_expression ':' statement {printf("\nlabeled-statement rule 2>\n");}|
                                DEFAULT ':' statement {printf("\nlabeled-statement rule 3>\n");};

compound_statement:             '{' block_item_list_opt '}' {printf("\ncompound-statement rule 1>\n");};

block_item_list_opt:            block_item_list {printf("\nblock-item-list-opt rule 1>\n");}|
                                /*Epslion*/ {};

block_item_list:                block_item {printf("\nblock-item-list rule 1>\n");}|
                                block_item_list_opt block_item {printf("\nblock-item-list rule 2>\n");};

block_item:                     declaration {printf("\nblock-item rule 1>\n");}|
                                statement {printf("\nblock-item rule 2>\n");};

expression_statement:           expression_opt ';'{printf("\nexpression-statement rule 1>\n");};

expression_opt:                 expression {printf("\nexpression-opt rule 1>\n");}|
                                /*Epslion*/ {};

selection_statement:            IF '(' expression ')' statement ELSE statement {printf("\nselection-statement rule 2>\n");}|
                                IF '(' expression ')' statement %prec IF_CONFLICT{printf("\nselection-statement rule 1>\n");}|
                                SWITCH '(' expression ')' statement {printf("\nselection-statement rule 3>\n");};

iteration_statement:            WHILE '('  expression ')'  statement {printf("\niteration-statement rule 1>\n");}|
                                DO statement  WHILE '(' expression ')' ';' {printf("\niteration-statement rule 2>\n");}|
                                FOR '(' expression_opt ';' expression_opt ';' expression_opt ')' statement {printf("\niteration-statement rule 3>\n");}|
                                FOR '(' declaration expression_opt ';' expression_opt ')' statement {printf("\niteration-statement rule 4>\n");};

jump_statement:                 GOTO ID ';' {printf("\njump-statement rule 1>\n");}|
                                CONTINUE ';' {printf("\njump-statement rule 2>\n");}|
                                BREAK ';' {printf("\njump-statement rule 3>\n");}|
                                RETURN expression_opt ';' {printf("\njump-statement rule 4>\n");};

/*External Definitions*/
translation_unit:               external_declaration  {printf("\n<translation-unit rule 1>\nSuccessful\n");}                            |
                                translation_unit external_declaration {printf("\n<translation-unit rule 2>\nSuccessful\n");}                  ;

external_declaration:           function_definition {printf("\nexternal-declaration rule 1>\n");}                                    |
                                declaration      {printf("\nexternal-statement rule 2>\n");}                                       ;

function_definition:            declaration_specifiers declarator declaration_list_opt compound_statement {printf("\nfunction-definition rule 1>\n");};

declaration_list_opt:           declaration_list {printf("\ndeclaration-list-opt rule 1>\n");}                                        |
                                /*epsilon*/                                             ;

declaration_list:               declaration {printf("\ndeclaration-list rule 1>\n");}                                            |
                                declaration_list declaration {printf("\ndeclaration-list rule 2>\n");}                           ;

%%

void yyerror(const char *s){
    printf("\nError occured\n");
}