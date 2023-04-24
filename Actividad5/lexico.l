%{
#include "expresiones.h"
#include <math.h>
int n_lineas;
//Jesus Castaño Tato , Asier Serrano Martín
%}

identificador [_a-zA-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?

%option noyywrap
%%
[sS][aA][lL][iI][rR] return SALIR;
div  return DIV;
true  yyval.c_bool=true; return BOOL;   
false yyval.c_bool=false; return BOOL;
^{identificador}     strcpy(yylval.var, yytext); return ID;
{entero}		         yylval.c_entero = atoi(yytext); return NUMERO;
{real}               yylval.c_real = atof(yytext); return REAL;
\n				           n_lineas++; return (yytext[0]);
[\t ]			           ;	

\<                return MENOR;
>                 return MAYOR;
\>=                return MAYORIGUAL;
\<=                return MENORIGUAL;
==                return IGUAL;
!=                return DISTINTO;
[a][n][d]           return AND;
or              return OR;
not           return NOT;
:=            return ASIGNACION;
. 				           return (yytext[0]);

%%