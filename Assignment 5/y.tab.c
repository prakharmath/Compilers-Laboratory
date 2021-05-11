/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ass5_17CS10036_17CS30013.y" /* yacc.c:339  */

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

#line 85 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO_KEYWORD = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN_KEYWORD = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    POINTER = 295,
    INCREMENT = 296,
    DECREMENT = 297,
    LEFT_SHIFT = 298,
    RIGHT_SHIFT = 299,
    LESS_EQUALS = 300,
    GREATER_EQUALS = 301,
    EQUALS = 302,
    NOT_EQUALS = 303,
    AND_OP = 304,
    OR_OP = 305,
    ELLIPSIS = 306,
    MULTIPLY_ASSIGN = 307,
    DIVIDE_ASSIGN = 308,
    MODULO_ASSIGN = 309,
    ADD_ASSIGN = 310,
    SUBTRACT_ASSIGN = 311,
    LEFT_SHIFT_ASSIGN = 312,
    RIGHT_SHIFT_ASSIGN = 313,
    AND_ASSIGN = 314,
    XOR_ASSIGN = 315,
    OR_ASSIGN = 316,
    SCOMMENT = 317,
    MCOMMENT = 318,
    ID = 319,
    CONST_INT = 320,
    CONST_ENUM = 321,
    CONST_FLT = 322,
    STRING = 323,
    CONST_CHAR = 324
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO_KEYWORD 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN_KEYWORD 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define BOOL 292
#define COMPLEX 293
#define IMAGINARY 294
#define POINTER 295
#define INCREMENT 296
#define DECREMENT 297
#define LEFT_SHIFT 298
#define RIGHT_SHIFT 299
#define LESS_EQUALS 300
#define GREATER_EQUALS 301
#define EQUALS 302
#define NOT_EQUALS 303
#define AND_OP 304
#define OR_OP 305
#define ELLIPSIS 306
#define MULTIPLY_ASSIGN 307
#define DIVIDE_ASSIGN 308
#define MODULO_ASSIGN 309
#define ADD_ASSIGN 310
#define SUBTRACT_ASSIGN 311
#define LEFT_SHIFT_ASSIGN 312
#define RIGHT_SHIFT_ASSIGN 313
#define AND_ASSIGN 314
#define XOR_ASSIGN 315
#define OR_ASSIGN 316
#define SCOMMENT 317
#define MCOMMENT 318
#define ID 319
#define CONST_INT 320
#define CONST_ENUM 321
#define CONST_FLT 322
#define STRING 323
#define CONST_CHAR 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "ass5_17CS10036_17CS30013.y" /* yacc.c:355  */

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

#line 276 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  363

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,     2,     2,     2,    85,    78,     2,
      70,    71,    79,    80,    77,    81,    74,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    93,
      86,    92,    87,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    89,    76,    82,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   109,   114,   122,   135,   148,   161,   164,
     171,   175,   187,   190,   206,   209,   212,   222,   232,   235,
     239,   247,   256,   259,   271,   283,   311,   314,   318,   322,
     326,   330,   334,   338,   343,   346,   350,   354,   436,   518,
     601,   605,   687,   770,   774,   814,   855,   859,   869,   879,
     889,   900,   904,   914,   925,   928,   938,   941,   951,   954,
     964,   967,   990,   993,  1017,  1020,  1050,  1053,  1056,  1059,
    1062,  1065,  1068,  1071,  1074,  1077,  1080,  1084,  1087,  1094,
    1098,  1101,  1106,  1109,  1181,  1184,  1187,  1190,  1194,  1197,
    1199,  1204,  1210,  1215,  1221,  1224,  1227,  1230,  1234,  1240,
    1246,  1249,  1255,  1258,  1261,  1267,  1270,  1273,  1276,  1279,
    1282,  1286,  1290,  1294,  1297,  1299,  1302,  1305,  1309,  1312,
    1314,  1317,  1321,  1324,  1328,  1331,  1334,  1338,  1342,  1347,
    1350,  1352,  1357,  1361,  1367,  1370,  1373,  1376,  1398,  1402,
    1405,  1407,  1410,  1412,  1415,  1417,  1423,  1432,  1435,  1439,
    1443,  1447,  1452,  1458,  1464,  1468,  1471,  1475,  1479,  1483,
    1486,  1490,  1493,  1497,  1499,  1502,  1506,  1509,  1513,  1516,
    1521,  1524,  1527,  1530,  1533,  1536,  1540,  1543,  1546,  1550,
    1553,  1557,  1562,  1569,  1573,  1577,  1582,  1586,  1590,  1602,
    1613,  1617,  1630,  1638,  1653,  1658,  1661,  1664,  1667,  1675,
    1690,  1693,  1697,  1700,  1704,  1723,  1727,  1730
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO_KEYWORD", "IF", "INLINE", "INT", "LONG", "REGISTER",
  "RESTRICT", "RETURN_KEYWORD", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "BOOL", "COMPLEX", "IMAGINARY", "POINTER", "INCREMENT",
  "DECREMENT", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_EQUALS",
  "GREATER_EQUALS", "EQUALS", "NOT_EQUALS", "AND_OP", "OR_OP", "ELLIPSIS",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MODULO_ASSIGN", "ADD_ASSIGN",
  "SUBTRACT_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "SCOMMENT", "MCOMMENT", "ID",
  "CONST_INT", "CONST_ENUM", "CONST_FLT", "STRING", "CONST_CHAR", "'('",
  "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "$accept", "M", "N", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression", "assignment_operator",
  "assignment_expression", "constant_expression", "expression",
  "declaration", "declaration_specifiers", "declaration_specifiers_opt",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "ID_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "pointer_opt", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt", "ID_list_opt",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "ID_list", "type_name",
  "initializer", "initializer_list", "designation_opt", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      40,    41,    91,    93,    46,   123,   125,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59
};
# endif

#define YYPACT_NINF -261

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-261)))

