%{
#include <iostream>
#include "tablaSimbolos.h"
#include "mondrian.h"
#include <math.h>
using namespace std;



//Jesus Castaño Tato , Asier Serrano Martín
int n_lineas;
map<string, InformacionSimbolo> tablaSimbolos

%}

identificadorMinuscula [a-z][_a-zA-Z0-9]*
identificadorMayuscula [A-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?

%option noyywrap
%x COM1
%%

[#] { BEGIN(COM1); }
<COM1>"\n" { BEGIN(0); n_lineas++; return COMENTARIO; }
<COM1>. ;


{identificadorMinuscula}     strcpy(yylval.var, yytext); return IDENTIFICADORMINUSCULA;
{identificadorMayuscula}     strcpy(yylval.var, yytext); return IDENTIFICADORMAYUSCULA;
{entero}		         yylval.c_entero = atoi(yytext); return ENTERO;
{real}               yylval.c_real = atof(yytext); return REAL;
true  yylval.c_bool=true; return BOOL;   
false yylval.c_bool=false; return BOOL;

Entero  return TIPOENTERO;
Real        return TIPOREAL;
Logico  return TIPOLOGICO;
VARIABLES return VARIABLES;
RECUADROS return RECUADROS;
blanco|negro|gris|rojo|azul|amarillo|verde return COLOR;
LINEAS return LINEAS;
horizontal|vertical return ORIENTACION;


\n				           n_lineas++; return (yytext[0]);
:=            return ASIGNACION;
=             return IGUAL;
. 				           return (yytext[0]);

%%