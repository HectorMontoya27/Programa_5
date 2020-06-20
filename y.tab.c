/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170430

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parse.y"

#include <stdio.h>
#include <string.h>
#include "datos.h"
#include "tipos.h"
#include "tabla_simbolos.h"
#include "tabla_tipos.h"
#include "lista_arg.h"
#include "cuadruplas.h"
#include "backpatch.h"

void inicializar();
void finalizar();

void yyerror(char *s);
extern int yylex();

code *codigo;
Pila_T_Tipos *PilaTT;
Pila_T_Simbolos *PilaTS;
T_Simbolos *tsGBL;
int tipoGBL;
int baseGBL;
int tamTS_GBL;
listaArg *listaRET;
char GBLid[20];

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 31 "parse.y"
typedef union{
  char dir[32];
  int base;

  struct {
      int tipo;
      int num;
      char dir[20];
  } numero;

  struct {
      int num;
      struct LIST_ARG *lista;
  } lista;

  struct {
      char dir[20];
      char base[20];
      int des;
      int tipo;
      int estructura;
      struct T_SIMBOLOS *tabla;
  } variable;

  struct {
      int tipo;
      char dir[20];
      int valor;
  }expresion;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 87 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PYC 257
#define INICIO 258
#define FIN 259
#define ESTRUCTURA 260
#define DEF 261
#define SIN 262
#define SI 263
#define ENTONCES 264
#define MIENTRAS 265
#define HACER 266
#define SEGUN 267
#define ESCRIBIR 268
#define DEVOLVER 269
#define LEER 270
#define TERMINAR 271
#define CASO 272
#define PRED 273
#define DOSP 274
#define FALSO 275
#define VERDADERO 276
#define PUNCOM 277
#define ENT 278
#define REAL 279
#define DREAL 280
#define CAR 281
#define ID 282
#define CARACTER 283
#define CADENA 284
#define NUM 285
#define COMA 286
#define ASIG 287
#define O 288
#define Y 289
#define OPERADOR_RELACIONAL 290
#define SUM_RES 291
#define MUL_DIV_MOD 292
#define NO 293
#define PUNTO 294
#define CORDER 295
#define CORIZQ 296
#define LPAR 297
#define RPAR 298
#define SIT 299
#define SINO 300
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   27,    0,   28,    1,    1,    1,   29,    2,   30,   16,
   14,   14,   14,   14,   14,   15,   15,    3,   13,   13,
   31,   32,    4,    4,   20,   20,   21,   21,   18,   33,
   17,   19,   19,    5,    5,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    7,    7,    8,
    8,    9,    9,    9,    9,    9,    9,   10,   10,   26,
   26,   26,   26,   26,   26,   26,   34,   22,   23,   23,
   23,   25,   25,   24,   24,   11,   11,   12,   12,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    0,    5,    0,    3,
    1,    1,    1,    1,    1,    4,    0,    2,    3,    0,
    0,    0,   13,    0,    1,    1,    3,    1,    2,    0,
    3,    3,    0,    2,    0,    5,    7,    5,    5,    8,
    4,    3,    3,    2,    3,    2,    3,    5,    4,    3,
    0,    3,    3,    2,    1,    1,    1,    3,    1,    3,
    3,    3,    1,    1,    1,    1,    0,    3,    1,    1,
    3,    3,    0,    3,    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    7,   11,   12,   13,   14,   15,    0,    0,
    9,    3,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,   10,    0,    0,   21,    0,
    5,    0,    0,    8,    0,   19,    0,    4,    0,   16,
    0,   30,    0,   28,    0,    0,    0,   29,    0,    0,
    0,   31,    0,   27,    0,   35,   32,    0,   35,   22,
    0,    0,   35,    0,    0,    0,    0,    0,   67,   34,
    0,    0,    0,   57,   56,   66,   65,   64,    0,    0,
    0,    0,   63,    0,    0,    0,    0,    0,   44,    0,
    0,   46,    0,    0,   47,   23,   54,    0,   35,    0,
    0,    0,    0,    0,   35,    0,    0,   42,   45,   43,
    0,    0,   68,   70,    0,    0,   62,    0,    0,   53,
   58,    0,   61,    0,    0,    0,    0,    0,    0,    0,
    0,   41,   36,   35,   38,   39,    0,    0,   71,    0,
   72,    0,    0,    0,   75,    0,   37,    0,    0,    0,
   35,   35,   40,    0,    0,   48,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   15,   58,   70,  144,  150,   81,   82,
  128,  129,   23,   11,   26,   12,   43,   44,   52,   45,
   46,   83,  113,  114,  115,   84,    2,   19,   13,   18,
   35,   73,   47,   93,
};
static const YYINT yysindex[] = {                         0,
    0,  -54,    0,    0,    0,    0,    0,    0, -256, -262,
    0,    0, -232,  -32,    0, -251, -233, -214, -262,  -54,
 -194, -190,    0,  -54, -191,    0, -162, -144,    0, -251,
    0, -179,  -54,    0, -177,    0, -214,    0,   -5,    0,
    0,    0, -152,    0, -180, -151, -156,    0, -121,  -32,
 -146,    0,  -54,    0, -156,    0,    0,  -66,    0,    0,
  -99,  -99,    0, -143,   14, -246, -131, -105,    0,    0,
 -122,  -48, -256,    0,    0,    0,    0,    0,  -99,   14,
 -224, -134,    0, -248, -258,   73, -131, -244,    0, -238,
  -88,    0, -217,   14,    0,    0,    0, -159,    0,  -99,
  -99,   14,   14,   14,    0,  -99, -126,    0,    0,    0,
   14,   14,    0,    0, -112, -234,    0, -196, -102,    0,
    0, -104,    0,  -30, -198,  -77, -117,  -91,  -90, -248,
  -73,    0,    0,    0,    0,    0,  -60,  -83,    0,   14,
    0,   19,  -71,  -42,    0, -248,    0,  -31,  -29,  -27,
    0,    0,    0,   37,   91,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  242,    0,
    0,    0,    0,    0,    0,  -13,    0,  -28,    0,   -9,
    0,    0,    0,    1,    0,    0,    0,    0,    0,  -13,
    0,    0,    1,    0,    0,    0,  -28,    0,    0,    0,
 -195,    0,    0,    0,    0,  -47,  -26,    0,    0,    0,
    0,    0,   55,    0,  -26,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  242,    0,    0,    0,    0,    0,    0,    0,
    0,  -98,    0, -109,    0,    0,    0,    0,    0,    0,
    0,    0, -181,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -43,    0,    0, -164,    0,    0,    0,  -93,    0,
    0, -128,    0,    0,    0,    0,    0,    0,  -40, -271,
    0,    0,    0,    0,    0,    0,    0, -145,    0,    0,
    0,    0,    0,   -6,    0, -209,    0,    0,    0,    0,
    0,    0,    0, -252,    6,    0,
};
static const YYINT yygindex[] = {                         0,
   -8,    0,  260,  188,  -53,    0,  126,    0,  -45,  179,
    0,    0,  261,  -17,  255,  279,    0,  244,  257,    0,
    0,  -58,    0,  172,    0,  -62,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 373
static const YYINT yytable[] = {                         71,
    6,    6,   88,   90,   14,   72,   49,  105,   91,   86,
   89,   28,  108,   71,   79,   31,   85,   98,  109,   16,
   49,   42,  132,   24,   38,   20,   79,   71,  107,  100,
  101,  116,   42,   97,   22,   69,   76,   77,   78,   99,
  122,  123,  103,  104,   56,  118,  103,  104,  127,  130,
   80,  124,  103,  104,  119,  120,  103,  104,  136,   71,
  125,   59,  133,  100,  101,   71,   61,  105,   62,   63,
   64,   65,   66,   67,   68,   73,   78,  146,  111,  112,
  142,   25,   73,   71,   73,   69,   11,   29,   78,  100,
  101,   30,   69,   32,   33,   71,   71,  154,  155,   69,
   11,   69,   26,  134,   73,   73,   73,   73,   73,   73,
   73,   74,   73,   73,   34,   37,   73,   49,   74,   39,
   74,   69,   69,   69,   69,   69,   69,   69,   60,   48,
   69,  103,  104,   69,   50,   60,   53,   60,  117,   51,
   74,   74,   74,   74,   74,   74,   74,   59,   55,   74,
   69,   92,   74,   87,   59,  102,   59,   60,   55,   60,
   60,   60,   60,   52,   94,   55,   60,   55,  110,   60,
   52,  126,   52,  103,  104,   74,   75,  138,   59,   59,
   59,  131,   69,   76,   77,   78,  101,  104,  137,   55,
   55,   59,   60,   79,   52,  140,   61,   80,   62,   63,
   64,   65,   66,   67,   68,    3,  139,    4,  141,   59,
   95,  143,  111,  148,   61,   69,   62,   63,   64,   65,
   66,   67,   68,    5,    6,    7,    8,   59,  135,    4,
  149,  153,   61,   69,   62,   63,   64,   65,   66,   67,
   68,   24,  151,   20,  152,    5,    6,    7,    8,    6,
   25,   69,   51,   17,   77,   33,   41,   76,    6,    6,
   96,    6,    6,    6,   50,    6,    6,    6,    6,    6,
    6,    6,    5,    6,    7,    8,   59,  147,   27,  156,
  121,   61,    6,   62,   63,   64,   65,   66,   67,   68,
   36,   40,   21,   54,   59,   69,   76,   77,   78,   61,
   69,   62,   63,   64,   65,   66,   67,   68,  143,  145,
   80,   57,    6,    6,    0,    0,    0,    6,   69,    6,
    6,    6,    6,    6,    6,    6,    0,    0,    0,    0,
   59,    0,    0,    0,    0,   61,    6,  106,   63,   64,
   65,   66,   67,   68,    0,    0,    0,    0,   59,    0,
    0,    0,    0,   61,   69,   62,   63,   64,   65,   66,
   67,   68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,
};
static const YYINT yycheck[] = {                         58,
    0,    0,   65,   66,  261,   59,  259,  266,   67,   63,
  257,   20,  257,   72,  286,   24,   62,   80,  257,  282,
  273,   39,  257,  257,   33,  258,  298,   86,   87,  288,
  289,   94,   50,   79,  286,  282,  283,  284,  285,  264,
  103,  104,  291,  292,   53,   99,  291,  292,  111,  112,
  297,  105,  291,  292,  100,  101,  291,  292,  257,  118,
  106,  258,  259,  288,  289,  124,  263,  266,  265,  266,
  267,  268,  269,  270,  271,  257,  286,  140,  296,  297,
  134,  296,  264,  142,  266,  282,  282,  282,  298,  288,
  289,  282,  257,  285,  257,  154,  155,  151,  152,  264,
  296,  266,  298,  300,  286,  287,  288,  289,  290,  291,
  292,  257,  294,  295,  259,  295,  298,  298,  264,  297,
  266,  286,  287,  288,  289,  290,  291,  292,  257,  282,
  295,  291,  292,  298,  286,  264,  258,  266,  298,  296,
  286,  287,  288,  289,  290,  291,  292,  257,  295,  295,
  282,  257,  298,  297,  264,  290,  266,  286,  257,  288,
  289,  290,  291,  257,  287,  264,  295,  266,  257,  298,
  264,  298,  266,  291,  292,  275,  276,  295,  288,  289,
  290,  294,  282,  283,  284,  285,  289,  292,  266,  288,
  289,  258,  259,  293,  288,  286,  263,  297,  265,  266,
  267,  268,  269,  270,  271,  260,  298,  262,  282,  258,
  259,  272,  296,  285,  263,  282,  265,  266,  267,  268,
  269,  270,  271,  278,  279,  280,  281,  258,  259,  262,
  273,  259,  263,  282,  265,  266,  267,  268,  269,  270,
  271,    0,  274,  257,  274,  278,  279,  280,  281,  259,
  298,  282,  259,  282,  298,  282,  262,  298,  258,  259,
   73,  261,  261,  263,  259,  265,  266,  267,  268,  269,
  270,  271,  278,  279,  280,  281,  258,  259,   19,  154,
  102,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   30,   37,   14,   50,  258,  282,  283,  284,  285,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  272,  138,
  297,   55,  258,  259,   -1,   -1,   -1,  263,  282,  265,
  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,  263,  282,  265,  266,  267,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,  258,   -1,
   -1,   -1,   -1,  263,  282,  265,  266,  267,  268,  269,
  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  282,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 337
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PYC","INICIO","FIN","ESTRUCTURA",
"DEF","SIN","SI","ENTONCES","MIENTRAS","HACER","SEGUN","ESCRIBIR","DEVOLVER",
"LEER","TERMINAR","CASO","PRED","DOSP","FALSO","VERDADERO","PUNCOM","ENT",
"REAL","DREAL","CAR","ID","CARACTER","CADENA","NUM","COMA","ASIG","O","Y",
"OPERADOR_RELACIONAL","SUM_RES","MUL_DIV_MOD","NO","PUNTO","CORDER","CORIZQ",
"LPAR","RPAR","SIT","SINO",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"declaraciones : tipo $$2 lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"$$3 :",
"tipo_registro : ESTRUCTURA $$3 INICIO declaraciones FIN",
"$$4 :",
"tipo : base $$4 tipo_arreglo",
"base : SIN",
"base : ENT",
"base : REAL",
"base : DREAL",
"base : CAR",
"tipo_arreglo : CORIZQ NUM CORDER tipo_arreglo",
"tipo_arreglo :",
"lista_var : ID A",
"A : COMA ID A",
"A :",
"$$5 :",
"$$6 :",
"funciones : DEF tipo ID $$5 LPAR argumentos RPAR INICIO declaraciones sentencias FIN $$6 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$7 :",
"tipo_arg : base $$7 param_arr",
"param_arr : CORIZQ CORDER param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias :",
"sentencia : SI e_bool ENTONCES sentencias FIN",
"sentencia : SI e_bool ENTONCES sentencias SINO sentencias FIN",
"sentencia : MIENTRAS e_bool HACER sentencias FIN",
"sentencia : HACER sentencias MIENTRAS e_bool PYC",
"sentencia : SEGUN LPAR variable RPAR HACER casos predeterminado FIN",
"sentencia : variable ASIG expresion PYC",
"sentencia : ESCRIBIR expresion PYC",
"sentencia : LEER variable PYC",
"sentencia : DEVOLVER PYC",
"sentencia : DEVOLVER expresion PYC",
"sentencia : TERMINAR PYC",
"sentencia : INICIO sentencias FIN",
"casos : CASO NUM DOSP sentencias casos",
"casos : CASO NUM DOSP sentencias",
"predeterminado : PRED DOSP sentencias",
"predeterminado :",
"e_bool : e_bool O e_bool",
"e_bool : e_bool Y e_bool",
"e_bool : NO e_bool",
"e_bool : relacional",
"e_bool : VERDADERO",
"e_bool : FALSO",
"relacional : relacional OPERADOR_RELACIONAL relacional",
"relacional : expresion",
"expresion : expresion SUM_RES expresion",
"expresion : expresion MUL_DIV_MOD expresion",
"expresion : LPAR expresion RPAR",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"$$8 :",
"variable : ID $$8 variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"variable_comp : LPAR parametros RPAR",
"dato_est_sim : dato_est_sim PUNTO ID",
"dato_est_sim :",
"arreglo : CORIZQ expresion CORDER",
"arreglo : CORIZQ expresion CORDER arreglo",
"parametros : lista_param",
"parametros :",
"lista_param : lista_param COMA expresion",
"lista_param : expresion",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 338 "parse.y"

/*
--Nombre Funcion: yyerror()
--Descripcion: Funcion para mandar un mensaje de error sintactico
--Autor: El profesor
--Fecha de creacion: Desconocido
*/
void yyerror(char *s){
    printf("Error sintactico. %s\n",s);
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void inicializar(){
    codigo = crearCodigo();
    PilaTS = PTS_nueva();
    PilaTT = PTT_nueva();
    PTT_push(PilaTT,TT_nueva("Global"));
    PTS_push(PilaTS,TS_nueva("Global"));
    TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("car",1,-1,NULL));
    TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("ent",4,-1,NULL));
    TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("real",4,-1,NULL));
    TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("dreal",8,-1,NULL));
    PilaTS->inicio->tt = PilaTT->inicio;
}

