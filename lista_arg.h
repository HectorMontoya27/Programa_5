#ifndef LISTA_ARG_H
#define LISTA_ARG_H
#include "datos.h"

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
listaArg *crearListaArg();                            //Lista
arg* crearArg(int tipo);                              //Lista
void agregarArg(listaArg *la, int tipo);              //Lista
/* Eliminar */
void borrarlistaArg(listaArg *la);                    //Lista
void borrarArgs(arg *a);                              //Lista
/* Impresion */
void imprimirLista(listaArg* lista);                  //Lista
void imprimirArg(arg* arg);                           //Lista
/* Busqueda */
int getTamlistaArg(listaArg *la);                     //Lista
int compararListasArg(listaArg *l1, listaArg *l2);    //Lista

#endif
