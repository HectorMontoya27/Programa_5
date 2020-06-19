
%{
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

%}

%union{
  char dir[32];
  int base;
  struct {
      int tipo;
      int num;
      char dir[10];
  } numero;
}

%token PYC
%token INICIO
%token FIN
%token ESTRUCTURA
%token DEF
%token SIN
%token SI
%token ENTONCES
%token MIENTRAS
%token HACER
%token SEGUN
%token ESCRIBIR
%token DEVOLVER
%token LEER
%token TERMINAR
%token CASO
%token PRED
%token DOSP
%token FALSO
%token VERDADERO
%token PUNCOM

%token<base> SIN ENT REAL DREAL CAR
%token<dir> ID
%token<dir> CARACTER
%token<dir> CADENA
%token<numero> NUM

%token COMA
%right ASIG
%left O
%left Y
%left<dir> OPERADOR_RELACIONAL
%left<dir> SUM_RES
%left<dir> MUL_DIV_MOD
%right NO
%nonassoc PUNTO
%nonassoc CORDER
%nonassoc CORIZQ
%nonassoc LPAR RPAR
%nonassoc SIT
%nonassoc SINO
/*No terminales*/
%type<dir> programa declaraciones tipo_registro lista_var arreglo funciones argumentos lista_arg
%type<dir> arg tipo_arg param_arr sentencias sentencia casos predeterminado e_bool relacional expresion variable dato_est_sim
%type<dir> parametros lista_param variable_comp A
%type<base> base tipo_arreglo tipo
/*Inicio*/
%start programa

%%

programa : { inicializar(); } declaraciones funciones {  printf("Aceptado\n"); finalizar(); };

declaraciones : tipo {tipoGBL = $1;} lista_var PYC declaraciones {}
| tipo_registro lista_var PYC declaraciones {}
| {};

tipo_registro : ESTRUCTURA INICIO declaraciones FIN {};

tipo : base { baseGBL = $1; } tipo_arreglo { $$ = $3; };

base : SIN { $$ = -1; }
| ENT { $$ = 1; }
| REAL { $$ = 2; }
| DREAL { $$ = 3; }
| CAR { $$ = 0; };

tipo_arreglo : CORIZQ NUM CORDER tipo_arreglo {
    if ($2.tipo = 1) {
        if ($2.num > 0){
          $$ = TT_nuevoRegistro(getTablaGlobal(PilaTT),T_nuevo("arreglo",$2.num*TT_getTam(getTablaGlobal(PilaTT),$4),$4,NULL));
        } else {
          yyerror("El tamano del arreglo no es valido");
        }
    } else {
        yyerror("El tamaño del arreglo no es un número entero");
    }
 }
| { $$ = baseGBL; };

lista_var : ID A {
    if (existeID(PilaTS->inicio,$1) == -1) {
        TS_nuevoRegistro(getTablaGlobal(PilaTT),PilaTS->inicio,S_nuevo($1,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
};

A : COMA ID A {
  if (existeID(PilaTS->inicio,$2) == -1) {
      TS_nuevoRegistro(getTablaGlobal(PilaTT),PilaTS->inicio,S_nuevo($2,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
|  {};

funciones : DEF tipo ID LPAR argumentos RPAR INICIO declaraciones sentencias FIN funciones {}
| {};

argumentos : lista_arg {}
| SIN {};

lista_arg : lista_arg COMA arg {}
| arg {};

arg : tipo_arg ID {};

tipo_arg : base param_arr {};

param_arr : CORIZQ CORDER param_arr {}
| {};

sentencias : sentencias sentencia {}
| {};

sentencia : SI e_bool ENTONCES sentencias FIN {}
| SI e_bool ENTONCES sentencias SINO sentencias FIN {}
| MIENTRAS e_bool HACER sentencias FIN {}
| HACER sentencias MIENTRAS e_bool PYC {}
| SEGUN LPAR variable RPAR HACER casos predeterminado FIN {}
| variable ASIG expresion PYC {}
| ESCRIBIR expresion PYC {}
| LEER variable PYC {}
| DEVOLVER PYC {}
| DEVOLVER expresion PYC {}
| TERMINAR PYC {}
| INICIO sentencias FIN {};

casos : CASO NUM DOSP sentencias casos {}
| CASO NUM DOSP sentencias {};

predeterminado : PRED DOSP sentencias {}
| {};

e_bool : e_bool O e_bool {}
| e_bool Y e_bool {}
| NO e_bool {}
| relacional {}
| VERDADERO {}
| FALSO {}

relacional : relacional OPERADOR_RELACIONAL relacional {}
| expresion {};

expresion : expresion SUM_RES expresion {}
| expresion MUL_DIV_MOD expresion {}
| LPAR expresion RPAR {}
| variable {}
| NUM {}
| CADENA {}
| CARACTER {};

variable : ID variable_comp {};

variable_comp : dato_est_sim {}
| arreglo {}
| LPAR parametros RPAR {};

dato_est_sim : dato_est_sim PUNTO ID {}
| {};

arreglo : CORIZQ expresion CORDER {}
| CORIZQ expresion CORDER arreglo {};

parametros : lista_param {}
| {};

lista_param : lista_param COMA expresion {}
| expresion {};

%%
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
