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

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 29 "parse.y"
typedef union{
  char dir[32];
  int base;
  struct {
      int tipo;
      int num;
      char dir[10];
  } numero;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 64 "y.tab.c"

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
   27,    0,   28,    1,    1,    1,   29,    2,   30,   26,
   24,   24,   24,   24,   24,   25,   25,    3,   23,   23,
    5,    5,    6,    6,    7,    7,    8,    9,   10,   10,
   11,   11,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   13,   13,   14,   14,   15,   15,
   15,   15,   15,   15,   16,   16,   17,   17,   17,   17,
   17,   17,   17,   18,   22,   22,   22,   19,   19,    4,
    4,   20,   20,   21,   21,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    0,    5,    0,    3,
    1,    1,    1,    1,    1,    4,    0,    2,    3,    0,
   11,    0,    1,    1,    3,    1,    2,    2,    3,    0,
    2,    0,    5,    7,    5,    5,    8,    4,    3,    3,
    2,    3,    2,    3,    5,    4,    3,    0,    3,    3,
    2,    1,    1,    1,    3,    1,    3,    3,    3,    1,
    1,    1,    1,    2,    1,    1,    3,    3,    0,    3,
    4,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    7,   11,   12,   13,   14,   15,    0,    0,
    9,    3,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    0,   10,    0,    0,    0,    0,
    5,    0,    0,    8,    0,   19,    0,    4,    0,    0,
    0,   26,    0,    0,   16,    0,    0,   27,    0,   28,
    0,   25,    0,   32,   29,    0,   32,    0,    0,    0,
   32,    0,    0,    0,    0,    0,    0,   31,    0,    0,
   21,   54,   53,   63,   62,   61,    0,    0,    0,    0,
    0,   60,    0,    0,    0,    0,   41,    0,    0,   43,
    0,    0,   66,    0,   64,    0,   44,   51,    0,   32,
    0,    0,    0,    0,    0,   32,    0,    0,   39,   42,
   40,    0,    0,    0,    0,    0,    0,   59,    0,    0,
   50,   55,    0,   58,    0,    0,    0,    0,   67,    0,
   68,   38,   33,   32,   35,   36,    0,   71,    0,    0,
    0,    0,   34,    0,    0,    0,   32,   32,   37,    0,
    0,   45,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   93,   15,   40,   41,   42,   43,   50,
   56,   68,  142,  146,   79,   80,   81,   82,   94,  114,
  115,   95,   23,   11,   26,   12,    2,   19,   13,   18,
};
static const YYINT yysindex[] = {                         0,
    0,  -64,    0,    0,    0,    0,    0,    0, -231, -270,
    0,    0, -204,  -42,    0, -222, -175, -198, -270,  -64,
 -183, -176,    0,  -64, -169,    0, -137, -129, -162, -222,
    0, -158,  -64,    0,   -5,    0, -198,    0,    0, -157,
 -144,    0, -139, -151,    0, -112,  -42,    0, -145,    0,
  -64,    0, -151,    0,    0,  -76,    0, -231,   74,   74,
    0, -143,  -50, -244, -130, -101, -277,    0, -122,  -58,
    0,    0,    0,    0,    0,    0,   74,  -50, -229, -124,
 -206,    0, -255,   55, -130, -249,    0, -241,  -89,    0,
  -50,  -50,    0, -110,    0,  -50,    0,    0, -159,    0,
   74,   74,  -50,  -50,  -50,    0,   74,  -99,    0,    0,
    0, -230, -206,  -96, -100,  -97, -234,    0, -192,  -92,
    0,    0, -104,    0,  -40, -185,  -63,  -75,    0,  -50,
    0,    0,    0,    0,    0,    0,  -68,    0, -206,   19,
  -45,  -30,    0,  -52,  -29,  -15,    0,    0,    0,  -17,
   73,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  256,    0,
    0,    0,    0,    0,    0,    4,    0,  -24,    0,   20,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    4,
    0,    0,    1,    0,    0,    0,  -24,    0, -191,    0,
  -18,    0,    0, -176,    0,    0,    0,    0,    0,    0,
   37,    0, -176,    0,    0,    0,    0,  256,    0,    0,
    0,    0,    0,    0,    0,    0, -177,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -109,
 -113,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -7,    0, -164,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -271,    0,   -6,    0,    0,    0,    0, -240,
    0,    0, -117,    0,    0,    0,    0, -128,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -261,    0,
    0,   22,    0,    0,    0,    0,    0,    0,    0, -252,
   34,    0,
};
static const YYINT yygindex[] = {                         0,
   68,    0,  275,  169,  240,    0,    0,  252,    0,  257,
  -51,    0,  159,    0,  -55,  208,  -60,  -56,    0,    0,
    0,    0,  282,   21,  277,  301,    0,    0,    0,    0,
};
#define YYTABLESIZE 371
static const YYINT yytable[] = {                         69,
    6,    6,   86,   88,   83,   70,   46,  109,   89,   84,
  106,   16,   87,   69,   75,  110,   49,   99,   91,   92,
   46,   98,  132,   49,   74,   49,   75,   69,  108,   14,
  112,  113,  101,  102,  100,  117,   74,   67,   74,   75,
   76,  104,  105,  123,  124,  120,  121,   49,  119,  104,
  105,  126,   78,   20,  125,   44,  104,  105,  101,  102,
  104,  105,   69,   22,  128,   57,  133,   44,   69,  139,
   59,  136,   60,   61,   62,   63,   64,   65,   66,   69,
  106,   24,  140,   69,  104,  105,   69,   28,   69,   67,
   11,   31,   65,   69,   69,  150,  151,   25,   29,   65,
   38,   65,  101,  102,   11,   30,   24,  134,   69,   69,
   69,   69,   69,   69,   69,   32,   69,   69,   54,   33,
   69,   65,   65,   65,   65,   65,   65,   65,   70,   34,
   65,  104,  105,   65,   35,   70,   37,   70,  118,   57,
   46,   47,   48,   56,   49,   51,   57,   52,   57,   53,
   56,   67,   56,   85,   52,   90,   52,   70,   70,   70,
   70,   70,   70,   70,   96,  103,   70,  111,   57,   70,
   57,   57,   57,   57,   56,   56,   56,   57,   52,   52,
   57,   57,   58,  116,  131,  130,   59,  105,   60,   61,
   62,   63,   64,   65,   66,    3,  102,    4,  127,   57,
   97,  129,  137,  141,   59,   67,   60,   61,   62,   63,
   64,   65,   66,    5,    6,    7,    8,   57,  135,    4,
   91,  147,   59,   67,   60,   61,   62,   63,   64,   65,
   66,   67,   74,   75,   76,    5,    6,    7,    8,  144,
   57,   67,  145,  149,  148,   59,   78,   60,   61,   62,
   63,   64,   65,   66,  141,   22,   39,   17,    6,    6,
   20,    6,    6,    6,   67,    6,    6,    6,    6,    6,
    6,    6,    5,    6,    7,    8,   57,  143,    6,   23,
   48,   59,    6,   60,   61,   62,   63,   64,   65,   66,
   73,   72,   47,   27,    6,    6,  138,   71,   52,    6,
   67,    6,    6,    6,    6,    6,    6,    6,  152,   55,
  122,   36,   57,   45,   21,    0,    0,   59,    6,  107,
   61,   62,   63,   64,   65,   66,    0,    0,    0,    0,
   57,    0,    0,    0,    0,   59,   67,   60,   61,   62,
   63,   64,   65,   66,    0,    0,    0,    0,   72,   73,
    0,    0,    0,    0,   67,   67,   74,   75,   76,    0,
    0,    0,    0,    0,    0,    0,   77,    0,    0,    0,
   78,
};
static const YYINT yycheck[] = {                         56,
    0,    0,   63,   64,   60,   57,  259,  257,   65,   61,
  266,  282,  257,   70,  286,  257,  257,   78,  296,  297,
  273,   77,  257,  264,  286,  266,  298,   84,   85,  261,
   91,   92,  288,  289,  264,   96,  298,  282,  283,  284,
  285,  291,  292,  104,  105,  101,  102,  288,  100,  291,
  292,  107,  297,  258,  106,   35,  291,  292,  288,  289,
  291,  292,  119,  286,  295,  258,  259,   47,  125,  130,
  263,  257,  265,  266,  267,  268,  269,  270,  271,  257,
  266,  257,  134,  140,  291,  292,  264,   20,  266,  282,
  282,   24,  257,  150,  151,  147,  148,  296,  282,  264,
   33,  266,  288,  289,  296,  282,  298,  300,  286,  287,
  288,  289,  290,  291,  292,  285,  294,  295,   51,  257,
  298,  286,  287,  288,  289,  290,  291,  292,  257,  259,
  295,  291,  292,  298,  297,  264,  295,  266,  298,  257,
  298,  286,  282,  257,  296,  258,  264,  257,  266,  295,
  264,  282,  266,  297,  264,  257,  266,  286,  287,  288,
  289,  290,  291,  292,  287,  290,  295,  257,  286,  298,
  288,  289,  290,  291,  288,  289,  290,  295,  288,  289,
  298,  258,  259,  294,  282,  286,  263,  292,  265,  266,
  267,  268,  269,  270,  271,  260,  289,  262,  298,  258,
  259,  298,  266,  272,  263,  282,  265,  266,  267,  268,
  269,  270,  271,  278,  279,  280,  281,  258,  259,  262,
  296,  274,  263,  282,  265,  266,  267,  268,  269,  270,
  271,  282,  283,  284,  285,  278,  279,  280,  281,  285,
  258,  282,  273,  259,  274,  263,  297,  265,  266,  267,
  268,  269,  270,  271,  272,    0,  262,  282,  258,  259,
  257,  261,  261,  263,  282,  265,  266,  267,  268,  269,
  270,  271,  278,  279,  280,  281,  258,  259,  259,  298,
  259,  263,  282,  265,  266,  267,  268,  269,  270,  271,
  298,  298,  259,   19,  258,  259,  128,   58,   47,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  150,   53,
  103,   30,  258,   37,   14,   -1,   -1,  263,  282,  265,
  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,  263,  282,  265,  266,  267,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,  275,  276,
   -1,   -1,   -1,   -1,  282,  282,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,
  297,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 333
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
0,0,0,0,0,0,"illegal-symbol",
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
"funciones : DEF tipo ID LPAR argumentos RPAR INICIO declaraciones sentencias FIN funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"tipo_arg : base param_arr",
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
"variable : ID variable_comp",
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
#line 225 "parse.y"

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
#line 490 "y.tab.c"

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
#line 91 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 91 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 93 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 93 "parse.y"
	{}
break;
case 5:
#line 94 "parse.y"
	{}
break;
case 6:
#line 95 "parse.y"
	{}
break;
case 7:
#line 97 "parse.y"
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
#line 104 "parse.y"
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
#line 113 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 10:
#line 113 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 11:
#line 115 "parse.y"
	{ yyval.base = -1; }
break;
case 12:
#line 116 "parse.y"
	{ yyval.base = 1; }
break;
case 13:
#line 117 "parse.y"
	{ yyval.base = 2; }
break;
case 14:
#line 118 "parse.y"
	{ yyval.base = 3; }
break;
case 15:
#line 119 "parse.y"
	{ yyval.base = 0; }
break;
case 16:
#line 121 "parse.y"
	{
    if (yystack.l_mark[-2].numero.tipo = 1) {
        if (yystack.l_mark[-2].numero.num > 0){
          yyval.base = TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("arreglo",yystack.l_mark[-2].numero.num*TT_getTam(getTablaGlobal(PilaTT),yystack.l_mark[0].base),yystack.l_mark[0].base,NULL));
        } else {
          yyerror("El tamano del arreglo no es valido");
        }
    } else {
        yyerror("El tamaño del arreglo no es un número entero");
    }
 }
