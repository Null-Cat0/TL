%{
#include "mondrian.h"
#include "tablaSimbolos.h"
#include <math.h>

//Jesus Castaño Tato , Asier Serrano Martín
int n_lineas;
std::map<std::string, InformacionSimbolo> tablaSimbolos;
%}

identificadorMinuscula [a-z][_a-zA-Z0-9]*
identificadorMayuscula [A-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?
color blanco|negro|gris|rojo|azul|amarillo|verde
tipo Entero|Real|Logico
orientacion horizontal|vertical

%option noyywrap
%x COM1
%%
[#] { BEGIN(COM1); }
<COM1>"\n" { BEGIN(0); n_lineas++; return COMENTARIO; }
<COM1>. ;

VARIABLES           return VARIABLES;
RECUADROS return RECUADROS;
LINEAS return LINEAS;
true  yylval.c_bool=true; return BOOL;   
false yylval.c_bool=false; return BOOL;

{orientacion} return ORIENTACION;
{tipo}  cout << "hola"; return TIPO;
{color} return COLOR;
{real}               yylval.c_real = atof(yytext); cout << "Real"<<endl; return REAL;
{identificadorMinuscula}     strcpy(yylval.var, yytext); cout << "minuscula"; return IDENTIFICADORMINUSCULA;
{identificadorMayuscula}     strcpy(yylval.var, yytext); return IDENTIFICADORMAYUSCULA;
{entero}		         yylval.c_entero = atoi(yytext); return ENTERO;


\n				           n_lineas++; return SALTOLINEA;
;               return PUNTOYCOMA;
:=            return ASIGNACION;
=             return IGUAL;











. 				           return (yytext[0]);

%%