%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
void error(char *s);
%}

identificador [a-zA-Z_][a-zA-Z_0-9]*
cadena \“[a-zA-Z][a-zA-Z]+\”
asignacion ":="
entero [0-9]+
real ([0-9]*[eE]-?[0-9]+)|([0-9]+"."[0-9]+)
num {entero}|{real}
caracter ‘[a-zA-Z]’
operador_relacional ">"|"<"|">="|"<="|"="|"<>"
comentarios "/*"([^*/])*"*/"
espacios [ \t\n\r]+

%%

[eE][sS][tT][rR][uU][cC][tT][uU][rR][aA]  {return ESTRUCTURA;}
[iI][nN][iI][cC][iI][oO]                  {return INICIO;}
[Ff][Ii][Nn]                              {return FIN;}
[Ee][Nn][Tt]                              {return TIPO;}
[Rr][Ee][Aa][Ll]                          {return TIPO;}
[Dd][Rr][Ee][Aa][Ll]                      {return TIPO;}
[Cc][Aa][Rr]                              {return TIPO;}
[Ss][Ii][Nn]                              {return TIPO;}
[Dd][Ee][Ff]                              {return DEF;}
[Ss][Ii]                                  {return SI;}
[Ee][Nn][Tt][Oo][Nn][Cc][Ee][Ss]          {return ENTONCES;}
[Mm][Ii][Ee][Nn][Tt][Rr][Aa][Ss]          {return MIENTRAS;}
[sS][iI][nN][oO]                          {return SINO;}
[hH][aA][cC][eE][rR]                      {return HACER;}
[sS][eE][gG][uU][nN]                      {return SEGUN;}
[eE][sS][cC][rR][iI][bB][iI][rR]          {return ESCRIBIR;}
[dD][eE][vV][oO][lL][vV][eE][rR]          {return DEVOLVER;}
[lL][eE][eE][rR]                          {return LEER;}
[Tt][Ee][Rr][Mm][Nn][Aa][Ll]              {return TERMINAR;}
[Cc][Aa][Ss][Oo]                          {return CASO;}
[Pp][Rr][Ee][dD]                          {return PRED;}
[oO]                                      {return O;}
[Yy]                                      {return Y;}
[Nn][Oo]                                  {return NO;}
[Vv][Ee][Rr][Dd][Aa][Dd][Ee][Rr][Oo]      {return VERDADERO;}
[Ff][Aa][Ll][Ss][Oo]                      {return FALSO;}
{identificador}                           {return ID;}
{cadena}                                  {return CADENA;}
{caracter}                                {return CARACTER;}
{num}                                     {return NUM;}
{asignacion}                              {return ASIG;}
{operador_relacional}                     {return OPERADOR_RELACIONAL;}
"+"|"-"                                   {return SUM_RES;}
"*"|"/"|"%"                               {return MUL_DIV_MOD;}
"("                                       {return LPAR;}
")"                                       {return RPAR;}
"["                                       {return CORIZQ;}
"]"                                       {return CORDER;}
";"                                       {return PYC;}
"."                                       {return PUNTO;}
":"                                       {return DOSP;}
","                                       {return COMA;}
{espacios}                                {/* Espacios en blanco */}
{comentarios}                             {/* Cometarios */}
. {error(yytext);}

%%

/*
--Nombre Funcion: error
--Descripcion: Funcion para mandar un error lexico
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 24 Mayo 2020
*/
void error(char *s){
    printf("Error lexico: %s, en la linea %d\n",s,yylineno);
}

/*
--Nombre Funcion: yywrap
--Descripcion: Funcion de yywrap()
--Autor: Héctor Montoya Pérez
--Fecha de creacion: 24 Mayo 2020
*/
int yywrap(){
  return 1;
}
