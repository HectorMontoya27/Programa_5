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
      struct LISTA_INDICE *nextlist;
      char label[10];
  }sentencias;

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
      int code_estructura;
      struct T_SIMBOLOS *tabla;
  } variable;

  struct {
      int tipo;
      char dir[20];
      int valor;
  }expresion;

  struct {
      char dir[20];
      int tipo;
      struct LISTA_INDICE *truelist;
      struct LISTA_INDICE *falselist;
  }boleano;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 100 "y.tab.c"

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
#define MUL_DIV 292
#define MOD 293
#define NO 294
#define PUNTO 295
#define CORDER 296
#define CORIZQ 297
#define LPAR 298
#define RPAR 299
#define SIT 300
#define SINO 301
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   27,    0,   28,    1,    1,    1,   29,    2,   30,   12,
   10,   10,   10,   10,   10,   11,   11,    3,    9,    9,
   31,   32,    4,    4,   16,   16,   17,   17,   14,   33,
   13,   15,   15,   25,   25,   26,   34,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,    5,    5,
    6,    6,   23,   23,   23,   23,   23,   23,   24,   24,
   22,   22,   22,   22,   22,   22,   22,   22,   35,   18,
   19,   19,   19,   21,   21,   20,   20,    7,    7,    8,
    8,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    0,    5,    0,    3,
    1,    1,    1,    1,    1,    4,    0,    2,    3,    0,
    0,    0,   13,    0,    1,    1,    3,    1,    2,    0,
    3,    3,    0,    2,    0,    5,    0,    8,    5,    5,
    8,    4,    3,    3,    2,    3,    2,    3,    5,    4,
    3,    0,    3,    3,    2,    1,    1,    1,    3,    1,
    3,    3,    3,    3,    1,    1,    1,    1,    0,    3,
    1,    1,    3,    3,    0,    3,    4,    1,    0,    3,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    7,   11,   12,   13,   14,   15,    0,    0,
    9,    3,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,   10,    0,    0,   21,    0,
    5,    0,    0,    8,    0,   19,    0,    4,    0,   16,
    0,   30,    0,   28,    0,    0,    0,   29,    0,    0,
    0,   31,    0,   27,    0,   35,   32,    0,   35,   22,
    0,    0,   35,    0,    0,    0,    0,    0,   69,    0,
   34,    0,    0,   58,   57,   68,   67,   66,    0,    0,
   65,    0,    0,    0,    0,    0,    0,    0,   45,    0,
    0,   47,    0,    0,   48,   23,   55,    0,    0,    0,
    0,   35,    0,    0,    0,   35,    0,    0,   43,   46,
   44,    0,    0,   70,   72,    0,    0,   64,    0,    0,
   63,    0,    0,   54,   59,    0,    0,    0,    0,    0,
    0,    0,    0,   42,   36,    0,   39,   40,    0,    0,
   73,    0,   74,   35,    0,    0,   77,    0,    0,    0,
    0,    0,   38,   35,   35,   41,    0,    0,   49,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   15,  146,  152,  130,  131,   23,   11,
   26,   12,   43,   44,   52,   45,   46,   81,  114,  115,
  116,   82,   83,   84,   58,   71,    2,   19,   13,   18,
   35,   73,   47,  136,   93,
};
static const YYINT yysindex[] = {                         0,
    0,  -32,    0,    0,    0,    0,    0,    0, -245, -247,
    0,    0, -205,  -75,    0, -243, -190, -227, -247,  -32,
 -197, -196,    0,  -32, -192,    0, -169, -164,    0, -243,
    0, -199,  -32,    0, -171,    0, -227,    0,  -28,    0,
    0,    0, -181,    0, -183, -157, -167,    0, -124,  -75,
 -160,    0,  -32,    0, -167,    0,    0,  -69,    0,    0,
  110,  110,    0, -161,   32, -211, -136, -117,    0, -139,
    0,  -44, -245,    0,    0,    0,    0,    0,  110,   32,
    0, -149, -209, -138, -176,   91, -136, -215,    0, -142,
 -104,    0, -275,   32,    0,    0,    0,  -18,   32,   32,
   32,    0,  110,  110,   32,    0,  110, -145,    0,    0,
    0,   32,   32,    0,    0, -133, -118,    0, -267, -137,
    0,  -26, -123,    0,    0,   19, -125,  -88,   54, -115,
 -105, -149, -100,    0,    0, -110,    0,    0,  -80, -102,
    0,   32,    0,    0,  -92,  -57,    0, -149,   37,  -62,
  -56,  -42,    0,    0,    0,    0,   55,  109,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  220,    0,
    0,    0,    0,    0,    0,  -22,    0,  -53,    0,  -23,
    0,    0,    0,    1,    0,    0,    0,    0,    0,  -22,
    0,    0,    1,    0,    0,    0,  -53,    0,    0,    0,
 -250,    0,    0,    0,    0,  -68,  -27,    0,    0,    0,
    0,    0,   73,    0,  -27,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  220,    0,    0,    0,    0,    0,    0,    0,
    0,  -81,    0,  -78,    0,    0,    0,    0,    0,    0,
    0,    0, -230,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -45,    0,    0, -182,    0,    0, -119, -131,
    0,  -43, -251,    0,    0,    0,    0,    0,    0,    0,
  -38, -269,    0,    0,    0,    0,    0,    0,    0, -168,
    0,    0,    0,    0,    0,   -2,    0, -268,    0,    0,
    0,    0,    0,    0,    0,    0, -249,    6,    0,
};
static const YYINT yygindex[] = {                         0,
  -12,    0,  257,  206,  123,    0,    0,    0,  261,   44,
  255,  279,    0,  244,  242,    0,    0,  -58,    0,  158,
    0,  -61,  -59,  194,  -52,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 408
static const YYINT yytable[] = {                         70,
    6,    6,   85,   88,   90,   53,   72,   28,   91,   50,
   86,   31,   53,   70,   53,   14,   81,   80,   98,   97,
   38,  112,  113,   50,  100,  101,   75,   70,  108,   81,
   80,   11,  117,   75,   16,   75,   53,  119,  120,  121,
   56,  109,   22,  123,  124,   89,   11,  127,   26,  122,
  129,  132,   20,  126,  102,   75,   75,   75,   75,   75,
   75,   75,   75,   70,   75,   75,   24,   70,   75,   25,
   69,   76,   77,   78,   71,   99,  100,  101,  103,  104,
  148,   71,   42,   71,   29,   30,   80,   33,   76,  106,
   70,  149,   32,   42,   34,   76,   37,   76,   70,   70,
   48,  157,  158,   71,   71,   71,   71,   71,   71,   71,
   71,  103,  104,   71,  110,   49,   71,   76,   76,   76,
   76,   76,   76,   76,   76,   62,   39,   76,   50,   51,
   76,  138,   62,   53,   62,   55,   87,   61,  134,   92,
  106,   99,  100,  101,   61,   69,   61,   94,   99,  100,
  101,  105,  111,  128,   62,  101,   62,   62,   62,   62,
   62,  133,  103,  104,   62,  104,   61,   62,   61,   61,
   61,   61,   99,  100,  101,   60,   61,  139,   56,   61,
  142,  143,   60,  141,   60,   56,    4,   56,   59,   60,
  144,  145,  150,   61,  112,   62,   63,   64,   65,   66,
   67,   68,    5,    6,    7,    8,   60,   60,   60,   56,
   56,  154,   69,   59,   95,  151,  156,  155,   61,   24,
   62,   63,   64,   65,   66,   67,   68,    3,   17,    4,
   25,   59,  135,   41,   20,    6,   61,   69,   62,   63,
   64,   65,   66,   67,   68,    5,    6,    7,    8,    5,
    6,    7,    8,   79,   33,   69,   52,   37,    6,    6,
   78,    6,    6,    6,   51,    6,    6,    6,    6,    6,
    6,    6,   99,  100,  101,   27,   59,  137,   96,  159,
  118,   61,    6,   62,   63,   64,   65,   66,   67,   68,
   36,   40,   21,   54,   59,  153,   57,  147,  125,   61,
   69,   62,   63,   64,   65,   66,   67,   68,    0,    0,
    0,    0,   59,   69,   76,   77,   78,   61,   69,   62,
   63,   64,   65,   66,   67,   68,  145,    0,    0,   80,
    6,    6,    0,    0,    0,    6,   69,    6,    6,    6,
    6,    6,    6,    6,   99,  100,  101,    0,   59,  140,
    0,    0,    0,   61,    6,  107,   63,   64,   65,   66,
   67,   68,    0,    0,    0,    0,   59,    0,    0,    0,
    0,   61,   69,   62,   63,   64,   65,   66,   67,   68,
    0,    0,    0,    0,   74,   75,    0,    0,    0,    0,
   69,   69,   76,   77,   78,    0,    0,    0,    0,    0,
    0,    0,    0,   79,    0,    0,    0,   80,
};
static const YYINT yycheck[] = {                         58,
    0,    0,   62,   65,   66,  257,   59,   20,   67,  259,
   63,   24,  264,   72,  266,  261,  286,  286,   80,   79,
   33,  297,  298,  273,  292,  293,  257,   86,   87,  299,
  299,  282,   94,  264,  282,  266,  288,   99,  100,  101,
   53,  257,  286,  103,  104,  257,  297,  107,  299,  102,
  112,  113,  258,  106,  264,  286,  287,  288,  289,  290,
  291,  292,  293,  122,  295,  296,  257,  126,  299,  297,
  282,  283,  284,  285,  257,  291,  292,  293,  288,  289,
  142,  264,   39,  266,  282,  282,  298,  257,  257,  266,
  149,  144,  285,   50,  259,  264,  296,  266,  157,  158,
  282,  154,  155,  286,  287,  288,  289,  290,  291,  292,
  293,  288,  289,  296,  257,  299,  299,  286,  287,  288,
  289,  290,  291,  292,  293,  257,  298,  296,  286,  297,
  299,  257,  264,  258,  266,  296,  298,  257,  257,  257,
  266,  291,  292,  293,  264,  282,  266,  287,  291,  292,
  293,  290,  257,  299,  286,  293,  288,  289,  290,  291,
  292,  295,  288,  289,  296,  289,  286,  299,  288,  289,
  290,  291,  291,  292,  293,  257,  296,  266,  257,  299,
  286,  282,  264,  299,  266,  264,  262,  266,  258,  259,
  301,  272,  285,  263,  297,  265,  266,  267,  268,  269,
  270,  271,  278,  279,  280,  281,  288,  289,  290,  288,
  289,  274,  282,  258,  259,  273,  259,  274,  263,    0,
  265,  266,  267,  268,  269,  270,  271,  260,  282,  262,
  299,  258,  259,  262,  257,  259,  263,  282,  265,  266,
  267,  268,  269,  270,  271,  278,  279,  280,  281,  278,
  279,  280,  281,  299,  282,  282,  259,  301,  258,  259,
  299,  261,  261,  263,  259,  265,  266,  267,  268,  269,
  270,  271,  291,  292,  293,   19,  258,  259,   73,  157,
  299,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   30,   37,   14,   50,  258,  259,   55,  140,  105,  263,
  282,  265,  266,  267,  268,  269,  270,  271,   -1,   -1,
   -1,   -1,  258,  282,  283,  284,  285,  263,  282,  265,
  266,  267,  268,  269,  270,  271,  272,   -1,   -1,  298,
  258,  259,   -1,   -1,   -1,  263,  282,  265,  266,  267,
  268,  269,  270,  271,  291,  292,  293,   -1,  258,  296,
   -1,   -1,   -1,  263,  282,  265,  266,  267,  268,  269,
  270,  271,   -1,   -1,   -1,   -1,  258,   -1,   -1,   -1,
   -1,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,
  282,  282,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  294,   -1,   -1,   -1,  298,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 339
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
"OPERADOR_RELACIONAL","SUM_RES","MUL_DIV","MOD","NO","PUNTO","CORDER","CORIZQ",
"LPAR","RPAR","SIT","SINO",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$8 :",
"sentencia : SI e_bool ENTONCES sentencias $$8 SINO sentencias FIN",
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
"expresion : expresion MUL_DIV expresion",
"expresion : expresion MOD expresion",
"expresion : LPAR expresion RPAR",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"$$9 :",
"variable : ID $$9 variable_comp",
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
#line 545 "parse.y"

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
--Nombre Funcion: inicializar()
--Descripcion: Inicializa el programa con lo necesario
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 19 Junio 2020
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
--Nombre Funcion: finalizar()
--Descripcion: Finaliza el compilado mostrando en pantalla los objetos
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 19 Junio 2020
*/
void finalizar(){
    PTT_imprimir(PilaTT);
    PTS_imprimir(PilaTS);
    imprimirCodigo(codigo);
    PTS_eliminar(PilaTS);
    PTT_eliminar(PilaTT);
    eliminarCodigo(codigo);
}
#line 544 "y.tab.c"

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
#line 132 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 132 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 134 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 134 "parse.y"
	{}
break;
case 5:
#line 135 "parse.y"
	{}
break;
case 6:
#line 136 "parse.y"
	{}
break;
case 7:
#line 138 "parse.y"
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
#line 146 "parse.y"
	{

      TS_imprimir(PilaTS->cabeza);
      printf("\n");
      TT_imprimir(PilaTT->cabeza);
      printf("\n");
      tsGBL = PTS_pop(PilaTS);
      tsGBL->tt = PTT_pop(PilaTT);
      tamTS_GBL = tsGBL->dirMax;
      tipoGBL = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("struct",tamTS_GBL,-2,tsGBL));
    }
break;
case 9:
#line 158 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 158 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 160 "parse.y"
	{ yyval.base = -1; }
break;
case 12:
#line 161 "parse.y"
	{ yyval.base = 1; }
break;
case 13:
#line 162 "parse.y"
	{ yyval.base = 2; }
break;
case 14:
#line 163 "parse.y"
	{ yyval.base = 3; }
break;
case 15:
#line 164 "parse.y"
	{ yyval.base = 0; }
break;
case 16:
#line 166 "parse.y"
	{
    if (yystack.l_mark[-2].numero.tipo = 1) {
        if (yystack.l_mark[-2].numero.num > 0){
          yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",yystack.l_mark[-2].numero.num*TT_getTam(getTablaGlobal(PilaTT),yystack.l_mark[0].base),yystack.l_mark[0].base,NULL));
        } else { yyerror("El tamano del arreglo no es valido"); }
    } else {   yyerror("El tamaño del arreglo no es un número entero"); }
 }
break;
case 17:
#line 173 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 175 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 19:
#line 183 "parse.y"
	{
  if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 20:
#line 190 "parse.y"
	{}
break;
case 21:
#line 192 "parse.y"
	{
          if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) == -1) {
              char *funcion = (char *)malloc(sizeof(char)*20);
              sprintf(funcion,"Funcion - %s",yystack.l_mark[0].dir);
              PTS_push(PilaTS,TS_nueva(funcion));
              PTT_push(PilaTT,TT_nueva(funcion));
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
#line 206 "parse.y"
	{
          TS_imprimir(PilaTS->cabeza);
          printf("\n");
          TT_imprimir(PilaTT->cabeza);
          printf("\n");
          TS_eliminar(PTS_pop( PilaTS ));
          TT_eliminar(PTT_pop( PilaTT ));
          borrarlistaArg(listaRET);

      }
break;
case 23:
#line 215 "parse.y"
	{}
break;
case 24:
#line 216 "parse.y"
	{}
break;
case 25:
#line 218 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[0].lista.lista; yyval.lista.num = yystack.l_mark[0].lista.num; }
break;
case 26:
#line 219 "parse.y"
	{ yyval.lista.lista = NULL; yyval.lista.num = 0; }
break;
case 27:
#line 221 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[-2].lista.lista; yyval.lista.num = yystack.l_mark[-2].lista.num + 1; agregarArg(yyval.lista.lista,yystack.l_mark[0].base); }
break;
case 28:
#line 222 "parse.y"
	{ yyval.lista.lista = crearListaArg(); agregarArg(yyval.lista.lista,yystack.l_mark[0].base); yyval.lista.num = 1; }
break;
case 29:
#line 224 "parse.y"
	{
      if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) == -1) {
          TS_nuevoRegistro(PilaTT->cabeza, PilaTS->cabeza, S_nuevo(yystack.l_mark[0].dir,yystack.l_mark[-1].base,"var",NULL));
          yyval.base = yystack.l_mark[-1].base;
      } else { yyerror("Ya se declaro la variable"); }
 }
