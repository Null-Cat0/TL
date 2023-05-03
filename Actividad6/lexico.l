%{
#include "expresiones.h"
#include "tablaSimbolos.h"
#include <math.h>
int n_lineas;
std::map<std::string, InformacionSimbolo> tablaSimbolos;



//Jesus Castaño Tato , Asier Serrano Martín
%}

identificador [_a-zA-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?

%option noyywrap
%x COM1
%%

[/][/] { BEGIN(COM1); }
<COM1>"\n" { BEGIN(0); n_lineas++; return COMENTARIO; }
<COM1>. ;

and           return AND;
or              return OR;
not           return NOT;
div  return DIV;


true  yylval.c_bool=true; return BOOL;   
false yylval.c_bool=false; return BOOL;
{identificador}     strcpy(yylval.var, yytext); return ID;
{entero}		         yylval.c_entero = atoi(yytext); return NUMERO;
{real}               yylval.c_real = atof(yytext); return REAL;
\n				           n_lineas++; return (yytext[0]);
[\t ]			           ;	

\<                return MENOR;
>                 return MAYOR;
\>=                return MAYORIGUAL;
\<=                return MENORIGUAL;
\==                return IGUAL;
\!=                return DISTINTO;

:=            return ASIGNACION;
. 				           return (yytext[0]);

%%