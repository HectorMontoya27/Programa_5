
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
T_Simbolos *tsGBL;
int tipoGBL;
int baseGBL;
int tamTS_GBL;
listaArg *listaRET;
char GBLid[20];

%}

%union{
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
%left<dir> MUL_DIV
%left<dir> MOD
%right NO
%nonassoc PUNTO
%nonassoc CORDER
%nonassoc CORIZQ
%nonassoc LPAR RPAR
%nonassoc SIT
%nonassoc SINO
/*No terminales*/
%type<dir> programa declaraciones tipo_registro lista_var funciones casos predeterminado parametros lista_param A
%type<base> base tipo_arreglo tipo tipo_arg arg param_arr
%type<lista> argumentos lista_arg
%type<variable> variable variable_comp arreglo dato_est_sim
%type<expresion> expresion
%type<boleano> e_bool relacional
%type<nextlist> sentencias sentencia

/*Inicio*/
%start programa

%%

programa : { inicializar(); } declaraciones funciones {  printf("Aceptado\n"); finalizar(); };

declaraciones : tipo {tipoGBL = $1;} lista_var PYC declaraciones {}
| tipo_registro lista_var PYC declaraciones {}
| {};

tipo_registro : ESTRUCTURA {
      PTT_push(PilaTT,TT_nueva("Estructura"));
      PTS_push(PilaTS,TS_nueva("Estructura"));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("car",1,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("ent",4,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("real",4,-1,NULL));
      TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("dreal",8,-1,NULL));

    } INICIO declaraciones FIN {

      TS_imprimir(PilaTS->cabeza);
      printf("\n");
      TT_imprimir(PilaTT->cabeza);
      printf("\n");
      tsGBL = PTS_pop(PilaTS);
      tsGBL->tt = PTT_pop(PilaTT);
      tamTS_GBL = tsGBL->dirMax;
      tipoGBL = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("struct",tamTS_GBL,-2,tsGBL));
    };

tipo : base { baseGBL = $1; } tipo_arreglo { $$ = $3; };

base : SIN { $$ = -1; }
| ENT { $$ = 1; }
| REAL { $$ = 2; }
| DREAL { $$ = 3; }
| CAR { $$ = 0; };

tipo_arreglo : CORIZQ NUM CORDER tipo_arreglo {
    if ($2.tipo = 1) {
        if ($2.num > 0){
          $$ = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",$2.num*TT_getTam(getTablaGlobal(PilaTT),$4),$4,NULL));
        } else { yyerror("El tamano del arreglo no es valido"); }
    } else {   yyerror("El tamaño del arreglo no es un número entero"); }
 }
| { $$ = baseGBL; };

lista_var : ID A {
    if (existeID(PilaTS->cabeza,$1) == -1) {
        TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo($1,tipoGBL,"var",NULL));
    } else {
        yyerror("Ya se declaró la variable");
    }
};

A : COMA ID A {
  if (existeID(PilaTS->cabeza,$2) == -1) {
      TS_nuevoRegistro(PilaTT->cabeza,PilaTS->cabeza,S_nuevo($2,tipoGBL,"var",NULL));
  } else {
      yyerror("Ya se declaró la variable");
  }
}
|  {};

funciones : DEF tipo ID {
          if (existeID(PilaTS->cabeza,$3) == -1) {
              char *funcion = (char *)malloc(sizeof(char)*20);
              sprintf(funcion,"Funcion - %s",$3);
              PTS_push(PilaTS,TS_nueva(funcion));
              PTT_push(PilaTT,TT_nueva(funcion));
              copiarGlobalTT(PilaTT);
              copiarGlobalTS(PilaTS);
              PilaTS->cabeza->tt = PilaTT->cabeza;
              listaRET = crearListaArg();
          } else {
              yyerror("Ya se declaro la variable");
          }

      } LPAR argumentos RPAR INICIO declaraciones sentencias FIN {
          TS_imprimir(PilaTS->cabeza);
          printf("\n");
          TT_imprimir(PilaTT->cabeza);
          printf("\n");
          TS_eliminar(PTS_pop( PilaTS ));
          TT_eliminar(PTT_pop( PilaTT ));
          borrarlistaArg(listaRET);

      } funciones {}
| {};

