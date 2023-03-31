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
[d][i]][v] return DIV;
^{identificador}     strcpy(yylval.var, yytext); return ID;
{entero}		         yylval.c_entero = atoi(yytext); return NUMERO;
{real}               yylval.c_real = atof(yytext); return REAL;
\n				           n_lineas++; return (yytext[0]);
[\t ]			           ;	
"<"                 return MENOR;
">="                return MAYORIGUAL;
">"                 return MAYOR;
"<="                return MENORIGUAL;
"=="                return IGUAL;
"!="                return DISTINTO;
[a][n][d]           return AND;
[o][r]              return OR;
[n][o][t]           return NOT;
. 				           return (yytext[0]);

%%