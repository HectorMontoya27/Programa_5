#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplas.h"
#include "backpatch.h"
#include "tipos.h"

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
--Nombre Funcion: ampliar
--Descripcion:*Recibe dos tipos, cada uno es su indice hacia la tabla de tipos en la cima de la pila
∗ Si el primero es mas chico que el segundo genera la cuadrupla
∗ para realizar la ampliacion del tipo.
∗ Retorna la nueva direccion generada por la ampliacion
∗ o la direccion original en caso de que no se realice
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 14/06/2020
--Fecha de modificacion:
--Autor modificacion:
--Descripcion de modificacion:
*/
void ampliar(char *res, char *dir, int t1, int t2, code *codigo){
    if (t1 != t2){
        int aux = max(t1, t2);
        if ( aux == -2){ res = NULL; }
        if ( aux == t1){ strcpy(res,dir); }
        else {
            nuevaTemp(res);
            switch (aux){
                case 1:
                    agregarCuadrupla(codigo,crearCuadrupla("(ent)", dir ,"-", res));
                    break;
                case 2:
                    agregarCuadrupla(codigo,crearCuadrupla("(real)", dir ,"-", res));
                    break;
                case 3:
                    agregarCuadrupla(codigo,crearCuadrupla("(dreal)", dir ,"-", res));
                    break;
                default:
                    res = NULL;
                    break;
            }
        }
    }
    else{
        strcpy(res,dir);
    }
}

/*
--Nombre Funcion: reducir
--Descripcion:∗Recibe dos tipos, cada uno es su indice hacia la tabla de tipos en la cima de la pila
∗ Si el primero es mas grande que e l segundo genera la cuadrupla
∗ para realizar la reduccion del tipo.
∗ Retorna la nueva direccion generada por la reduccion
∗ o la direccion original en caso de que no se realice
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 14/06/2020
*/
void reducir(char *res, char *dir, int t1, int t2, code *codigo){
    if (t1 != t2){
        int aux = min(t1, t2);
        if ( aux == -2 ){ res = NULL; }
        if ( aux == t1 ){ strcpy(res,dir); }
        else {
        nuevaTemp(res);
        switch (aux){
            case 0:
                agregarCuadrupla(codigo,crearCuadrupla("(car)", dir ,"-", res));
                break;
            case 1:
                agregarCuadrupla(codigo,crearCuadrupla("(ent)", dir ,"-", res));
                break;
            case 2:
                agregarCuadrupla(codigo,crearCuadrupla("(real)", dir ,"-", res));
                break;
            default:
                res = NULL;
                break;
            }
        }
    } else {
        strcpy(res,dir);
    }
}

/*
--Nombre Funcion: max
--Descripcion:∗Recibe dos tipos, cada uno es su indice hacia la tabla de tipos en la cima de la pila
*retorna el indice de menor dimension
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 14/06/2020
*/
int max(int t1, int t2){
    if ((0 <= t1 && t1 <= 3) && (0 <= t2 && t2 <= 3)){
        if (t1 > t2) { return t1; }
        else { return t2; }
    }
    else{
        printf("El tipo no es valido\n");
        return -2;
    }
}



/*
--Nombre Funcion: min
--Descripcion:∗Recibe dos tipos, cada uno es su indice hacia la tabla de tipos en la cima de la pila
*retorna el indicie de menor dimension
--Autor: Soto Vázquez Patricia
--Fecha de creacion: 14/06/2020
*/
int min(int t1, int t2){
    if ((0 <= t1 <= 3) && (0 <= t2 <= 3)){
        if (t1 > t2) { return t2; }
        else { return t1; }
    }
    else{
        printf("El tipo no es valido\n");
        return -2;
    }
}