argumentos : lista_arg { $$.lista = $1.lista; $$.num = $1.num; }
| SIN { $$.lista = NULL; $$.num = 0; };

lista_arg : lista_arg COMA arg { $$.lista = $1.lista; $$.num = $1.num + 1; agregarArg($$.lista,$3); }
| arg { $$.lista = crearListaArg(); agregarArg($$.lista,$1); $$.num = 1; };

arg : tipo_arg ID {
      if (existeID(PilaTS->cabeza,$2) == -1) {
          TS_nuevoRegistro(PilaTT->cabeza, PilaTS->cabeza, S_nuevo($2,$1,"var",NULL));
          $$ = $1;
      } else { yyerror("Ya se declaro la variable"); }
 };

tipo_arg : base { baseGBL = $1; } param_arr { $$ = $3; };

param_arr : CORIZQ CORDER param_arr { $$ = TT_nuevoRegistro(PilaTT->cabeza,T_nuevo("arreglo",2,-1,NULL)); }
| { $$ = baseGBL; };

sentencias : sentencias sentencia {}
| {};

sentencia : SI e_bool ENTONCES sentencias FIN {}
| SI e_bool ENTONCES sentencias SINO sentencias FIN {}
| MIENTRAS e_bool HACER sentencias FIN {}
| HACER sentencias MIENTRAS e_bool PYC {}
| SEGUN LPAR variable RPAR HACER casos predeterminado FIN {}
| variable ASIG expresion PYC {
    char *tmp = (char *)malloc(sizeof(char)*10);
    char *tmp2 = (char *)malloc(sizeof(char)*10);
    reducir(tmp,$3.dir,$3.tipo,$1.tipo,codigo);
    strcpy(tmp2,$1.dir);
    agregarCuadrupla(codigo,crearCuadrupla("=",tmp,"-",tmp2));
}
| ESCRIBIR expresion PYC {
      char *tmp = (char *)malloc(sizeof(char)*15);
      strcpy(tmp,$2.dir);
      agregarCuadrupla(codigo,crearCuadrupla("write",tmp,"-","-"));
}
| LEER variable PYC {
    char *id = (char *)malloc(sizeof(char)*20);
    strcpy(id,$2.dir);
    agregarCuadrupla(codigo,crearCuadrupla("read",id,"-","-"));
}
| DEVOLVER PYC { agregarCuadrupla(codigo,crearCuadrupla("return","-","-","-")); }
| DEVOLVER expresion PYC {}
| TERMINAR PYC {}
| INICIO sentencias FIN {};

casos : CASO NUM DOSP sentencias casos {}
| CASO NUM DOSP sentencias {};

predeterminado : PRED DOSP sentencias {}
| {};

e_bool : e_bool O e_bool {
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,$1.falselist,tmpE);
    $$.truelist = combinar($1.truelist,$3.truelist);
    $$.falselist = $3.falselist;
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
| e_bool Y e_bool {
    char *tmpE = (char *)malloc(sizeof(char)*10);
    nuevaEtiqueta(tmpE);
    backpatch(codigo,$1.truelist,tmpE);
    $$.truelist = $1.truelist;
    $$.falselist = combinar($1.falselist,$3.falselist);
    agregarCuadrupla(codigo,crearCuadrupla("Label","-","-",tmpE));
}
| NO e_bool {
    $$.truelist = $2.falselist;
    $$.falselist = $2.truelist;
}
| relacional {
    $$.truelist = $1.truelist;
    $$.falselist = $1.falselist;
}
| VERDADERO {
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    $$.truelist = nuevaListaIndice();
    agregarIndice($$.truelist,nuevoIndice(indice));
}
| FALSO {
    char *indice = (char *)malloc(sizeof(char)*10);
    nuevoIndex(indice);
    $$.falselist = nuevaListaIndice();
    agregarIndice($$.falselist,nuevoIndice(indice));
};