#define YYTABLE_NINF -155

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1061,  -261,  -261,  -261,  -261,   -47,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,    15,  1061,  1061,  -261,  1061,  1061,  1024,
    -261,  -261,   -51,   -12,    26,  -261,    -5,  -261,   279,    39,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    11,  -261,
       5,    26,     5,   322,   752,  -261,    15,  -261,   723,  -261,
       5,   -19,     9,   -41,  -261,  -261,  -261,  -261,    37,    61,
     832,    70,    82,  -261,    99,   119,   117,   534,   852,   123,
    -261,   882,   882,   104,  -261,  -261,  -261,  -261,   642,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,    -3,   145,   832,
    -261,    21,    78,   142,   -27,   161,   111,   130,   144,   170,
     -35,  -261,  -261,   149,  -261,  -261,  -261,  -261,   158,  -261,
    -261,   143,  -261,  -261,  -261,  -261,    90,  -261,  -261,  -261,
    -261,   167,   762,    19,   832,  -261,    31,  -261,  -261,  -261,
     148,  -261,   564,   564,   484,   147,   832,  -261,   -43,   642,
    -261,   832,   173,   642,  -261,  -261,   564,    33,  1095,  -261,
    1095,   175,   183,  -261,  -261,   782,   832,   185,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,   832,
    -261,   832,   832,   832,   832,   832,   832,   832,   832,   832,
     832,   832,   832,   832,   832,   832,   832,   201,   -28,   832,
    -261,   403,  -261,   832,   187,   134,   752,  -261,   -26,  -261,
    -261,  -261,    65,   181,   188,   177,  -261,   186,    26,   902,
      45,  -261,  -261,  -261,   564,  -261,  -261,   832,   169,  -261,
     149,  -261,   193,    66,   832,   194,  -261,  -261,  -261,  -261,
    -261,   802,  -261,  -261,    68,  -261,     2,  -261,  -261,  -261,
    -261,  -261,    21,    21,    78,    78,   142,   142,   142,   142,
     -27,   -27,   161,   111,   130,  -261,  -261,  -261,  -261,  -261,
     198,  -261,  -261,    81,  -261,  -261,  -261,  -261,  -261,  -261,
     983,   202,   832,   200,  -261,   203,   832,  -261,   231,   184,
    -261,   208,   199,   564,   149,   199,    90,  -261,  -261,   832,
    -261,   832,   832,   832,  -261,  -261,   752,  -261,  -261,  -261,
     214,  -261,  -261,   215,   219,   832,   832,  -261,  -261,   220,
     137,  -261,   144,  -261,   149,  -261,  -261,  -261,   832,   224,
    -261,   564,  -261,  -261,    98,  -261,   201,   205,    75,   564,
     204,  -261,   564,  -261,  -261,   210,  -261,  -261,   294,  -261,
     832,  -261,   832,  -261,  -261,  -261,   564,   237,  -261,  -261,
    -261,   564,  -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    99,   124,   104,   119,    94,   103,   127,   101,
     102,    97,   125,   100,   105,    95,   106,    98,   126,   107,
     108,   109,   203,   130,    89,    89,   110,    89,    89,     0,
     200,   202,   117,     0,   140,    82,    83,    90,    92,     0,
     129,    88,    84,    85,    86,    87,     1,   201,     0,   147,
     145,   139,   130,   187,     0,   206,   130,   204,     0,   131,
     130,   128,   122,     0,   120,   146,   148,    91,    92,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     4,     5,     6,     8,     7,     0,   179,
      28,    29,    30,    31,    32,    33,    10,    22,    34,     0,
      36,    40,    43,    46,    51,    54,    56,    58,    60,    62,
      64,    77,    80,   186,   183,   184,   170,   171,     2,   181,
     172,     0,   173,   174,   175,     4,   164,   158,    93,   207,
     205,     0,   144,   140,     0,   115,     0,   197,    34,    79,
       0,   196,   187,   187,   187,     0,     0,   198,     0,     0,
      26,     0,     0,     0,    23,    24,   187,     0,   114,   157,
     114,     0,     0,    16,    17,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    66,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   187,   185,     0,     0,     0,     0,   163,     0,   166,
     132,   155,   130,     0,     0,   149,   151,   143,   140,   142,
     139,   123,   116,   121,   187,   178,     2,   187,     0,   195,
       3,   199,     0,     0,     0,     0,   176,     9,   113,   111,
     112,     0,    15,    12,     0,    20,     0,    14,    78,    37,
      38,    39,    41,    42,    44,    45,    49,    50,    47,    48,
      52,    53,    55,    57,    59,     2,     2,     2,    81,   182,
       0,   169,   159,   164,   161,   165,   167,   153,   138,   137,
       0,     0,     0,    29,   141,     0,     0,   177,     0,     0,
       2,     0,    27,   187,     3,     0,   164,    35,    13,     0,
      11,     0,     0,     0,   168,   160,     0,   150,   152,   156,
       0,   136,   133,     0,     0,   187,   187,     2,   190,     0,
       0,    21,     3,     3,     3,   162,   134,   135,     0,     0,
       3,   187,     2,    18,   164,    61,    63,     0,     0,   187,
       0,     3,   187,    19,     2,     0,   194,     2,   189,   191,
       0,   192,   187,     2,    65,     3,   187,     0,     3,     2,
     188,   187,   193
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,   -75,  -100,  -261,  -261,  -261,   -70,  -261,   -93,    32,
      34,   -11,    36,   115,   116,   114,    14,    17,  -261,   -69,
    -261,   -38,  -111,   -68,   -13,     3,   122,  -261,   268,  -261,
     -67,    24,   162,  -261,  -261,  -261,   217,     7,  -261,   -16,
    -261,  -261,  -119,  -261,  -261,   271,   190,  -261,  -261,    44,
    -261,   -21,  -204,    55,  -260,  -261,  -261,   126,   -86,  -261,
      38,  -261,   164,  -261,  -140,  -261,  -261,  -261,  -261,   333,
    -261,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   143,   197,    96,    97,   244,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     179,   112,   140,   113,    22,    56,    42,    36,    37,    24,
      25,   159,   239,    26,    33,    63,    64,    27,    28,    68,
      39,    61,    50,   285,   213,    40,    51,   214,   215,   216,
     217,   161,   128,   205,   206,   207,   208,   209,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    29,    30,
      31,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     138,   139,   274,    23,   228,   152,   180,    38,   150,   148,
     198,   154,   155,   306,   219,    -3,   127,    32,   188,   189,
     157,   158,   266,   221,  -118,    55,     3,    41,    41,   138,
      41,    41,    23,     3,   199,   135,   136,   162,   163,   164,
     114,    49,    12,   201,   131,   129,   203,   218,   204,    12,
     231,   132,     3,   133,    18,    -3,   225,   226,    66,   190,
     191,    18,   267,    48,   138,   139,   275,   165,    12,   166,
     236,   167,    52,   286,   306,   300,    57,    62,   230,   199,
      18,   157,   158,   233,    34,   157,   158,   289,   249,   250,
     251,   158,   270,   158,    34,   160,   130,    62,   246,   282,
     181,   134,   325,    59,   237,   182,   183,   222,    35,    60,
     199,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   245,   232,    54,
     291,   227,   235,   138,   139,   212,  -154,   293,   287,   298,
      49,   248,  -154,   199,    34,   299,   345,    43,   297,    44,
      45,   288,   199,   203,   137,   204,   160,   305,   184,   185,
     160,   268,   203,   141,   204,   160,   294,   160,   127,   144,
     203,   138,   204,   142,   343,   329,   330,   256,   257,   258,
     259,   284,   238,   145,   238,   186,   187,   146,   114,   194,
     301,   302,   303,   151,   319,   156,   277,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   318,   192,   193,
     272,   273,   355,   333,   334,   316,   252,   253,   195,    -3,
     254,   255,   335,   336,   337,    49,   199,    66,   260,   261,
     340,   138,   138,   196,   200,   324,   202,   178,   210,   224,
     229,   348,   331,   234,   310,   341,   241,   242,   313,   247,
     265,   271,   278,   346,   280,   357,   349,   342,   360,   279,
     338,   321,   290,   281,   292,   295,   309,   314,   127,   350,
     358,   304,   352,   311,   296,   362,   312,   315,   356,   317,
     138,   354,     1,   212,   361,     2,     3,   326,   327,   328,
       4,   332,     5,     6,     7,   339,   344,   347,     8,     9,
      10,    11,    12,   351,    13,    14,   353,    15,   359,   262,
     264,   263,    16,    17,    18,   322,    19,    20,    21,   323,
      67,    65,   240,   220,   308,     1,    69,    70,     2,     3,
      71,    72,    73,     4,   276,     5,     6,     7,    74,    75,
      76,     8,     9,    10,    11,    12,    77,    13,    14,    78,
      15,   320,    79,   223,    53,    16,    17,    18,    80,    19,
      20,    21,    47,    81,    82,   269,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,    85,
      86,    87,    88,     0,     0,     0,     0,    53,    89,     0,
      90,    91,    92,    93,    94,    95,     1,    69,    70,     2,
       3,    71,    72,    73,     4,     0,     5,     6,     7,    74,
      75,    76,     8,     9,    10,    11,    12,    77,    13,    14,
      78,    15,     0,    79,     0,     0,    16,    17,    18,    80,
      19,    20,    21,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,     0,
      85,    86,    87,    88,     0,     0,     0,     0,    53,     0,
       0,    90,    91,    92,    93,    94,    95,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,    78,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,    84,
       0,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,    78,    90,    91,    92,    93,    94,    95,    69,    70,
       0,     0,    71,    72,    73,    81,    82,     0,     0,     0,
      74,    75,    76,     0,     0,     0,     0,     0,    77,     0,
       0,    78,     0,     0,    79,     0,     0,     0,   125,    84,
      80,    85,    86,    87,    88,    81,    82,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,    83,    84,
       0,    85,    86,    87,    88,     0,     0,     0,     0,    53,
       0,     0,    90,    91,    92,    93,    94,    95,     2,     3,
       0,     0,     0,     4,     0,     5,     0,     7,     0,     0,
       0,     0,     9,    10,     0,    12,     0,    13,    14,    78,
       0,     0,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,    84,     0,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21,     0,     0,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,    78,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,     0,     0,    81,    82,    16,    17,    18,    53,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,   125,    84,     0,    85,
      86,    87,    88,    81,    82,     0,   211,   126,     0,    78,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,   125,    84,     0,    85,
      86,    87,    88,   243,     0,     0,     0,     0,     0,    78,
      90,    91,    92,    93,    94,    95,   125,    84,     0,    85,
      86,    87,    88,    81,    82,     0,     0,   296,     0,    78,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,   125,    84,     0,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,    78,
      90,    91,    92,    93,    94,    95,   125,    84,     0,    85,
      86,    87,   149,    81,    82,     0,     0,     0,     0,    78,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,   125,    84,     0,    85,
      86,    87,   153,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,   125,    84,     0,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      90,   283,    92,    93,    94,    95,     1,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,     0,     0,     0,     0,    16,    17,    18,     0,
      19,    20,    21,     0,    46,     0,     0,     1,     0,     0,
       2,     3,     0,     0,   307,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,     1,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
       0,     0,     0,     0,    16,    17,    18,     0,    19,    20,
      21,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       7,     0,     0,     0,     0,     9,    10,     0,    12,     0,
      13,    14,     0,     0,     0,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      70,    70,   206,     0,   144,    80,    99,    23,    78,    77,
     110,    81,    82,   273,   133,    50,    54,    64,    45,    46,
      88,    88,    50,   134,    75,    38,     7,    24,    25,    99,
      27,    28,    29,     7,    77,    76,    77,    40,    41,    42,
      53,    34,    23,   118,    60,    58,    72,    28,    74,    23,
      93,    70,     7,    72,    35,    90,   142,   143,    51,    86,
      87,    35,    90,    75,   134,   134,    92,    70,    23,    72,
     156,    74,    77,    28,   334,    73,    38,    66,   146,    77,
      35,   149,   149,   151,    79,   153,   153,   227,   181,   182,
     183,   158,   203,   160,    79,    88,    58,    66,   166,   218,
      79,    92,   306,    64,    71,    84,    85,    76,    93,    70,
      77,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   165,   149,    92,
     230,   144,   153,   203,   203,   132,    71,    71,   224,    71,
     133,   179,    77,    77,    79,    77,    71,    25,   241,    27,
      28,   226,    77,    72,    93,    74,   149,    76,    80,    81,
     153,   199,    72,    93,    74,   158,   234,   160,   206,    70,
      72,   241,    74,    91,    76,   315,   316,   188,   189,   190,
     191,   219,   158,    64,   160,    43,    44,    70,   201,    78,
     265,   266,   267,    70,   294,    91,   212,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   293,    47,    48,
      76,    77,   352,    76,    77,   290,   184,   185,    88,    49,
     186,   187,   322,   323,   324,   218,    77,   220,   192,   193,
     330,   301,   302,    89,    76,   303,    93,    92,    71,    91,
      93,   341,   317,    70,   282,   331,    71,    64,   286,    64,
      49,    64,    71,   339,    77,   355,   342,   332,   358,    71,
     328,   299,    93,    77,    71,    71,    64,    36,   306,   344,
     356,    73,   347,    73,    75,   361,    73,    93,   353,    71,
     350,   350,     3,   280,   359,     6,     7,    73,    73,    70,
      11,    71,    13,    14,    15,    71,    91,    93,    19,    20,
      21,    22,    23,    93,    25,    26,    12,    28,    71,   194,
     196,   195,    33,    34,    35,   301,    37,    38,    39,   302,
      52,    50,   160,   133,   280,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   208,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   296,    30,   136,    75,    33,    34,    35,    36,    37,
      38,    39,    29,    41,    42,   201,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    78,    79,    80,    81,    82,    83,     4,     5,
      -1,    -1,     8,     9,    10,    41,    42,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    64,    65,
      36,    67,    68,    69,    70,    41,    42,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    64,    65,
      -1,    67,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,    -1,    -1,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    27,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    -1,    -1,    41,    42,    33,    34,    35,    75,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    70,    41,    42,    -1,    64,    75,    -1,    27,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    64,    65,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    27,
      78,    79,    80,    81,    82,    83,    64,    65,    -1,    67,
      68,    69,    70,    41,    42,    -1,    -1,    75,    -1,    27,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      78,    79,    80,    81,    82,    83,    64,    65,    -1,    67,
      68,    69,    70,    41,    42,    -1,    -1,    -1,    -1,    27,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,     3,    -1,    -1,     6,
       7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,    -1,     0,    -1,    -1,     3,    -1,    -1,
       6,     7,    -1,    -1,    51,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,
      39,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   118,   119,   123,   124,   127,   131,   132,   162,
     163,   164,    64,   128,    79,    93,   121,   122,   133,   134,
     139,   119,   120,   120,   120,   120,     0,   163,    75,   131,
     136,   140,    77,    75,    92,   118,   119,   154,   165,    64,
      70,   135,    66,   129,   130,   139,   131,   122,   133,     4,
       5,     8,     9,    10,    16,    17,    18,    24,    27,    30,
      36,    41,    42,    64,    65,    67,    68,    69,    70,    76,
      78,    79,    80,    81,    82,    83,    97,    98,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   115,   117,   118,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    64,    75,   115,   146,   118,
     154,   133,    70,    72,    92,    76,    77,    93,   100,   113,
     116,    93,    91,    95,    70,    64,    70,    93,   117,    70,
     100,    70,    95,    70,   100,   100,    91,   117,   124,   125,
     131,   145,    40,    41,    42,    70,    72,    74,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    92,   114,
     102,    79,    84,    85,    80,    81,    43,    44,    45,    46,
      86,    87,    47,    48,    78,    88,    89,    96,    96,    77,
      76,    95,    93,    72,    74,   147,   148,   149,   150,   151,
      71,    64,   119,   138,   141,   142,   143,   144,    28,   136,
     140,   116,    76,   130,    91,   152,   152,   118,   158,    93,
     117,    93,   145,   117,    70,   145,   152,    71,   125,   126,
     126,    71,    64,    71,    99,   115,   117,    64,   115,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   107,   108,   109,    49,    50,    90,   115,   156,
     116,    64,    76,    77,   146,    92,   151,   133,    71,    71,
      77,    77,   136,    79,   115,   137,    28,   152,    95,   158,
      93,    96,    71,    71,   117,    71,    75,   102,    71,    77,
      73,    95,    95,    95,    73,    76,   148,    51,   143,    64,
     115,    73,    73,   115,    36,    93,    95,    71,   152,    96,
     147,   115,   110,   111,   117,   146,    73,    73,    70,   158,
     158,    95,    71,    76,    77,    96,    96,    96,   117,    71,
      96,   152,    95,    76,    91,    71,   152,    93,    96,   152,
      95,    93,    95,    12,   113,   158,    95,    96,   152,    71,
      96,    95,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     117,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   131,   132,   133,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   146,   146,
     146,   147,   147,   148,   148,   149,   150,   150,   151,   151,
     152,   152,   152,   152,   152,   152,   153,   153,   153,   154,
     154,   155,   155,   156,   156,   157,   158,   158,   159,   159,
     159,   160,   160,   160,   160,   161,   161,   161,   161,   161,
     162,   162,   163,   163,   164,   164,   165,   165
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     1,     6,     1,     9,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     0,     5,     6,     2,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       0,     1,     3,     5,     6,     6,     5,     4,     4,     1,
       0,     1,     0,     1,     0,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     1,     3,
       4,     2,     4,     1,     0,     2,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     3,     1,     1,     2,     1,     0,    12,     8,
       5,     8,     9,    14,     8,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     3,     4,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 105 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
    (yyval.expr_attr) = new exp_attr;
    (yyval.expr_attr)->instr = Q_arr.index;}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
    (yyval.expr_attr) = new exp_attr;
    (yyval.expr_attr)->nextlist = makelist(Q_arr.index);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                //printf("\nprimary expression rule 1\n");
                                    (yyval.expr_attr) = new exp_attr;
                                    string t = (*((yyvsp[0].str)));     //done
                                    symtab *h = curr_sym->lookup(t);
                                    (yyval.expr_attr)->loc = t;
                                    h -> nested_table = NULL;
                                }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\nprimary expression rule 2\n");
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type.type_name = "int";
                                    opcodeType op = COPY;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].intval));
                                    init_value *init = new init_value;
                                    init->int_val = (yyvsp[0].intval);
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\nprimary expression rule 2\n");
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type.type_name = "double";
                                    opcodeType op = COPY;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].floatval));
                                    init_value *init = new init_value;
                                    init->int_val = (yyvsp[0].floatval);
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\nprimary expression rule 2\n");
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type.type_name = "char";
                                    opcodeType op = COPY;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op,(yyval.expr_attr)->loc, (yyvsp[0].charval));
                                    init_value *init = new init_value;
                                    init->int_val = (yyvsp[0].charval);
                                    curr_sym->lookup((yyval.expr_attr)->loc)->init_val = init;
                                    (yyval.expr_attr)->is_pointer_type = 0;
                                }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 161 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\nprimary expression rule 3\n");
                                }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 164 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\nprimary expression rule 4\n");
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                               }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 171 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\n<postfix-expression rule 1>\n");
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 176 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    //printf("\n<postfix-expression rule 2>\n");
                                    type_inf t = curr_sym->lookup((yyvsp[-3].expr_attr)->loc)->type;
                                    if((yyvsp[-3].expr_attr)->dim == 0)
                                    {
                                        string f = curr_sym->gentemp(t);
                                        Q_arr.emit(COPY, f, 0);
                                        (yyvsp[-3].expr_attr) -> inner = new string(f);
                                    }
                                    string f = *((yyvsp[-3].expr_attr)->inner);
                                }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 3>\n"); */
                                }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 190 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 3>\n"); */
                                    string f = (yyvsp[-3].expr_attr)->loc;
                                    symboltable *fsym = GT.lookup(f)->nested_table;
                                    func_list *flist = ((yyvsp[-1].func_list_));
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
                                }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 4>\n"); */
                                }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 209 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 5>\n"); */
                                }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 6>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    string s = (yyvsp[-1].expr_attr)->loc;
                                    symtab * f = curr_sym->lookup((yyvsp[-1].expr_attr)->loc);
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(f->type);
                                    /* //cout<<$$->loc<<"\n"; */
                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "");
                                    Q_arr.emit(PLUS, (yyvsp[-1].expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "1");
                                }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 222 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 7>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    string s = (yyvsp[-1].expr_attr)->loc;
                                    symtab * f = curr_sym->lookup((yyvsp[-1].expr_attr)->loc);
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(f->type);
                                    //cout<<$$->loc<<"\n";
                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "");
                                    Q_arr.emit(MINUS, (yyvsp[-1].expr_attr)->loc, (yyvsp[-1].expr_attr)->loc, "1");
                                }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 8>\n"); */
                                }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 235 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<postfix-expression rule 1>\n"); */
                                }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 239 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<argument-expression-list rule 1>\n"); */
                                    func_def *f = new func_def;
                                    f->param_name = (yyvsp[0].expr_attr)->loc;
                                    (yyval.func_list_) = new func_list;
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    (yyval.func_list_)->func_def_list.push_back(f);
                                }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 247 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<argument-expression-list rule 1>\n"); */
                                    func_def *f = new func_def;
                                    f->param_name = (yyvsp[0].expr_attr)->loc;
                                    (yyval.func_list_) = new func_list;
                                    f->type = &(curr_sym->lookup(f->param_name)->type);
                                    (yyval.func_list_)->func_def_list.push_back(f);
                                }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 256 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 1>\n"); */
                                }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 2>\n"); */
                                    opcodeType op;
                                    op = PLUS;
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "1");
                                    op = COPY;
                                    Q_arr.emit(op, (yyvsp[0].expr_attr)->loc, (yyval.expr_attr)->loc, "");
                                }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 271 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 3>\n"); */
                                    opcodeType op;
                                    op = MINUS;
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(op, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "1");
                                    op = COPY;
                                    Q_arr.emit(op, (yyvsp[0].expr_attr)->loc, (yyval.expr_attr)->loc, "");
                                }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 283 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 4>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type;
                                    type.type_name = string("int");
                                    if((yyvsp[-1].charval) == '-')
                                    {
                                        (yyval.expr_attr) = new exp_attr;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(UNARY_MINUS,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else if((yyvsp[-1].charval) == '&')
                                    {
                                        (yyval.expr_attr) = new exp_attr;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(REFERENCE,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else if((yyvsp[-1].charval) == '*')
                                    {
                                        (yyval.expr_attr) = new exp_attr;
                                        (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                        Q_arr.emit(DEREFERENCE,(yyval.expr_attr)->loc,(yyvsp[0].expr_attr)->loc,"");
                                    }
                                    else
                                    {
                                        (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    }
                                }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 311 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 5>\n"); */
                                }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 314 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<unary-expression rule 6>\n"); */
                                }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 318 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - AND\n"); */
                                    (yyval.charval) = '&';
                                }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 322 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - STAR\n"); */
                                    (yyval.charval) = '*';
                                }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 326 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - PLUS\n"); */
                                    (yyval.charval) = '+';
                                }
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 330 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - MINUS\n"); */
                                    (yyval.charval) = '-';
                                }
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - TILDE\n"); */
                                    (yyval.charval) = '~';
                                }
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 338 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nUnary operator - NOT\n"); */
                                    (yyval.charval) = '!';
                                }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 343 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<cast-expression rule 1>\n"); */
                                }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 346 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<cast-expression rule 2>\n"); */
                                }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 350 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<multiplicative-expression rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 354 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<multiplicative-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                        Q_arr.convI2D(e,(yyvsp[0].expr_attr));
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
                                        Q_arr.convI2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MULT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 436 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<multiplicative-expression rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                        Q_arr.convI2D(e,(yyvsp[0].expr_attr));
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
                                        Q_arr.convI2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(DIVIDE, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 518 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<multiplicative-expression rule 4>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                        Q_arr.convI2D(e,(yyvsp[0].expr_attr));
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
                                        Q_arr.convI2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MODULO, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 601 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<additive-expression rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 605 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<additive-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                        Q_arr.convI2D(e,(yyvsp[0].expr_attr));
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
                                        Q_arr.convI2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(PLUS, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 687 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<additive-expression rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2, type;
                                    type1 = curr_sym->lookup((yyvsp[-2].expr_attr)->loc)->type;
                                    type2 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                        Q_arr.convI2D(e,(yyvsp[0].expr_attr));
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
                                        Q_arr.convI2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;
                                    }
                                    if(type1.type_name.compare("double")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2D(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("double")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type2;
                                        Q_arr.convC2D(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("char")==0 && type2.type_name.compare("int")==0)
                                    {
                                        string t = curr_sym->gentemp(type2);
                                        symtab *s = curr_sym->lookup(t, type2.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[-2].expr_attr));
                                        type.type_name = type2.type_name;

                                    }
                                    if(type1.type_name.compare("int")==0 && type2.type_name.compare("char")==0)
                                    {
                                        string t = curr_sym->gentemp(type1);
                                        symtab *s = curr_sym->lookup(t, type1.type_name);
                                        exp_attr *e = new exp_attr;
                                        e->loc = t;
                                        e->type = type1;
                                        Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                        type.type_name = type1.type_name;

                                    }
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(MINUS, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 770 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<shift-expression rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 774 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<shift-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1;
                                    type1 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                            Q_arr.convD2I(e,(yyvsp[0].expr_attr));
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
                                            Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                            //type.type_name = type1.type_name;
                                        }
                                    }
                                    type1.type_name = "int";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_LEFT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 814 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<shift-expression rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1;
                                    type1 = curr_sym->lookup((yyvsp[0].expr_attr)->loc)->type;
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
                                            Q_arr.convD2I(e,(yyvsp[0].expr_attr));
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
                                            Q_arr.convC2I(e,(yyvsp[0].expr_attr));
                                            //type.type_name = type1.type_name;
                                        }
                                    }
                                    type1.type_name = "int";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type1);
                                    Q_arr.emit(SHIFT_RIGHT, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 855 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<relational-expression rule 1>\n"); */
                                    /* $$ = $1; */
                                }
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 859 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<relational-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 869 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<relational-expression rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 879 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<relational-expression rule 4>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_LESS_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 889 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<relational-expression rule 5>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_GREATER_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 900 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<equality-expression rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 904 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<equality-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_IS_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 914 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<equality-expression rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type.type_name = "bool";
                                    (yyval.expr_attr)->loc = curr_sym->gentemp((yyval.expr_attr)->type);
                                    (yyval.expr_attr)->truelist = makelist(Q_arr.index);
                                    (yyval.expr_attr)->falselist = makelist(Q_arr.index + 1);
                                    Q_arr.emit(IF_NOT_EQUAL, "", (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                    Q_arr.emit(GOTO,"","","");
                                }
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 925 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<AND-expression rule 1>\n"); */
                                }
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 928 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<AND-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(LOGICAL_AND, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 938 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<exclusive-OR-expression rule 1>\n"); */
                                }
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 941 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<exclusive-OR-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(XOR, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 951 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<inclusive-OR-expression rule 1>\n"); */
                                }
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 954 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<inclusive-OR-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    symtab *f = curr_sym->lookup((yyvsp[-2].expr_attr)->loc);//check
                                    type_inf t;
                                    t = f->type;
                                    (yyval.expr_attr)->loc = curr_sym->gentemp(t);
                                    Q_arr.emit(OR, (yyval.expr_attr)->loc, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc);
                                }
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 964 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<logical-AND-expression rule 1>\n"); */
                                }
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 967 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<logical-AND-expression rule 2>\n"); */
                                    type_inf type;
                                    type.type_name = "bool";
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type = type;

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-1].expr_attr));

                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->truelist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->truelist = (yyvsp[-1].expr_attr)->truelist;
                                    (yyval.expr_attr)->falselist = merge((yyvsp[-5].expr_attr)->falselist, (yyvsp[-1].expr_attr)->falselist);
                                }
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 990 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<logical-OR-expression rule 1>\n"); */
                                }
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 993 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<logical-expression rule 2>\n"); */
                                    type_inf type;
                                    type.type_name = "bool";
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->type = type;

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $1 to bool
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));

                                    //N required to prevent fall-through
                                    //backpatching is required to convert $5 to bool
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-1].expr_attr));

                                    //this is standard stuff, as mentioned in the slide
                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->falselist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->falselist = (yyvsp[-1].expr_attr)->falselist;
                                    (yyval.expr_attr)->truelist = merge((yyvsp[-5].expr_attr)->truelist, (yyvsp[-1].expr_attr)->truelist);
                                }
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1017 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<conditional-expression rule 1>\n"); */
                                }
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1020 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<conditional-expression rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    list<int> I;
                                    type_inf type;
                                    type = curr_sym->lookup((yyvsp[-4].expr_attr)->loc)->type;

                                    (yyval.expr_attr)->loc = curr_sym->gentemp(type);
                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[0].expr_attr)->loc,"");
                                    I = makelist(Q_arr.index);
                                    Q_arr.emit(GOTO,"","","");

                                    // for the second N
                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist, Q_arr.index);

                                    Q_arr.emit(COPY, (yyval.expr_attr)->loc, (yyvsp[-4].expr_attr)->loc, "");
                                    I = merge(I, makelist(Q_arr.index));
                                    Q_arr.emit(GOTO,"", "", "");

                                    // for the first N
                                    Q_arr.backpatch((yyvsp[-7].expr_attr)->nextlist, Q_arr.index);

                                    Q_arr.convInt2Bool((yyvsp[-8].expr_attr));

                                    // the standard stuff from the slides
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->truelist, (yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->falselist, (yyvsp[-1].expr_attr)->instr);
                                    Q_arr.backpatch(I, Q_arr.index);
                                }
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1050 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: =\n");  */
                                }
