#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backpatch.h"
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
--Nombre Funcion: nuevoIndice()
--Descripcion: Creacion de un nuevo indice
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/

Indice* nuevoIndice(char *i){
    Indice *indice = (Indice *)malloc(sizeof(Indice));
    indice->indice = i;
    indice->siguente = NULL;
    return indice;
}

/*
--Nombre Funcion: nuevaListaIndice()
--Descripcion: Creacion de un nueva lista de indices
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
listaIndice* nuevaListaIndice(){
    listaIndice *lista = (listaIndice *)malloc(sizeof(listaIndice));
    lista->inicio = NULL;
    lista->final = NULL;
    return lista;
}

/*
--Nombre Funcion: eliminarIndice()
--Descripcion: Libera la memoria de un indice y los siguentes a el
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarIndice(Indice *indice){
    if (indice != NULL) {
        eliminarIndice(indice->siguente);
        free(indice);
        indice = NULL;
    }
}

/*
--Nombre Funcion: eliminarListaIndice()
--Descripcion: Libera la memoria de una lista de indices y de su contenido
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void eliminarListaIndice(listaIndice *lista){
    if (lista != NULL){
        eliminarIndice(lista->inicio);
        free(lista);
        lista = NULL;
    }
}

/*
--Nombre Funcion: imprimirLista()
--Descripcion: Imprime una lista de indices
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void imprimirListaIndice(listaIndice *lista){
    if (lista != NULL) {
        Indice *i = lista->inicio;
        while (i != NULL) {
            printf("%s ", i->indice);
            i = i->siguente;
        }
        printf("\n");
    }
}

/*
--Nombre Funcion: agregarIndice()
--Descripcion: Se agrega un nuevo indice a la lista
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void agregarIndice(listaIndice *lista, Indice *indice){
    if (lista != NULL) {
        if (indice != NULL) {
            if (lista->inicio == NULL){
                lista->inicio = indice;
                lista->final = indice;
            } else {
                lista->final->siguente = indice;
                lista->final = indice;
            }
        } else { printf("No existe el indice a insertar\n"); }
    } else { printf("No existe la lista referida\n"); }
}

/*
--Nombre Funcion: combinar()
--Descripcion: Combina el contenido de las lista y regresa en una unica lista, por lo que la otra lista es eliminada
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
listaIndice* combinar(listaIndice *lista1, listaIndice *lista2){
    if (lista1 == NULL && lista2 == NULL) { return NULL; }
    if (lista1 == NULL) { return lista2; }
    if (lista2 == NULL) { return lista1; }
    Indice *indice = lista2->inicio;
    lista1->final->siguente = lista2->inicio;
    lista1->final = lista2->final;
    lista2->inicio = NULL;
    eliminarListaIndice(lista2);
    return lista1;
}

/*
--Nombre Funcion: backpatch()
--Descripcion: Busca en las cuadruplas cada uno de los indices de la lista y los sustituye con el argumento label
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 13 Junio 2020
*/
void backpatch(code *codigo, listaIndice *lista, char *label){
    if (codigo != NULL && lista != NULL && label != NULL){
        cuadru *cuadrupla;
        Indice *i = lista->inicio;
        while (i != NULL) {
            cuadrupla = codigo->inicio;
            while (cuadrupla != NULL) {
                if (strcmp(cuadrupla->op  ,i->indice) == 0) { cuadrupla->op   = label; }
                if (strcmp(cuadrupla->arg1,i->indice) == 0) { cuadrupla->arg1 = label; }
                if (strcmp(cuadrupla->arg2,i->indice) == 0) { cuadrupla->arg2 = label; }
                if (strcmp(cuadrupla->res ,i->indice) == 0) { cuadrupla->res  = label; }
                cuadrupla = cuadrupla->siguente;
            }
            i = i->siguente;
        }
    }
}

/*
--Nombre Funcion: nuevaTemp
--Descripcion: Funcion para crear una nueva temporal
--Autor: El profesor
--Fecha de creacion: Desconocido
*/
void nuevaTemp(char *t){
    sprintf(t, "t%d", temp++);
}

/*
--Nombre Funcion: nuevaEtiqueta()
--Descripcion: Funacion para crear una nuava Etiqueta
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 23 Mayo 2020
--Ultima modificacion: 24 Mayo 2020
*/
void nuevaEtiqueta(char *dire){
    char L[32];
    sprintf(L, "L%d", temp2++);
    strcpy (dire,L);
}