break;
case 17:
#line 132 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 18:
#line 134 "parse.y"
	{
    if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 19:
#line 142 "parse.y"
	{
  if (existeID(PilaTS->cabeza,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 20:
#line 149 "parse.y"
	{}
break;
case 21:
#line 151 "parse.y"
	{}
break;
case 22:
#line 152 "parse.y"
	{}
break;
case 23:
#line 154 "parse.y"
	{}
break;
case 24:
#line 155 "parse.y"
	{}
break;
case 25:
#line 157 "parse.y"
	{}
break;
case 26:
#line 158 "parse.y"
	{}
break;
case 27:
#line 160 "parse.y"
	{}
break;
case 28:
#line 162 "parse.y"
	{}
break;
case 29:
#line 164 "parse.y"
	{}
break;
case 30:
#line 165 "parse.y"
	{}
break;
case 31:
#line 167 "parse.y"
	{}
break;
case 32:
#line 168 "parse.y"
	{}
break;
case 33:
#line 170 "parse.y"
	{}
break;
case 34:
#line 171 "parse.y"
	{}
break;
case 35:
#line 172 "parse.y"
	{}
break;
case 36:
#line 173 "parse.y"
	{}
break;
case 37:
#line 174 "parse.y"
	{}
break;
case 38:
#line 175 "parse.y"
	{}
break;
case 39:
#line 176 "parse.y"
	{}
break;
case 40:
#line 177 "parse.y"
	{}
break;
case 41:
#line 178 "parse.y"
	{}
break;
case 42:
#line 179 "parse.y"
	{}
break;
case 43:
#line 180 "parse.y"
	{}
break;
case 44:
#line 181 "parse.y"
	{}
break;
case 45:
#line 183 "parse.y"
	{}
break;
case 46:
#line 184 "parse.y"
	{}
break;
case 47:
#line 186 "parse.y"
	{}
break;
case 48:
#line 187 "parse.y"
	{}
break;
case 49:
#line 189 "parse.y"
	{}
break;
case 50:
#line 190 "parse.y"
	{}
break;
case 51:
#line 191 "parse.y"
	{}
break;
case 52:
#line 192 "parse.y"
	{}
break;
case 53:
#line 193 "parse.y"
	{}
break;
case 54:
#line 194 "parse.y"
	{}
break;
case 55:
#line 196 "parse.y"
	{}
break;
case 56:
#line 197 "parse.y"
	{}
break;
case 57:
#line 199 "parse.y"
	{}
break;
case 58:
#line 200 "parse.y"
	{}
break;
case 59:
#line 201 "parse.y"
	{}
break;
case 60:
#line 202 "parse.y"
	{}
break;
case 61:
#line 203 "parse.y"
	{}
break;
case 62:
#line 204 "parse.y"
	{}
break;
case 63:
#line 205 "parse.y"
	{}
break;
case 64:
#line 207 "parse.y"
	{}
break;
case 65:
#line 209 "parse.y"
	{}
break;
case 66:
#line 210 "parse.y"
	{}
break;
case 67:
#line 211 "parse.y"
	{}
break;
case 68:
#line 213 "parse.y"
	{}
break;
case 69:
#line 214 "parse.y"
	{}
break;
case 70:
#line 216 "parse.y"
	{}
break;
case 71:
#line 217 "parse.y"
	{}
break;
case 72:
#line 219 "parse.y"
	{}
break;
case 73:
#line 220 "parse.y"
	{}
break;
case 74:
#line 222 "parse.y"
	{}
break;
case 75:
#line 223 "parse.y"
	{}
break;
#line 1025 "y.tab.c"
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
