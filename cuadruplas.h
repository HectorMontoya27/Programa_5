#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

/* ---------------------- Estructuras de codigo y cuadrupla ----------------------- */
typedef struct QUAD cuadru;
typedef struct CODE code;

struct QUAD{
    char *op;
    char *arg1;
    char *arg2;
    char *res;
    cuadru *siguente;
};

struct CODE{
    cuadru *inicio;
    cuadru *final;
};

/* -------------------------Declaracion de Funciones -------------------------- */
/* Creacion */
cuadru *crearCuadrupla(char *op, char *arg1, char *arg2, char *res);            //Lista
code *crearCodigo();                                                            //Lista
/* Eliminacion */
void eliminarCuadrupla(cuadru *c);                                              //Lista
void eliminarCodigo(code *c);                                                   //Lista
/* Impresion */
void imprimirCuadrupla(cuadru *c);                                              //Lista
void imprimirCodigo(code *c);                                                   //Lista
/* Utiles y necesarias */
void agregarCuadrupla(code *codigo, cuadru *cuadrupla);                         //Lista


#endif
