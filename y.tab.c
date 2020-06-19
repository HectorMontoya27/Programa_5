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
int tipoGBL;
int baseGBL;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 27 "parse.y"
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
#line 62 "y.tab.c"

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
   27,    0,   28,    1,    1,    1,    2,   29,   26,   24,
   24,   24,   24,   24,   25,   25,    3,   23,   23,    5,
    5,    6,    6,    7,    7,    8,    9,   10,   10,   11,
   11,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,   13,   13,   14,   14,   15,   15,   15,
   15,   15,   15,   16,   16,   17,   17,   17,   17,   17,
   17,   17,   18,   22,   22,   22,   19,   19,    4,    4,
   20,   20,   21,   21,
};
static const YYINT yylen[] = {                            2,
    0,    3,    0,    5,    4,    0,    4,    0,    3,    1,
    1,    1,    1,    1,    4,    0,    2,    3,    0,   11,
    0,    1,    1,    3,    1,    2,    2,    3,    0,    2,
    0,    5,    7,    5,    5,    8,    4,    3,    3,    2,
    3,    2,    3,    5,    4,    3,    0,    3,    3,    2,
    1,    1,    1,    3,    1,    3,    3,    3,    1,    1,
    1,    1,    2,    1,    1,    3,    3,    0,    3,    4,
    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,   10,   11,   12,   13,   14,    0,    0,
    8,    3,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   17,    0,    0,    9,    0,    7,    0,    0,
    5,    0,    0,    0,   18,    0,    4,    0,    0,    0,
   25,    0,    0,   15,    0,    0,   26,    0,   27,    0,
   24,    0,   31,   28,    0,   31,    0,    0,    0,   31,
    0,    0,    0,    0,    0,    0,   30,    0,    0,   20,
   53,   52,   62,   61,   60,    0,    0,    0,    0,    0,
   59,    0,    0,    0,    0,   40,    0,    0,   42,    0,
    0,   65,    0,   63,    0,   43,   50,    0,   31,    0,
    0,    0,    0,    0,   31,    0,    0,   38,   41,   39,
    0,    0,    0,    0,    0,    0,   58,    0,    0,   49,
   54,    0,   57,    0,    0,    0,    0,   66,    0,   67,
   37,   32,   31,   34,   35,    0,   70,    0,    0,    0,
    0,   33,    0,    0,    0,   31,   31,   36,    0,    0,
   44,
};
static const YYINT yydgoto[] = {                          1,
    9,   10,   17,   92,   15,   39,   40,   41,   42,   49,
   55,   67,  141,  145,   78,   79,   80,   81,   93,  113,
  114,   94,   23,   11,   26,   12,    2,   19,   18,
};
static const YYINT yysindex[] = {                         0,
    0, -174, -246,    0,    0,    0,    0,    0, -235, -267,
    0,    0, -174,  -79,    0, -269, -227, -242, -267, -211,
 -210, -197,    0, -174, -186,    0, -156,    0, -194, -269,
    0, -179, -174,  -57,    0, -242,    0,    0, -178, -149,
    0, -152, -161,    0, -119,  -79,    0, -145,    0, -174,
    0, -161,    0,    0,  -73,    0, -235,  -32,  -32,    0,
 -154,  -43, -244, -130, -103, -151,    0, -131,  -51,    0,
    0,    0,    0,    0,    0,  -32,  -43, -207, -125, -159,
    0, -147,   73, -130, -241,    0, -233,  -91,    0,  -43,
  -43,    0, -126,    0,  -43,    0,    0, -200,    0,  -32,
  -32,  -43,  -43,  -43,    0,  -32, -114,    0,    0,    0,
  -16, -159, -111,  -98,  -78, -230,    0, -192,  -86,    0,
    0,  -82,    0,  -33, -224,  -60,  -85,    0,  -43,    0,
    0,    0,    0,    0,    0,  -45,    0, -159,   19,  -56,
  -28,    0,  -46,  -27,  -13,    0,    0,    0,   37,   91,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    2,    0,    0,    0,    0,    0,    0,  248,    0,
    0,    0,   -4,    0,    0,   -1,    0, -267,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,   -1,
    0,    0,    1,    0,    0, -267,    0, -261,    0,  -41,
    0,    0, -210,    0,    0,    0,    0,    0,    0,   55,
    0, -210,    0,    0,    0,    0,  248,    0,    0,    0,
    0,    0,    0,    0,    0, -177,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -109, -113,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -40,    0, -164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -279,    0,  -25,    0,    0,    0,    0,  -75,    0,
    0, -117,    0,    0,    0,    0, -128,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -278,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0, -248,   21,
    0,
};
static const YYINT yygindex[] = {                         0,
   10,    0,  262,  164,  235,    0,    0,  247,    0,  242,
  -50,    0,  147,    0,  -54,  195,  -59,  -55,    0,    0,
    0,    0,  268,   22,  263,  296,    0,    0,    0,
};
#define YYTABLESIZE 373
static const YYINT yytable[] = {                         68,
    6,    6,   85,   87,   82,   69,   74,   73,   88,   83,
   45,   13,   86,   68,   16,  108,   22,   98,   74,   73,
   10,   97,   20,  109,   45,   14,  131,   68,  107,   24,
  111,  112,  135,   31,   10,  116,   23,   66,   73,   74,
   75,  105,   37,  122,  123,  119,  120,   28,  118,  103,
  104,  125,   77,   25,  124,   43,   99,  103,  104,   53,
  103,  104,   68,  100,  101,   56,  132,   43,   68,  138,
   58,   29,   59,   60,   61,   62,   63,   64,   65,   68,
  100,  101,  139,   68,   30,    3,   68,    4,   68,   66,
  103,  104,   64,   68,   68,  149,  150,  117,   32,   64,
   33,   64,   34,    5,    6,    7,    8,  133,   68,   68,
   68,   68,   68,   68,   68,   36,   68,   68,  105,   45,
   68,   64,   64,   64,   64,   64,   64,   64,   69,   47,
   64,  103,  104,   64,   48,   69,   46,   69,   50,   56,
  100,  101,   84,   55,   90,   91,   56,   51,   56,   52,
   55,   66,   55,   89,   51,   95,   51,   69,   69,   69,
   69,   69,   69,   69,  102,  110,   69,  115,   56,   69,
   56,   56,   56,   56,   55,   55,   55,   56,   51,   51,
   56,   48,    4,  126,   56,   57,  128,  129,   48,   58,
   48,   59,   60,   61,   62,   63,   64,   65,    5,    6,
    7,    8,  101,  130,   38,  136,   56,   96,   66,  104,
   90,   58,   48,   59,   60,   61,   62,   63,   64,   65,
    5,    6,    7,    8,   56,  134,  140,  146,  143,   58,
   66,   59,   60,   61,   62,   63,   64,   65,   66,   73,
   74,   75,   71,   72,  144,  148,  147,   21,   66,   66,
   73,   74,   75,   77,    6,   19,   22,   72,    6,    6,
   76,    6,    6,    6,   77,    6,    6,    6,    6,    6,
    6,    6,   71,   47,  103,  104,   56,  142,  127,   46,
   27,   58,    6,   59,   60,   61,   62,   63,   64,   65,
  137,   70,   51,   54,   56,  151,  121,   35,   44,   58,
   66,   59,   60,   61,   62,   63,   64,   65,  140,   21,
    0,    0,    6,    6,    0,    0,    0,    6,   66,    6,
    6,    6,    6,    6,    6,    6,    0,    0,    0,    0,
   56,    0,    0,    0,    0,   58,    6,  106,   60,   61,
   62,   63,   64,   65,    0,    0,    0,    0,   56,    0,
    0,    0,    0,   58,   66,   59,   60,   61,   62,   63,
   64,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,
};
static const YYINT yycheck[] = {                         55,
    0,    0,   62,   63,   59,   56,  286,  286,   64,   60,
  259,  258,  257,   69,  282,  257,  286,   77,  298,  298,
  282,   76,   13,  257,  273,  261,  257,   83,   84,  257,
   90,   91,  257,   24,  296,   95,  298,  282,  283,  284,
  285,  266,   33,  103,  104,  100,  101,  259,   99,  291,
  292,  106,  297,  296,  105,   34,  264,  291,  292,   50,
  291,  292,  118,  288,  289,  258,  259,   46,  124,  129,
  263,  282,  265,  266,  267,  268,  269,  270,  271,  257,
  288,  289,  133,  139,  282,  260,  264,  262,  266,  282,
  291,  292,  257,  149,  150,  146,  147,  298,  285,  264,
  257,  266,  297,  278,  279,  280,  281,  300,  286,  287,
  288,  289,  290,  291,  292,  295,  294,  295,  266,  298,
  298,  286,  287,  288,  289,  290,  291,  292,  257,  282,
  295,  291,  292,  298,  296,  264,  286,  266,  258,  257,
  288,  289,  297,  257,  296,  297,  264,  257,  266,  295,
  264,  282,  266,  257,  264,  287,  266,  286,  287,  288,
  289,  290,  291,  292,  290,  257,  295,  294,  286,  298,
  288,  289,  290,  291,  288,  289,  290,  295,  288,  289,
  298,  257,  262,  298,  258,  259,  298,  286,  264,  263,
  266,  265,  266,  267,  268,  269,  270,  271,  278,  279,
  280,  281,  289,  282,  262,  266,  258,  259,  282,  292,
  296,  263,  288,  265,  266,  267,  268,  269,  270,  271,
  278,  279,  280,  281,  258,  259,  272,  274,  285,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  282,  283,
  284,  285,  275,  276,  273,  259,  274,    0,  282,  282,
  283,  284,  285,  297,  259,  257,  298,  298,  258,  259,
  293,  261,  261,  263,  297,  265,  266,  267,  268,  269,
  270,  271,  298,  259,  291,  292,  258,  259,  295,  259,
   19,  263,  282,  265,  266,  267,  268,  269,  270,  271,
  127,   57,   46,   52,  258,  149,  102,   30,   36,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  272,   14,
   -1,   -1,  258,  259,   -1,   -1,   -1,  263,  282,  265,
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
#define YYUNDFTOKEN 332
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
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"programa : $$1 declaraciones funciones",
"$$2 :",
"declaraciones : tipo $$2 lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"tipo_registro : ESTRUCTURA INICIO declaraciones FIN",
"$$3 :",
"tipo : base $$3 tipo_arreglo",
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
#line 209 "parse.y"

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
#line 487 "y.tab.c"

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
#line 89 "parse.y"
	{ inicializar(); }
break;
case 2:
#line 89 "parse.y"
	{  printf("Aceptado\n"); finalizar(); }
break;
case 3:
#line 91 "parse.y"
	{tipoGBL = yystack.l_mark[0].base;}
break;
case 4:
#line 91 "parse.y"
	{}
break;
case 5:
#line 92 "parse.y"
	{}
break;
case 6:
#line 93 "parse.y"
	{}
break;
case 7:
#line 95 "parse.y"
	{}
break;
case 8:
#line 97 "parse.y"
	{ baseGBL = yystack.l_mark[0].base; }
break;
case 9:
#line 97 "parse.y"
	{ yyval.base = yystack.l_mark[0].base; }
break;
case 10:
#line 99 "parse.y"
	{ yyval.base = -1; }
break;
case 11:
#line 100 "parse.y"
	{ yyval.base = 1; }
break;
case 12:
#line 101 "parse.y"
	{ yyval.base = 2; }
break;
case 13:
#line 102 "parse.y"
	{ yyval.base = 3; }
break;
case 14:
#line 103 "parse.y"
	{ yyval.base = 0; }
break;
case 15:
#line 105 "parse.y"
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
case 16:
#line 116 "parse.y"
	{ yyval.base = baseGBL; }
break;
case 17:
#line 118 "parse.y"
	{
    if (existeID(PilaTS->inicio,yystack.l_mark[-1].dir) == -1) {
        TS_nuevoRegistro(getTablaGlobal(PilaTT),PilaTS->inicio,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
}
break;
case 18:
#line 126 "parse.y"
	{
  if (existeID(PilaTS->inicio,yystack.l_mark[-1].dir) == -1) {
      TS_nuevoRegistro(getTablaGlobal(PilaTT),PilaTS->inicio,S_nuevo(yystack.l_mark[-1].dir,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
break;
case 19:
#line 133 "parse.y"
	{}
break;
case 20:
#line 135 "parse.y"
	{}
break;
case 21:
#line 136 "parse.y"
	{}
break;
case 22:
#line 138 "parse.y"
	{}
break;
case 23:
#line 139 "parse.y"
	{}
break;
case 24:
#line 141 "parse.y"
	{}
break;
case 25:
#line 142 "parse.y"
	{}
break;
case 26:
#line 144 "parse.y"
	{}
break;
case 27:
#line 146 "parse.y"
	{}
break;
case 28:
#line 148 "parse.y"
	{}
break;
case 29:
#line 149 "parse.y"
	{}
break;
case 30:
#line 151 "parse.y"
	{}
break;
case 31:
#line 152 "parse.y"
	{}
break;
case 32:
#line 154 "parse.y"
	{}
break;
case 33:
#line 155 "parse.y"
	{}
break;
case 34:
#line 156 "parse.y"
	{}
break;
case 35:
#line 157 "parse.y"
	{}
break;
case 36:
#line 158 "parse.y"
	{}
break;
case 37:
#line 159 "parse.y"
	{}
break;
case 38:
#line 160 "parse.y"
	{}
break;
case 39:
#line 161 "parse.y"
	{}
break;
case 40:
#line 162 "parse.y"
	{}
break;
case 41:
#line 163 "parse.y"
	{}
break;
case 42:
#line 164 "parse.y"
	{}
break;
case 43:
#line 165 "parse.y"
	{}
break;
case 44:
#line 167 "parse.y"
	{}
break;
case 45:
#line 168 "parse.y"
	{}
break;
case 46:
#line 170 "parse.y"
	{}
break;
case 47:
#line 171 "parse.y"
	{}
break;
case 48:
#line 173 "parse.y"
	{}
break;
case 49:
#line 174 "parse.y"
	{}
break;
case 50:
#line 175 "parse.y"
	{}
break;
case 51:
#line 176 "parse.y"
	{}
break;
case 52:
#line 177 "parse.y"
	{}
break;
case 53:
#line 178 "parse.y"
	{}
break;
case 54:
#line 180 "parse.y"
	{}
break;
case 55:
#line 181 "parse.y"
	{}
break;
case 56:
#line 183 "parse.y"
	{}
break;
case 57:
#line 184 "parse.y"
	{}
break;
case 58:
#line 185 "parse.y"
	{}
break;
case 59:
#line 186 "parse.y"
	{}
break;
case 60:
#line 187 "parse.y"
	{}
break;
case 61:
#line 188 "parse.y"
	{}
break;
case 62:
#line 189 "parse.y"
	{}
break;
case 63:
#line 191 "parse.y"
	{}
break;
case 64:
#line 193 "parse.y"
	{}
break;
case 65:
#line 194 "parse.y"
	{}
break;
case 66:
#line 195 "parse.y"
	{}
break;
case 67:
#line 197 "parse.y"
	{}
break;
case 68:
#line 198 "parse.y"
	{}
break;
case 69:
#line 200 "parse.y"
	{}
break;
case 70:
#line 201 "parse.y"
	{}
break;
case 71:
#line 203 "parse.y"
	{}
break;
case 72:
#line 204 "parse.y"
	{}
break;
case 73:
#line 206 "parse.y"
	{}
break;
case 74:
#line 207 "parse.y"
	{}
break;
#line 1004 "y.tab.c"
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
