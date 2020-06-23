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
      char Lfinal[10];
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
#line 101 "y.tab.c"

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
   27,    0,   28,    1,    1,    1,   29,    2,   30,   10,
    8,    8,    8,    8,    8,    9,    9,    3,    7,    7,
   31,   32,   33,    4,    4,   14,   14,   15,   15,   12,
   34,   11,   13,   13,   25,   25,   26,   35,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,    5,
    5,    6,    6,   36,   23,   37,   23,   23,   23,   23,
   23,   24,   24,   22,   22,   22,   22,   22,   22,   22,
   22,   38,   18,   19,   19,   39,   19,   21,   21,   20,
   20,   16,   16,   17,   17,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    0,    5,    0,    3,
    1,    1,    1,    1,    1,    4,    0,    2,    3,    0,
    0,    0,    0,   14,    0,    1,    1,    3,    1,    2,
    0,    3,    3,    0,    2,    0,    5,    0,    8,    5,
    5,    8,    4,    3,    3,    2,    3,    2,    3,    5,
    4,    3,    0,    0,    4,    0,    4,    2,    1,    1,
    1,    3,    1,    3,    3,    3,    3,    1,    1,    1,
    1,    0,    3,    1,    1,    0,    4,    3,    0,    3,
    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    7,   11,   12,   13,   14,   15,    0,    0,
    9,    3,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,   10,    0,    0,   21,    0,
    5,    0,    0,    8,    0,   19,    0,    4,    0,   16,
    0,   31,    0,   29,    0,    0,    0,   30,   22,    0,
    0,   32,    0,   28,    0,    0,   33,   36,    0,   36,
   23,    0,    0,   36,    0,    0,    0,    0,    0,   72,
    0,   35,    0,    0,   61,   60,   71,   70,   69,    0,
    0,   68,    0,    0,    0,    0,    0,    0,    0,   46,
    0,    0,   48,    0,    0,   49,   24,   58,    0,    0,
    0,    0,   36,   54,   56,    0,   36,    0,    0,   44,
   47,   45,    0,   76,   73,   75,    0,    0,   67,    0,
    0,   66,    0,    0,    0,   62,    0,    0,    0,    0,
    0,    0,   43,   37,    0,    0,   57,   40,   41,    0,
    0,    0,    0,    0,   78,   36,    0,    0,   81,   77,
    0,    0,    0,    0,    0,    0,   39,   36,   36,   42,
    0,    0,   50,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   15,  148,  155,   23,   11,   26,   12,
   43,   44,   52,   45,   46,  142,  143,   82,  115,  116,
  117,   83,   84,   85,   59,   72,    2,   19,   13,   18,
   35,   53,   74,   47,  135,  124,  125,   94,  131,
};
static const YYINT yysindex[] = {                         0,
    0,  -64,    0,    0,    0,    0,    0,    0, -241, -260,
    0,    0, -206,  -42,    0, -232, -225, -234, -260,  -64,
 -197, -191,    0,  -64, -229,    0, -184, -165,    0, -232,
    0, -200,  -64,    0, -182,    0, -234,    0,   -5,    0,
    0,    0, -174,    0, -173, -153, -150,    0,    0,  -42,
 -152,    0, -112,    0, -150,  -64,    0,    0,  -58,    0,
    0,  110,  110,    0, -149,  -94, -239, -131, -104,    0,
 -122,    0,  -40, -241,    0,    0,    0,    0,    0,  110,
  -94,    0, -181, -247, -124, -190,   91, -131, -231,    0,
 -226, -102,    0, -135,  -94,    0,    0,    0,   18,  -94,
  -94,  -94,    0,    0,    0,  -94,    0,  110, -130,    0,
    0,    0,  -94,    0,    0,    0, -116, -221,    0, -164,
 -120,    0,   19,  110,  110,    0,   37, -254,  -85,   54,
  -94,  -99,    0,    0, -117, -103,    0,    0,    0,  -77,
 -110, -100,  -89, -181,    0,    0,  -79,  -52,    0,    0,
  -94,   55,  -41,  -39,  -37, -181,    0,    0,    0,    0,
  -17,  109,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  232,    0,
    0,    0,    0,    0,    0,  -14,    0,  -48,    0,  -19,
    0,    0,    0,    1,    0,    0,    0,    0,    0,  -14,
    0,    0,    1,    0,    0,    0,  -48,    0,    0,    0,
 -274,    0,    0,    0,    0,  -55,  -35,    0,    0,    0,
    0,    0,    0,    0,  -35,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  232,    0,    0,    0,    0,    0,    0,
    0,    0,  -96,    0,  -86,    0,    0,    0,    0,    0,
    0,    0,    0, -209,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -169,    0,    0, -114,
 -132,    0,  -56,    0,    0,    0,    0,    0,    0,    0,
  -43,    0,    0,    0,    0, -157,    0,    0,    0,    0,
 -151,    0,  -38, -249,    0,    0,    0,   -1,    0,    0,
    0,    0,    0,    0,    0, -185,    0,    0,    0,    0,
 -252,   20,    0,
};
static const YYINT yygindex[] = {                         0,
   -9,    0,  261,  207,  130,    0,  262,  -23,  256,  280,
    0,  247,  243,    0,    0,    0,    0,  -59,    0,  158,
    0,  -62,  -50,  206,  -54,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 408
static const YYINT yytable[] = {                         71,
    6,    6,  139,   89,   91,   73,   51,   11,   92,   87,
   28,  107,   86,   71,   31,   42,  103,   90,   99,   14,
   51,   16,   11,   38,   27,  110,   42,   71,  109,   98,
  111,   24,  118,  104,  105,  133,   85,  120,  121,  122,
  104,  105,   70,   77,   78,   79,   58,   79,  123,   85,
  130,   20,  127,   22,   79,   32,   79,  128,   81,  100,
  101,  102,   25,   71,  100,  101,  102,   71,  144,  100,
  101,  102,   33,  136,  137,  107,   79,   79,   79,   79,
   79,   79,   79,   79,   29,   79,   79,   74,  156,   79,
   30,  152,   71,   34,   74,   37,   74,  104,  105,   55,
   84,   71,   71,  161,  162,   80,   55,   48,   55,  100,
  101,  102,   80,   84,   80,   39,   74,   74,   74,   74,
   74,   74,   74,   74,   65,   49,   74,  101,  102,   74,
   55,   65,   50,   65,   80,   80,   80,   80,   80,   80,
   80,   80,   64,   55,   80,   56,   51,   80,   88,   64,
   70,   64,   93,   65,  112,   65,   65,   65,   65,   65,
   63,  113,  114,   65,   95,  106,   65,   63,  129,   63,
   59,   64,  102,   64,   64,   64,   64,   59,  132,   59,
  140,   64,  145,  146,   64,  105,  113,   70,   77,   78,
   79,   63,   63,   63,  147,    3,  151,    4,  150,   60,
   61,   59,   59,   81,   62,  153,   63,   64,   65,   66,
   67,   68,   69,    5,    6,    7,    8,   60,   96,    4,
  154,  160,   62,   70,   63,   64,   65,   66,   67,   68,
   69,   25,  158,   17,  159,    5,    6,    7,    8,    6,
   60,   70,   20,   26,   38,   62,   34,   63,   64,   65,
   66,   67,   68,   69,  147,   83,   41,   53,    6,    6,
   82,    6,    6,    6,   70,    6,    6,    6,    6,    6,
    6,    6,    5,    6,    7,    8,   60,  134,   52,   27,
   97,   62,    6,   63,   64,   65,   66,   67,   68,   69,
  163,   36,   40,   21,   60,  138,   54,   57,  149,   62,
   70,   63,   64,   65,   66,   67,   68,   69,  100,  101,
  102,  126,   60,  157,    0,    0,  119,   62,   70,   63,
   64,   65,   66,   67,   68,   69,    0,    0,    0,    0,
    6,    6,    0,    0,    0,    6,   70,    6,    6,    6,
    6,    6,    6,    6,  100,  101,  102,    0,   60,  141,
    0,    0,    0,   62,    6,  108,   64,   65,   66,   67,
   68,   69,    0,    0,    0,    0,   60,    0,    0,    0,
    0,   62,   70,   63,   64,   65,   66,   67,   68,   69,
    0,    0,    0,    0,   75,   76,    0,    0,    0,    0,
   70,   70,   77,   78,   79,    0,    0,    0,    0,    0,
    0,    0,    0,   80,    0,    0,    0,   81,
};
static const YYINT yycheck[] = {                         59,
    0,    0,  257,   66,   67,   60,  259,  282,   68,   64,
   20,  266,   63,   73,   24,   39,  264,  257,   81,  261,
  273,  282,  297,   33,  299,  257,   50,   87,   88,   80,
  257,  257,   95,  288,  289,  257,  286,  100,  101,  102,
  288,  289,  282,  283,  284,  285,   56,  257,  103,  299,
  113,  258,  107,  286,  264,  285,  266,  108,  298,  291,
  292,  293,  297,  123,  291,  292,  293,  127,  131,  291,
  292,  293,  257,  124,  125,  266,  286,  287,  288,  289,
  290,  291,  292,  293,  282,  295,  296,  257,  151,  299,
  282,  146,  152,  259,  264,  296,  266,  288,  289,  257,
  286,  161,  162,  158,  159,  257,  264,  282,  266,  291,
  292,  293,  264,  299,  266,  298,  286,  287,  288,  289,
  290,  291,  292,  293,  257,  299,  296,  292,  293,  299,
  288,  264,  286,  266,  286,  287,  288,  289,  290,  291,
  292,  293,  257,  296,  296,  258,  297,  299,  298,  264,
  282,  266,  257,  286,  257,  288,  289,  290,  291,  292,
  257,  297,  298,  296,  287,  290,  299,  264,  299,  266,
  257,  286,  293,  288,  289,  290,  291,  264,  295,  266,
  266,  296,  282,  301,  299,  289,  297,  282,  283,  284,
  285,  288,  289,  290,  272,  260,  286,  262,  299,  258,
  259,  288,  289,  298,  263,  285,  265,  266,  267,  268,
  269,  270,  271,  278,  279,  280,  281,  258,  259,  262,
  273,  259,  263,  282,  265,  266,  267,  268,  269,  270,
  271,    0,  274,  282,  274,  278,  279,  280,  281,  259,
  258,  282,  257,  299,  301,  263,  282,  265,  266,  267,
  268,  269,  270,  271,  272,  299,  262,  259,  258,  259,
  299,  261,  261,  263,  282,  265,  266,  267,  268,  269,
  270,  271,  278,  279,  280,  281,  258,  259,  259,   19,
   74,  263,  282,  265,  266,  267,  268,  269,  270,  271,
  161,   30,   37,   14,  258,  259,   50,   55,  141,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  291,  292,
  293,  106,  258,  259,   -1,   -1,  299,  263,  282,  265,
  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,
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
#define YYUNDFTOKEN 343
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$7 :",
"funciones : DEF tipo ID $$5 LPAR argumentos RPAR $$6 INICIO declaraciones sentencias FIN $$7 funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"$$8 :",
"tipo_arg : base $$8 param_arr",
"param_arr : CORIZQ CORDER param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias :",
"sentencia : SI e_bool ENTONCES sentencias FIN",
"$$9 :",
"sentencia : SI e_bool ENTONCES sentencias $$9 SINO sentencias FIN",
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
"$$10 :",
"e_bool : e_bool O $$10 e_bool",
"$$11 :",
"e_bool : e_bool Y $$11 e_bool",
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
"$$12 :",
"variable : ID $$12 variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"$$13 :",
"variable_comp : LPAR $$13 parametros RPAR",
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
#line 600 "parse.y"

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
#line 552 "y.tab.c"

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
#line 133 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 133 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 135 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 135 "parse.y"
	{}
break;
case 5:
#line 136 "parse.y"
	{}
break;
case 6:
#line 137 "parse.y"
	{}
break;
case 7:
#line 139 "parse.y"
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
#line 147 "parse.y"
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
#line 159 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 159 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 161 "parse.y"
	{ yyval.base = -1; }
break;
case 12:
#line 162 "parse.y"
	{ yyval.base = 1; }
break;
case 13:
#line 163 "parse.y"
	{ yyval.base = 2; }
break;
case 14:
#line 164 "parse.y"
	{ yyval.base = 3; }
break;
case 15:
#line 165 "parse.y"
	{ yyval.base = 0; }
break;
case 16:
#line 167 "parse.y"
	{
    if (yystack.l_mark[-2].numero.tipo = 1) {
        if (yystack.l_mark[-2].numero.num > 0){
          yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",yystack.l_mark[-2].numero.num*TT_getTam(getTablaGlobal(PilaTT),yystack.l_mark[0].base),yystack.l_mark[0].base,NULL));
        } else { yyerror("El tamano del arreglo no es valido"); }
    } else {   yyerror("El tamaño del arreglo no es un número entero"); }
 }
break;
case 17:
#line 174 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 176 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 19:
#line 184 "parse.y"
	{
  if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 20:
#line 191 "parse.y"
	{}
break;
case 21:
#line 193 "parse.y"
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
#line 207 "parse.y"
	{
          TS_nuevoRegistro(PilaTT->inicio,PilaTS->inicio,S_nuevo(yystack.l_mark[-4].dir,yystack.l_mark[-5].base,"funcion",yystack.l_mark[-1].lista.lista));
      }
break;
case 23:
#line 209 "parse.y"
	{
        printf("%s\n",yystack.l_mark[-1].sentencias.Lfinal );
          if (strcmp(yystack.l_mark[-1].sentencias.Lfinal,"") != 0){ agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",yystack.l_mark[-1].sentencias.Lfinal)); }
          TS_imprimir(PilaTS->cabeza);
          printf("\n");
          TT_imprimir(PilaTT->cabeza);
          printf("\n");
          TS_eliminar(PTS_pop( PilaTS ));
          TT_eliminar(PTT_pop( PilaTT ));
          borrarlistaArg(listaRET);

      }
break;
case 24:
#line 220 "parse.y"
	{}
break;
case 25:
#line 221 "parse.y"
	{}
break;
case 26:
#line 223 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[0].lista.lista; yyval.lista.num = yystack.l_mark[0].lista.num; }
break;
case 27:
#line 224 "parse.y"
	{ yyval.lista.lista = NULL; yyval.lista.num = 0; }
break;
case 28:
#line 226 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[-2].lista.lista; yyval.lista.num = yystack.l_mark[-2].lista.num + 1; agregarArg(yyval.lista.lista,yystack.l_mark[0].base); }
break;
case 29:
#line 227 "parse.y"
	{ yyval.lista.lista = crearListaArg(); agregarArg(yyval.lista.lista,yystack.l_mark[0].base); yyval.lista.num = 1; }
break;
case 30:
#line 229 "parse.y"
	{
      if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) == -1) {
          TS_nuevoRegistro(PilaTT->cabeza, PilaTS->cabeza, S_nuevo(yystack.l_mark[0].dir,yystack.l_mark[-1].base,"var",NULL));
          yyval.base = yystack.l_mark[-1].base;
      } else { yyerror("Ya se declaro la variable"); }
 }
break;
case 31:
#line 236 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 32:
#line 236 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 33:
#line 238 "parse.y"
	{ yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",2,-1,NULL)); }
break;
case 34:
#line 239 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 35:
#line 241 "parse.y"
	{
    if (strcmp(yystack.l_mark[0].sentencias.Lfinal,"") == 0) { strcpy(yyval.sentencias.Lfinal,yystack.l_mark[-1].sentencias.Lfinal);
    } else { strcpy(yyval.sentencias.Lfinal,yystack.l_mark[0].sentencias.Lfinal); }
}
break;
case 36:
#line 245 "parse.y"
	{
    yyval.sentencias.nextlist = nuevaListaIndice();
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    strcpy(yyval.sentencias.label,tmpE);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 37:
#line 253 "parse.y"
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
case 38:
#line 264 "parse.y"
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
case 39:
#line 276 "parse.y"
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
case 40:
#line 286 "parse.y"
	{}
break;
case 41:
#line 287 "parse.y"
	{
    char *tmpE1 = (char *)malloc(sizeof(char)*10);
    char *tmpE2 = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE1);
    strcpy(tmpE2,yystack.l_mark[-3].sentencias.label);
    backpatch(codigo,yystack.l_mark[-1].boleano.truelist,tmpE2);
    backpatch(codigo,yystack.l_mark[-1].boleano.falselist,tmpE1);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE1));
}
break;
case 42:
#line 296 "parse.y"
	{}
break;
case 43:
#line 297 "parse.y"
	{
    char *tmp = (char *)malloc(sizeof(char)*10);
    char *tmp2 = (char *)malloc(sizeof(char)*10);
    reducir(tmp,yystack.l_mark[-1].expresion.dir,yystack.l_mark[-1].expresion.tipo,yystack.l_mark[-3].variable.tipo,codigo);
    strcpy(tmp2,yystack.l_mark[-3].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("=",tmp,"-",tmp2));
}
break;
case 44:
#line 304 "parse.y"
	{
      char *tmp = (char *)malloc(sizeof(char)*15);
      strcpy(tmp,yystack.l_mark[-1].expresion.dir);
      agregarCuadrupla(codigo,crearCuadrupla("write",tmp,"-","-"));
}
break;
case 45:
#line 309 "parse.y"
	{
    char *id = (char *)malloc(sizeof(char)*20);
    strcpy(id,yystack.l_mark[-1].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("read",id,"-","-"));
}
break;
case 46:
#line 314 "parse.y"
	{ agregarCuadrupla(codigo,crearCuadrupla("return","-","-","-")); }
break;
case 47:
#line 315 "parse.y"
	{}
break;
case 48:
#line 316 "parse.y"
	{
    char *tmpI = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpI);
    strcpy(yyval.sentencias.Lfinal,tmpI);
    agregarCuadrupla(codigo,crearCuadrupla("GOTO","-","-",tmpI));
}
break;
case 49:
#line 322 "parse.y"
	{}