break;
case 30:
#line 231 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 31:
#line 231 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 32:
#line 233 "parse.y"
	{ yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",2,-1,NULL)); }
break;
case 33:
#line 234 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 34:
#line 236 "parse.y"
	{}
break;
case 35:
#line 237 "parse.y"
	{
    yyval.sentencias.nextlist = nuevaListaIndice();
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    strcpy(yyval.sentencias.label,tmpE);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 36:
#line 245 "parse.y"
	{
      char tmpE[10];
      char *tmp = (char *)malloc(sizeof(char)*10);
      nuevaEtiqueta(tmpE);
      strcpy(tmp,yystack.l_mark[-1].sentencias.label);
      backpatch(codigo,yystack.l_mark[-3].boleano.truelist,tmp);
      agregarIndice(yystack.l_mark[-1].sentencias.nextlist,nuevoIndice(tmpE));
      yyval.sentencias.nextlist = combinar(yystack.l_mark[-3].boleano.falselist,yystack.l_mark[-1].sentencias.nextlist);
      backpatch(codigo,yyval.sentencias.nextlist,tmpE);
      agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 37:
#line 256 "parse.y"
	{
      char *tmpE1 = (char *)malloc(sizeof(char)*10);
      char *tmpE3 = (char *)malloc(sizeof(char)*10);
      char *tmp5 = (char *)malloc(sizeof(char)*10);
      nuevaEtiqueta(tmpE1);
      nuevaEtiqueta(tmpE3);
      strcpy(tmp5,yystack.l_mark[0].sentencias.label);
      backpatch(codigo,yystack.l_mark[-2].boleano.truelist,tmp5);
      agregarIndice(yystack.l_mark[-2].boleano.falselist,nuevoIndice(tmpE1));
      agregarIndice(yystack.l_mark[0].sentencias.nextlist,nuevoIndice(tmpE3));
      agregarCuadrupla(codigo,crearCuadrupla("GOTO","-","-",tmpE3));
      agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE1));
}
break;
case 38:
#line 268 "parse.y"
	{
      char *tmpE2 = (char *)malloc(sizeof(char)*10);
      char *tmpE4 = (char *)malloc(sizeof(char)*10);
      nuevaEtiqueta(tmpE2);
      nuevaEtiqueta(tmpE4);
      agregarIndice(yystack.l_mark[-6].boleano.falselist,nuevoIndice(yystack.l_mark[-1].sentencias.label));
      backpatch(codigo,yystack.l_mark[-6].boleano.falselist,tmpE4);
      backpatch(codigo,yystack.l_mark[-4].sentencias.nextlist,tmpE2);
      agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE2));
}
break;
case 39:
#line 278 "parse.y"
	{}