/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
void finalizar(){
    PTT_imprimir(PilaTT);
    PTS_imprimir(PilaTS);
    imprimirCodigo(codigo);
    PTS_eliminar(PilaTS);
    PTT_eliminar(PilaTT);
    eliminarCodigo(codigo);
}
#line 520 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 118 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 118 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 120 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 120 "parse.y"
	{}
break;
case 5:
#line 121 "parse.y"
	{}
break;
case 6:
#line 122 "parse.y"
	{}
break;
case 7:
#line 124 "parse.y"
	{
      PTT_push(PilaTT,TT_nueva("Estructura"));
      PTS_push(PilaTS,TS_nueva("Estructura"));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("car",1,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("ent",4,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("real",4,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("dreal",8,-1,NULL));

    }
break;
case 8:
#line 132 "parse.y"
	{

      TS_imprimir(PilaTS->cabeza);
      TT_imprimir(PilaTT->cabeza);
      tsGBL = PTS_pop(PilaTS);
      tsGBL->tt = PTT_pop(PilaTT);
      tamTS_GBL = tsGBL->dirMax;
      tipoGBL = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("struct",tamTS_GBL,-2,tsGBL));
    }
break;
case 9:
#line 142 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 142 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 144 "parse.y"
	{ yyval.base = -1; }
break;
case 12:
#line 145 "parse.y"
	{ yyval.base = 1; }
break;
case 13:
#line 146 "parse.y"
	{ yyval.base = 2; }
break;
case 14:
#line 147 "parse.y"
	{ yyval.base = 3; }
break;
case 15:
#line 148 "parse.y"
	{ yyval.base = 0; }
break;
case 16:
#line 150 "parse.y"
	{
    if (yystack.l_mark[-2].numero.tipo = 1) {
        if (yystack.l_mark[-2].numero.num > 0){
          yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",yystack.l_mark[-2].numero.num*TT_getTam(getTablaGlobal(PilaTT),yystack.l_mark[0].base),yystack.l_mark[0].base,NULL));
        } else {
          yyerror("El tamano del arreglo no es valido");
        }
    } else {
        yyerror("El tamaño del arreglo no es un número entero");
    }
 }
break;
case 17:
#line 161 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 163 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 19:
#line 171 "parse.y"
	{
  if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 20:
#line 178 "parse.y"
	{}
break;
case 21:
#line 180 "parse.y"
	{
          if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) == -1) {
              PTS_push(PilaTS,TS_nueva("Funcion"));
              PTT_push(PilaTT,TT_nueva("Funcion"));
              copiarGlobalTT(PilaTT);
              copiarGlobalTS(PilaTS);
              PilaTS->cabeza->tt = PilaTT->cabeza;
              listaRET = crearListaArg();
          } else {
              yyerror("Ya se declaro la variable");
          }

      }