#line 3060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1053 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: *=\n"); */
                                }
#line 3068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1056 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: /=\n"); */
                                }
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1059 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: =\n"); */
                                }
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1062 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: +=\n"); */
                                }
#line 3092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1065 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: -=\n"); */
                                }
#line 3100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1068 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: <<=\n"); */
                                }
#line 3108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1071 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: >>=\n"); */
                                }
#line 3116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1074 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: &=\n"); */
                                }
#line 3124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1077 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: ^=\n"); */
                                }
#line 3132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1080 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nAssignment operator :: |=\n"); */
                                }
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1084 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<assignment-expression rule 1>\n"); */
                                }
#line 3148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1087 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<assignment-expression rule 2>\n"); */
                                    Q_arr.emit(COPY, (yyvsp[-2].expr_attr)->loc, (yyvsp[0].expr_attr)->loc, "");
                                    (yyval.expr_attr) = (yyvsp[-2].expr_attr);
                                }
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1094 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<constant-expression rule 1>\n"); */
                                }
#line 3166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1098 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<expression rule 1>\n"); */
                                }
#line 3174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1101 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<expression rule 2>\n"); */
                                }
#line 3182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1106 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration rule 1>\n"); */
                                }
#line 3190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1109 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<init-declarator-list-opt rule 1>\n"); */
                                    init_dec_list *new_dec = new init_dec_list;
                                    new_dec = (yyvsp[0].init_dec_list_);
                                    int size = 0;
                                    type_inf *type = (yyvsp[-1].type_);
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("double")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;

                                    list<declaration*>::iterator it;
                                    for(it = (yyvsp[0].init_dec_list_)->dec_list.begin(); it != (yyvsp[0].init_dec_list_)->dec_list.end(); it++)
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
                                }
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1181 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration-specifiers rule 1>\n"); */
                                }