break;
case 40:
#line 279 "parse.y"
	{}
break;
case 41:
#line 280 "parse.y"
	{}
break;
case 42:
#line 281 "parse.y"
	{
    char *tmp = (char *)malloc(sizeof(char)*10);
    char *tmp2 = (char *)malloc(sizeof(char)*10);
    reducir(tmp,yystack.l_mark[-1].expresion.dir,yystack.l_mark[-1].expresion.tipo,yystack.l_mark[-3].variable.tipo,codigo);
    strcpy(tmp2,yystack.l_mark[-3].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("=",tmp,"-",tmp2));
}
break;
case 43:
#line 288 "parse.y"
	{
      char *tmp = (char *)malloc(sizeof(char)*15);
      strcpy(tmp,yystack.l_mark[-1].expresion.dir);
      agregarCuadrupla(codigo,crearCuadrupla("write",tmp,"-","-"));
}
break;
case 44:
#line 293 "parse.y"
	{
    char *id = (char *)malloc(sizeof(char)*20);
    strcpy(id,yystack.l_mark[-1].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("read",id,"-","-"));
}
break;
case 45:
#line 298 "parse.y"
	{ agregarCuadrupla(codigo,crearCuadrupla("return","-","-","-")); }
break;
case 46:
#line 299 "parse.y"
	{}