relacional : relacional OPERADOR_RELACIONAL relacional {
    char *tmpI1 = (char *)malloc(sizeof(char)*10);
    char *tmpI2 = (char *)malloc(sizeof(char)*10);
    char *tmpR1 = (char *)malloc(sizeof(char)*10);
    char *tmpR2 = (char *)malloc(sizeof(char)*10);
    char *tmp = (char *)malloc(sizeof(char)*10);
    nuevoIndex(tmpI1);
    nuevoIndex(tmpI2);
    $$.truelist = nuevaListaIndice();
    $$.falselist = nuevaListaIndice();
    agregarIndice($$.truelist,nuevoIndice(tmpI1));
    agregarIndice($$.falselist,nuevoIndice(tmpI2));
    strcpy(tmp,$2);
    strcpy(tmpR1,$1.dir);
    strcpy(tmpR2,$3.dir);
    agregarCuadrupla(codigo,crearCuadrupla(tmp,tmpR1,tmpR2,tmpI1));
    agregarCuadrupla(codigo,crearCuadrupla("GOTO","-","-",tmpI2));
}
| expresion {
    strcpy($$.dir,$1.dir);
    $$.tipo = $1.tipo;
};

expresion : expresion SUM_RES expresion {
      $$.tipo = max($1.tipo,$3.tipo);
      char *tmp1 = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      char *tmp3 = (char *)malloc(sizeof(char)*10);
      char *op = (char *)malloc(sizeof(char));
      nuevaTemp(tmp1);
      strcpy($$.dir,tmp1);
      strcpy(op,$2);
      ampliar(tmp2,$1.dir,$1.tipo,$3.tipo,codigo);
      ampliar(tmp3,$3.dir,$3.tipo,$1.tipo,codigo);
      agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
}
| expresion MUL_DIV expresion {
      $$.tipo = max($1.tipo,$3.tipo);
      char *tmp1 = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      char *tmp3 = (char *)malloc(sizeof(char)*10);
      char *op = (char *)malloc(sizeof(char));
      nuevaTemp(tmp1);
      strcpy($$.dir,tmp1);
      strcpy(op,$2);
      ampliar(tmp2,$1.dir,$1.tipo,$3.tipo,codigo);
      ampliar(tmp3,$3.dir,$3.tipo,$1.tipo,codigo);
      agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
}
| expresion MOD expresion {
    if ($1.tipo == 1 && $3.tipo == 1){
        $$.tipo = max($1.tipo,$3.tipo);
        char *tmp1 = (char *)malloc(sizeof(char)*10);
        char *tmp2 = (char *)malloc(sizeof(char)*10);
        char *tmp3 = (char *)malloc(sizeof(char)*10);
        char *op = (char *)malloc(sizeof(char));
        nuevaTemp(tmp1);
        strcpy($$.dir,tmp1);
        strcpy(op,$2);
        ampliar(tmp2,$1.dir,$1.tipo,$3.tipo,codigo);
        ampliar(tmp3,$3.dir,$3.tipo,$1.tipo,codigo);
        agregarCuadrupla(codigo,crearCuadrupla(op,tmp2,tmp3,tmp1));
    } else {
        yyerror("El modulo se aplica a enteros");
    }
}
| LPAR expresion RPAR { $$.tipo = $2.tipo; strcpy($$.dir,$2.dir); }
| variable { $$.tipo = $1.tipo; strcpy($$.dir,$1.dir); }
| NUM { $$.tipo = $1.tipo; strcpy($$.dir,$1.dir); $$.valor = $1.num; }
| CADENA {  }
| CARACTER {  };

variable : ID {
    if (existeID(PilaTS->cabeza,$1) != -1) { strcpy(GBLid,$1);
    } else {
        char error[50];
        sprintf(error,"No se ha declarado variable: %s",$1);
        yyerror(error);
    }

} variable_comp {
    if ($3.estructura == 1) {
        char *tmp = (char *)malloc(sizeof(char)*10);
        char *tmp2 = (char *)malloc(sizeof(char)*20);
        nuevaTemp(tmp);
        strcpy($$.dir,tmp);
        $$.tipo = $3.tipo;
        sprintf(tmp2,"%s[%s]",$1,$3.dir);
        agregarCuadrupla(codigo,crearCuadrupla("=",tmp2,"-",tmp));
        strcpy($$.base,$1);
        $$.estructura = 1;
        $$.des = $3.des;
    } else {
        strcpy($$.dir,$1);
        $$.tipo = getTipo(PilaTS->cabeza,$1);
        $$.estructura = 0;
    }
};