#line 3274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1184 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration-specifiers rule 2>\n"); */
                                }
#line 3282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1187 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration-specifiers rule 3>\n"); */
                                }
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1190 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration-specifiers rule 4>\n"); */
                                }
#line 3298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1194 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declaration-specifiers-opt rule 1>\n"); */
                                }
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1197 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1199 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<init-declarator-list rule 1>\n"); */
                                    (yyval.init_dec_list_) = new init_dec_list;
                                    (yyval.init_dec_list_)->dec_list.push_back((yyvsp[0].decclist));
                                }
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1204 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<init-declarator-list rule 2>\n"); */
                                    (yyvsp[-2].init_dec_list_)->dec_list.push_back((yyvsp[0].decclist));
                                    (yyval.init_dec_list_) = (yyvsp[-2].init_dec_list_);
                                }
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1210 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<init-declarator rule 1>\n"); */
                                    (yyval.decclist) = (yyvsp[0].decclist);
                                    (yyval.decclist)->init = NULL;
                                }
#line 3342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1215 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<init-declarator rule 2>\n"); */
                                    (yyval.decclist) = (yyvsp[-2].decclist);
                                    (yyval.decclist)->init = (yyvsp[0].expr_attr);
                                }
#line 3352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1221 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<storage-class-specifier :: extern>\n"); */
                                }
