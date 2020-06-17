#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplas.h"

/* --------------------------- Formato de Documentacion ------------------------- */

// Documentacion de Creacion - Copiar y pegar
/*
--Nombre Funcion:
--Descripcion:
--Autor:
--Fecha de creacion:
*/
// Documentacion de Modificacion - Copiar y pegar
/*
--Fecha de modificacion:
--Autor modificacion:
--Descripcion de modificacion:
*/

/* -------------------------------- Funciones -------------------------------- */
/*
--Nombre Funcion: crearCuadrupla()
--Descripcion: Creacion de memoria para un tipo cuadrupla
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
cuadru *crearCuadrupla(char *op, char *arg1, char *arg2, char *res){
    cuadru *cuadrupla = (cuadru *)malloc(sizeof(cuadru));
    cuadrupla->op = op;
    cuadrupla->arg1 = arg1;
    cuadrupla->arg2 = arg2;
    cuadrupla->res = res;
    cuadrupla->siguente = NULL;
    return cuadrupla;
}

/*
--Nombre Funcion: crearCodigo()
--Descripcion: Apartamos memoria para el tipo code
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
code *crearCodigo(){
    code *codigo = (code *)malloc(sizeof(code));
    codigo->inicio = NULL;
    codigo->final = NULL;
    return codigo;
}

/*
--Nombre Funcion: eliminarCuadrupla()
--Descripcion: Liberacion de memoria para una cuadrupla y de las siguentes a ella
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarCuadrupla(cuadru * c){
    if (c != NULL){
        eliminarCuadrupla(c->siguente);
        free(c);
    }
}

/*
--Nombre Funcion: eliminarCodigo()
--Descripcion: Libera memoria de un codigo y su contenido
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarCodigo(code *c){
    eliminarCuadrupla(c->inicio);
    free(c);
}

/*
--Nombre Funcion: imprimirCuadrupla()
--Descripcion: Imprime una cuadrupla
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void imprimirCuadrupla(cuadru *c){
    if (c != NULL) { printf("%s\t%s\t%s\t%s\n", c->op, c->arg1, c->arg2, c->res); }
}

/*
--Nombre Funcion: imprimirCodigo()
--Descripcion: Imprime un codigo y su contenido
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void imprimirCodigo(code *c){
    if (c != NULL) {
        cuadru *cuadrupla = c->inicio;
        printf("\nOp\tArg1\tArg2\tRes\n\n");
        while (cuadrupla != NULL) {
            imprimirCuadrupla(cuadrupla);
            cuadrupla = cuadrupla->siguente;
        }
    }
}

/*
--Nombre Funcion: agregarCuadrupla()
--Descripcion: Se agrega una nueva cuadrupla a un codigo
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void agregarCuadrupla(code *codigo, cuadru *cuadrupla){
    if (codigo != NULL){
        if (cuadrupla != NULL){
          if (codigo->inicio == NULL){
              codigo->inicio = cuadrupla;
              codigo->final = cuadrupla;
          } else {
              codigo->final->siguente = cuadrupla;
              codigo->final = cuadrupla;
          }
        } else { printf("No existe una cuadrupla\n"); }
    } else { printf("No existe la variable code\n"); }
}