break;
case 47:
#line 300 "parse.y"
	{}
break;
case 48:
#line 301 "parse.y"
	{}
break;
case 49:
#line 303 "parse.y"
	{}
break;
case 50:
#line 304 "parse.y"
	{}
break;
case 51:
#line 306 "parse.y"
	{}
break;
case 52:
#line 307 "parse.y"
	{}
break;
case 53:
#line 309 "parse.y"
	{
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,yystack.l_mark[-2].boleano.falselist,tmpE);
    yyval.boleano.truelist = combinar(yystack.l_mark[-2].boleano.truelist,yystack.l_mark[0].boleano.truelist);
    yyval.boleano.falselist = yystack.l_mark[0].boleano.falselist;
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 54:
#line 317 "parse.y"
	{
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,yystack.l_mark[-2].boleano.truelist,tmpE);
    yyval.boleano.truelist = yystack.l_mark[-2].boleano.truelist;
    yyval.boleano.falselist = combinar(yystack.l_mark[-2].boleano.falselist,yystack.l_mark[0].boleano.falselist);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 55:
#line 325 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.falselist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.truelist;
}
break;
case 56:
#line 329 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.truelist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.falselist;
}
break;
case 57:
#line 333 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.truelist = nuevaListaIndice();
    agregarIndice(yyval.boleano.truelist,nuevoIndice(indice));
}
break;
case 58:
#line 339 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.falselist = nuevaListaIndice();
    agregarIndice(yyval.boleano.falselist,nuevoIndice(indice));
}
break;
case 59:
#line 346 "parse.y"
	{
    char *tmpI1 = (char *)malloc(sizeof(char)*10);
    char *tmpI2 = (char *)malloc(sizeof(char)*10);
    char *tmpR1 = (char *)malloc(sizeof(char)*10);
    char *tmpR2 = (char *)malloc(sizeof(char)*10);
    char *tmp = (char *)malloc(sizeof(char)*10);
    nuevoIndex(tmpI1);
    nuevoIndex(tmpI2);
    yyval.boleano.truelist = nuevaListaIndice();
    yyval.boleano.falselist = nuevaListaIndice();
    agregarIndice(yyval.boleano.truelist,nuevoIndice(tmpI1));
    agregarIndice(yyval.boleano.falselist,nuevoIndice(tmpI2));
    strcpy(tmp,yystack.l_mark[-1].dir);
    strcpy(tmpR1,yystack.l_mark[-2].boleano.dir);
    strcpy(tmpR2,yystack.l_mark[0].boleano.dir);
    agregarCuadrupla(codigo,crearCuadrupla(tmp,tmpR1,tmpR2,tmpI1));
    agregarCuadrupla(codigo,crearCuadrupla("GOTO","-","-",tmpI2));
}
break;
case 60:
#line 364 "parse.y"
	{
    strcpy(yyval.boleano.dir,yystack.l_mark[0].expresion.dir);
    yyval.boleano.tipo = yystack.l_mark[0].expresion.tipo;
}
break;
case 61:
#line 369 "parse.y"
	{
      yyval.expresion.tipo = max(yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo);
      char *tmp1 = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      char *tmp3 = (char *)malloc(sizeof(char)*10);
      char *op = (char *)malloc(sizeof(char));
      nuevaTemp(tmp1);
      strcpy(yyval.expresion.dir,tmp1);
      strcpy(op,yystack.l_mark[-1].dir);
      ampliar(tmp2,yystack.l_mark[-2].expresion.dir,yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo,codigo);
      ampliar(tmp3,yystack.l_mark[0].expresion.dir,yystack.l_mark[0].expresion.tipo,yystack.l_mark[-2].expresion.tipo,codigo);
      agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
}
break;
case 62:
#line 382 "parse.y"
	{
      yyval.expresion.tipo = max(yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo);
      char *tmp1 = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      char *tmp3 = (char *)malloc(sizeof(char)*10);
      char *op = (char *)malloc(sizeof(char));
      nuevaTemp(tmp1);
      strcpy(yyval.expresion.dir,tmp1);
      strcpy(op,yystack.l_mark[-1].dir);
      ampliar(tmp2,yystack.l_mark[-2].expresion.dir,yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo,codigo);
      ampliar(tmp3,yystack.l_mark[0].expresion.dir,yystack.l_mark[0].expresion.tipo,yystack.l_mark[-2].expresion.tipo,codigo);
      agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
}
break;
case 63:
#line 395 "parse.y"
	{
    if (yystack.l_mark[-2].expresion.tipo == 1 && yystack.l_mark[0].expresion.tipo == 1){
        yyval.expresion.tipo = max(yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo);
        char *tmp1 = (char *)malloc(sizeof(char)*10);
        char *tmp2 = (char *)malloc(sizeof(char)*10);
        char *tmp3 = (char *)malloc(sizeof(char)*10);
        char *op = (char *)malloc(sizeof(char));
        nuevaTemp(tmp1);
        strcpy(yyval.expresion.dir,tmp1);
        strcpy(op,yystack.l_mark[-1].dir);
        ampliar(tmp2,yystack.l_mark[-2].expresion.dir,yystack.l_mark[-2].expresion.tipo,yystack.l_mark[0].expresion.tipo,codigo);
        ampliar(tmp3,yystack.l_mark[0].expresion.dir,yystack.l_mark[0].expresion.tipo,yystack.l_mark[-2].expresion.tipo,codigo);
        agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
    } else {
        yyerror("El modulo se aplica a enteros");
    }
}
break;
case 64:
#line 412 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[-1].expresion.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[-1].expresion.dir); }
break;
case 65:
#line 413 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].variable.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].variable.dir); }
break;
case 66:
#line 414 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].numero.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].numero.dir); yyval.expresion.valor = yystack.l_mark[0].numero.num; }
break;
case 67:
#line 415 "parse.y"
	{  }