#line 3360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1224 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<storage-class-specifier :: static>\n"); */
                                }
#line 3368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1227 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<storage-class-specifier :: auto>\n"); */
                                }
#line 3376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1230 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<storage-class-specifier :: register>\n"); */
                                }
#line 3384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1234 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: void>\n"); */
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("void");
                                    (yyval.type_)->next = NULL;
                                }
#line 3395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1240 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: char>\n"); */
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("char");
                                    (yyval.type_)->next = NULL;
                                }
#line 3406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1246 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: short>\n"); */
                                }
#line 3414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1249 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: int>\n"); */
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("int");
                                    (yyval.type_)->next = NULL;
                                }
#line 3425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1255 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: long>\n"); */
                                }
#line 3433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1258 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: float>\n"); */
                                }
#line 3441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1261 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: double>\n"); */
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("double");
                                    (yyval.type_)->next = NULL;
                                }
#line 3452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1267 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: signed>\n"); */
                                }
#line 3460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1270 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: unsigned>\n"); */
                                }
#line 3468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1273 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: _Bool>\n"); */
                                }
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1276 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: _Complex>\n"); */
                                }
#line 3484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1279 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: _Imaginary>\n"); */
                                }
#line 3492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1282 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-specifier :: enum>\n"); */
                                }
#line 3500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1286 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    (yyval.type_) = (yyvsp[-1].type_);
                                    /* printf("\n<specifier-qualifier-list rule 1>\n"); */
                                }