break;
case 22:
#line 192 "parse.y"
	{
          TS_imprimir(PilaTS->cabeza);
          TT_imprimir(PilaTT->cabeza);
          TS_eliminar(PTS_pop( PilaTS ));
          TT_eliminar(PTT_pop( PilaTT ));
          borrarlistaArg(listaRET);

      }
break;
case 23:
#line 199 "parse.y"
	{}
break;
case 24:
#line 200 "parse.y"
	{}
break;
case 25:
#line 202 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[0].lista.lista; yyval.lista.num = yystack.l_mark[0].lista.num; }
break;
case 26:
#line 203 "parse.y"
	{ yyval.lista.lista = NULL; yyval.lista.num = 0; }
break;
case 27:
#line 205 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[-2].lista.lista; yyval.lista.num = yystack.l_mark[-2].lista.num + 1; agregarArg(yyval.lista.lista,yystack.l_mark[0].base); }
break;
case 28:
#line 206 "parse.y"
	{ yyval.lista.lista = crearListaArg(); agregarArg(yyval.lista.lista,yystack.l_mark[0].base); yyval.lista.num = 1; }
break;
case 29:
#line 208 "parse.y"
	{
      if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) == -1) {
          TS_nuevoRegistro(PilaTT->cabeza, PilaTS->cabeza, S_nuevo(yystack.l_mark[0].dir,yystack.l_mark[-1].base,"var",NULL));
          yyval.base = yystack.l_mark[-1].base;
      } else {
          yyerror("Ya se declaro la variable");
      }
 }