break;
case 68:
#line 416 "parse.y"
	{  }
break;
case 69:
#line 418 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) != -1) { strcpy(GBLid,yystack.l_mark[0].dir);
    } else {
        char error[50];
        sprintf(error,"No se ha declarado variable: %s",yystack.l_mark[0].dir);
        yyerror(error);
    }

}
break;
case 70:
#line 426 "parse.y"
	{
    if (yystack.l_mark[0].variable.estructura == 1) {
        char *tmp = (char *)malloc(sizeof(char)*10);
        char *tmp2 = (char *)malloc(sizeof(char)*20);
        nuevaTemp(tmp);
        strcpy(yyval.variable.dir,tmp);
        yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
        sprintf(tmp2,"%s[%s]",yystack.l_mark[-2].dir,yystack.l_mark[0].variable.dir);
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
case 71:
#line 445 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = yystack.l_mark[0].variable.estructura;
    if (yystack.l_mark[0].variable.estructura == 1) {
      char *tmp = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      nuevaTemp(tmp);
      sprintf(tmp2,"%d",yystack.l_mark[0].variable.des);
      agregarCuadrupla(codigo,crearCuadrupla("=",tmp2,"-",tmp));
      strcpy(yyval.variable.dir,tmp);
    }
}
break;
case 72:
#line 458 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = 1;
    strcpy(yyval.variable.dir,yystack.l_mark[0].variable.dir);
}
break;
case 73:
#line 464 "parse.y"
	{}
