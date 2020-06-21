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
  struct LISTA_INDICE *nextlist;

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

  struct {
      struct LISTA_INDICE *truelist;
      struct LISTA_INDICE *falselist;
  }boleano;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 94 "y.tab.c"

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
   27,    0,   28,    1,    1,    1,   29,    2,   30,   12,
   10,   10,   10,   10,   10,   11,   11,    3,    9,    9,
   31,   32,    4,    4,   16,   16,   17,   17,   14,   33,
   13,   15,   15,   25,   25,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,    5,    5,    6,
    6,   23,   23,   23,   23,   23,   23,   24,   24,   22,
   22,   22,   22,   22,   22,   22,   34,   18,   19,   19,
   19,   21,   21,   20,   20,    7,    7,    8,    8,
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
    0,    0,   35,    0,    0,    0,    0,    0,   67,    0,
   34,    0,    0,   57,   56,   66,   65,   64,    0,    0,
   63,    0,    0,    0,    0,    0,    0,    0,   44,    0,
    0,   46,    0,    0,   47,   23,   54,    0,    0,    0,
   35,    0,    0,    0,   35,    0,    0,   42,   45,   43,
    0,    0,   68,   70,    0,    0,   62,    0,   61,    0,
    0,   53,   58,    0,    0,    0,    0,    0,    0,    0,
    0,   41,   36,   35,   38,   39,    0,    0,   71,    0,
   72,    0,    0,    0,   75,    0,   37,    0,    0,    0,
   35,   35,   40,    0,    0,   48,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   15,  144,  150,  128,  129,   23,   11,
   26,   12,   43,   44,   52,   45,   46,   81,  113,  114,
  115,   82,   83,   84,   58,   71,    2,   19,   13,   18,
   35,   73,   47,   93,
};
static const YYINT yysindex[] = {                         0,
    0, -134,    0,    0,    0,    0,    0,    0, -235, -251,
    0,    0, -225,  -83,    0, -222, -206, -231, -251, -134,
 -210, -208,    0, -134, -202,    0, -180, -198,    0, -222,
    0, -203, -134,    0, -212,    0, -231,    0,  -44,    0,
    0,    0, -188,    0, -186, -173, -166,    0, -133,  -83,
 -172,    0, -134,    0, -166,    0,    0,  -56,    0,    0,
   92,   92,    0, -165,   14, -148, -144, -118,    0, -129,
    0,  -38, -235,    0,    0,    0,    0,    0,   92,   14,
    0, -275, -201, -147, -199,   73, -144, -236,    0, -232,
  -98,    0, -196,   14,    0,    0,    0, -223,   14,   14,
    0,   92,   92,   14,    0,   92, -117,    0,    0,    0,
   14,   14,    0,    0, -111, -221,    0, -107,    0, -224,
 -103,    0,    0,  -17,  -88,  -79, -115, -110,  -97, -275,
  -92,    0,    0,    0,    0,    0,  -81,  -91,    0,   14,
    0,   19,  -86,  -69,    0, -275,    0,  -66,  -57,  -43,
    0,    0,    0,   37,   91,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  219,    0,
    0,    0,    0,    0,    0,  -35,    0,  -59,    0,  -21,
    0,    0,    0,    1,    0,    0,    0,    0,    0,  -35,
    0,    0,    1,    0,    0,    0,  -59,    0,    0,    0,
 -274,    0,    0,    0,    0,  -74,  -42,    0,    0,    0,
    0,    0,   55,    0,  -42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  219,    0,    0,    0,    0,    0,    0,    0,
    0,  -96,    0, -116,    0,    0,    0,    0,    0,    0,
    0,    0, -184,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -55,    0,    0, -171,    0,    0, -124,    0,    0,
  -82,    0,    0,    0,    0,    0,    0,    0,  -51, -271,
    0,    0,    0,    0,    0,    0,    0, -135,    0,    0,
    0,    0,    0,  -20,    0, -207,    0,    0,    0,    0,
    0,    0,    0, -254,  -14,    0,
};
static const YYINT yygindex[] = {                         0,
  -13,    0,  236,  183,  103,    0,    0,    0,  228,  -27,
  224,  259,    0,  225,  221,    0,    0,  -58,    0,  136,
    0,  -62,  -49,  175,  -53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 389
static const YYINT yytable[] = {                         70,
    6,    6,   88,   90,   49,   72,   28,   11,   91,   86,
   31,   42,   85,   70,   79,   99,  100,   98,   49,   38,
  108,   11,   42,   26,  109,   14,   79,   70,  107,   97,
   16,  116,   20,   59,  133,  132,  118,  119,   61,   56,
   62,   63,   64,   65,   66,   67,   68,  120,  127,  130,
   24,  124,  121,  122,   99,  100,  125,   69,   99,  100,
   34,   70,  101,   22,   25,   70,  105,   99,  100,   99,
  100,   29,   73,   30,  117,  134,   33,  146,   78,   73,
  142,   73,   32,   70,   39,   69,  102,  103,  102,  103,
   78,   37,   69,   48,   69,   70,   70,  154,  155,  111,
  112,   73,   73,   73,   73,   73,   73,   73,   89,   73,
   73,   49,   50,   73,   69,   69,   69,   69,   69,   69,
   69,   74,   55,   69,   53,    3,   69,    4,   74,   51,
   74,   87,   60,   69,   76,   77,   78,   69,   92,   60,
   55,   60,  104,    5,    6,    7,    8,   55,   80,   55,
   74,   74,   74,   74,   74,   74,   74,   94,  110,   74,
   59,   60,   74,   60,   60,   60,   60,   59,  136,   59,
   60,   55,   55,   60,   52,   99,  100,  105,    4,  138,
  126,   52,  131,   52,  100,  103,  137,  139,  140,  141,
  143,   59,   59,   59,    5,    6,    7,    8,  148,  102,
  103,   59,   60,  149,  111,   52,   61,  151,   62,   63,
   64,   65,   66,   67,   68,  153,  152,   41,   24,   59,
   95,   20,   17,   25,   61,   69,   62,   63,   64,   65,
   66,   67,   68,    5,    6,    7,    8,    6,   51,   33,
   59,  135,   77,   69,   50,   61,   76,   62,   63,   64,
   65,   66,   67,   68,   27,   96,  156,   36,    6,    6,
   40,    6,    6,    6,   69,    6,    6,    6,    6,    6,
    6,    6,   21,  145,   54,   57,   59,  147,  123,    0,
    0,   61,    6,   62,   63,   64,   65,   66,   67,   68,
    0,    0,    0,    0,   59,   69,   76,   77,   78,   61,
   69,   62,   63,   64,   65,   66,   67,   68,  143,    0,
   80,    0,    6,    6,    0,    0,    0,    6,   69,    6,
    6,    6,    6,    6,    6,    6,    0,    0,    0,    0,
   59,    0,    0,    0,    0,   61,    6,  106,   63,   64,
   65,   66,   67,   68,    0,    0,    0,    0,   59,    0,
    0,    0,    0,   61,   69,   62,   63,   64,   65,   66,
   67,   68,    0,    0,    0,    0,   74,   75,    0,    0,
    0,    0,   69,   69,   76,   77,   78,    0,    0,    0,
    0,    0,    0,    0,   79,    0,    0,    0,   80,
};
static const YYINT yycheck[] = {                         58,
    0,    0,   65,   66,  259,   59,   20,  282,   67,   63,
   24,   39,   62,   72,  286,  291,  292,   80,  273,   33,
  257,  296,   50,  298,  257,  261,  298,   86,   87,   79,
  282,   94,  258,  258,  259,  257,   99,  100,  263,   53,
  265,  266,  267,  268,  269,  270,  271,  101,  111,  112,
  257,  105,  102,  103,  291,  292,  106,  282,  291,  292,
  259,  120,  264,  286,  296,  124,  266,  291,  292,  291,
  292,  282,  257,  282,  298,  300,  257,  140,  286,  264,
  134,  266,  285,  142,  297,  257,  288,  289,  288,  289,
  298,  295,  264,  282,  266,  154,  155,  151,  152,  296,
  297,  286,  287,  288,  289,  290,  291,  292,  257,  294,
  295,  298,  286,  298,  286,  287,  288,  289,  290,  291,
  292,  257,  295,  295,  258,  260,  298,  262,  264,  296,
  266,  297,  257,  282,  283,  284,  285,  282,  257,  264,
  257,  266,  290,  278,  279,  280,  281,  264,  297,  266,
  286,  287,  288,  289,  290,  291,  292,  287,  257,  295,
  257,  286,  298,  288,  289,  290,  291,  264,  257,  266,
  295,  288,  289,  298,  257,  291,  292,  266,  262,  295,
  298,  264,  294,  266,  292,  289,  266,  298,  286,  282,
  272,  288,  289,  290,  278,  279,  280,  281,  285,  288,
  289,  258,  259,  273,  296,  288,  263,  274,  265,  266,
  267,  268,  269,  270,  271,  259,  274,  262,    0,  258,
  259,  257,  282,  298,  263,  282,  265,  266,  267,  268,
  269,  270,  271,  278,  279,  280,  281,  259,  259,  282,
  258,  259,  298,  282,  259,  263,  298,  265,  266,  267,
  268,  269,  270,  271,   19,   73,  154,   30,  258,  259,
   37,  261,  261,  263,  282,  265,  266,  267,  268,  269,
  270,  271,   14,  138,   50,   55,  258,  259,  104,   -1,
   -1,  263,  282,  265,  266,  267,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,  258,  282,  283,  284,  285,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  272,   -1,
  297,   -1,  258,  259,   -1,   -1,   -1,  263,  282,  265,
  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,  263,  282,  265,  266,  267,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,  258,   -1,
   -1,   -1,   -1,  263,  282,  265,  266,  267,  268,  269,
  270,  271,   -1,   -1,   -1,   -1,  275,  276,   -1,   -1,
   -1,   -1,  282,  282,  283,  284,  285,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,  297,
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
#line 382 "parse.y"

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
#line 529 "y.tab.c"

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
#line 125 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 125 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 127 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 127 "parse.y"
	{}
break;
case 5:
#line 128 "parse.y"
	{}
break;
case 6:
#line 129 "parse.y"
	{}
break;
case 7:
#line 131 "parse.y"
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
#line 139 "parse.y"
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
#line 149 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 149 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 151 "parse.y"
	{ yyval.base = -1; }
break;
case 12:
#line 152 "parse.y"
	{ yyval.base = 1; }
break;
case 13:
#line 153 "parse.y"
	{ yyval.base = 2; }
break;
case 14:
#line 154 "parse.y"
	{ yyval.base = 3; }
break;
case 15:
#line 155 "parse.y"
	{ yyval.base = 0; }
break;
case 16:
#line 157 "parse.y"
	{
    if (yystack.l_mark[-2].numero.tipo = 1) {
        if (yystack.l_mark[-2].numero.num > 0){
          yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",yystack.l_mark[-2].numero.num*TT_getTam(getTablaGlobal(PilaTT),yystack.l_mark[0].base),yystack.l_mark[0].base,NULL));
        } else { yyerror("El tamano del arreglo no es valido"); }
    } else {   yyerror("El tamaño del arreglo no es un número entero"); }
 }
break;
case 17:
#line 164 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 166 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 19:
#line 174 "parse.y"
	{
  if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 20:
#line 181 "parse.y"
	{}
break;
case 21:
#line 183 "parse.y"
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
#line 197 "parse.y"
	{
          TS_imprimir(PilaTS->cabeza);
          TT_imprimir(PilaTT->cabeza);
          TS_eliminar(PTS_pop( PilaTS ));
          TT_eliminar(PTT_pop( PilaTT ));
          borrarlistaArg(listaRET);

      }
break;
case 23:
#line 204 "parse.y"
	{}
break;
case 24:
#line 205 "parse.y"
	{}
break;
case 25:
#line 207 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[0].lista.lista; yyval.lista.num = yystack.l_mark[0].lista.num; }
break;
case 26:
#line 208 "parse.y"
	{ yyval.lista.lista = NULL; yyval.lista.num = 0; }
break;
case 27:
#line 210 "parse.y"
	{ yyval.lista.lista = yystack.l_mark[-2].lista.lista; yyval.lista.num = yystack.l_mark[-2].lista.num + 1; agregarArg(yyval.lista.lista,yystack.l_mark[0].base); }
break;
case 28:
#line 211 "parse.y"
	{ yyval.lista.lista = crearListaArg(); agregarArg(yyval.lista.lista,yystack.l_mark[0].base); yyval.lista.num = 1; }
break;
case 29:
#line 213 "parse.y"
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
#line 222 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 31:
#line 222 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 32:
#line 224 "parse.y"
	{ yyval.base = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",2,-1,NULL)); }
break;
case 33:
#line 225 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 34:
#line 227 "parse.y"
	{}
break;
case 35:
#line 228 "parse.y"
	{}
break;
case 36:
#line 230 "parse.y"
	{}
break;
case 37:
#line 231 "parse.y"
	{}
break;
case 38:
#line 232 "parse.y"
	{}
break;
case 39:
#line 233 "parse.y"
	{}
break;
case 40:
#line 234 "parse.y"
	{}
break;
case 41:
#line 235 "parse.y"
	{}
break;
case 42:
#line 236 "parse.y"
	{ agregarCuadrupla(codigo,crearCuadrupla("write",yystack.l_mark[-1].expresion.dir,"-","-")); }
break;
case 43:
#line 237 "parse.y"
	{
    char *id = (char *)malloc(sizeof(char)*20);
    strcpy(id,yystack.l_mark[-1].variable.dir);
    agregarCuadrupla(codigo,crearCuadrupla("read",id,"-","-"));
}
break;
case 44:
#line 242 "parse.y"
	{ agregarCuadrupla(codigo,crearCuadrupla("return","-","-","-")); }
break;
case 45:
#line 243 "parse.y"
	{}
break;
case 46:
#line 244 "parse.y"
	{}
break;
case 47:
#line 245 "parse.y"
	{}
break;
case 48:
#line 247 "parse.y"
	{}
break;
case 49:
#line 248 "parse.y"
	{}
break;
case 50:
#line 250 "parse.y"
	{}
break;
case 51:
#line 251 "parse.y"
	{}
break;
case 52:
#line 253 "parse.y"
	{}
break;
case 53:
#line 254 "parse.y"
	{}
break;
case 54:
#line 255 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.falselist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.truelist;
}
break;
case 55:
#line 259 "parse.y"
	{
    yyval.boleano.truelist = yystack.l_mark[0].boleano.truelist;
    yyval.boleano.falselist = yystack.l_mark[0].boleano.falselist;
}
break;
case 56:
#line 263 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.truelist = nuevaListaIndice();
    agregarIndice(yyval.boleano.truelist,nuevoIndice(indice));
}
break;
case 57:
#line 269 "parse.y"
	{
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    yyval.boleano.falselist = nuevaListaIndice();
    agregarIndice(yyval.boleano.falselist,nuevoIndice(indice));
}
break;
case 58:
#line 276 "parse.y"
	{}
break;
case 59:
#line 277 "parse.y"
	{}
break;
case 60:
#line 279 "parse.y"
	{}
break;
case 61:
#line 280 "parse.y"
	{}
break;
case 62:
#line 281 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[-1].expresion.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[-1].expresion.dir); }
break;
case 63:
#line 282 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].variable.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].variable.dir); }
break;
case 64:
#line 283 "parse.y"
	{ yyval.expresion.tipo = yystack.l_mark[0].numero.tipo; strcpy(yyval.expresion.dir,yystack.l_mark[0].numero.dir); yyval.expresion.valor = yystack.l_mark[0].numero.num; }
break;
case 65:
#line 284 "parse.y"
	{}
break;
case 66:
#line 285 "parse.y"
	{  }
break;
case 67:
#line 287 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[0].dir) != -1) { strcpy(GBLid,yystack.l_mark[0].dir);
    } else { yyerror("No se ha declarado variable"); }

}
break;
case 68:
#line 291 "parse.y"
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
case 69:
#line 310 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = yystack.l_mark[0].variable.estructura;
}
break;
case 70:
#line 315 "parse.y"
	{
    yyval.variable.tipo = yystack.l_mark[0].variable.tipo;
    yyval.variable.des = yystack.l_mark[0].variable.des;
    yyval.variable.estructura = 1;
}
break;
case 71:
#line 320 "parse.y"
	{}