#line 3509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1290 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<specifier-qualifier-list rule 2>\n"); */
                                }
#line 3517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1294 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<specifier-qualifier-list-opt rule 1>\n"); */
                                }
#line 3525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1297 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1299 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enum-specifier rule 1>\n"); */
                                }
#line 3539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1302 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enum-specifier rule 2>\n"); */
                                }
#line 3547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1305 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enum-specifier rule 3>\n"); */
                                }
#line 3555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1309 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<identifier rule 1>\n"); */
                                }
#line 3563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1312 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1314 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enumerator-list rule 1>\n"); */
                                }
#line 3577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1317 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enumerator-list rule 2>\n"); */
                                }
#line 3585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1321 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enumerator rule 1>\n"); */
                                }
#line 3593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1324 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<enumerator rule 2>\n"); */
                                }
#line 3601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1328 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier :: const>\n"); */
                                }
#line 3609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1331 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier :: inline>\n"); */
                                }
#line 3617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1334 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier :: volatile>\n"); */
                                }
#line 3625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1338 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<function-specifier :: inline>\n"); */
                                }
#line 3633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1342 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<declarator rule 1>\n"); */
                                    (yyval.decclist) = (yyvsp[0].decclist);
                                }
#line 3642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1347 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<pointer-opt rule 1>\n"); */
                                }