break;
case 50:
#line 324 "parse.y"
	{}
break;
case 51:
#line 325 "parse.y"
	{}
break;
case 52:
#line 327 "parse.y"
	{}
break;
case 53:
#line 328 "parse.y"
	{}
break;
case 54:
#line 330 "parse.y"
	{
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,yystack.l_mark[-1].boleano.falselist,tmpE);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 55:
#line 335 "parse.y"
	{
    yyval.boleano.truelist = combinar(yystack.l_mark[-3].boleano.truelist,yystack.l_mark[0].boleano.truelist);
    yyval.boleano.falselist = yystack.l_mark[0].boleano.falselist;
}
break;
case 56:
#line 339 "parse.y"
	{
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,yystack.l_mark[-1].boleano.truelist,tmpE);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
break;
case 57:
#line 344 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.truelist;
    yyval.boleano.falselist = combinar(yystack.l_mark[-3].boleano.falselist,yystack.l_mark[0].boleano.falselist);
}
break;
case 58:
#line 348 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.falselist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.truelist;
}
break;
case 59:
#line 352 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.truelist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.falselist;
}
break;
case 60:
#line 356 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.truelist = nuevaListaIndice();
    agregarIndice(yyval.boleano.truelist,nuevoIndice(indice));
}
break;
case 61:
#line 362 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.falselist = nuevaListaIndice();
    agregarIndice(yyval.boleano.falselist,nuevoIndice(indice));
}
break;
case 62:
#line 369 "parse.y"
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
case 63:
#line 387 "parse.y"
	{
    strcpy(yyval.boleano.dir,yystack.l_mark[0].expresion.dir);
    yyval.boleano.tipo = yystack.l_mark[0].expresion.tipo;
}
break;
case 64:
#line 392 "parse.y"
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
case 65:
#line 405 "parse.y"
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
case 66:
#line 418 "parse.y"
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
case 67:
#line 435 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[-1].expresion.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[-1].expresion.dir); }
break;
case 68:
#line 436 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].variable.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].variable.dir); }
break;
case 69:
#line 437 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].numero.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].numero.dir); yyval.expresion.valor = yystack.l_mark[0].numero.num; }
break;
case 70:
#line 438 "parse.y"
	{  }