break;
case 72:
#line 322 "parse.y"
	{}
break;
case 73:
#line 323 "parse.y"
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
#line 335 "parse.y"
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
case 75:
#line 352 "parse.y"
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
          /*char *tmp6 = (char *)malloc(sizeof(char)*10);*/
          nuevaTemp(tmp2);
          nuevaTemp(tmp5);
          strcpy(yyval.variable.dir,tmp5);
          sprintf(tmp3,"%d",tam);
          strcpy(tmp4,yystack.l_mark[-2].expresion.dir);
          /*strcpy(tmp6,$4.dir);*/
          agregarCuadrupla(codigo,crearCuadrupla("*",tmp4,tmp3,tmp2));
          agregarCuadrupla(codigo,crearCuadrupla("+",tmp2,yystack.l_mark[0].variable.dir,tmp5));
          yyval.variable.des = yystack.l_mark[-2].expresion.valor * atoi(tmp3);
      } else { yyerror("El numero del arreglo no es un numero entero"); }
  } else { yyerror("La variable asociada no es de tipo arreglo"); }
}
break;
case 76:
#line 376 "parse.y"
	{}
break;
case 77:
#line 377 "parse.y"
	{}
break;
case 78:
#line 379 "parse.y"
	{}
break;
case 79:
#line 380 "parse.y"
	{}
break;
#line 1203 "y.tab.c"
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