break;
case 74:
#line 466 "parse.y"
	{
      if (yystack.l_mark[-2].variable.code_estructura == 1) {
          if (existeID(yystack.l_mark[-2].variable.tabla,yystack.l_mark[0].dir) != -1) {
              yyval.variable.des = yystack.l_mark[-2].variable.des + getDir(yystack.l_mark[-2].variable.tabla,yystack.l_mark[0].dir);
              int tipoV = getTipo(yystack.l_mark[-2].variable.tabla,yystack.l_mark[0].dir);
              yyval.variable.tipo = tipoV;
              char est[15];
              strcpy(est,getNombre_TT(yystack.l_mark[-2].variable.tabla->tt,tipoV));
              if (strcmp(est,"struct") == 0) {
                  yyval.variable.code_estructura = 1;
                  yyval.variable.tabla = getTS(yystack.l_mark[-2].variable.tabla->tt,tipoV);
              } else {
                  yyval.variable.code_estructura = 0;
                  yyval.variable.tabla = NULL;
              }
          } else { yyerror("La variable no ha sido declarada"); }
      } else { yyerror("La variable no es una estructura"); }
}
break;
case 75:
#line 484 "parse.y"
	{
      int tmp6 = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,tmp6),"struct") == 0) {
          yyval.variable.estructura = 1;
          yyval.variable.code_estructura = 1;
          yyval.variable.tabla = getTS(PilaTT->cabeza,tmp6);
          yyval.variable.des = 0;
      } else {
          yyval.variable.estructura = 0;
          yyval.variable.code_estructura = 0;
          yyval.variable.tipo = tmp6;
      }
}
break;
case 76:
#line 498 "parse.y"
	{
      yyval.variable.tipo = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,yyval.variable.tipo),"arreglo") == 0) {
          if (yystack.l_mark[-1].expresion.tipo == 1) {
              int tmp3 = getTipoBase(PilaTT->cabeza,yyval.variable.tipo);
              int tam = TT_getTam(PilaTT->cabeza,tmp3);
              char *tmp4 = (char *)malloc(sizeof(char)*20);
              char *tmp5 = (char *)malloc(sizeof(char)*10);
              char *tmp7 = (char *)malloc(sizeof(char)*10);
              nuevaTemp(tmp4);
              strcpy(yyval.variable.dir,tmp4);
              sprintf(tmp5,"%d",tam);
              strcpy(tmp7,yystack.l_mark[-1].expresion.dir);
              agregarCuadrupla(codigo,crearCuadrupla("*",tmp7,tmp5,tmp4));
          } else { yyerror("El numero del arreglo no es un numero entero"); }
      } else { yyerror("La variable asociada no es de tipo arreglo"); }
}
break;
case 77:
#line 515 "parse.y"
	{
  yyval.variable.tipo = getTipoBase(PilaTT->cabeza,yystack.l_mark[0].variable.tipo);
  if (strcmp(getNombre_TT(PilaTT->cabeza,yyval.variable.tipo),"arreglo") == 0) {
      if (yystack.l_mark[-2].expresion.tipo == 1) {
          int tmp = getTipoBase(PilaTT->cabeza,yyval.variable.tipo);
          int tam = TT_getTam(PilaTT->cabeza,tmp);
          char *tmp2 = (char *)malloc(sizeof(char)*20);
          char *tmp3 = (char *)malloc(sizeof(char)*10);
          char *tmp4 = (char *)malloc(sizeof(char)*10);
          char *tmp5 = (char *)malloc(sizeof(char)*10);
          char *tmp6 = (char *)malloc(sizeof(char)*10);
          nuevaTemp(tmp2);
          nuevaTemp(tmp5);
          strcpy(yyval.variable.dir,tmp5);
          sprintf(tmp3,"%d",tam);
          strcpy(tmp4,yystack.l_mark[-2].expresion.dir);
          strcpy(tmp6,yystack.l_mark[0].variable.dir);
          agregarCuadrupla(codigo,crearCuadrupla("*",tmp4,tmp3,tmp2));
          agregarCuadrupla(codigo,crearCuadrupla("+",tmp2,tmp6,tmp5));
          yyval.variable.des = yystack.l_mark[-2].expresion.valor * atoi(tmp3);
      } else { yyerror("El numero del arreglo no es un numero entero"); }
  } else { yyerror("La variable asociada no es de tipo arreglo"); }
}
break;
case 78:
#line 539 "parse.y"
	{}
break;
case 79:
#line 540 "parse.y"
	{}
break;
case 80:
#line 542 "parse.y"
	{}
break;
case 81:
#line 543 "parse.y"
	{}
break;
#line 1381 "y.tab.c"
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