break;
case 71:
#line 439 "parse.y"
	{  }
break;
case 72:
#line 441 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) != -1 || existeID(PilaTS->inicio,yystack.l_mark[0].dir) != -1) { strcpy(GBLid,yystack.l_mark[0].dir);
    } else {
        char error[50];
        sprintf(error,"No se ha declarado variable: %s",yystack.l_mark[0].dir);
        yyerror(error);
    }

}
break;
case 73:
#line 449 "parse.y"
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
    } else if (yystack.l_mark[0].variable.estructura == 2){
        strcpy(yyval.variable.dir,yystack.l_mark[0].variable.dir);
        yyval.variable.tipo = getTipo(PilaTS->cabeza,yystack.l_mark[-2].dir);
        yyval.variable.estructura = 0;
    } else {
        strcpy(yyval.variable.dir,yystack.l_mark[-2].dir);
        yyval.variable.tipo = getTipo(PilaTS->cabeza,yystack.l_mark[-2].dir);
        yyval.variable.estructura = 0;
    }
}
break;
case 74:
#line 472 "parse.y"
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
case 75:
#line 485 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = 1;
    strcpy(yyval.variable.dir,yystack.l_mark[0].variable.dir);
}
break;
case 76:
#line 491 "parse.y"
	{strcpy(yystack.l_mark[0].dir,GBLid);}