#line 3650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1350 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1352 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 1>\n"); */
                                    (yyval.decclist) = new declaration;
                                    (yyval.decclist)->dec_name = *((yyvsp[0].str));
                                }
#line 3666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1357 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 2>\n"); */
                                    (yyval.decclist) = (yyvsp[-1].decclist);
                                }
#line 3675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1361 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 3>\n"); */
                                    (yyval.decclist) = (yyvsp[-4].decclist);
                                    int idx = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->init_val->int_val;
                                    (yyval.decclist)->alist.push_back(idx);
                                }
#line 3686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1367 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 4>\n"); */
                                }
#line 3694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1370 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 5>\n"); */
                                }
#line 3702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1373 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 6>\n"); */
                                }
#line 3710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1376 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 7>\n"); */
                                    //name of function is now available
                                    symboltable *new_sym = new symboltable;
                                    (yyval.decclist) = (yyvsp[-3].decclist);
                                    string name = (yyval.decclist)->dec_name;
                                    (yyval.decclist)->type = new type_inf;
                                    (yyval.decclist)->type->type_name = string("function");
                                    symtab *func_lookup = curr_sym->lookup((yyval.decclist)->dec_name, (yyval.decclist)->type->type_name);
                                    func_lookup -> nested_table = new_sym;

                                    list<func_def*> l = (yyvsp[-1].func_list_)->func_def_list;
                                    list<func_def*>::iterator it;
                                    for(it = l.begin(); it != l.end(); it++)
                                    {
                                        func_def *temp = *it;
                                        new_sym -> lookup(temp->param_name, temp->type->type_name);
                                    }
                                    curr_sym = new_sym;
                                    Q_arr.emit(_FUNCTION_START, name,"","");
                                    //printf("direct_declarator -> direct_declarator (parameter_type_list)\n");
                                }
#line 3737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1398 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<direct-declarator rule 8>\n"); */
                                }
#line 3745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1402 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier-list-opt rule 1>\n"); */
                                }
#line 3753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1405 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1407 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<assignment-expression-opt rule 1>\n"); */
                                }
#line 3767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1410 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1412 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<identifier-list-opt rule 1>\n"); */
                                }
#line 3781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1415 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {}
#line 3787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1417 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<pointer rule 1>\n"); */
                                    (yyval.type_) = new type_inf;
                                    (yyval.type_)->type_name = string("ptr");
                                    (yyval.type_)->next = NULL;
                                }
#line 3798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1423 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<pointer rule 2>\n"); */
                                    (yyval.type_) = (yyvsp[0].type_);
                                    type_inf *t = new type_inf;
                                    t->type_name = string("ptr");
                                    t->size = 4;
                                    t->next = (yyvsp[0].type_);
                                }
#line 3811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1432 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier-list rule 1>\n"); */
                                }
#line 3819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1435 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-qualifier-list rule 2>\n"); */
                                }
#line 3827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1439 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-type-list rule 1>\n"); */
                                    (yyval.func_list_) = new func_list;
                                }
#line 3836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1443 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-type-list rule 2>\n"); */
                                }
#line 3844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1447 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-list rule 1>\n"); */
                                    (yyval.func_list_) = new func_list;
                                    (yyval.func_list_)->func_def_list.push_back((yyvsp[0].func_def_));
                                }
#line 3854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1452 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-list rule 2>\n"); */
                                    (yyvsp[-2].func_list_)->func_def_list.push_back((yyvsp[0].func_def_));
                                    (yyval.func_list_) = (yyvsp[-2].func_list_);
                                }
#line 3864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1458 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-declaration rule 1>\n"); */
                                    (yyval.func_def_) = new func_def;
                                    (yyval.func_def_)->type = (yyvsp[-1].type_);
                                    (yyval.func_def_)->param_name = (yyvsp[0].decclist)->dec_name;
                                }
#line 3875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1464 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<parameter-declaration rule 2>\n"); */
                                }
#line 3883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1468 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<identifier-list rule 1>\n"); */
                                }
#line 3891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1471 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<identifier-list rule 2>\n"); */
                                }
#line 3899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1475 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<type-name rule 1>\n"); */
                                }
#line 3907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1479 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<initializer rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 3916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1483 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<initializer rule 2>\n"); */
                                }
#line 3924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1486 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<initializer rule 3>\n"); */
                                }
#line 3932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1490 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<initializer-list rule 1>\n"); */
                                }
#line 3940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1493 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<initializer-list rule 2>\n"); */
                                }
#line 3948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1497 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<designation-opt rule 1>\n"); */
                                }
#line 3956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1502 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<designation rule 1>\n"); */
                                }
#line 3964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1506 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndesignator-list rule 1>\n"); */
                                }
#line 3972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1509 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndesignator-list rule 2>\n"); */
                                }
#line 3980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1513 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndesignator rule 1>\n"); */
                                }
#line 3988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1516 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndesignator rule 2>\n"); */
                                }
#line 3996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1521 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 1>\n"); */
                                }
#line 4004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1524 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 2>\n"); */
                                }
#line 4012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1527 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 3>\n"); */
                                }
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1530 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 4>\n"); */
                                }
#line 4028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1533 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 5>\n"); */
                                }
#line 4036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1536 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nstatement rule 6>\n"); */
                                }
#line 4044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1540 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nlabeled-statement rule 1>\n"); */
                                }
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1543 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nlabeled-statement rule 2>\n"); */
                                }
