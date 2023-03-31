%{
#include "expresiones.h"
#include <math.h>
int n_lineas;
//Definir un token para la asignación debido a que da problemas mas de un token
%}

identificador [_a-zA-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?

%option noyywrap
%%
[sS][aA][lL][iI][rR] return SALIR;
^{identificador}     strcpy(yylval.var, yytext); return ID;
{entero}		         yylval.c_entero = atoi(yytext); return NUMERO;
{real}               yylval.c_real = atof(yytext); return REAL;
\n				           n_lineas++; return (yytext[0]);
[\t ]			           ;	
. 				           return (yytext[0]);
%%