break;
case 77:
#line 491 "parse.y"
	{
    char *tmp = (char *)malloc(sizeof(char)*10);
    char *tmp2 = (char *)malloc(sizeof(char)*10);
    strcpy(tmp,yystack.l_mark[-3].dir);
    nuevaTemp(tmp2);
    strcpy(yyval.variable.dir,tmp2);
    yyval.variable.estructura = 2;
    if (strcmp(getVar_TS(PilaTS->inicio,tmp),"funcion") == 0) {
        listaArg *lista = getArgs(PilaTS->inicio,tmp);
        int num = lista->tam;
        if (num != yystack.l_mark[-1].lista.num) { yyerror("El numero de parametros no coinciden con la funcion"); }
        if (compararListasArg(lista,yystack.l_mark[-1].lista.lista) == -1) { yyerror("El numero de parametros no coinciden con la funcion"); }
    } else { yyerror("La variable no es una funcion"); }
    agregarCuadrupla(codigo,crearCuadrupla("CALL",tmp,"-",tmp2));
}
break;
case 78:
#line 507 "parse.y"
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
case 79:
#line 525 "parse.y"
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
case 80:
#line 539 "parse.y"
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
case 81:
#line 556 "parse.y"
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
case 82:
#line 580 "parse.y"
	{
    yyval.lista.lista = yystack.l_mark[0].lista.lista;
    yyval.lista.num = yystack.l_mark[0].lista.num;
}
break;
case 83:
#line 584 "parse.y"
	{
    yyval.lista.lista = NULL;
    yyval.lista.num = 0;
}
break;
case 84:
#line 589 "parse.y"
	{
      yyval.lista.lista = yystack.l_mark[-2].lista.lista;
      agregarArg(yyval.lista.lista,yystack.l_mark[0].expresion.tipo);
      yyval.lista.num = yyval.lista.num + 1;
}
break;
case 85:
#line 594 "parse.y"
	{
      yyval.lista.lista = crearListaArg();
      agregarArg(yyval.lista.lista,yystack.l_mark[0].expresion.tipo);
      yyval.lista.num = 1;
}
break;
#line 1459 "y.tab.c"
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