#line 4060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1546 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nlabeled-statement rule 3>\n"); */
                                }
#line 4068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1550 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ncompound-statement rule 1>\n"); */
                                }
#line 4076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1553 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                                }
#line 4084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1557 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nblock-item-list rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, Q_arr.index);
                                }
#line 4094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1562 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nblock-item-list rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    (yyval.expr_attr)->nextlist = (yyvsp[0].expr_attr)->nextlist;
                                    Q_arr.backpatch((yyvsp[-2].expr_attr)->nextlist, (yyvsp[-1].expr_attr)->instr);
                                }
#line 4105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1569 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nblock-item rule 1>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                }
#line 4114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1573 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nblock-item rule 2>\n"); */
                                }
#line 4122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1577 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nexpression-statement rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[-1].expr_attr);
                                }
#line 4131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1582 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nexpression-opt rule 1>\n"); */
                                    (yyval.expr_attr) = (yyvsp[0].expr_attr);
                                }
#line 4140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1586 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                }
#line 4148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1590 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nselection-statement rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->nextlist , Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-9].expr_attr));

                                    (yyval.expr_attr)->nextlist = merge((yyvsp[-5].expr_attr)->nextlist, (yyvsp[-4].expr_attr)->nextlist);
                                    Q_arr.backpatch((yyvsp[-9].expr_attr)->truelist, (yyvsp[-6].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-9].expr_attr)->falselist, (yyvsp[-2].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[-1].expr_attr)->nextlist);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[0].expr_attr)->nextlist);
                                }
#line 4165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1602 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nselection-statement rule 1>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-5].expr_attr));

                                    Q_arr.backpatch((yyvsp[-5].expr_attr)->truelist, (yyvsp[-2].expr_attr)->instr);

                                    (yyval.expr_attr)->nextlist = merge((yyvsp[0].expr_attr)->nextlist, (yyvsp[-1].expr_attr)->nextlist);
                                    (yyval.expr_attr)->nextlist = merge((yyval.expr_attr)->nextlist, (yyvsp[-5].expr_attr)->falselist);
                                }
#line 4181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1613 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nselection-statement rule 3>\n"); */
                                }
#line 4189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1617 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\niteration-statement rule 1>\n"); */
                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),(yyvsp[-6].expr_attr)->instr);

                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist,Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-4].expr_attr));

                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist, (yyvsp[-6].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-4].expr_attr)->truelist, (yyvsp[-1].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = (yyvsp[-4].expr_attr)->falselist;
                                }
#line 4207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1630 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\niteration-statement rule 2>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    Q_arr.convInt2Bool((yyvsp[-2].expr_attr));
                                    Q_arr.backpatch((yyvsp[-6].expr_attr)->nextlist, (yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-2].expr_attr)->truelist, (yyvsp[-7].expr_attr)->instr);
                                    (yyval.expr_attr)->nextlist = (yyvsp[-2].expr_attr)->falselist;
                                }
#line 4220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1638 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\niteration-statement rule 3>\n"); */
                                    (yyval.expr_attr) = new exp_attr;

                                    Q_arr.emit(GOTO,"","","");
                                    Q_arr.backpatch(makelist(Q_arr.index-1),(yyvsp[-5].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-7].expr_attr)->nextlist, Q_arr.index);
                                    Q_arr.convInt2Bool((yyvsp[-8].expr_attr));

                                    Q_arr.backpatch((yyvsp[-3].expr_attr)->nextlist,(yyvsp[-9].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[-8].expr_attr)->truelist,(yyvsp[-1].expr_attr)->instr);
                                    Q_arr.backpatch((yyvsp[0].expr_attr)->nextlist,(yyvsp[-5].expr_attr)->instr);

                                    (yyval.expr_attr)->nextlist = (yyvsp[-8].expr_attr)->falselist;
                                }
#line 4240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1653 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\niteration-statement rule 4>\n"); */
                                    // Not to be produced, as per assignment
                                }
#line 4249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1658 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\njump-statement rule 1>\n"); */
                                }
#line 4257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1661 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\njump-statement rule 2>\n"); */
                                }
#line 4265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1664 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\njump-statement rule 3>\n"); */
                                }
#line 4273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1667 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\njump-statement rule 4>\n"); */
                                    (yyval.expr_attr) = new exp_attr;
                                    if(curr_sym->lookup("retVal")->type.type_name.compare("void")==0)
                                    {
                                        Q_arr.emit(RETURN_VOID,"","","");
                                    }
                                }
#line 4286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1675 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    (yyval.expr_attr) = new exp_attr;
                                    type_inf type1, type2;
                                    type1 = curr_sym->lookup("retVal")->type;
                                    type2 = curr_sym->lookup((yyvsp[-1].expr_attr)->loc)->type;
                                    if(type1.type_name == type2.type_name)
                                    {
                                        Q_arr.emit(RETURN, (yyvsp[-1].expr_attr)->loc, "", "");
                                    }
                                    else{
                                        // mismatch of return type , maybe convert ?
                                    }
                                }
#line 4304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1690 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                        /* printf("\n<translation-unit rule 1>\nSuccessful\n"); */
                                }
#line 4312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1693 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\n<translation-unit rule 2>\nSuccessful\n"); */
                                }
#line 4320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1697 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nexternal-declaration rule 1>\n"); */
                                }
#line 4328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1700 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nexternal-statement rule 2>\n"); */
                                }
#line 4336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1704 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nfunction-definition rule 1>\n"); */
                                    declaration *new_dec = (yyvsp[-1].decclist);
                                    int size = 0;
                                    type_inf *type = (yyvsp[-2].type_);
                                    if(type->type_name.compare("int")==0) size = 4;
                                    if(type->type_name.compare("double")==0) size = 8;
                                    if(type->type_name.compare("char")==0) size = 1;
                                    //cout<<$2->type->type_name;
                                    symboltable *gt = &GT;
                                    symtab *func = gt->lookup((yyvsp[-1].decclist)->dec_name);
                                    func->nested_table = new symboltable;
                                    symtab *ret = func->nested_table->lookup("retVal", type->type_name, (yyvsp[-1].decclist)->pc);
                                    ret->offset = curr_sym->offset;
                                    ret->size = size;
                                    ret->init_val = NULL;
                                    //curr_sym = func->nested_table;
                                    (yyval.decclist) = (yyvsp[-1].decclist);
                                }
#line 4360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1723 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\nfunction-definition rule 1>\n"); */
                                }
#line 4368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1727 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndeclaration-list rule 1>\n"); */
                                }
#line 4376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1730 "ass5_17CS10036_17CS30013.y" /* yacc.c:1646  */
    {
                                    /* printf("\ndeclaration-list rule 2>\n"); */
                                }
#line 4384 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4388 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1734 "ass5_17CS10036_17CS30013.y" /* yacc.c:1906  */


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
