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

void yyerror(char *s);
extern int yylex();
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 17 "parse.y"
typedef union{
  char dir[64];
  int base;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

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
    0,    1,    1,    1,    2,    3,   26,   26,   26,   26,
   26,    4,    4,    5,   25,   25,    7,    7,    8,    8,
    9,    9,   10,   11,   12,   12,   13,   13,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   15,   15,   16,   16,   17,   17,   17,   17,   17,   17,
   18,   18,   19,   19,   19,   19,   19,   19,   19,   20,
   24,   24,   24,   21,   21,    6,    6,   22,   22,   23,
   23,
};
static const YYINT yylen[] = {                            2,
    2,    4,    4,    0,    4,    2,    1,    1,    1,    1,
    1,    4,    0,    2,    3,    0,   11,    0,    1,    1,
    3,    1,    2,    2,    3,    0,    2,    0,    5,    7,
    5,    5,    8,    4,    3,    3,    2,    3,    2,    3,
    5,    4,    3,    0,    3,    3,    2,    1,    1,    1,
    3,    1,    3,    3,    3,    1,    1,    1,    1,    2,
    1,    1,    3,    3,    0,    3,    4,    1,    0,    3,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    7,    8,    9,   10,   11,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    6,    0,
    0,    0,   14,    0,    0,    0,    5,    0,    0,    3,
    2,    0,    0,   15,   12,    0,    0,    0,   22,    0,
    0,    0,    0,   23,    0,   24,    0,   21,    0,   28,
   25,    0,   28,    0,    0,    0,   28,    0,    0,    0,
    0,    0,    0,   27,    0,    0,   17,   50,   49,   59,
   58,   57,    0,    0,    0,    0,    0,   56,    0,    0,
    0,    0,   37,    0,    0,   39,    0,    0,   62,    0,
   60,    0,   40,   47,    0,   28,    0,    0,    0,    0,
    0,   28,    0,    0,   35,   38,   36,    0,    0,    0,
    0,    0,    0,   55,    0,    0,   46,   51,    0,   54,
    0,    0,    0,    0,   63,    0,   64,   34,   29,   28,
   31,   32,    0,   67,    0,    0,    0,    0,   30,    0,
    0,    0,   28,   28,   33,    0,    0,   41,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   10,   19,   16,   89,   14,   37,   38,   39,
   40,   46,   52,   64,  138,  142,   75,   76,   77,   78,
   90,  110,  111,   91,   23,   11,
};
static const YYINT yysindex[] = {                       -64,
 -250,    0,    0,    0,    0,    0,    0, -249, -252, -252,
 -253,  -64,  -42,    0, -221, -175, -171, -178,    0, -143,
 -194, -152,    0,  -64,  -64, -163,    0, -162, -221,    0,
    0, -253,   13,    0,    0,    0, -165, -149,    0, -139,
 -157, -112,  -42,    0, -145,    0,  -64,    0, -157,    0,
    0,  -76,    0, -249,   74,   74,    0, -141,  -50, -244,
 -130, -103, -191,    0, -122,  -58,    0,    0,    0,    0,
    0,    0,   74,  -50, -227, -124, -172,    0, -255,   55,
 -130, -241,    0, -234,  -89,    0,  -50,  -50,    0, -110,
    0,  -50,    0,    0, -200,    0,   74,   74,  -50,  -50,
  -50,    0,   74, -101,    0,    0,    0, -150, -172,  -99,
 -100,  -97, -232,    0, -192,  -87,    0,    0, -104,    0,
  -40, -185,  -63,  -92,    0,  -50,    0,    0,    0,    0,
    0,    0,  -32,    0, -172,   19,  -41,  -30,    0,  -53,
  -29,  -37,    0,    0,    0,  -17,   73,    0,
};
static const YYINT yyrindex[] = {                         2,
    0,    0,    0,    0,    0,    0,    0,  256,    0,    0,
  -25,   -1,    0,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    1,    0,    0,    0,    4,    0,
    0,  -25,    0,    0,    0, -197,    0,  -24,    0,    0,
   -9,    0,    0,    0,    0,    0,   37,    0,   -9,    0,
    0,    0,    0,  256,    0,    0,    0,    0,    0,    0,
    0,    0, -177,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -109, -113,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -22,    0, -164,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -271,    0,
  -19,    0,    0,    0,    0, -240,    0,    0, -117,    0,
    0,    0,    0, -128,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -230,    0,    0,   22,    0,    0,
    0,    0,    0,    0,    0, -238,   38,    0,
};
static const YYINT yygindex[] = {                         0,
   -5,    0,  267,  266,  289,  185,  257,    0,    0,  269,
    0,  261,  -47,    0,  168,    0,  -51,  216,  -56,  -52,
    0,    0,    0,    0,  287,   21,
};
#define YYTABLESIZE 371
static const YYINT yytable[] = {                         65,
    4,    4,   82,   84,   79,   66,   20,   12,   85,   80,
  102,   13,   83,   65,   71,  105,   45,   95,   30,   31,
   42,   94,  106,   45,  128,   45,   71,   65,  104,   15,
  108,  109,   97,   98,   42,  113,   96,   63,   70,   71,
   72,   50,   18,  119,  120,  116,  117,   45,  115,  100,
  101,  122,   74,   41,  121,   70,  100,  101,  100,  101,
   97,   98,   65,   41,   22,   53,  129,   70,   65,  135,
   55,  132,   56,   57,   58,   59,   60,   61,   62,   65,
  102,   24,  136,   65,    7,   25,   65,   28,   65,   63,
  100,  101,   61,   65,   65,  146,  147,  114,    7,   61,
   20,   61,   97,   98,   87,   88,   26,  130,   65,   65,
   65,   65,   65,   65,   65,   27,   65,   65,  100,  101,
   65,   61,   61,   61,   61,   61,   61,   61,   66,   29,
   61,   32,   42,   61,   33,   66,   43,   66,   45,   53,
  100,  101,   44,   52,  124,   47,   53,   48,   53,   49,
   52,   63,   52,   86,   48,   81,   48,   66,   66,   66,
   66,   66,   66,   66,   92,   99,   66,  107,   53,   66,
   53,   53,   53,   53,   52,   52,   52,   53,   48,   48,
   53,   53,   54,  112,  127,  126,   55,  101,   56,   57,
   58,   59,   60,   61,   62,    1,  123,    2,  125,   53,
   93,   98,  133,   87,   55,   63,   56,   57,   58,   59,
   60,   61,   62,    3,    4,    5,    6,   53,  131,    2,
  143,  145,   55,   63,   56,   57,   58,   59,   60,   61,
   62,   63,   70,   71,   72,    3,    4,    5,    6,  137,
   53,   63,  141,  140,  144,   55,   74,   56,   57,   58,
   59,   60,   61,   62,  137,   18,   13,    4,    4,    4,
   16,    4,    4,    4,   63,    4,    4,    4,    4,    4,
    4,    4,   26,   19,   36,   69,   53,  139,   68,   21,
   44,   55,    4,   56,   57,   58,   59,   60,   61,   62,
    3,    4,    5,    6,    4,    4,   43,   35,   17,    4,
   63,    4,    4,    4,    4,    4,    4,    4,  134,   51,
   67,   48,   53,  148,  118,   34,    0,   55,    4,  103,
   57,   58,   59,   60,   61,   62,    0,    0,    0,    0,
   53,    0,    0,    0,    0,   55,   63,   56,   57,   58,
   59,   60,   61,   62,    0,    0,    0,    0,   68,   69,
    0,    0,    0,    0,   63,   63,   70,   71,   72,    0,
    0,    0,    0,    0,    0,    0,   73,    0,    0,    0,
   74,
};
static const YYINT yycheck[] = {                         52,
    0,    0,   59,   60,   56,   53,   12,  258,   61,   57,
  266,  261,  257,   66,  286,  257,  257,   74,   24,   25,
  259,   73,  257,  264,  257,  266,  298,   80,   81,  282,
   87,   88,  288,  289,  273,   92,  264,  282,  283,  284,
  285,   47,  296,  100,  101,   97,   98,  288,   96,  291,
  292,  103,  297,   33,  102,  286,  291,  292,  291,  292,
  288,  289,  115,   43,  286,  258,  259,  298,  121,  126,
  263,  257,  265,  266,  267,  268,  269,  270,  271,  257,
  266,  257,  130,  136,  282,  257,  264,  282,  266,  282,
  291,  292,  257,  146,  147,  143,  144,  298,  296,  264,
  298,  266,  288,  289,  296,  297,  285,  300,  286,  287,
  288,  289,  290,  291,  292,  259,  294,  295,  291,  292,
  298,  286,  287,  288,  289,  290,  291,  292,  257,  282,
  295,  295,  298,  298,  297,  264,  286,  266,  296,  257,
  291,  292,  282,  257,  295,  258,  264,  257,  266,  295,
  264,  282,  266,  257,  264,  297,  266,  286,  287,  288,
  289,  290,  291,  292,  287,  290,  295,  257,  286,  298,
  288,  289,  290,  291,  288,  289,  290,  295,  288,  289,
  298,  258,  259,  294,  282,  286,  263,  292,  265,  266,
  267,  268,  269,  270,  271,  260,  298,  262,  298,  258,
  259,  289,  266,  296,  263,  282,  265,  266,  267,  268,
  269,  270,  271,  278,  279,  280,  281,  258,  259,  262,
  274,  259,  263,  282,  265,  266,  267,  268,  269,  270,
  271,  282,  283,  284,  285,  278,  279,  280,  281,  272,
  258,  282,  273,  285,  274,  263,  297,  265,  266,  267,
  268,  269,  270,  271,  272,    0,  282,  259,  258,  259,
  257,  261,  261,  263,  282,  265,  266,  267,  268,  269,
  270,  271,  282,  298,  262,  298,  258,  259,  298,   13,
  259,  263,  282,  265,  266,  267,  268,  269,  270,  271,
  278,  279,  280,  281,  258,  259,  259,   32,   10,  263,
  282,  265,  266,  267,  268,  269,  270,  271,  124,   49,
   54,   43,  258,  146,   99,   29,   -1,  263,  282,  265,
  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,  263,  282,  265,  266,  267,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,  275,  276,
   -1,   -1,   -1,   -1,  282,  282,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  293,   -1,   -1,   -1,
  297,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 329
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
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"programa : declaraciones funciones",
"declaraciones : tipo lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"tipo_registro : ESTRUCTURA INICIO declaraciones FIN",
"tipo : base tipo_arreglo",
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
#line 172 "parse.y"

/*
--Nombre Funcion: yyerror()
--Descripcion: Funcion para mandar un mensaje de error sintactico
--Autor: El profesor
--Fecha de creacion: Desconocido
*/
void yyerror(char *s){
    printf("Error sintactico. %s\n",s);
}
#line 433 "y.tab.c"

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
#line 74 "parse.y"
	{  printf("Aceptado\n"); }
break;
case 2:
#line 76 "parse.y"
	{}
break;
case 3:
#line 77 "parse.y"
	{}
break;
case 4:
#line 78 "parse.y"
	{}
break;
case 5:
#line 80 "parse.y"
	{}
break;
case 6:
#line 82 "parse.y"
	{}
break;
case 7:
#line 84 "parse.y"
	{}
break;
case 8:
#line 85 "parse.y"
	{}
break;
case 9:
#line 86 "parse.y"
	{}
break;
case 10:
#line 87 "parse.y"
	{}
break;
case 11:
#line 88 "parse.y"
	{}
break;
case 12:
#line 90 "parse.y"
	{}
break;
case 13:
#line 91 "parse.y"
	{}
break;
case 14:
#line 93 "parse.y"
	{}
break;
case 15:
#line 95 "parse.y"
	{}
break;
case 16:
#line 96 "parse.y"
	{}
break;
case 17:
#line 98 "parse.y"
	{}
break;
case 18:
#line 99 "parse.y"
	{}
break;
case 19:
#line 101 "parse.y"
	{}
break;
case 20:
#line 102 "parse.y"
	{}
break;
case 21:
#line 104 "parse.y"
	{}
break;
case 22:
#line 105 "parse.y"
	{}
break;
case 23:
#line 107 "parse.y"
	{}
break;
case 24:
#line 109 "parse.y"
	{}
break;
case 25:
#line 111 "parse.y"
	{}
break;
case 26:
#line 112 "parse.y"
	{}
break;
case 27:
#line 114 "parse.y"
	{}
break;
case 28:
#line 115 "parse.y"
	{}
break;
case 29:
#line 117 "parse.y"
	{}
break;
case 30:
#line 118 "parse.y"
	{}
break;
case 31:
#line 119 "parse.y"
	{}
break;
case 32:
#line 120 "parse.y"
	{}
break;
case 33:
#line 121 "parse.y"
	{}
break;
case 34:
#line 122 "parse.y"
	{}
break;
case 35:
#line 123 "parse.y"
	{}
break;
case 36:
#line 124 "parse.y"
	{}
break;
case 37:
#line 125 "parse.y"
	{}
break;
case 38:
#line 126 "parse.y"
	{}
break;
case 39:
#line 127 "parse.y"
	{}
break;
case 40:
#line 128 "parse.y"
	{}
break;
case 41:
#line 130 "parse.y"
	{}
break;
case 42:
#line 131 "parse.y"
	{}
break;
case 43:
#line 133 "parse.y"
	{}
break;
case 44:
#line 134 "parse.y"
	{}
break;
case 45:
#line 136 "parse.y"
	{}
break;
case 46:
#line 137 "parse.y"
	{}
break;
case 47:
#line 138 "parse.y"
	{}
break;
case 48:
#line 139 "parse.y"
	{}
break;
case 49:
#line 140 "parse.y"
	{}
break;
case 50:
#line 141 "parse.y"
	{}
break;
case 51:
#line 143 "parse.y"
	{}
break;
case 52:
#line 144 "parse.y"
	{}
break;
case 53:
#line 146 "parse.y"
	{}
break;
case 54:
#line 147 "parse.y"
	{}
break;
case 55:
#line 148 "parse.y"
	{}
break;
case 56:
#line 149 "parse.y"
	{}
break;
case 57:
#line 150 "parse.y"
	{}
break;
case 58:
#line 151 "parse.y"
	{}
break;
case 59:
#line 152 "parse.y"
	{}
break;
case 60:
#line 154 "parse.y"
	{}
break;
case 61:
#line 156 "parse.y"
	{}
break;
case 62:
#line 157 "parse.y"
	{}
break;
case 63:
#line 158 "parse.y"
	{}
break;
case 64:
#line 160 "parse.y"
	{}
break;
case 65:
#line 161 "parse.y"
	{}
break;
case 66:
#line 163 "parse.y"
	{}
break;
case 67:
#line 164 "parse.y"
	{}
break;
case 68:
#line 166 "parse.y"
	{}
break;
case 69:
#line 167 "parse.y"
	{}
break;
case 70:
#line 169 "parse.y"
	{}
break;
case 71:
#line 170 "parse.y"
	{}
break;
#line 916 "y.tab.c"
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