variable_comp : dato_est_sim {
    $$.tipo = $1.tipo;
    $$.des = $1.des;
    $$.estructura = $1.estructura;
    if ($1.estructura == 1) {
      char *tmp = (char *)malloc(sizeof(char)*10);
      char *tmp2 = (char *)malloc(sizeof(char)*10);
      nuevaTemp(tmp);
      sprintf(tmp2,"%d",$1.des);
      agregarCuadrupla(codigo,crearCuadrupla("=",tmp2,"-",tmp));
      strcpy($$.dir,tmp);
    }
}
| arreglo {
    $$.tipo = $1.tipo;
    $$.des = $1.des;
    $$.estructura = 1;
    strcpy($$.dir,$1.dir);
}
| LPAR parametros RPAR {};

dato_est_sim : dato_est_sim PUNTO ID {
      if ($1.code_estructura == 1) {
          if (existeID($1.tabla,$3) != -1) {
              $$.des = $1.des + getDir($1.tabla,$3);
              int tipoV = getTipo($1.tabla,$3);
              $$.tipo = tipoV;
              char est[15];
              strcpy(est,getNombre_TT($1.tabla->tt,tipoV));
              if (strcmp(est,"struct") == 0) {
                  $$.code_estructura = 1;
                  $$.tabla = getTS($1.tabla->tt,tipoV);
              } else {
                  $$.code_estructura = 0;
                  $$.tabla = NULL;
              }
          } else { yyerror("La variable no ha sido declarada"); }
      } else { yyerror("La variable no es una estructura"); }
}
| {
      int tmp6 = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,tmp6),"struct") == 0) {
          $$.estructura = 1;
          $$.code_estructura = 1;
          $$.tabla = getTS(PilaTT->cabeza,tmp6);
          $$.des = 0;
      } else {
          $$.estructura = 0;
          $$.code_estructura = 0;
          $$.tipo = tmp6;
      }
};

arreglo : CORIZQ expresion CORDER {
      $$.tipo = getTipo(PilaTS->cabeza,GBLid);
      if (strcmp(getNombre_TT(PilaTT->cabeza,$$.tipo),"arreglo") == 0) {
          if ($2.tipo == 1) {
              int tmp3 = getTipoBase(PilaTT->cabeza,$$.tipo);
              int tam = TT_getTam(PilaTT->cabeza,tmp3);
              char *tmp4 = (char *)malloc(sizeof(char)*20);
              char *tmp5 = (char *)malloc(sizeof(char)*10);
              char *tmp7 = (char *)malloc(sizeof(char)*10);
              nuevaTemp(tmp4);
              strcpy($$.dir,tmp4);
              sprintf(tmp5,"%d",tam);
              strcpy(tmp7,$2.dir);
              agregarCuadrupla(codigo,crearCuadrupla("*",tmp7,tmp5,tmp4));
          } else { yyerror("El numero del arreglo no es un numero entero"); }
      } else { yyerror("La variable asociada no es de tipo arreglo"); }
}
| CORIZQ expresion CORDER arreglo {
  $$.tipo = getTipoBase(PilaTT->cabeza,$4.tipo);
  if (strcmp(getNombre_TT(PilaTT->cabeza,$$.tipo),"arreglo") == 0) {
      if ($2.tipo == 1) {
          int tmp = getTipoBase(PilaTT->cabeza,$$.tipo);
          int tam = TT_getTam(PilaTT->cabeza,tmp);
          char *tmp2 = (char *)malloc(sizeof(char)*20);
          char *tmp3 = (char *)malloc(sizeof(char)*10);
          char *tmp4 = (char *)malloc(sizeof(char)*10);
          char *tmp5 = (char *)malloc(sizeof(char)*10);
          char *tmp6 = (char *)malloc(sizeof(char)*10);
          nuevaTemp(tmp2);
          nuevaTemp(tmp5);
          strcpy($$.dir,tmp5);
          sprintf(tmp3,"%d",tam);
          strcpy(tmp4,$2.dir);
          strcpy(tmp6,$4.dir);
          agregarCuadrupla(codigo,crearCuadrupla("*",tmp4,tmp3,tmp2));
          agregarCuadrupla(codigo,crearCuadrupla("+",tmp2,tmp6,tmp5));
          $$.des = $2.valor * atoi(tmp3);
      } else { yyerror("El numero del arreglo no es un numero entero"); }
  } else { yyerror("La variable asociada no es de tipo arreglo"); }
};

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
