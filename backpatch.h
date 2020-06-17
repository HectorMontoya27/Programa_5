#ifndef BACKPATCH_H
#define BACKPATCH_H

#include "cuadruplas.h"

/* ---------------------- Estructuras de codigo y cuadrupla ----------------------- */

typedef struct INDICE Indice;
typedef struct LISTA_INDICE listaIndice;

struct INDICE{
    char *indice;
    Indice *siguente;
};

struct LISTA_INDICE{
    Indice* inicio;
    Indice* final;
};

int temp;
int temp2;

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
Indice* nuevoIndice(char *i);                                         //Lista
listaIndice* nuevaListaIndice();                                      //Lista
/* Eliminacion */
void eliminarIndice(Indice *indice);                                  //Lista
void eliminarListaIndice(listaIndice *lista);                         //Lista
/* Impresion */
void imprimirListaIndice(listaIndice *lista);                         //Lista
/* Utiles y necesarias */
void agregarIndice(listaIndice *lista, Indice *indice);               //Lista
listaIndice* combinar(listaIndice *lista1, listaIndice *lista2);      //Lista
void backpatch(code *codigo, listaIndice *lista, char *label);        //Lista
void nuevaTemp(char *t);                                                   //Lista
void nuevaEtiqueta(char *dire);                                       //Lista

#endif