break;
case 30:
#line 217 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 31:
#line 217 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 32:
#line 219 "parse.y"
	{ yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",2,-1,NULL)); }
break;
case 33:
#line 220 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 34:
#line 222 "parse.y"
	{}
break;
case 35:
#line 223 "parse.y"
	{}
break;
case 36:
#line 225 "parse.y"
	{}
break;
case 37:
#line 226 "parse.y"
	{}
break;
case 38:
#line 227 "parse.y"
	{}
break;
case 39:
#line 228 "parse.y"
	{}
break;
case 40:
#line 229 "parse.y"
	{}
break;
case 41:
#line 230 "parse.y"
	{}
break;
case 42:
#line 231 "parse.y"
	{}
break;
case 43:
#line 232 "parse.y"
	{
    char *id = (char *)malloc(sizeof(char)*20);
    strcpy(id,yystack.l_mark[-1].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("read",id,"-","-"));
}
break;
case 44:
#line 237 "parse.y"
	{}
break;
case 45:
#line 238 "parse.y"
	{}
break;
case 46:
#line 239 "parse.y"
	{}
break;
case 47:
#line 240 "parse.y"
	{}
break;
case 48:
#line 242 "parse.y"
	{}
break;
case 49:
#line 243 "parse.y"
	{}
break;
case 50:
#line 245 "parse.y"
	{}
break;
case 51:
#line 246 "parse.y"
	{}
break;
case 52:
#line 248 "parse.y"
	{}
break;
case 53:
#line 249 "parse.y"
	{}
break;
case 54:
#line 250 "parse.y"
	{}
break;
case 55:
#line 251 "parse.y"
	{}
break;
case 56:
#line 252 "parse.y"
	{}
break;
case 57:
#line 253 "parse.y"
	{}
break;
case 58:
#line 255 "parse.y"
	{}
break;
case 59:
#line 256 "parse.y"
	{}
break;
case 60:
#line 258 "parse.y"
	{}
break;
case 61:
#line 259 "parse.y"
	{}
break;
case 62:
#line 260 "parse.y"
	{}
break;
case 63:
#line 261 "parse.y"
	{}
break;
case 64:
#line 262 "parse.y"
	{ strcpy(yyval.expresion.dir,yystack.l_mark[0].numero.dir); yyval.expresion.valor = yystack.l_mark[0].numero.num; }
break;
case 65:
#line 263 "parse.y"
	{}
break;
case 66:
#line 264 "parse.y"
	{}
break;
case 67:
#line 266 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) != -1) { strcpy(GBLid,yystack.l_mark[0].dir);
    } else { yyerror("No se ha declarado variable"); }

}
break;
case 68:
#line 270 "parse.y"
	{
    if (yystack.l_mark[0].variable.estructura == 1) {
        char tmp[10], tmp2[20];
        nuevaTemp(tmp);
        strcpy(yyval.variable.dir,tmp);
        yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
        sprintf(tmp2,"%s[%d]",yystack.l_mark[-2].dir,yystack.l_mark[0].variable.des);
        agregarCuadrupla(codigo,crearCuadrupla("=",tmp2,"-",tmp));
        strcpy(yyval.variable.base,yystack.l_mark[-2].dir);
        yyval.variable.estructura = 1;
        yyval.variable.des = yystack.l_mark[0].variable.des;
    } else {
        strcpy(yyval.variable.dir,yystack.l_mark[-2].dir);
        yyval.variable.tipo = getTipo(PilaTS->cabeza,yystack.l_mark[-2].dir);
        yyval.variable.estructura = 0;
    }
}
break;
case 69:
#line 288 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = yystack.l_mark[0].variable.estructura;
}
break;
case 70:
#line 293 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = 1;
}
break;
case 71:
#line 298 "parse.y"
	{}
break;
case 72:
#line 300 "parse.y"
	{}
break;
case 73:
#line 301 "parse.y"
	{
      int tmp6 = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,tmp6),"struct") == 0) {
          yyval.variable.estructura = 1;
          yyval.variable.tabla = getTS(PilaTT->cabeza,tmp6);
          yyval.variable.des = 0;
      } else {
          yyval.variable.estructura = 0;
          yyval.variable.tipo = tmp6;
      }
}
break;
case 74:
#line 313 "parse.y"
	{
      yyval.variable.tipo = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,yyval.variable.tipo),"arreglo") == 0) {
          printf("holaaaaaaaa\n");
          if (yystack.l_mark[-1].expresion.tipo == 1) {
              int tmp3 = getTipoBase(PilaTT->cabeza,yyval.variable.tipo);
              int tam = TT_getTam(PilaTT->cabeza,tmp3);
              char tmp4[20], tmp5[10], tmp7[10];
              nuevaTemp(tmp4);
              strcpy(yyval.variable.dir,tmp4);
              sprintf(tmp5,"%d",tam);
              strcpy(tmp7,yystack.l_mark[-1].expresion.dir);
              agregarCuadrupla(codigo,crearCuadrupla("*",tmp7,tmp5,tmp4));
              yyval.variable.des = yystack.l_mark[-1].expresion.valor * atoi(tmp5);
          } else { yyerror("El numero del arreglo no es un numero entero"); }
      } else { yyerror("La variable asociada no es de tipo arreglo"); }
}
break;
case 75:
#line 330 "parse.y"
	{}
break;
case 76:
#line 332 "parse.y"
	{}
break;
case 77:
#line 333 "parse.y"
	{}
break;
case 78:
#line 335 "parse.y"
	{}
break;
case 79:
#line 336 "parse.y"
	{}
break;
#line 1157 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
